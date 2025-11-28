#include "filesystem.h"

#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include <iostream>

namespace mToolkit {
namespace utilities {

bool Filesystem::Exists(const std::string& path) { return access(path.c_str(), F_OK) == 0; }

bool Filesystem::Remove(const std::string& path) {
  if (IsDirectory(path)) {
    DIR* dir = opendir(path.c_str());

    if (dir == nullptr) {
      std::cerr << "mToolkit filesystem error:" << path << std::endl;
      return false;
    }

    struct dirent* dirEvent = readdir(dir);

    while (dirEvent) {
      if (dirEvent->d_name[0] != '.') {
        std::string value{};

        if (path[path.size() - 1] == '/') {
          value = path + dirEvent->d_name;
        } else {
          value = path + '/' + dirEvent->d_name;
        }

        if (IsDirectory(value)) {
          if (!Remove(value)) {
            closedir(dir);

            return false;
          }
        } else {
          if (std::remove(value.c_str()) == -1) {
            closedir(dir);

            return false;
          }
        }
      }

      dirEvent = readdir(dir);
    }

    if (std::remove(path.c_str()) == -1) {
      closedir(dir);

      return false;
    }

    closedir(dir);

    return true;
  } else {
    return std::remove(path.c_str()) == 0;
  }
}

bool Filesystem::Rename(const std::string& src, const std::string& dst) {
  if (std::rename(src.c_str(), dst.c_str()) == 0) {
    return true;
  } else {
    return false;
  }
}

bool Filesystem::IsDirectory(const std::string& path) {
  if (Exists(path)) {
    struct stat status {};

    if (::stat(path.c_str(), &status) == -1) {
      return false;
    }

    return S_ISDIR(status.st_mode);
  } else {
    return false;
  }
}

std::size_t Filesystem::Size(const std::string& path) {
  std::ifstream ifs(path, std::ifstream::ate | std::ifstream::binary);

  if (ifs.is_open()) {
    std::size_t size = static_cast<std::size_t>(ifs.tellg());

    ifs.close();

    return size;
  }
  std::cerr << "mToolkit filesystem Size:" << path << std::endl;
  return 0;
}

std::string Filesystem::Content(const std::string& path) {
  std::ifstream ifs(path, std::ios::binary);

  if (ifs.is_open()) {
    std::string str((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    ifs.close();

    return str;
  }
  return "";
}

std::size_t Filesystem::ReadFile(const std::string& path, std::vector<std::string>& container, bool keepEmpty) {
  std::ifstream ifs(path, std::ios::binary);

  if (ifs.is_open()) {
    std::string str{};

    while (!ifs.eof()) {
      std::getline(ifs, str);

      if (!ifs.good()) {
        break;
      }

      if (keepEmpty || !str.empty()) {
        container.push_back(str);
      }
    }

    ifs.close();
    return container.size();
  }
  std::cerr << "mToolkit filesystem ReadFile:" << path << std::endl;
  return 0;
}

std::vector<std::string> Filesystem::ReadFile(const std::string& path, bool keepEmpty) {
  std::vector<std::string> container;

  ReadFile(path, container, keepEmpty);

  return container;
}

std::map<std::string, std::string> Filesystem::FileContent(const std::string& path) {
  std::map<std::string, std::string> value;
  std::ifstream ifs(path, std::ios::binary);
  if (ifs.is_open()) {
    std::string str;
    while (std::getline(ifs, str)) {
      auto find = str.find(":");
      if (std::string::npos != find) {
        value.insert(std::make_pair(str.substr(0, find), str.substr(find + 1)));
      }
    }
    ifs.close();
  }
  return value;
}

bool Filesystem::StoreFile(const std::string& path, const char* data, uint32_t len) {
  std::ofstream ofs(path, std::ios::binary);

  if (ofs.is_open()) {
    ofs.write(data, len);

    ofs.close();

    return true;
  }
  return false;
}

bool Filesystem::CreateFile(const std::string& path) {
  std::ofstream ofs(path, std::ios::binary);

  if (ofs.is_open()) {
    ofs.close();

    return true;
  }

  return false;
}

bool Filesystem::CreateDirectory(const std::string& path) {
  if (mkdir(path.c_str(), 0777) == -1) {
    if (!Exists(path)) {
      return false;
    }
  }
  return true;
}

bool Filesystem::CreateDirectories(const std::string& path) {
  std::size_t size = path.size();

  for (std::size_t i = 0; i < size; ++i) {
    if (i == (size - 1)) {
      if (!CreateDirectory(path)) {
        return false;
      }
    } else if (path[i] == '/') {
      if (i == 0) {
        continue;
      }

      if (!CreateDirectory(path.substr(0, i))) {
        return false;
      }
    }
  }

  return true;
}

std::string Filesystem::CurrentDirectory() {
  char directory[1024 + 1] = {0};

  return getcwd(directory, 1024) ? directory : "";
}

}  // namespace utilities
}  // namespace mToolkit
