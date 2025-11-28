#pragma once

#include <stdint.h>

namespace mTooklit {
namespace utilities {

class Math {
 public:
  static bool IsPowerOfTwo(uint32_t num);

  static uint32_t GetRoundupPowerOfTwo(uint32_t num);

  static uint32_t GetRoundDownPowerOfTwo(uint32_t num);

  static bool IsOddNumber(int32_t num);

  static bool IsEventNumber(int32_t num);
};

}  // namespace utilities
}  // namespace mTooklit
