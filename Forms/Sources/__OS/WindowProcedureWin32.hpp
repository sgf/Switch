﻿#if defined(_WIN32)

#include <Switch/System/Collections/Generic/Dictionary.hpp>

typedef HWND__* HWND;

namespace __OS {
  class WindowProcedure _static {
  public:
    static System::Collections::Generic::Dictionary<int64, intptr(__stdcall*)(HWND, uint32, uintptr, int64)> DefWindowProcs;

    static void SetWindowTheme(HWND handle);
    static int64 __stdcall WndProc(HWND hwnd, uint32 msg, uintptr wParam, int64 lParam);
  };
}

#endif
