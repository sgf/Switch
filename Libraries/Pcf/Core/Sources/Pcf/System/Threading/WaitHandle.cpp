#include "../../../../Includes/Pcf/System/Threading/WaitHandle.h"
#include "../../../../Includes/Pcf/System/Threading/Thread.h"
#include "../../../../Includes/Pcf/System/Diagnostics/Stopwatch.h"
#include "../../../../Includes/Pcf/System/Array.h"
#include "../../../../Includes/Pcf/System/Boolean.h"
#include "../../../../Includes/Pcf/System/DateTime.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::Threading;

Property<int32, ReadOnly> Timeout::Infinite {
  [] {return -1;}
};

Property<int32, ReadOnly> WaitHandle::WaitTimeout {
  [] {return -1;} // 258 in .Net
};

bool WaitHandle::WaitAll(Array<Reference<WaitHandle>> waitHandles) {
  return WaitAll(waitHandles, Timeout::Infinite);
}

bool WaitHandle::WaitAll(Array<Reference<WaitHandle>> waitHandles, int32 millisecondsTimeout) {
  if (millisecondsTimeout < Timeout::Infinite)
    throw ArgumentException(pcf_current_information);
  
  if (millisecondsTimeout == Timeout::Infinite) {
    for (auto& item : waitHandles)
      item().WaitOne();
    return true;
  }
  
  int32 timeout = millisecondsTimeout;
  Stopwatch sw = Stopwatch::StartNew();
  for (auto& item : waitHandles) {
    if (item().WaitOne(timeout) == false)
      return false;
    timeout = millisecondsTimeout - (int32)sw.ElapsedMilliseconds();
    if (timeout < 0)
      return false;
  }
  return true;
}

bool WaitHandle::WaitAll(Array<Reference<WaitHandle>> waitHandles, const TimeSpan& timeOut) {
  return WaitAll(waitHandles, Convert::ToInt32(timeOut.TotalMilliseconds()));
}

int32 WaitHandle::WaitAny(Array<Reference<WaitHandle>> waitHandles) {
  return WaitAny(waitHandles, Timeout::Infinite);
}

int32 WaitHandle::WaitAny(Array<Reference<WaitHandle>> waitHandles, int32 millisecondsTimeout) {
  if (millisecondsTimeout < Timeout::Infinite)
    throw ArgumentException(pcf_current_information);
  
  if (millisecondsTimeout == Timeout::Infinite) {
    for (int32 index = 0; index < waitHandles.Count; index++) {
      if (waitHandles[index]().WaitOne(0) == true)
        return index;
      Thread::Yield();
      Thread::Sleep(1);
    }
    return WaitTimeout;
  }
  
  int32 timeout = millisecondsTimeout;
  Stopwatch sw = Stopwatch::StartNew();
  do {
    for (int32 index = 0; index < waitHandles.Count; index++) {
      if (waitHandles[index]().WaitOne(0) == true)
        return index;
      timeout = millisecondsTimeout - (int32)sw.ElapsedMilliseconds();
      if (timeout < 0)
        return WaitTimeout;
      Thread::Yield();
      Thread::Sleep(1);
    }
  } while (timeout >= 0);
  return WaitTimeout;
}

int32 WaitHandle::WaitAny(Array<Reference<WaitHandle>> waitHandles, const TimeSpan& timeOut) {
  return WaitAny(waitHandles, Convert::ToInt32(timeOut.TotalMilliseconds()));
}

bool WaitHandle::DoWait(int32 millisecondsTimeOut) {
  return Thread::DoWait(*this, millisecondsTimeOut);
}

