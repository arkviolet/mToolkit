#pragma once

#include <pulse/pulseaudio.h>

#include <memory>
#include <string>
#include <thread>

#include "mToolkit/lock_container/lock_map.h"

namespace mToolkit {
namespace enckit {

class AudioStream;

class PulseAudioManager final {
 public:
  PulseAudioManager() { Start(); }
  ~PulseAudioManager() { Stop(); }

 protected:
  void Start();
  void Stop();

 public:
  void ExitLoop();
  void Play(const std::string &task_id, const std::string &path, int volume);
  void Pause();
  void Pause(const std::string &task_id);
  void Resume();
  void Resume(const std::string &task_id);
  void Cancel();
  void Cancel(const std::string &task_id);

 protected:
  static void context_state_callback(pa_context *c, void *userdata);
  void DeleteExpiredAudioStreamsHandle();

 private:
  pa_context *context_{};
  pa_mainloop *mainloop_{};
  bool context_is_connect_{false};
  std::shared_ptr<std::thread> loop_thread_;
  mToolkit::container::LockMap<std::string, std::shared_ptr<AudioStream>> stream_manager_;
};

}  // namespace enckit
}  // namespace mToolkit
