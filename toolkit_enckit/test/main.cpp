

#include "../source/toolkit_enckit.h"
#include "mToolkit/toolkit.h"

using namespace mToolkit::enckit;
using namespace mToolkit::timer;
using namespace mToolkit::utilities;
using namespace mToolkit::container;
using namespace mToolkit::message_queue;

void test_audio() {
  /// pulseaudio
  {
    int volume = 50;
    std::string audio_path = "./test.wav";
    auto taskid = std::to_string(Timestamp::MonotonicMilliseconds());
    auto pulseaudio = std::make_shared<PulseAudioManager>();
    pulseaudio->Play(taskid, audio_path, volume);
    pulseaudio->Pause(taskid);
    pulseaudio->Resume(taskid);
    pulseaudio->Cancel();
    pulseaudio = nullptr;
  }

  /// gst audio
  {
    int volume = 50;
    std::string audio_path = "./test.wav";  ///*.wav *.mp3
    auto taskid = std::to_string(Timestamp::MonotonicMilliseconds());
    auto gst = std::make_shared<GstAudioManager>();
    gst->Play(taskid, audio_path, volume);
    gst->Pause(taskid);
    gst->Resume(taskid);
    gst->Cancel();
    gst = nullptr;
  }
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  test_audio();

  return 0;
}
