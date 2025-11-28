#include "timestamp.h"

#include <chrono>

#define duration_cast_t std::chrono::duration_cast

namespace mToolkit {
namespace utilities {

typedef std::chrono::seconds s_t;
typedef std::chrono::nanoseconds ns_t;
typedef std::chrono::milliseconds ms_t;
typedef std::chrono::microseconds us_t;

using SystemClockType = std::chrono::system_clock;
using SystemClockTimePoint = std::chrono::system_clock::time_point;

using SteadyClockType = std::chrono::steady_clock;
using SteadyClockTimePoint = std::chrono::steady_clock::time_point;

inline SystemClockTimePoint SystemTimePoint() { return SystemClockType::now(); }
inline SteadyClockTimePoint SteadyTimePoint() { return SteadyClockType::now(); }

uint64_t Timestamp::Seconds() { return duration_cast_t<s_t>(SystemTimePoint().time_since_epoch()).count(); }

uint64_t Timestamp::Milliseconds() { return duration_cast_t<ms_t>(SystemTimePoint().time_since_epoch()).count(); }

uint64_t Timestamp::Microseconds() { return duration_cast_t<us_t>(SystemTimePoint().time_since_epoch()).count(); }

uint64_t Timestamp::Nanoseconds() { return duration_cast_t<ns_t>(SystemTimePoint().time_since_epoch()).count(); }

uint64_t Timestamp::MonotonicSeconds() { return duration_cast_t<s_t>(SteadyTimePoint().time_since_epoch()).count(); }

uint64_t Timestamp::MonotonicMilliseconds() { return duration_cast_t<ms_t>(SteadyTimePoint().time_since_epoch()).count(); }

uint64_t Timestamp::MonotonicMicroseconds() { return duration_cast_t<us_t>(SteadyTimePoint().time_since_epoch()).count(); }

uint64_t Timestamp::MonotonicNanoseconds() { return duration_cast_t<ns_t>(SteadyTimePoint().time_since_epoch()).count(); }

}  // namespace utilities
}  // namespace mToolkit
