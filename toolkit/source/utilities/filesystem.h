#pragma once

#include <stdint.h>

#include <fstream>
#include <map>
#include <string>
#include <vector>

namespace mToolkit {
namespace utilities {

class Filesystem {
 public:
  static bool Exists(const std::string& path);

  static bool Remove(const std::string& path);

  static bool Rename(const std::string& src, const std::string& dst);

  static bool IsDirectory(const std::string& path);

  static std::size_t Size(const std::string& path);

  static std::string Content(const std::string& path);

  static std::size_t ReadFile(const std::string& path, std::vector<std::string>& container, bool keepEmpty = false);

  static std::vector<std::string> ReadFile(const std::string& path, bool keepEmpty = false);

  static std::map<std::string, std::string> FileContent(const std::string& path);

  static bool StoreFile(const std::string& path, const char* data, uint32_t len);

  template <typename ValueT>
  static bool StoreFile(const std::string& path, ValueT&& value) {
    std::ofstream ofs(path, std::ios::binary);

    if (ofs.is_open()) {
      ofs << std::forward<ValueT>(value);  /// ofs.write is fast cmp <<

      ofs.close();

      return true;
    } else {
      return false;
    }
  }

  template <typename It>
  static bool WriteFile(const std::string& path, const It& begin, const It& end) {
    std::ofstream ofs(path, std::ios::binary);

    if (ofs.is_open()) {
      for (auto iter = begin; iter != end; ++iter) {
        ofs << *iter << std::endl;
      }

      ofs.close();

      return true;
    } else {
      return false;
    }
  }

  static bool CreateFile(const std::string& path);

  static bool CreateDirectory(const std::string& path);

  static bool CreateDirectories(const std::string& path);

  static std::string CurrentDirectory();
};

}  // namespace utilities
}  // namespace mToolkit
