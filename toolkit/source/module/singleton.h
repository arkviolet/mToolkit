#pragma once

namespace mToolkit {
namespace module {

class SingletonInterface {
 public:
  static SingletonInterface* Instance() { return _ins; }
  virtual void Handle(void* in, void* out);

 protected:
  SingletonInterface();
  virtual ~SingletonInterface();

  SingletonInterface(const SingletonInterface&) = delete;
  SingletonInterface& operator=(const SingletonInterface&) = delete;

  static SingletonInterface* _ins;
};

template <class _Tp>
class Singleton {
 public:
  static _Tp& Instance() {
    /// TODO std::mutex
    static _Tp ins;
    return ins;
  }

 public:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

 protected:
  Singleton() = default;
};

}  // namespace module
}  // namespace mToolkit
