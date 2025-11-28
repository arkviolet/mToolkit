#pragma once

#include <chrono>
#include <thread>

///////////////////////////////////////////////////////////////////////////////////////////////////

#define THIS_CPU_TIME_MS \
  (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock().now().time_since_epoch()).count())

#define THIS_UTC_TIME_MS \
  (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count())

#define THIS_THREAD_SLEEP_MS(n) std::this_thread::sleep_for(std::chrono::milliseconds(n))

///////////////////////////////////////////////////////////////////////////////////////////////////

#define MTOOKIT_PI (3.1415926535898f)
#define MTOOKIT_COMPARE_MAX(a, b) (a) > (b) ? (a) : (b)
#define MTOOKIT_COMPARE_MIN(a, b) (a) > (b) ? (b) : (a)

///////////////////////////////////////////////////////////////////////////////////////////////////
#define MTOOKIT_OFFSET_VALUE(value) ((char*)(&value + 1) - (char*)(&value))
#define MTOOKIT_OFFSET_VARIABLE(val) ((char*)((val*)0 + 1) - (char*)((val*)0))

#define MTOOKIT_OFFSET_OF(type, member) ((size_t)(&((type*)0)->member))
#define MTOOKIT_CONTAINER_OF(ptr, type, member) ((type*)((char*)ptr - MTOOKIT_OFFSET_OF(type, member)));

///////////////////////////////////////////////////////////////////////////////////////////////////

#define API_EXPORT __attribute__((visibility("default")))

///////////////////////////////////////////////////////////////////////////////////////////////////
