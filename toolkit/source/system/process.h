#pragma once

#include <stdint.h>

#include <string>

namespace mToolkit {
namespace system {

class Process {
 public:
  static uint64_t ThreadID();

  static std::string ThreadName();

  static void ThreadName(const std::string& name);

  static bool Priority(int priority);

  static int MaxThreadPriority();

  static pid_t Fork(const char** argv);

  static int WaitPid(pid_t pid, bool is_wait = false);
};

}  // namespace system
}  // namespace mToolkit
