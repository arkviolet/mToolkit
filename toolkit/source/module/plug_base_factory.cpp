#include "plug_base_factory.h"

#include <dlfcn.h>

#include <unordered_map>

namespace mToolkit {
namespace module {

using PlugBaseFunction = std::function<const std::shared_ptr<PlugBase>()>;
using PPlugBaseFunction = PlugBaseFunction (*)(const std::string& name);

using PlugMapType = std::unordered_map<std::string, PlugBaseFunction>;

static PlugMapType PlugMap __attribute__((init_priority(REGISTER_PLUG_PRIORITY - 100)));

extern "C" {
PlugMapType& GetPlugFactoryMap() { return PlugMap; }

PlugBaseFunction GetDeviceBaseClass(const std::string& name) {
  auto find = GetPlugFactoryMap().find(name);
  if (find == GetPlugFactoryMap().end()) {
    return nullptr;
  }

  return find->second;
}
}

void RegisterPlugFactory(const std::string& plug_name, const std::function<std::shared_ptr<PlugBase>()>& plug) {
  auto& f_map = GetPlugFactoryMap();
  auto find = f_map.find(plug_name);
  if (find != f_map.end()) {
    return;
  }

  f_map[plug_name] = plug;
}

std::shared_ptr<PlugBase> LoadDriver(const std::string& driver_path, const std::string& driver_name) {
  auto handle = ::dlopen(driver_path.c_str(), RTLD_NOW);
  if (nullptr == handle) {
    return nullptr;
  }

  PPlugBaseFunction pfunc = (PPlugBaseFunction)::dlsym(handle, "GetDeviceBaseClass");
  if (pfunc == nullptr) {
    ::dlclose(handle);
    return nullptr;
  }

  auto func = pfunc(driver_name);

  if (nullptr == func) {
    ::dlclose(handle);
    return nullptr;
  }

  return func();
}

}  // namespace module
}  // namespace mToolkit
