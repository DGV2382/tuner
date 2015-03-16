#include "audiostream.h"
#include <QFile>
#include <QTimer>
#include <iostream>
#include <unistd.h>
using namespace std;
//QFile out;
AudioStream::AudioStream()
{
	byteArray = new QByteArray( FREQ * sizeof(int), 0);
	buffer = new QBuffer(byteArray);

	//memset( &buffer, 0, sizeof(short) * FREQ);
	format.setSampleRate (8000);
	format.setChannelCount (1);
	format.setSampleSize (16);
	format.setCodec ("audio/pcm");
	format.setByteOrder (QAudioFormat::LittleEndian);
	format.setSampleType (QAudioFormat::SignedInt);

	QAudioDeviceInfo info(QAudioDeviceInfo::defaultInputDevice());
	if (!info.isFormatSupported(format)) {
		//qWarning() << "Default format not supported - trying to use nearest";
		format = info.nearestFormat(format);
	}

	audio = new QAudioInput(format, 0);
	//audio->setBufferSize ( 1000);
	audio->setVolume (0.4);
}

AudioStream::~AudioStream()
{
	delete(audio);
	delete(buffer);
	delete(byteArray);
	delete(buf);
}

unsigned int AudioStream::getFrequency()
{
	//memset( &buffer, 0, sizeof(short) * FREQ);
	buffer->open(QIODevice::WriteOnly);
	audio->reset();
	//memset( buffer->buffer ().data (), 0, sizeof(short) * FREQ);
	QTimer::singleShot(RECORD_TIME, 0, SLOT(stopRecording()));
	audio->start(buffer);

	usleep (1000 * RECORD_TIME);

	buf = (signed int*) buffer->buffer().data();
	for(int i=0;i < FREQ;i++)cout<<buf[i]<<endl;
	return 2;
}

void AudioStream::stopRecording (){
	audio->stop();
	//audio->reset();

	//buffer->close();
	//for(int i=0;i < FREQ;i++)cout<<buf[i]<<endl;
	cout<<"wewerwer";
	//cout<<out;
	//out.close();
}
