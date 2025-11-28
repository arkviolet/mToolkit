#pragma once

#include <stdint.h>

namespace mToolkit {
namespace efficent {

class AnnularCache {
 public:
  AnnularCache() = delete;

  explicit AnnularCache(uint32_t size);

  ~AnnularCache();

 public:
  uint32_t Push(uint8_t* data, uint32_t len);

  uint32_t Pop(uint8_t* data, uint32_t len);

 private:
  uint32_t _w{0};
  uint32_t _r{0};
  uint32_t _size{0};
  uint8_t* _cache{nullptr};
};

}  // namespace efficent
}  // namespace mToolkit
