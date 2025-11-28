#pragma once

#include <iostream>
#include <memory>

namespace mToolkit {
namespace actor {

typedef uint32_t Signal;

class Event {
 public:
  explicit Event(Signal sig);
  virtual ~Event();

 public:
  Signal _signal;
};

enum { EVENT_INIT, EVENT_ENTER, EVENT_EXIT, EVENT_EMPTY };

extern std::shared_ptr<Event> StdEventPtr[];

}  // namespace actor
}  // namespace mToolkit
