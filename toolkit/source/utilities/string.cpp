#include "string.h"

#include <algorithm>
#include <cstring>
#include <iostream>

#define HEXSTR(i) "0123456789ABCDEF"[i]

namespace mToolkit {
namespace utilities {

void String::PrintHex(const std::string& data) {
  for (auto& iter : data) {
    std::cout << HEXSTR(iter >> 4) << HEXSTR(iter & 0xF) << ' ';
  }
}

void String::PrintHex(const char* data, uint32_t len) {
  for (int i = 0; i < len; ++i) {
    std::cout << HEXSTR(data[i] >> 4) << HEXSTR(data[i] & 0xF) << ' ';
  }
}

std::string String::Trim(const char* str, uint32_t max_len) {
  std::string str_str;

  for (int i = 0; i < max_len; ++i) {
    if (str[i] == '\0') {
      break;
    }
    str_str += str[i];
  }
  return str_str;
}

void String::Trim(std::string& value, const char* group) {
  std::string::size_type end = value.find_last_not_of(group);
  std::string::size_type start = value.find_first_not_of(group);

  value = (start == std::string::npos) ? "" : value.substr(start, 1 + end - start);
}

std::string String::Trim(const std::string& value, const char* group) {
  std::string::size_type end = value.find_last_not_of(group);
  std::string::size_type start = value.find_first_not_of(group);

  return (start == std::string::npos) ? "" : value.substr(start, 1 + end - start);
}

std::vector<std::string> String::SplitString(const std::string& str, size_t chunkSize) {
  std::vector<std::string> result;
  size_t len = str.length();
  for (size_t i = 0; i < len; i += chunkSize) {
    result.push_back(std::move(str.substr(i, chunkSize)));
  }

  return result;
}

std::size_t String::Split(const std::string& value, const std::string& key, std::vector<std::string>& container,
                          bool keepEmpty) {
  if (key.empty()) {
    container.push_back(value);
  } else {
    std::string::const_iterator beg = value.begin();
    std::string::const_iterator end;

    while (true) {
      end = std::search(beg, value.end(), key.begin(), key.end());

      if (beg != end) {
        std::string str(beg, end);

        Trim(str, "\r\n");

        if (keepEmpty || !str.empty()) {
          container.push_back(str);
        }

        if (end == value.end()) {
          break;
        }
      } else if (beg == value.end()) {
        break;
      }

      beg = end + key.size();
    }
  }

  return container.size();
}

std::vector<std::string> String::Split(const std::string& value, const std::string& key, bool keepEmpty) {
  std::vector<std::string> container;

  Split(value, key, container, keepEmpty);

  return container;
}

std::size_t String::SplitLines(const std::string& value, std::vector<std::string>& container, bool keepEnter) {
  std::size_t i = 0;
  std::size_t j = 0;

  while (i < value.size()) {
    while (i < value.size() && value[i] != '\r' && value[i] != '\n' && value[i] != '\0') {
      ++i;
    }

    std::size_t eol = i;

    if (i < value.size()) {
      i += (value[i] == '\r' && i + 1 < value.size() && value[i + 1] == '\n') ? 2 : 1;

      if (keepEnter) {
        eol = i;
      }
    }

    container.push_back(value.substr(j, eol - j));

    j = i;
  }

  return container.size();
}

std::vector<std::string> String::SplitLines(const std::string& value, bool keepEnter) {
  std::vector<std::string> container;

  SplitLines(value, container, keepEnter);

  return container;
}

static uint8_t asc2nibble(char c) {
  if ((c >= '0') && (c <= '9')) return c - '0';

  if ((c >= 'A') && (c <= 'F')) return c - 'A' + 10;

  if ((c >= 'a') && (c <= 'f')) return c - 'a' + 10;

  return 16; /* error */
}

std::string String::AsHexString2Byte(const uint8_t* value, uint32_t len) {
  std::string result;
  for (uint32_t index = 0; index < len; ++index) {
    if (' ' == value[index]) {
      continue;
    }

    auto data = (asc2nibble(value[index++])) << 4;

    data |= asc2nibble(value[index]);

    result += data;
  }

  return result;
}

std::string String::AsByte2HexString(const uint8_t* value, uint32_t len) {
  std::string result;

  for (int index = 0; index < len; ++index) {
    result += (HEXSTR(value[index] >> 4));
    result += (HEXSTR(value[index] & 0xF));
    result += (' ');
  }

  return result;
}

}  // namespace utilities
}  // namespace mToolkit
