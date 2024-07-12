#include "Demodulator.h"
#include "wav.h"

// ------------------------- вспомогательные функции --------------------------------------
// direct form II transposed
std::vector<float> filter(std::vector<float>& B, std::vector<float>& A, const std::vector<float>& inputSignal)
{
    int filterOrder = std::max(B.size(), A.size()) - 1;
    int lengthOfA   = A.size();
    // вектор, хранящий состояния элементов задержки
    std::vector<float> filterState(filterOrder);

    for(int i = 0; i < B.size(); ++i) {
        B[i] /= A[0];
    }
    for(int i = 0; i < A.size(); ++i) {
        A[i] /= A[0];
    }

    std::vector<float> Out(inputSignal.size());
    // m - номер отсчета (начинаем с 0), j - номер элемента задержки (начинаем с 0)
    for(int m = 0; m < Out.size(); ++m) {
        Out[m] = B[0] * inputSignal[m] + filterState[0];
        for(int j = 1; j < filterOrder + 1; ++j) {
            filterState[j - 1] = B[j] * inputSignal[m] + filterState[j] - A[j] * Out[m];
        }
    }
    return Out;
}

void butter(std::vector<float>& B, std::vector<float>& A, float fc, float fs, bool lowPass = true)
{
    const float k    = tanf(M_PI * fc / (fs * 2));
    const float k2   = k * k;
    const float q    = 1 / sqrtf(2);
    const float norm = 1 / (1 + k / q + k2);

    // std::vector<float> B(3);
    // std::vector<float> A(2);
    if(lowPass) {
        B[0] = k2 * norm;
        B[1] = 2 * B[0];
        B[2] = B[0];
    }
    else {
        B[0] = 1 * norm;
        B[1] = -2 * B[0];
        B[2] = B[0];
    }
    A[0] = 2 * (k2 - 1) * norm;
    A[1] = (1 - k / q + k2) * norm;
}

std::vector<std::complex<float>> lowpass(float cutOffFreqHz, float samplingFreqHz,
                                         std::vector<std::complex<float>>& complexNumbers)
{
    std::vector<float> B(3);
    std::vector<float> A(2);
    // float gain = getCoefficientsOfButterworthFilter(B, A, cutOffFreqHz, samplingFreqHz);
    float gain = 1;
    butter(B, A, cutOffFreqHz, samplingFreqHz);
    std::vector<std::complex<float>> filteredSignal(complexNumbers.size());
    for(int i = 2; i < complexNumbers.size(); ++i) {
        filteredSignal[i] = gain * complexNumbers[i] + B[0] * complexNumbers[i - 1] + B[1] * complexNumbers[i - 2] -
                            A[0] * filteredSignal[i - 1] - A[1] * filteredSignal[i - 2];
    }
    return filteredSignal;
}

std::vector<float> lowpass(float cutOffFreqHz, float samplingFreqHz, std::vector<float>& complexNumbers)
{
    std::vector<float> B(3);
    std::vector<float> A(2);
    float gain = 1;
    butter(B, A, cutOffFreqHz, samplingFreqHz);
    std::vector<float> filteredSignal(complexNumbers.size());
    for(int i = 2; i < complexNumbers.size(); ++i) {
        filteredSignal[i] = gain * complexNumbers[i] + B[0] * complexNumbers[i - 1] + B[1] * complexNumbers[i - 2] -
                            A[0] * filteredSignal[i - 1] - A[1] * filteredSignal[i - 2];
    }
    return filteredSignal;
}

std::vector<float> averageFilter(std::vector<float> inputSignal, int windowSize)
{
    std::vector<float> a = {1};
    std::vector<float> b(windowSize);
    // заполняем массив коэффициентов b значением 1 / windowSize
    for(int index = 0; index < windowSize; ++index)
        b[index] = 1.f / windowSize;
    // применяем фильтр
    return filter(b, a, inputSignal);
}

std::vector<std::complex<float>> downsample(std::vector<std::complex<float>>& complexSamples, int decimationFactor)
{
    std::vector<std::complex<float>> downsampledSignal(0);
    for(int i = 0; i < complexSamples.size(); i += decimationFactor)
        downsampledSignal.push_back(complexSamples[i]);
    return downsampledSignal;
}

std::vector<float> downsample(std::vector<float>& signalFloat, int decimationFactor)
{
    std::vector<float> downsampledSignal(0);
    for(int i = 0; i < signalFloat.size(); i += decimationFactor)
        downsampledSignal.push_back(signalFloat[i]);
    return downsampledSignal;
}

//------------------------------ функции классов -----------------------------------------------
template <typename T>
std::vector<std::complex<T>> FileManager<T>::getComplexSignalFromBinaryFile(std::string& filename)
{
    std::ifstream ifs(filename, std::ios::binary | std::ios::in);
    // вычисляем количество элементов
    int legthOfFileInBytes = 0;
    if(ifs) {
        ifs.seekg(0, ifs.end);
        legthOfFileInBytes = ifs.tellg();
        ifs.seekg(0, ifs.beg);
    }
    int numOfComplexNumbers = legthOfFileInBytes / sizeof(T) / 2;
    std::vector<std::complex<T>> complexNumbers(numOfComplexNumbers);
    ifs.read(reinterpret_cast<char*>(complexNumbers.data()), legthOfFileInBytes);
    ifs.close();
    return complexNumbers;
}

template <typename T>
void FileManager<T>::writeToWavFile(std::string filename, std::vector<float>& demodulatedSignal, int sampleRate)
{
    WavFile<float_t> wavFileCore(filename, demodulatedSignal.size(), sampleRate);
    wavFileCore.writeDataBlock(demodulatedSignal);
}

std::vector<float> AmplitudeDemodulator::demodulate(std::vector<std::complex<int>>& complexSamples)
{
    std::vector<float> modulatingSignal(0);
    for(auto complexNumber: complexSamples) {
        modulatingSignal.push_back(std::sqrt(pow(complexNumber.imag(), 2) + pow(complexNumber.real(), 2)));
    }

    float average = 0;
    for(auto elem: modulatingSignal) {
        average += elem / modulatingSignal.size();
    }

    for(int i = 0; i < modulatingSignal.size(); ++i) {
        modulatingSignal[i] -= average;
        modulatingSignal[i] /= average;
    }

    modulatingSignal = averageFilter(modulatingSignal, 10);

    return modulatingSignal;
}

std::vector<float> FrequencyDemodulator::demodulate(std::vector<std::complex<float>>& complexSamples)
{
    std::vector<float> demodulatedSignal(0);
    for(int i = 0; i < complexSamples.size() - 1; ++i) {
        std::complex<float> mul = complexSamples[i] * std::conj(complexSamples[i + 1]);
        demodulatedSignal.push_back(std::atan2(mul.imag(), mul.real()));
    }

    // Фильтрация. Пропускаем через ФНЧ с частотой среза, совпадающещей с новой частотой Найквиста
    demodulatedSignal = lowpass(10000, 20000, demodulatedSignal);
    // Проводим downsampling
    demodulatedSignal = downsample(demodulatedSignal, 25);

    return demodulatedSignal;
}
