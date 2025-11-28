#pragma once

#include "hsm.h"

#include "event.h"

#define TRIGGER(state_, sig_) (State)((this->*(state_))(StdEventPtr[sig_]))

namespace mToolkit {
namespace actor {

Hsm::Hsm(PseudoState initial) : myState(&Hsm::Top), mySource((State)initial) {}

Hsm::~Hsm() {}

STATE Hsm::Top(std::shared_ptr<Event>) { return 0; }

void Hsm::Initialize() {}

}  // namespace actor
}  // namespace mToolkit
