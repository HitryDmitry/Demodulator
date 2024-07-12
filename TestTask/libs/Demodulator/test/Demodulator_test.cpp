#include <gtest/gtest.h>
#include <memory>
#include "Demodulator.h"
#include "Demodulator.cpp"

// /**
//  * @brief тестируем функцию filter
//  */
// TEST(DemodulatorTest, TestFilterFunction)
// {
//     // создаем вектор чисел, к которому будем применять фильтр
//     std::vector<float> numbers = {2, 1, 6, 2, 4, 3};
//     // размер окна
//     int windowSize = 3;
//     // вектор коэффициентов a
//     std::vector<float> a = {1};
//     // заполняем вектор b значениями 1/windowSize
//     std::vector<float> b(windowSize);
//     for(int index = 0; index < windowSize; ++index) {
//         b[index] = (float)1 / windowSize;
//     }
//     // вектор с ожидаемым результатом (с сайта matlab)
//     std::vector<float> required_answer = {0.6667, 1.0, 3.0, 3.0, 4.0, 3.0};
//     // проверка
//     ASSERT_EQ(Filter::filter(b, a, numbers), required_answer);
// }

// /**
//  * @brief TEST тестируем функцию, считывающую комплексные отсчеты из файла
//  */
// TEST(DemodulatorTest, CheckGetComplexSignalFromBinaryFile)
// {
//     // записываем последовательность чисел 1 2 3 4 5 6 7 8 9 10 в файл numbers.dat
//     std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     AmplitudeDemodulator::writeToDatFile("numbers.dat", numbers);
//     // формируем вектор комплексных отсчетов из numbers
//     std::vector<std::complex<int>> answer;
//     for(int i = 0; i < numbers.size(); i += 2) {
//         answer.push_back(std::complex<int>(numbers[i], numbers[i + 1]));
//     }
//     // проверяем
//     std::vector<std::complex<int>> functionReturned =
//         AmplitudeDemodulator::getComplexSignalFromBinaryFile("numbers.dat");
//     ASSERT_EQ(functionReturned, answer);
// }

// /**
//  * @brief TEST тестируем функцию, демодулирующую АМ сигнал
//  */
// TEST(DemodulatorTest, demodulateAMSignal)
// {
//     // создаем последовательность чисел 1 1 2 1 3 5 1 2 4 0
//     std::vector<int> numbers = {1, 1, 2, 1, 3, 5, 1, 2, 4, 0};
//     // формируем вектор комплексных отсчетов из numbers
//     std::vector<std::complex<int>> complexSamples;
//     // вектор модулей комплексных чисел
//     std::vector<float> samplesAbs;
//     for(int i = 0; i < numbers.size(); i += 2) {
//         std::complex<int> C(numbers[i], numbers[i + 1]);
//         complexSamples.push_back(C);
//         samplesAbs.push_back(abs(C));
//     }
//     // результат работы функции
//     std::vector<float> demodulatedSignal = AmplitudeDemodulator::demodulate(complexSamples);

//     ASSERT_EQ(demodulatedSignal, samplesAbs);
// }

// /**
//  * @brief TEST тестируем функцию averageFilter
//  */
// TEST(DemodulatorTest, TestAverageFilter)
// {
//     // тестируем на первом наборе чисел
//     std::vector<float> numbers    = {1, 1, 2, 1, 3, 5, 1, 2, 4, 0, 1, 9};
//     int windowSize                = 3;
//     std::vector<float> meanValues = {0.333333, 0.666667, 1.33333, 1.33333, 2,       3,
//                                      3,        2.66667,  2.33333, 2,       1.66667, 3.33333};
//     ASSERT_EQ(Filter.averageFilter(numbers, windowSize), meanValues);
//     // тестируем для другого набора чисел
//     numbers                            = {2, 1, 6, 2, 4, 3};
//     std::vector<float> required_answer = {0.6667, 1.0, 3.0, 3.0, 4.0, 3.0};
//     ASSERT_EQ(Filter::averageFilter(numbers, windowSize), required_answer);
// }

// /**
//  * @brief тестируем функцию записи в wav-file
//  */
// TEST(DemodulatorTest, writeToWavFile)
// {
//     std::vector<std::complex<int>> complexSamples =
//         AmplitudeDemodulator::getComplexSignalFromBinaryFile("am_sound.dat");
//     std::vector<float> demodulatedSignal = AmplitudeDemodulator::demodulate(complexSamples);
//     std::vector<float> filteredSignal    = AmplitudeDemodulator::averageFilter(demodulatedSignal, 10);
//     AmplitudeDemodulator::writeToWavFile("demodulated_AM", demodulatedSignal, 16000);
// }

// /**
//  * @brief тестируем функцию downsample
//  */
// TEST(DemodulatorTest, testDownsampleFunc)
// {
//     // формируем вектор комплексных отсчетов из numbers
//     std::vector<std::complex<int>> complexSamples = {{1, 1}, {2, 1}, {3, 5}, {1, 2}, {4, 0}, {6, 7}};
//     // выбрасываем каждый второй
//     std::vector<std::complex<int>> downsampledAnswer = {{1, 1}, {3, 5}, {4, 0}};
//     ASSERT_EQ(FrequencyDemodulator::downsample(complexSamples, 2), downsampledAnswer);
// }

// /**
//  * @brief тестируем функцию FM демодуляции
//  */
// TEST(DemodulatorTest, testDemodulationFM)
// {
//     // Считываем данные из файла
//     std::vector<std::complex<float>> complexSamples = getComplexSignalFromBinaryFile("file1EuropaPlus.bin");

//     // ДЕМОДУЛЯЦИЯ. Умножаем каждый отсчет на следующее за ним комплексное число сопряженное
//     std::vector<float> demodulatedSignal = demodulate(complexSamples);

//     // ФИЛЬТРАЦИЯ. Пропускаем через ФНЧ с частотой среза, совпадающещей с новой частотой Найквиста
//     demodulatedSignal = lowpass(10000, 20000, demodulatedSignal);
//     // Еще раз проводим downsampling
//     demodulatedSignal = downsample(demodulatedSignal, 25);
//     // Записываем в wav файл
//     writeToWavFile("demodulated_FM", demodulatedSignal, 20000);
// }

/**
 * @brief проверяем работу интерфейса
 */
TEST(DemodulatorTest, TestDemodulatorInterface)
{
    FileManager<int> F;

    std::unique_ptr<IDemodulator<int>> D = std::make_unique<AmplitudeDemodulator>();
    // IDemodulator<int>* D = new AmplitudeDemodulator();
    std::string filename("am_sound.dat");
    std::vector<std::complex<int>> complexSamples = F.getComplexSignalFromBinaryFile(filename);
    std::vector<float> demodulatedSignal          = D->demodulate(complexSamples);
    F.writeToWavFile("demodulated_AM", demodulatedSignal, 32000);

    // auto* FD = new FrequencyDemodulator<float>();
    // std::string filename("file1EuropaPlus.bin");
    // std::vector<std::complex<float>> complexSamples = FD->getComplexSignalFromBinaryFile(filename);
    // std::vector<float> demodulatedSignal            = FD->demodulate(complexSamples);
    // FD->writeToWavFile("demodulated_FM", demodulatedSignal, 20000);
    // delete FD;
}
