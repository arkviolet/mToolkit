#include "annularcache.h"

#include <cstring>

#include "../common/common.h"
#include "../utilities/math.h"

namespace mToolkit {
namespace efficent {

AnnularCache::AnnularCache(uint32_t size) {
  _size = mTooklit::utilities::Math::GetRoundupPowerOfTwo(size);

  _cache = new uint8_t[_size];
}

AnnularCache::~AnnularCache() {
  delete[] _cache;

  _cache = nullptr;

  _size = _w = _r = 0;
}

uint32_t AnnularCache::Push(uint8_t* data, uint32_t len) {
  len = MTOOKIT_COMPARE_MIN(len, _size - (_w - _r));  /// 获取写入数据长度

  auto l = MTOOKIT_COMPARE_MIN(len, _size - (_w & (_size - 1)));

  memcpy(_cache + (_w & (_size - 1)), data, l);

  memcpy(_cache, data + l, len - l);

  _w += len;

  return len;
}

uint32_t AnnularCache::Pop(uint8_t* data, uint32_t len) {
  len = MTOOKIT_COMPARE_MIN(len, _w - _r);

  auto l = MTOOKIT_COMPARE_MIN(len, _size - (_r & (_size - 1)));

  memcpy(data, _cache + (_r & (_size - 1)), l);

  memcpy(data + l, _cache, len - l);

  _r += len;

  return len;
}

}  // namespace efficent
}  // namespace mToolkit
