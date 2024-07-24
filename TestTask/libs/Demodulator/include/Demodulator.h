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

template <class T>
class AmplitudeDemodulator : public IDemodulator<T> {
public:
    AmplitudeDemodulator()
    {}
    ~AmplitudeDemodulator()
    {}
    std::vector<float> demodulate(std::vector<std::complex<T>>& complexSamples) override;
};

template <class T>
class FrequencyDemodulator : public IDemodulator<T> {
public:
    FrequencyDemodulator()
    {}
    ~FrequencyDemodulator()
    {}
    std::vector<float> demodulate(std::vector<std::complex<T>>& complexSamples) override;
};

#endif // DEMODULATOR_H
