#ifndef DEMODULATOR_H
#define DEMODULATOR_H

#include <vector>
#include <complex>

// #include "WAe.h"
// class Waw;
// изучить forward declaration

// direct form II transposed
std::vector<float> filter(const Waw B, const std::vector<float>& A, const std::vector<float>& inputSignal);

std::vector<std::complex<float>> getComplexSignalFromBinaryFile(const std::string& filename);

std::vector<float> demodulateAMSignal(std::vector<std::complex<int>> signalComplexSamples, int normilizingPower,
                                      float DCcomponent);

std::vector<float> averageFilter(std::vector<float> inputSignal, int windowSize = 10);

std::vector<std::complex<float>> downsample(std::vector<std::complex<float>> signal, int decimationFactor);

std::vector<float> downsample(std::vector<float> signal, int decimationFactor);

std::vector<std::complex<float>> lowpass(float cutOffFreqHz, float samplingFreqHz,
                                         std::vector<std::complex<float>>& complexNumbers);

std::vector<float> lowpass(float cutOffFreqHz, float samplingFreqHz, std::vector<float>& complexNumbers);

std::vector<float> derivFilter(std::vector<float> inputSignal);

std::vector<float> demodulateFMSignal(std::vector<std::complex<float>> complexSamples);

void writeToDatFile(char const* filename, std::vector<int> dataSequence);

void writeToWavFile(std::string outputPath, std::vector<float> demodulatedSignal, int sampleRate);

#endif // DEMODULATOR_H
