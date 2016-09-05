#include "bass.h"
#include "bassmix.h"
#include "AudioStream.h"
#include <memory>


class StreamCapture {
public:

	StreamCapture();
	~StreamCapture();
	
	AudioStream GetStream(const char*);

private:
	class StreamCaptureObj
	{
		std::shared_ptr<BASS_INFO> info;
	public:
		StreamCaptureObj();
		~StreamCaptureObj();
	};
	StreamCaptureObj* pCapturer;
};