#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include <QAudioInput>
#include <QAudioFormat>
#include <QFile>
#include <QBuffer>

#define FREQ 8000
#define RECORD_TIME 500 //in milliseconds

class AudioStream
{
public:
	AudioStream();
	~AudioStream();

	unsigned int getFrequency();
private:
	QAudioInput* audio;
	QAudioFormat format;
	QDataStream* dataStream;
	QBuffer* buffer;
	QByteArray* byteArray;
	signed int* buf;
private slots:
	void stopRecording();



};

#endif // AUDIOSTREAM_H
