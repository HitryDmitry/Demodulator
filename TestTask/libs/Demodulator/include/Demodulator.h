#ifndef DEMODULATOR_H
#define DEMODULATOR_H

#include <vector>
#include <complex>
#include <numeric>
#include <algorithm>

// #include "Wav.h"
// class Waw;
// изучить forward declaration

// class FileManager {

// };

template <class T>
class IDemodulator {
public:
    virtual std::vector<float> demodulate(std::vector<std::complex<T>>& complexSamples) = 0;

    std::vector<std::complex<T>> getComplexSignalFromBinaryFile(std::string& filename);

    void writeToWavFile(std::string filename, std::vector<float>& demodulatedSignal, int sampleRate);
};

class AmplitudeDemodulator : public IDemodulator<int> {
public:
    AmplitudeDemodulator()
    {}
    std::vector<float> demodulate(std::vector<std::complex<int>>& complexSamples) override;
};

class FrequencyDemodulator : public IDemodulator<float> {
public:
    FrequencyDemodulator()
    {}
    std::vector<float> demodulate(std::vector<std::complex<float>>& complexSamples) override;
};

#endif // DEMODULATOR_H
