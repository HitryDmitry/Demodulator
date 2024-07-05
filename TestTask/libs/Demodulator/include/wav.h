#ifndef WAV_H
#define WAV_H

#include <string>
#include <vector>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <algorithm>

template <class Type>
class WavFile {
	struct WAV_HEADER {
		/* RIFF Chunk Descriptor */
		uint8_t RIFF[4];    // RIFF Header Magic header
		uint32_t ChunkSize; // RIFF Chunk Size
		uint8_t WAVE[4];    // WAVE Header
		/* "fmt" sub-chunk */
		uint8_t fmt[4];         // FMT header
		uint32_t Subchunk1Size; // Size of the fmt chunk
		uint16_t AudioFormat;   // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
		uint16_t NumOfChan;     // Number of channels 1=Mono 2=Sterio
		uint32_t SamplesPerSec; // Sampling Frequency in Hz
		uint32_t bytesPerSec;   // bytes per second
		uint16_t blockAlign;    // 2=16-bit mono, 4=16-bit stereo
		uint16_t bitsPerSample; // Number of bits per sample
		/* "data" sub-chunk */
		uint8_t Subchunk2ID[4];     // "data"  string
		uint32_t Subchunk2Size = 0; // Sampled data length
	};

public:
	WavFile(const std::string& file, long dataSize, int samplerate = 32000) : filename(file)
	{
		if(sizeof(Type) * 8 < 8) {
			std::cerr << "Wrong wav file output type" << std::endl;
			exit(1);
		}
		WAV_HEADER wavHeader;
		wavHeader.RIFF[0]        = 'R';
		wavHeader.RIFF[1]        = 'I';
		wavHeader.RIFF[2]        = 'F';
		wavHeader.RIFF[3]        = 'F';
		wavHeader.WAVE[0]        = 'W';
		wavHeader.WAVE[1]        = 'A';
		wavHeader.WAVE[2]        = 'V';
		wavHeader.WAVE[3]        = 'E';
		wavHeader.fmt[0]         = 'f';
		wavHeader.fmt[1]         = 'm';
		wavHeader.fmt[2]         = 't';
		wavHeader.fmt[3]         = ' ';
		wavHeader.Subchunk2ID[0] = 'd';
		wavHeader.Subchunk2ID[1] = 'a';
		wavHeader.Subchunk2ID[2] = 't';
		wavHeader.Subchunk2ID[3] = 'a';
		wavHeader.Subchunk1Size = 16; // объем данных равен размеру стандартного формата WAV (16 байт)
		wavHeader.AudioFormat   = 1;                // 1 (0x0001) 	PCM/uncompressed
		wavHeader.NumOfChan     = 1;                // 1 - mono
		wavHeader.SamplesPerSec = samplerate;       // sample rate
		wavHeader.bitsPerSample = sizeof(Type) * 8; // 8, 16, 24 или 32
		wavHeader.blockAlign =
		    wavHeader.bitsPerSample / 8 * wavHeader.NumOfChan; // BlockAlign = BitsPerSample / 8 * NumChannels
		wavHeader.bytesPerSec =
		    wavHeader.SamplesPerSec * wavHeader.blockAlign; // AvgBytesPerSec = SampleRate * BlockAlign
		wavHeader.Subchunk2Size = dataSize * wavHeader.blockAlign;

		wavHeader.ChunkSize = sizeof(WAV_HEADER) - 8 + wavHeader.Subchunk2Size;

		size_t headerSize = sizeof(WAV_HEADER);

		std::ofstream wavfile(filename, std::ios_base::trunc);
		if(!wavfile) {
			std::cerr << "Can't open file" << std::endl;
			exit(1);
		}
		wavfile.write((char*)&wavHeader, headerSize);
		wavfile.close();
	}

	void writeDataBlock(const std::vector<Type>& data)
	{
		float normCoef;
		normCoef = this->normalize(data);
		std::ofstream wavfile(filename, std::ios_base::app);
		if(!wavfile) {
			std::cerr << "Can't open file" << std::endl;
			exit(1);
		}
		Type tmp;
		for(uint32_t i = 0; i < data.size(); i++) {
			tmp = static_cast<Type>(float(data[i]) * normCoef);
			wavfile.write((char*)&tmp, sizeof(Type));
		}
		wavfile.close();
	}

private:
	std::string filename;

	float normalize(const std::vector<Type>& data)
	{
		if(sizeof(Type) * 8 == 32 || sizeof(Type) * 8 == 24) {
			float max_val = *std::max_element(data.begin(), data.end());
			float min_val = *std::min_element(data.begin(), data.end());
			if(min_val < 0)
				min_val *= -1;
			if(max_val < 0)
				max_val *= -1;
			return 1.0 / std::max(min_val, max_val);
		}
		else
			return 1.0;
	}
};

	// 		std::string voiceFile("./voice" + std::string(strIt) + ".wav");
	//		uint32_t voiceFs = 8000;
	//		WavFile<int16_t> wavFileCore(voiceFile, call.second.size(), voiceFs);
	//		wavFileCore.writeDataBlock(call.second);

