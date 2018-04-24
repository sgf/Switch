#pragma once

#if defined(__APPLE__)
#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

#include <Switch/System/Double.hpp>
#include <Switch/System/Collections/Generic/Dictionary.hpp>
#include "Api.hpp"
#include "WindowMessage.hpp"
#include "WindowMessageKey.hpp"
#include "../../include/Switch/System/Windows/Forms/Form.hpp"

namespace Native {
  class WindowProcedure static_ {
  public:
    using ControlDictionary = System::Collections::Generic::Dictionary<intptr, ref<System::Windows::Forms::Control>>;
    static ControlDictionary Controls;

    static int32 GetMouseButtonState(NSEvent* event);
    static void WndProc(NSEvent* event);

  private:
    static ref<System::Windows::Forms::Control> GetChildAtPoint(const System::Windows::Forms::Control& control, System::Drawing::Point& point);
    static int32 GetMouseXCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control);
    static int32 GetMouseYCoordinateRelativeToClientArea(NSEvent* event, System::Windows::Forms::Control& control);
    static void MouseEnterEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void MouseLeaveEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void LeftMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void LeftMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void OtherMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void OtherMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void RightMouseDownEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void RightMouseUpEvent(NSEvent* event, System::Windows::Forms::Control& control);
    static void MouseMoveEvent(NSEvent* event, System::Windows::Forms::Control& control);

    static bool messageLoopRunning ;
    static const int32 notUsed = 0;
    static bool hover;
  };
}

#endif
