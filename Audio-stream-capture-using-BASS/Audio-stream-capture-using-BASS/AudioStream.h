#include "bass.h"
#include "bassmix.h"
#include <memory>

class AudioStream {
public:
	bool PlayStream();
	bool SetStream(const char*);
	AudioStream(const char*);
	~AudioStream();

private:
	class AudioStreamObj {
		std::shared_ptr<HSTREAM> stream;
		std::shared_ptr<BASS_CHANNELINFO> ci;
	public:
		AudioStreamObj(const char*);
		AudioStreamObj();
		~AudioStreamObj();
		void FreeStream();

	};
	AudioStreamObj* pStream;
};