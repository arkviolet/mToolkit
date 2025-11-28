#pragma once

namespace mToolkit {
namespace efficent {

typedef struct TWLinkList {
  TWLinkList* _next{nullptr};
  TWLinkList* _prev{nullptr};
} TWLinkList;

TWLinkList* Initialize(TWLinkList* node);

void DestroyNode(TWLinkList* entry);

void InsertBack(TWLinkList* head, TWLinkList* nnew);

void InsertFront(TWLinkList* head, TWLinkList* nnew);

void InsertTWLinkList(TWLinkList* nnew, TWLinkList* prev, TWLinkList* next);

}  // namespace efficent
}  // namespace mToolkit
