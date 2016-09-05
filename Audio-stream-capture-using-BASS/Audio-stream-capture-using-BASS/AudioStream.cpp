#include "AudioStream.h"
#include <iostream>

AudioStream::AudioStreamObj::AudioStreamObj(const char* fileName)
{
	stream = std::make_shared<HSTREAM>(BASS_StreamCreateFile(
		FALSE,
		fileName,
		0,
		0,
		BASS_STREAM_DECODE
		));
	if (!stream)
	{
		throw "Sinc error creating HSTREAM";
	}
	if (!BASS_ChannelGetInfo(*stream, &(*ci)))
	{
		throw "Can not get info for stream";
	}
	
}

AudioStream::AudioStreamObj::AudioStreamObj()
{
}

void AudioStream::AudioStreamObj::FreeStream()
{
	BASS_ChannelStop(*stream);
	BASS_SampleFree(*stream);
	delete &ci;
}

AudioStream::AudioStreamObj::~AudioStreamObj()
{
	try {
		FreeStream();
	}
	catch (...)
	{
		std::cout << "AudioStreamObj delete BASS_error";
	}
	stream.~shared_ptr();
	ci.~shared_ptr();
}

bool AudioStream::PlayStream()
{
	return true;
}

bool AudioStream::SetStream(const char* fileName)
{
	pStream->~AudioStreamObj();
	pStream = new AudioStreamObj(fileName);
	return true;
}

AudioStream::AudioStream(const char * fileName)
{
	AudioStreamObj pStream(fileName);
}

AudioStream::~AudioStream()
{
	pStream->~AudioStreamObj();
}
