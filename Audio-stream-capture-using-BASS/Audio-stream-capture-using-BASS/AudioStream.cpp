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

AudioStream::AudioStreamObj::~AudioStreamObj()
{
	try {
		BASS_ChannelStop(*stream);
		BASS_SampleFree(*stream);
	}
	catch (...)
	{
		std::cout << "AudioStreamObj delete BASS_error";
	}
	stream.~shared_ptr();
	ci.~shared_ptr();
}

AudioStream::AudioStream(const char * fileName)
{
	AudioStreamObj Stream(fileName);
}

AudioStream::~AudioStream()
{
	Stream.~AudioStreamObj();
}
