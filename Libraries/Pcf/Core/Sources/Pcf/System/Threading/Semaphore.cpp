#include "../../../../Includes/Pcf/System/Threading/Semaphore.h"
#include "NamedHandleCollection.h"

using namespace System;
using namespace System::Threading;

namespace {
  NamedHandleCollection<Semaphore> semaphores;
}

Semaphore::Semaphore(int32 initialCount, int32 maximumCount, const string& name) {
  bool createdNew = true;
  if (name != "")
    this->operator =(semaphores.AddOrCreate(name, createdNew));
  if (createdNew) {
    *this->name = name;
    *this->count = initialCount;
    *this->maxCount = maximumCount;
  }
}

Semaphore::Semaphore(int32 initialCount, int32 maximumCount, const string& name, bool& createdNew) {
  createdNew = true;
  if (name != "")
    this->operator =(semaphores.AddOrCreate(name, createdNew));
  if (createdNew) {
    *this->name = name;
    *this->count = initialCount;
    *this->maxCount = maximumCount;
  }
}

void Semaphore::Close() {
  if (this->guard.IsNull())
    return;
  if (this->name() != "")
    ::semaphores.Remove(this->name());
  this->name.Reset();
  this->guard.Reset();
  this->signal.Reset();
  this->count.Reset();
  this->maxCount.Reset();
}

Semaphore Semaphore::OpenExisting(const string& name) {
  if (!semaphores.Conatains(name))
    throw WaitHandleCannotBeOpenedException(pcf_current_information);
  bool createNew;
  Semaphore value = semaphores.AddOrCreate(name, createNew);
  return value;
}

bool Semaphore::TryOpenExisting(const string& name, Semaphore& result) {
  if (!semaphores.Conatains(name))
    return false;
  bool createNew;
  result = semaphores.AddOrCreate(name, createNew);
  return true;
}
