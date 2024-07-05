#include "Demodulator.h"
#include "wav.h"

// direct form II transposed
std::vector<float> filter(std::vector<float> B, std::vector<float> A, std::vector<float>& inputSignal)
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

// float getCoefficientsOfButterworthFilter(std::vector<float>& B, std::vector<float>& A, float fc, float fs)
// {
//     float cyclicCutOffFreq = 2 * M_PI * fc / fs;
//     float alpha            = tan(cyclicCutOffFreq / 2);

//     float gain = alpha * alpha / (1 + sqrt(2) * alpha + alpha * alpha);
//     A[0]       = 2 * (alpha * alpha - 1) / (1 + sqrt(2) * alpha + alpha * alpha);
//     A[1]       = (1 + sqrt(2) * alpha + alpha * alpha) / (1 + sqrt(2) * alpha + alpha * alpha);
//     B[0]       = 2 * gain;
//     B[1]       = gain;

//     return gain;
// }

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
    _t return filteredSignal;
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

std::vector<std::complex<float>> getComplexSignalFromBinaryFile(const char* filename)
{
    std::ifstream ifs(filename, std::ios::binary | std::ios::in);
    // вычисляем количество элементов
    int legthOfFileInBytes = 0;
    if(ifs) {
        ifs.seekg(0, ifs.end);
        legthOfFileInBytes = ifs.tellg();
        ifs.seekg(0, ifs.beg);
    }
    int numOfComplexNumbers = legthOfFileInBytes / sizeof(float) / 2;
    std::vector<std::complex<float>> complexNumbers(numOfComplexNumbers);
    ifs.read(reinterpret_cast<char*>(complexNumbers.data()), legthOfFileInBytes);
    ifs.close();
    return complexNumbers;
}

std::vector<float> demodulateAMSignal(std::vector<std::complex<int>> signalComplexSamples, int normilizingPower,
                                      float DCcomponent) // нормировка внутри по умолчанию. Убрать лишние параметры
{
    std::vector<float> modulatingSignal(0);
    for(auto complexNumber: signalComplexSamples) {
        // добавляем в вектор, содержащий отсчеты сигнала, модуль комплексного отсчета,
        // умноженный на 10^-5 и вычитаем постоянную составляющую (3.2)
        modulatingSignal.push_back(std::sqrt(pow(complexNumber.imag(), 2) + pow(complexNumber.real(), 2)) *
                                       pow(10, normilizingPower) -
                                   DCcomponent);
    }

    return modulatingSignal;
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

std::vector<float> hammingWindow(int windowSize)
{
    std::vector<float> w(windoSize);
    for(int i = 0; i <= windoSize; ++i)
        w.push_back(0.54 - 0.46 * cos(2 * M_PI * i / windoSize));
    return w;
}

std::vector<float> vectorOfImpulseResponceOfderivFilter()
{
    // Задержка фильтра во времени
    const int32_t L = 19;
    // окно Хэмминга для определенного значения задержки
    std::vector<float> hamming = hammingWindow(2 * L + 1);
    // Импульсная характеристика дифференцирующего фильтра
    std::vector<float> impulseResponce(0);
    for(int i = 0; i < L * 2 + 1; ++i) {
        if(i == 0)
            impulseResponce.push_back(0);
        impulseResponce.push_back(hamming[i] * pow(-1, i - 19) / (i - 19));
    }
    return impulseResponce;
}

std::vector<float> demodulateFMSignal(std::vector<std::complex<float>> complexSamples)
{
    std::vector<float> demodulatedSignal(0);
    for(int i = 0; i < complexSamples.size() - 1; ++i) {
        std::complex<float> mul = complexSamples[i] * std::conj(complexSamples[i + 1]);
        demodulatedSignal.push_back(std::atan2(mul.imag(), mul.real()));
    }

    return demodulatedSignal;
}

std::vector<std::complex<float>> downsample(std::vector<std::complex<float>> complexSignal, int decimationFactor)
{
    std::vector<std::complex<float>> downsampledSignal(0);
    for(int i = 0; i < complexSignal.size(); i += decimationFactor)
        downsampledSignal.push_back(complexSignal[i]);
    return downsampledSignal;
}

std::vector<float> downsample(std::vector<float> signal, int decimationFactor)
{
    std::vector<float> downsampledSignal(0);
    for(int i = 0; i < signal.size(); i += decimationFactor)
        downsampledSignal.push_back(signal[i]);
    return downsampledSignal;
}

void writeToDatFile(const char* filename, std::vector<int> dataSequence)
{
    std::ofstream ofs(filename, std::ios::out | std::ios::binary);
    ofs.write(reinterpret_cast<char*>(dataSequence.data()), dataSequence.size() * sizeof(int));
    ofs.close();
}

void writeToWavFile(std::string outputPath, std::vector<float> demodulatedSignal, int sampleRate)
{
    WavFile<float_t> wavFileCore(outputPath, demodulatedSignal.size(), sampleRate);
    wavFileCore.writeDataBlock(demodulatedSignal);
}
