#pragma once

#include "../lock_container/lock_event.h"
#include "../lock_container/lock_list.h"
#include "message.h"

namespace mToolkit {
namespace message_queue {

using namespace mToolkit::container;

class MessageQueue {
 public:
  MessageQueue() = default;
  virtual ~MessageQueue(){};

 public:
  bool Enqueue(const std::shared_ptr<Message>& message);

  std::shared_ptr<Message> Next();

  void Dump();

 private:
  LockEvent _event;
  LockList<std::shared_ptr<Message>> _list;
};

}  // namespace message_queue
}  // namespace mToolkit
