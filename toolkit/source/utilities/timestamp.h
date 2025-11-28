#pragma once

#include <stdint.h>

namespace mToolkit {
namespace utilities {

class Timestamp {
 public:
  static uint64_t Seconds();

  static uint64_t Milliseconds();

  static uint64_t Microseconds();

  static uint64_t Nanoseconds();

  static uint64_t MonotonicSeconds();

  static uint64_t MonotonicMilliseconds();

  static uint64_t MonotonicMicroseconds();

  static uint64_t MonotonicNanoseconds();
};

}  // namespace utilities
}  // namespace mToolkit
