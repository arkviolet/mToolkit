#pragma once

namespace mToolkit {
namespace timer {

class ITimerEvent {
 public:
  ITimerEvent() = default;
  virtual ~ITimerEvent() = default;

 public:
  virtual void OnPause() = 0;
  virtual void OnResume() = 0;
  virtual void OnTrigger() = 0;
  virtual void OnStop(bool forced) = 0;
};

}  // namespace timer
}  // namespace mToolkit
