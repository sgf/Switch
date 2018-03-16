/// @file
/// @brief Contains Switch::System::Windows::Forms::ControlStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Specifies control functionality.
        /// @remarks This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
        /// @remarks Controls use this enumeration in various properties and methods to specify functionality. A control can enable a style by calling the SetStyle method and passing in the appropriate ControlStyles bit (or bits) and the Boolean value to set the bit(s) to. For example, the following line code would enable double-buffering.
        /// @code
        /// myControl.SetStyle(ControlStyles::UserPaint | ControlStyles::AllPaintingInWmPaint | ControlStyles::DoubleBuffer, True)
        /// @endcode
        /// @remarks If the AllPaintingInWmPaint bit is set to true, the window message WM_ERASEBKGND is ignored, and both OnPaintBackground and OnPaint methods are called directly from the window message WM_PAINT. This generally reduces flicker unless other controls send the window message WM_ERASEBKGND to the control. You might send the window message WM_ERASEBKGRND to achieve a pseudo-transparent effect similar to SupportsTransparentBackColor; for example, a ToolBar with flat appearance does this.
        /// @remarks To fully enable double-buffering, you can set the OptimizedDoubleBuffer and AllPaintingInWmPaint bits to true. However the preferred method for enabling double buffering, which yields the same result, is to set the DoubleBuffered property for the control to true.
        /// @remarks If the SupportsTransparentBackColor bit is set to true, and the BackColor is set to a color whose alpha component is less than 255, OnPaintBackground will simulate transparency by asking its parent control to paint the background. This is not true transparency.
        /// @note If there is another control between the control and its parent, the current control will not show the control in the middle.
        /// @remarks When the UserMouse bit is set to true, the following methods are still called: Control.OnMouseDown, Control.OnMouseUp, Control.OnMouseEnter, Control.OnMouseMove, Control.OnMouseHover, Control.OnMouseLeave, and Control.OnMouseWheel.
        /// @remarks When the control is clicked, if the StandardClick bit is set to true the Control.OnClick method is called and it raises the Control.Click event. When the control is double-clicked, and both the StandardClick and StandardDoubleClick bits are set to true, the click is passed on to the DoubleClick event. Then the Control.OnDoubleClick method is called and it raises the Control.DoubleClick event. However, the control can call OnClick or OnDoubleClick directly regardless of the StandardClick and StandardDoubleClick bit values. For more information on control click and double click behaviors, see the Control.Click and Control.DoubleClick topics.
        /// @remarks When the UseTextForAccessibility bit is set and there is a value in the control's Text property, the value of that control's Text property determines the control's default Active Accessibility name and shortcut key. Otherwise, the text of the preceding Label control will be used instead. This style is set by default. Certain built-in control types, such as TextBox and ComboBox, reset this style so that the Text property of those controls will not be used by Active Accessibility.
        /// @par Notes to Inheritors
        /// nheriting from a standard Windows Forms control and changing the StandardClick or StandardDoubleClick bit values to true can cause unexpected behavior or can have no effect at all if the control does not support the Click or DoubleClick events.
        /// @par Examples
        /// The following example demonstrates a use of ControlStyles with the StyleChanged event.
        /// @code
        /// // Set the 'FixedHeight' and 'FixedWidth' styles to false.
        /// void MyForm_Load(const object& sender, const EventArgs& e){
        ///   this->SetStyle(ControlStyles::FixedHeight, false);
        ///   this->SetStyle(ControlStyles::FixedWidth, false);
        /// }
        ///
        /// void RegisterEventHandler() {
        ///   this->StyleChanged += EventHandler(*this, &Form1::MyForm_StyleChanged);
        /// }
        ///
        /// // Handle the 'StyleChanged' event for the 'Form'.
        /// void MyForm_StyleChanged(const object& sender, const EventArgs& e) {
        ///   MessageBox::Show("The style releated to the 'Form' has been changed");
        /// }
        /// @endcode
        enum class ControlStyles {
          /// @brief Indicates whether the control is a container-like control.
          ContainerControl = 0x00000001,
          /// @brief The control paints itself; WM_PAINT and WM_ERASEBKGND messages are not passed on to the underlying NativeWindow. This style only applies to subclasses of Control.
          UserPaint = 0x00000002,
          /// @brief If specified, a PaintBackground event will not be raised, OnPaintBackground will not be called, and Invalidate() will not invalidate the background of the HWND.
          Opaque = 0x00000004,
          /// @brief The control is completely redrawn when it is resized.
          ResizeRedraw = 0x00000010,
          /// @brief The control has a fixed width.
          FixedWidth = 0x00000020,
          /// @brief The control has a fixed height.
          FixedHeight = 0x00000040,
          /// @brief If set, windows forms calls OnClick and raises the Click event when the control is clicked (unless it's the second click of a double-click and StandardDoubleClick is specified). Regardless of this style, the control may call OnClick directly.
          StandardClick = 0x00000100,
          /// @brief The control can get the focus.
          Selectable = 0x00000200,
          /// @brief The control does its own mouse processing; WM_MOUSEDOWN, WM_MOUSEMOVE, and WM_MOUSEUP messages are not passed on to the underlying NativeWindow.
          UserMouse = 0x00000400,
          /// @brief If the BackColor is set to a color whose alpha component is less than 255 (i.e., BackColor.A &lt; 255), OnPaintBackground will simulate transparency by asking its parent control to paint our background.  This is not true transparency -- if there is another control between us and our parent, we will not show the control in the middle. This style only applies to subclasses of Control.  It only works if UserPaint is set, and the parent control is a Control.
          SupportsTransparentBackColor = 0x00000800,
          /// @brief If set, windows forms calls OnDoubleClick and raises the DoubleClick event when the control is double clicked. Regardless of whether it is set, the control may call OnDoubleClick directly. This style is ignored if StandardClick is not set.
          StandardDoubleClick = 0x00001000,
          /// @brief If true, WM_ERASEBKGND is ignored, and both OnPaintBackground and OnPaint are called directly from WM_PAINT. This generally reduces flicker, but can cause problems if other controls send WM_ERASEBKGND messages to us.  (This is sometimes done to achieve a pseudo-transparent effect similar to ControlStyles.SupportsTransparentBackColor; for instance, ToolBar with flat appearance does this). This style only makes sense if UserPaint is true.
          AllPaintingInWmPaint = 0x00002000,
          /// @brief If true, the control keeps a copy of the text rather than going to the hWnd for the text every time. This improves performance but makes it difficult to keep the control and hWnd's text synchronized. This style defaults to false.
          CacheText = 0x00004000,
          /// @brief If true, the OnNotifyMessage method will be called for every message sent to the control's WndProc. This style defaults to false.
          EnableNotifyMessage = 0x00008000,
          /// @brief If set, all control painting will be double buffered. You must also set the UserPaint and AllPaintingInWmPaint style.  Note: This is obsolete, please use OptimizedDoubleBuffer instead.
          DoubleBuffer = 0x00010000,
          /// @brief If set, all control painting will be double buffered.
          OptimizedDoubleBuffer = 0x00020000,
          /// @brief If this style is set, and there is a value in the control's Text property, that value will be used to determine the control's default Active Accessibility name and shortcut key. Otherwise, the text of the preceding Label control will be used instead. This style is set by default. Certain built-in control types such as TextBox and ComboBox un-set this style, so that their current text will not be used by Active Accessibility.
          UseTextForAccessibility = 0x00040000,
        };
      }
    }
  }
}
/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::ControlStyles> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::ControlStyles> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::ControlStyles, string>& values, bool& flags) {
    values[System::Windows::Forms::ControlStyles::ContainerControl] = "ContainerControl";
    values[System::Windows::Forms::ControlStyles::UserPaint] = "UserPaint";
    values[System::Windows::Forms::ControlStyles::Opaque] = "Opaque";
    values[System::Windows::Forms::ControlStyles::ResizeRedraw] = "ResizeRedraw";
    values[System::Windows::Forms::ControlStyles::FixedWidth] = "FixedWidth";
    values[System::Windows::Forms::ControlStyles::FixedHeight] = "FixedHeight";
    values[System::Windows::Forms::ControlStyles::StandardClick] = "StandardClick";
    values[System::Windows::Forms::ControlStyles::Selectable] = "Selectable";
    values[System::Windows::Forms::ControlStyles::UserMouse] = "UserMouse";
    values[System::Windows::Forms::ControlStyles::SupportsTransparentBackColor] = "SupportsTransparentBackColor";
    values[System::Windows::Forms::ControlStyles::StandardDoubleClick] = "StandardDoubleClick";
    values[System::Windows::Forms::ControlStyles::AllPaintingInWmPaint] = "AllPaintingInWmPaint";
    values[System::Windows::Forms::ControlStyles::CacheText] = "CacheText";
    values[System::Windows::Forms::ControlStyles::EnableNotifyMessage] = "EnableNotifyMessage";
    values[System::Windows::Forms::ControlStyles::DoubleBuffer] = "DoubleBuffer";
    values[System::Windows::Forms::ControlStyles::OptimizedDoubleBuffer] = "OptimizedDoubleBuffer";
    values[System::Windows::Forms::ControlStyles::UseTextForAccessibility] = "UseTextForAccessibility";
    flags = true;
  }
};
/// @endcond

using namespace Switch;
