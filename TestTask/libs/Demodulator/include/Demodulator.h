#ifndef DEMODULATOR_H
#define DEMODULATOR_H

#include <vector>
#include <complex>
#include <numeric>
#include <algorithm>

// #include "Wav.h"
// class Waw;
// изучить forward declaration

template <class T>
class FileManager {
public:
    std::vector<std::complex<T>> getComplexSignalFromBinaryFile(std::string& filename);
    void writeToWavFile(std::string filename, std::vector<float>& demodulatedSignal, int sampleRate);
};

template <class T>
class IDemodulator {
public:
    virtual ~IDemodulator()                                                             = default;
    virtual std::vector<float> demodulate(std::vector<std::complex<T>>& complexSamples) = 0;
};

class AmplitudeDemodulator : public IDemodulator<int> {
public:
    AmplitudeDemodulator()
    {}
    ~AmplitudeDemodulator()
    {}
    std::vector<float> demodulate(std::vector<std::complex<int>>& complexSamples) override;
};

class FrequencyDemodulator : public IDemodulator<float> {
public:
    FrequencyDemodulator()
    {}
    ~FrequencyDemodulator()
    {}
    std::vector<float> demodulate(std::vector<std::complex<float>>& complexSamples) override;
};

#endif // DEMODULATOR_H