// template <>
// class WavFile<float> {
//	struct WAV_HEADER {
//		/* RIFF Chunk Descriptor */
//		uint8_t RIFF[4];    // RIFF Header Magic header
//		uint32_t ChunkSize; // RIFF Chunk Size
//		uint8_t WAVE[4];    // WAVE Header
//		/* "fmt" sub-chunk */
//		uint8_t fmt[4];         // FMT header
//		uint32_t Subchunk1Size; // Size of the fmt chunk
//		uint16_t AudioFormat;   // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
//		uint16_t NumOfChan;     // Number of channels 1=Mono 2=Sterio
//		uint32_t SamplesPerSec; // Sampling Frequency in Hz
//		uint32_t bytesPerSec;   // bytes per second
//		uint16_t blockAlign;    // 2=16-bit mono, 4=16-bit stereo
//		uint16_t bitsPerSample; // Number of bits per sample
//		/* "data" sub-chunk */
//		uint8_t Subchunk2ID[4];     // "data"  string
//		uint32_t Subchunk2Size = 0; // Sampled data length
//	};

// public:
//	WavFile(const std::string& file, long dataSize, int samplerate = 32000) : filename(file)
//	{
//		WAV_HEADER wavHeader;
//		wavHeader.RIFF[0]        = 'R';
//		wavHeader.RIFF[1]        = 'I';
//		wavHeader.RIFF[2]        = 'F';
//		wavHeader.RIFF[3]        = 'F';
//		wavHeader.WAVE[0]        = 'W';
//		wavHeader.WAVE[1]        = 'A';
//		wavHeader.WAVE[2]        = 'V';
//		wavHeader.WAVE[3]        = 'E';
//		wavHeader.fmt[0]         = 'f';
//		wavHeader.fmt[1]         = 'm';
//		wavHeader.fmt[2]         = 't';
//		wavHeader.fmt[3]         = ' ';
//		wavHeader.Subchunk2ID[0] = 'd';
//		wavHeader.Subchunk2ID[1] = 'a';
//		wavHeader.Subchunk2ID[2] = 't';
//		wavHeader.Subchunk2ID[3] = 'a';
//		wavHeader.Subchunk1Size = 16; // объем данных равен размеру стандартного формата WAV (16 байт)
//		wavHeader.AudioFormat   = 1;                 // 1 (0x0001) 	PCM/uncompressed
//		wavHeader.NumOfChan     = 1;                 // 1 - mono
//		wavHeader.SamplesPerSec = samplerate;        // sample rate
//		wavHeader.bitsPerSample = sizeof(float) * 8; // 8, 16, 24 или 32
//		wavHeader.blockAlign =
//		    wavHeader.bitsPerSample / 8 * wavHeader.NumOfChan; // BlockAlign = BitsPerSample / 8 * NumChannels
//		wavHeader.bytesPerSec =
//		    wavHeader.SamplesPerSec * wavHeader.blockAlign; // AvgBytesPerSec = SampleRate * BlockAlign
//		wavHeader.Subchunk2Size = dataSize * wavHeader.blockAlign;

//		wavHeader.ChunkSize = sizeof(WAV_HEADER) - 8 + wavHeader.Subchunk2Size;

//		size_t headerSize = sizeof(WAV_HEADER);

//		std::ofstream wavfile(filename, std::ios_base::trunc);
//		if(!wavfile) {
//			std::cerr << "Can't open file" << std::endl;
//			exit(1);
//		}
//		wavfile.write((char*)&wavHeader, headerSize);
//		wavfile.close();
//	}

//	void writeDataBlock(const std::vector<float>& data)
//	{
//		float normCoef;
//		normCoef = this->normalize(data);
//		std::ofstream wavfile(filename, std::ios_base::app);
//		if(!wavfile) {
//			std::cerr << "Can't open file" << std::endl;
//			exit(1);
//		}
//		float tmp;
//		for(int i = 0; i < data.size(); i++) {
//			tmp = data[i] * normCoef;
//			wavfile.write((char*)&tmp, sizeof(float));
//		}
//		wavfile.close();
//	}

// private:
//	std::string filename;

//	float normalize(const std::vector<float>& data)
//	{
//		float max_val = *std::max_element(data.begin(), data.end());
//		float min_val = *std::min_element(data.begin(), data.end());
//		if(min_val < 0)
//			min_val *= -1;
//		if(max_val < 0)
//			max_val *= -1;
//		return 1.0 / std::max(min_val, max_val);
//	}
//};

#endif // WAV_H
