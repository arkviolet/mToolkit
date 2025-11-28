#pragma once

#include <stdint.h>

#include <string>
#include <vector>

namespace mToolkit {
namespace utilities {

class String {
 public:
  static void PrintHex(const std::string& data);

  static void PrintHex(const char* data, uint32_t len);

  static std::string Trim(const char* str, uint32_t max_len);

  static void Trim(std::string& value, const char* group = "\r\n\t ");

  static std::string Trim(const std::string& value, const char* group = "\r\n\t ");

  static std::vector<std::string> SplitString(const std::string& str, size_t chunkSize);

  static std::size_t Split(const std::string& value, const std::string& key, std::vector<std::string>& container,
                           bool keepEmpty = false);

  static std::vector<std::string> Split(const std::string& value, const std::string& key, bool keepEmpty = false);

  static std::size_t SplitLines(const std::string& value, std::vector<std::string>& container, bool keepEnter = false);

  static std::vector<std::string> SplitLines(const std::string& value, bool keepEnter = false);

  static std::string AsHexString2Byte(const uint8_t* value, uint32_t len);

  static std::string AsByte2HexString(const uint8_t* value, uint32_t len);
};

}  // namespace utilities
}  // namespace mToolkit
