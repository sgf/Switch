#if __linux__
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/NotImplementedException.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"

#include <X11/Xlib.h>
#undef None

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  static bool messageLoopRunning = false;

  class X11Display {
  public:
    X11Display() {this->display = XOpenDisplay(null);}
    ~X11Display() {XCloseDisplay(this->display);}

    Property<::Display*, ReadOnly> Display {
      pcf_get {return this->display;}
    };

  private:
    ::Display* display;
  };

  static UniquePointer<X11Display> x11Display;
  
  int32 GetMessage(Message& message) {
    return 0;
  }
  
  int32 PeekMessage(Message& message) {
    return 0;
  }
  
  void TranslateMessage(Message& message) {
  }
  
  void DispatchMessage(const Message& message) {
  }
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  x11Display.Reset();
  Environment::Exit(0);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  /*
  messageLoopRunning = true;
  while (messageLoopRunning) {
    Message msg;
    int32 result = idle.IsEmpty() ? GetMessage(msg) : PeekMessage(msg);
    while (result != 0) {
      TranslateMessage(msg);
      DispatchMessage(msg);
      if (msg.Msg == WM_QUIT) {
        messageLoopRunning = false;
        break;
      }
      result = idle.IsEmpty() ? GetMessage(msg) : PeekMessage(msg);
      if (idle.IsEmpty() && !result)
        messageLoopRunning = false;
    }
    idle(object(), EventArgs());
  }*/

  XEvent event;
  while(1) {
    XNextEvent(x11Display().Display(), &event);
    if (event.type == Expose) {

    }

    if (event.type == KeyPress)
      break;
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return DialogResult::None;
}

void FormsApi::Application::Start() {
  x11Display = UniquePointer<X11Display>::Create();
}

void FormsApi::Application::Stop() {
  XCloseDisplay(x11Display().Display());
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {  
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  return IntPtr::Zero;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  return IntPtr::Zero;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  return IntPtr::Zero;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  int32 screen = DefaultScreen(x11Display().Display());
  Window window = XCreateSimpleWindow(x11Display().Display(), RootWindow(x11Display().Display(), screen), 200 /*form.Location().X()*/, 100 /*form.Location().Y()*/, form.Size().Width, form.Size().Height, 1, BlackPixel(x11Display().Display(), screen), WhitePixel(x11Display().Display(), screen));
  XSelectInput(x11Display().Display(), window, ExposureMask | KeyPressMask);
  XMapWindow(x11Display().Display(), window);
  XStoreName(x11Display().Display(), window, form.Text().c_str());
  return window;
 }

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  return IntPtr::Zero;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  return IntPtr::Zero;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return IntPtr::Zero;
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {
}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return {};
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return {};
}

void FormsApi::Control::SetBackColor(intptr hdc, const System::Drawing::Color& color) {
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    XStoreName(x11Display().Display(), control.data().handle, control.Text().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
}

int32 FormsApi::SystemInformation::GetActiveWindowTrackingDelay() {
  return 0;
}

ArrangeDirection FormsApi::SystemInformation::GetArrangeDirection() {
  return ArrangeDirection::Left;
}

ArrangeStartingPosition FormsApi::SystemInformation::GetArrangeStartingPosition() {
  return ArrangeStartingPosition::Hide;
}

BootMode FormsApi::SystemInformation::GetBootMode() {
  return BootMode::Normal;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorder3DSize() {
  return System::Drawing::Size(1, 1);
}

int32 FormsApi::SystemInformation::GetBorderMultiplierFactor() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorderSize() {
  return System::Drawing::Size(1, 1);
}

System::Drawing::Size FormsApi::SystemInformation::GetCaptionButtonSize() {
  return System::Drawing::Size(16, 16);
}

int32 FormsApi::SystemInformation::GetCaptionHeight() {
  return 23;
}

int32 FormsApi::SystemInformation::GetCaretBlinkTime() {
  return 530;
}

int32 FormsApi::SystemInformation::GetCaretWidth() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetCursorSize() {
  return System::Drawing::Size(32, 32);
}

bool FormsApi::SystemInformation::GetDbcsEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetDebugOS() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetDoubleClickSize() {
  return System::Drawing::Size(4, 4);
}

int32 FormsApi::SystemInformation::GetDoubleClickTime() {
  return 500;
}

bool FormsApi::SystemInformation::GetDragFullWindows() {
  return true;
}

System::Drawing::Size FormsApi::SystemInformation::GetDragSize() {
  return System::Drawing::Size(4, 4);
}

System::Drawing::Size FormsApi::SystemInformation::GetFixedFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

int32 FormsApi::SystemInformation::GetFontSmoothingContrast() {
  return 1200;
}

int32 FormsApi::SystemInformation::GetFontSmoothingType() {
  return 2;
}

System::Drawing::Size FormsApi::SystemInformation::GetFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetHighContrast() {
  return false;
}

int32 FormsApi::SystemInformation::GetHorizontalFocusThickness() {
  return 1;
}

int32 FormsApi::SystemInformation::GetHorizontalResizeBorderThickness() {
  return 4;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarHeight() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetIconHorizontalSpacing() {
  return 75;
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSize() {
  return System::Drawing::Size(64, 64);
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSpacingSize() {
  return System::Drawing::Size(75, 75);
}

int32 FormsApi::SystemInformation::GetIconVerticalSpacing() {
  return 75;
}

bool FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsDropShadowEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsFlatMenuEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsFontSmoothingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsHotTrackingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsKeyboardPreferred() {
  return false;
}

bool FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuFadeEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsSelectionFadeEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsSnapToDefaultEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsTitleBarGradientEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsToolTipAnimationEnabled() {
  return false;
}

int32 FormsApi::SystemInformation::GetKanjiWindowHeight() {
  return 0;
}

int32 FormsApi::SystemInformation::GetKeyboardDelay() {
  return 1;
}

int32 FormsApi::SystemInformation::GetKeyboardSpeed() {
  return 31;
}

System::Drawing::Size FormsApi::SystemInformation::GetMaxWindowTrackSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetMenuAccessKeysUnderlined() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuBarButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuCheckSize() {
  return System::Drawing::Size(15, 15);
}

System::Drawing::Font FormsApi::SystemInformation::GetMenuFont() {
  return System::Drawing::Font::FromLogFont((intptr)0);
}

int32 FormsApi::SystemInformation::GetMenuHeight() {
  return 23;
}

#endif
