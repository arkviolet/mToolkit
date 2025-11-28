#include "singleton.h"

namespace mToolkit {
namespace module {

SingletonInterface* SingletonInterface::_ins = nullptr;

SingletonInterface::SingletonInterface() { _ins = this; }

SingletonInterface::~SingletonInterface() {}

void SingletonInterface::Handle(void* in, void* out) {
  (void)in;
  (void)out;
}

}  // namespace module
}  // namespace mToolkit