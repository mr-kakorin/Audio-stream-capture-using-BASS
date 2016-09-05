#include "StreamCapture.h"
#include <iostream>

StreamCapture::StreamCapture()
{
	(BASS_Init(-1, 44100, 0, 0, NULL)) ? pCapturer : throw "Bass could not init";	
}

StreamCapture::~StreamCapture()
{
	try
	{
		BASS_Free();
	}
	catch (...)
	{
		std::cout<<"BASS_Free error";
	}
}

AudioStream StreamCapture::GetStream(const char * fileName)
{
	return AudioStream(fileName);
}

StreamCapture::StreamCaptureObj::StreamCaptureObj()
{
	BASS_INFO tmp;
	BASS_GetInfo(&tmp);
	info = std::make_shared<BASS_INFO>(tmp);	
}

StreamCapture::StreamCaptureObj::~StreamCaptureObj()
{
	info.~shared_ptr();	
}
