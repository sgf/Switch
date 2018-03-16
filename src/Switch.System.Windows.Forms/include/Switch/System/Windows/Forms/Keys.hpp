/// @file
/// @brief Contains Switch::System::Windows::Forms::Keys enum.
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
        /// @brief Specifies key codes and modifiers.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The Keys class contains constants for processing keyboard input. The members of the Keys enumeration consist of a key code and a set of modifiers combined into a single integer value. In the Win32 application programming interface (API) a key value has two halves, with the high-order bits containing the key code (which is the same as a Windows virtual key code), and the low-order bits representing key modifiers such as the SHIFT, CONTROL, and ALT keys.
        /// @warning Do not use the values in this enumeration for combined bitwise operations. The values in the enumeration are not mutually exclusive.
        /// @note This enumeration provides no way to test whether the CAPS LOCK or NUM LOCK keys are currently activated. You can use one of the following techniques to determine if these keys are activated:
        /// * Call the IsKeyLocked method of the Control class.
        /// * For finer control, use the Win32 API functions GetKeyState, GetAsyncKeyState, or GetKeyboardState defined in user32.dll, to do this. For more information about calling native functions, see Consuming Unmanaged DLL Functions.
        /// @remarks The following table shows the key code values represented by two enumerated values, representing both the general original equipment manufacturer (OEM) keys and the more specific U.S.-keyboard associations.
        /// | Hexadecimal value | U.S. keyboard    | General OEM |
        /// |-------------------|------------------|-------------|
        /// | BA                | OemSemicolon     | Oem1        |
        /// | BF                | OemQuestion      | Oem2        |
        /// | C0                | Oemtilde         | Oem3        |
        /// | DB                | OemOpenBrackets  | Oem4        |
        /// | DC                | OemPipe          | Oem5        |
        /// | DD                | OemCloseBrackets | Oem6        |
        /// | DE                | OemQuotes        | Oem7        |
        /// | E2                | OemBackslash     | Oem102      |
        /// @par Examples
        /// The following code example uses the KeyDown event to determine the type of character entered into the control.
        /// @code
        /// // Boolean flag used to determine when a character other than a number is entered.
        /// bool nonNumberEntered = false;
        ///
        /// // Handle the KeyDown event to determine the type of character entered into the control.
        /// void textBox1_KeyDown(const object& sender, const System::Windows::Forms::KeyEventArgs& e) {
        ///   // Initialize the flag to false.
        ///   nonNumberEntered = false;
        ///
        ///   // Determine whether the keystroke is a number from the top of the keyboard.
        ///   if (e.KeyCode < Keys::D0 || e::KeyCode > Keys::D9) {
        ///     // Determine whether the keystroke is a number from the keypad.
        ///     if (e.KeyCode < Keys::NumPad0 || e.KeyCode > Keys::NumPad9) {
        ///       // Determine whether the keystroke is a backspace.
        ///       if(e.KeyCode != Keys::Back) {
        ///         // A non-numerical keystroke was pressed.
        ///         // Set the flag to true and evaluate in KeyPress event.
        ///         nonNumberEntered = true;
        ///       }
        ///     }
        ///   }
        ///   //If shift key was pressed, it's not a number.
        ///   if (Control::ModifierKeys == Keys::Shift) {
        ///     nonNumberEntered = true;
        ///   }
        /// }
        ///
        /// // This event occurs after the KeyDown event and can be used to prevent
        /// // characters from entering the control.
        /// void textBox1_KeyPress(const object& sender, const System::Windows::Forms::KeyPressEventArgs& e) {
        ///   // Check for the flag being set in the KeyDown event.
        ///   if (nonNumberEntered == true) {
        ///     // Stop the character from being entered into the control since it is non-numerical.
        ///     e.Handled = true;
        ///   }
        /// }
        /// @endcode
        enum class Keys {
          /// @brief No key pressed.
          None = 0,
          /// @brief The left mouse button.
          LButton = 1,
          /// @brief The right mouse button.
          RButton = 2,
          /// @brief The CANCEL key.
          Cancel = 3,
          /// @brief The middle mouse button (three-button mouse).
          MButton = 4,
          /// @brief The first x mouse button (five-button mouse).
          XButton1 = 5,
          /// @brief The second x mouse button (five-button mouse).
          XButton2 = 6,
          /// @brief The BACK key.
          Back = 8,
          /// @brief The TAB key.
          Tab = 9,
          /// @brief The LINEFEED key.
          LineFeed = 10,
          /// @brief The CLEAR key.
          Clear = 12,
          /// @brief The RETURN key.
          Return = 13,
          /// @brief The ENTER key.
          Enter = 13,
          /// @brief The SHIFT key.
          ShiftKey = 16,
          /// @brief The CTRL key.
          ControlKey = 17,
          /// @brief The ALT key.
          Menu = 18,
          /// @brief The PAUSE key.
          Pause = 19,
          /// @brief The CAPS LOCK key.
          CapsLock = 20,
          /// @brief The CAPS LOCK key.
          Capital = 20,
          /// @brief The IME Kana mode key.
          KanaMode = 21,
          /// @breif The IME Hanguel mode key. (maintained for compatibility; use HangulMode)
          HanguelMode = 21,
          /// @brief The IME Hangul mode key.
          HangulMode = 21,
          /// @brief The IME Junja mode key.
          JunjaMode = 23,
          /// @brief The IME Final mode key.
          FinalMode = 24,
          /// @brief The IME Kanji mode key.
          KanjiMode = 25,
          /// @brief The IME Hanja mode key.
          HanjaMode = 25,
          /// @brief The ESC key.
          Escape = 27,
          /// @brief The IME convert key.
          IMEConvert = 28,
          /// @brief The IME nonconvert key.
          IMENonconvert = 29,
          /// @brief The IME accept key.
          IMEAceept = 30,
          /// @brief The IME mode change key.
          IMEModeChange = 31,
          /// @brief The SPACEBAR key.
          Space = 32,
          /// @brief The PAGE UP key.
          PageUp = 33,
          /// @brief The PAGE UP key.
          Prior = 33,
          /// @brief The PAGE DOWN key.
          PageDown = 34,
          /// @brief The PAGE DOWN key.
          Next = 34,
          /// @brief The END key.
          End = 35,
          /// @brief The HOME key.
          Home = 36,
          /// @brief The LEFT key.
          Left = 37,
          /// @brief The UP key.
          Up = 38,
          /// @brief The RIGHT key.
          Right = 39,
          /// @brief The DOWN key.
          Down = 40,
          /// @brief The SELECT key.
          Select = 41,
          /// @brief The PRINT key.
          Print = 42,
          /// @brief The EXECUTE key.
          Execute = 43,
          /// @brief The PRINT SCREEN key.
          PrintScreen = 44,
          /// @brief The PRINT SCREEN key.
          Snapshot = 44,
          /// @brief The INSERT key.
          Insert = 45,
          /// @brief The DEL key.
          Delete = 46,
          /// @brief The HELP key.
          Help = 47,
          /// @brief The 0 key.
          D0 = 48,
          /// @brief The 1 key.
          D1 = 49,
          /// @brief The 2 key.
          D2 = 50,
          /// @brief The 3 key.
          D3 = 51,
          /// @brief The 4 key.
          D4 = 52,
          /// @brief The 5 key.
          D5 = 53,
          /// @brief The 6 key.
          D6 = 54,
          /// @brief The 7 key.
          D7 = 55,
          /// @brief The 8 key.
          D8 = 56,
          /// @brief The 9 key.
          D9 = 57,
          /// @brief The A key.
          A = 65,
          /// @brief The B key.
          B = 66,
          /// @brief The C key.
          C = 67,
          /// @brief The D key.
          D = 68,
          /// @brief The E key.
          E = 69,
          /// @brief The F key.
          F = 70,
          /// @brief The G key.
          G = 71,
          /// @brief The H key.
          H = 72,
          /// @brief The I key.
          I = 73,
          /// @brief The J key.
          J = 74,
          /// @brief The K key.
          K = 75,
          /// @brief The L key.
          L = 76,
          /// @brief The M key.
          M = 77,
          /// @brief The N key.
          N = 78,
          /// @brief The O key.
          O = 79,
          /// @brief The P key.
          P = 80,
          /// @brief The Q key.
          Q = 81,
          /// @brief The R key.
          R = 82,
          /// @brief The S key.
          S = 83,
          /// @brief The T key.
          T = 84,
          /// @brief The U key.
          U = 85,
          /// @brief The V key.
          V = 86,
          /// @brief The W key.
          W = 87,
          /// @brief The X key.
          X = 88,
          /// @brief The Y key.
          Y = 89,
          /// @brief The Z key.
          Z = 90,
          /// @brief The left Windows logo key (Microsoft Natural Keyboard).
          LWin = 91,
          /// @brief The right Windows logo key (Microsoft Natural Keyboard).
          RWin = 92,
          /// @brief The application key (Microsoft Natural Keyboard).
          Apps = 93,
          /// @brief The 0 key on the numeric keypad.
          NumPad0 = 96,
          /// @brief The 1 key on the numeric keypad.
          NumPad1 = 97,
          /// @brief The 2 key on the numeric keypad.
          NumPad2 = 98,
          /// @brief The 3 key on the numeric keypad.
          NumPad3 = 99,
          /// @brief The 4 key on the numeric keypad.
          NumPad4 = 100,
          /// @brief The 5 key on the numeric keypad.
          NumPad5 = 101,
          /// @brief The 6 key on the numeric keypad.
          NumPad6 = 102,
          /// @brief The 7 key on the numeric keypad.
          NumPad7 = 103,
          /// @brief The 8 key on the numeric keypad.
          NumPad8 = 104,
          /// @brief The 9 key on the numeric keypad.
          NumPad9 = 105,
          /// @brief The multiply key.
          Multiply = 106,
          /// @brief The add key.
          Add = 107,
          /// @brief The separator key.
          Separator = 108,
          /// @brief The subtract key.
          Subtract = 109,
          /// @brief The decimal key.
          Decimal = 110,
          /// @brief The divide key.
          Divide = 111,
          /// @brief The F1 key.
          F1 = 112,
          /// @brief The F2 key.
          F2 = 113,
          /// @brief The F3 key.
          F3 = 114,
          /// @brief The F4 key.
          F4 = 115,
          /// @brief The F5 key.
          F5 = 116,
          /// @brief The F6 key.
          F6 = 117,
          /// @brief The F7 key.
          F7 = 118,
          /// @brief The F8 key.
          F8 = 119,
          /// @brief The F9 key.
          F9 = 120,
          /// @brief The F10 key.
          F10 = 121,
          /// @brief The F11 key.
          F11 = 122,
          /// @brief The F12 key.
          F12 = 123,
          /// @brief The F13 key.
          F13 = 124,
          /// @brief The F14 key.
          F14 = 125,
          /// @brief The F15 key.
          F15 = 126,
          /// @brief The F16 key.
          F16 = 127,
          /// @brief The F17 key.
          F17 = 128,
          /// @brief The F18 key.
          F18 = 129,
          /// @brief The F19 key.
          F19 = 130,
          /// @brief The F20 key.
          F20 = 131,
          /// @brief The F21 key.
          F21 = 132,
          /// @brief The F22 key.
          F22 = 133,
          /// @brief The F23 key.
          F23 = 134,
          /// @brief The F24 key.
          F24 = 135,
          /// @brief The NUM LOCK key.
          NumLock = 144,
          /// @brief The SCROLL LOCK key.
          Scroll = 145,
          /// @brief The left SHIFT key.
          LShiftKey = 160,
          /// @brief The right SHIFT key.
          RShiftKey = 161,
          /// @brief The left CTRL key.
          LControlKey = 162,
          /// @brief The right CTRL key.
          RControlKey = 163,
          /// @brief The left ALT key.
          LMenu = 164,
          /// @brief The right ALT key.
          RMenu = 165,
          /// @brief The browser back key.
          BrowserBack = 166,
          /// @brief The browser forward key.
          BrowserForward = 167,
          /// @brief The browser refresh key.
          BrowserRefresh = 168,
          /// @brief The browser stop key.
          BrowserStop = 169,
          /// @brief The browser search key.
          BrowserSearch = 170,
          /// @brief The browser favorites key.
          BrowserFavorites = 171,
          /// @brief The browser home key.
          BrowserHome = 172,
          /// @brief The volume mute key.
          VolumeMute = 173,
          /// @brief The volume down key.
          VolumeDown = 174,
          /// @brief The volume up key.
          VolumeUp = 175,
          /// @brief The media next track key.
          MediaNextTrack = 176,
          /// @brief The media previous track key.
          MediaPreviousTrack = 177,
          /// @brief The media stop key.
          MediaStop = 178,
          /// @brief The media play pause key.
          MediaPlayPause = 179,
          /// @brief The launch mail key.
          LaunchMail = 180,
          /// @brief The select media key.
          SelectMedia = 181,
          /// @brief The start application one key.
          LaunchApplication1 = 182,
          /// @brief The start application two key.
          LaunchApplication2 = 183,
          /// @brief The OEM Semicolon key on a US standard keyboard.
          OemSemicolon = 186,
          /// @brief The OEM plus key on any country/region keyboard.
          Oemplus = 187,
          /// @brief The OEM comma key on any country/region keyboard.
          Oemcomma = 188,
          /// @brief The OEM minus key on any country/region keyboard.
          OemMinus = 189,
          /// @brief The OEM period key on any country/region keyboard.
          OemPeriod = 190,
          /// @brief The OEM question mark key on a US standard keyboard.
          OemQuestion = 191,
          /// @brief The OEM tilde key on a US standard keyboard.
          Oemtilde = 192,
          /// @brief The OEM open bracket key on a US standard keyboard.
          OemOpenBrackets = 219,
          /// @brief The OEM pipe key on a US standard keyboard.
          OemPipe = 220,
          /// @brief The OEM close bracket key on a US standard keyboard.
          OemCloseBrackets = 221,
          /// @brief The OEM singled/double quote key on a US standard keyboard.
          OemQuotes = 222,
          /// @brief The OEM 8 key.
          Oem8 = 223,
          /// @brief The OEM angle bracket or backslash key on the RT 102 key keyboard.
          OemBackslash = 226,
          /// @brief The PROCESS KEY key.
          ProcessKey = 229,
          /// @brief The ATTN key.
          Attn = 246,
          /// @brief The CRSEL key.
          Crsel = 247,
          /// @brief The EXSEL key.
          Exsel = 248,
          /// @brief The ERASE EOF key.
          EraseEof = 249,
          /// @brief The PLAY key.
          Play = 250,
          /// @brief The ZOOM key.
          Zoom = 251,
          /// @brief A constant reserved for future use.
          NoName = 252,
          /// @brief The PA1 key.
          Pa1 = 253,
          /// @brief The CLEAR key.
          OemClear = 254,
          /// @brief The bitmask to extract a key code from a key value.
          KeyCode = 65535,
          /// @brief The SHIFt modifier key.
          Shift = 65536,
          /// @brief The CTRL modifier key.
          Control = 131072,
          /// @brief The ALT modifier key.
          Alt = 262144,
          /// @brief The CMD modifier key.
          Command = 524288,
          /// @brief The bitmask to extract modifiers from a key value.
          Modifiers = -65536,
          /// @brief The IME accept key.
          IMEAccept = 30,
          /// @brief The OEM 1 key.
          Oem1 = 186,
          /// @brief The OEM 102 key.
          Oem102 = 226,
          /// @brief The OEM 2 key.
          Oem2 = 191,
          /// @brief The OEM 3 key.
          Oem3 = 192,
          /// @brief The OEM 4 key.
          Oem4 = 219,
          /// @brief The OEM 5 key.
          Oem5 = 220,
          /// @brief The OEM 6 key.
          Oem6 = 221,
          /// @brief The OEM 7 key.
          Oem7 = 222,
          /// @brief Used to pass Unicode characters as if they were keystrokes. The Packet key value is the low word of a 32-bit virtual-key value used for non-keyboard input methods.
          Packet = 231,
          /// @brief The computer sleep key.
          Sleep = 95,
          /// @brief The CMD key.
          CommandKey = 255,
          /// @brief The left CMD key.
          LCommandKey = 256,
          /// @brief The right CMD key.
          RCommandKey = 257,
        };

        /// @cond
        inline Keys& operator +=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) + static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator -=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) - static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator &=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) & static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator |=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) | static_cast<int32>(rhs)); return lhs;}
        inline Keys& operator ^=(Keys& lhs, Keys rhs) {lhs = static_cast<Keys>(static_cast<int32>(lhs) ^ static_cast<int32>(rhs)); return lhs;}
        inline Keys operator +(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) + static_cast<int32>(rhs));}
        inline Keys operator -(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) - static_cast<int32>(rhs));}
        inline Keys operator ~(Keys rhs) { return static_cast<Keys>(~ static_cast<int32>(rhs));}
        inline Keys operator &(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) & static_cast<int32>(rhs));}
        inline Keys operator |(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) | static_cast<int32>(rhs));}
        inline Keys operator ^(Keys lhs, Keys rhs) {return static_cast<Keys>(static_cast<int32>(lhs) ^ static_cast<int32>(rhs));}
        /// @endcond
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::Keys> : public TrueType {};

template<>
struct EnumRegister<System::Windows::Forms::Keys> {
  void operator()(System::Collections::Generic::IDictionary<System::Windows::Forms::Keys, string>& values, bool& flags) {
    values[System::Windows::Forms::Keys::None] = "None";
    values[System::Windows::Forms::Keys::LButton] = "LButton";
    values[System::Windows::Forms::Keys::RButton] = "RButton";
    values[System::Windows::Forms::Keys::Cancel] = "Cancel";
    values[System::Windows::Forms::Keys::MButton] = "None";
    values[System::Windows::Forms::Keys::XButton1] = "XButton1";
    values[System::Windows::Forms::Keys::XButton2] = "XButton2";
    values[System::Windows::Forms::Keys::Back] = "Back";
    values[System::Windows::Forms::Keys::Tab] = "Tab";
    values[System::Windows::Forms::Keys::LineFeed] = "LineFeed";
    values[System::Windows::Forms::Keys::Clear] = "Clear";
    values[System::Windows::Forms::Keys::Return] = "Return";
    //values[System::Windows::Forms::Keys::Enter] = "Enter";
    values[System::Windows::Forms::Keys::ShiftKey] = "ShiftKey";
    values[System::Windows::Forms::Keys::ControlKey] = "ControlKey";
    values[System::Windows::Forms::Keys::Menu] = "Menu";
    values[System::Windows::Forms::Keys::Pause] = "Pause";
    values[System::Windows::Forms::Keys::CapsLock] = "CapsLock";
    //{System::Windows::Forms::Keys::Capital] = "Capital";
    values[System::Windows::Forms::Keys::KanaMode] = "KanaMode";
    //values[System::Windows::Forms::Keys::HanguelMode] = "HanguelMode";
    //values[System::Windows::Forms::Keys::HangulMode] = "HangulMode";
    values[System::Windows::Forms::Keys::JunjaMode] = "JunjaMode";
    values[System::Windows::Forms::Keys::FinalMode] = "FinalMode";
    values[System::Windows::Forms::Keys::KanjiMode] = "KanjiMode";
    //values[System::Windows::Forms::Keys::HanjaMode] = "HanjaMode";
    values[System::Windows::Forms::Keys::Escape] = "Escape";
    values[System::Windows::Forms::Keys::IMEConvert] = "IMEConvert";
    values[System::Windows::Forms::Keys::IMENonconvert] = "IMENonconvert";
    values[System::Windows::Forms::Keys::IMEModeChange] = "IMEModeChange";
    values[System::Windows::Forms::Keys::Space] = "Space";
    values[System::Windows::Forms::Keys::PageUp] = "PageUp";
    //values[System::Windows::Forms::Keys::Prior] = "Prior";
    values[System::Windows::Forms::Keys::PageDown] = "PageDown";
    //values[System::Windows::Forms::Keys::Next] = "Next";
    values[System::Windows::Forms::Keys::End] = "End";
    values[System::Windows::Forms::Keys::Home] = "Home";
    values[System::Windows::Forms::Keys::Left] = "Left";
    values[System::Windows::Forms::Keys::Up] = "Up";
    values[System::Windows::Forms::Keys::Right] = "Right";
    values[System::Windows::Forms::Keys::Down] = "Down";
    values[System::Windows::Forms::Keys::Select] = "Select";
    values[System::Windows::Forms::Keys::Print] = "Print";
    values[System::Windows::Forms::Keys::Execute] = "Execute";
    values[System::Windows::Forms::Keys::PrintScreen] = "PrintScreen";
    //values[System::Windows::Forms::Keys::Snapshot] = "Snapshot";
    values[System::Windows::Forms::Keys::Insert] = "Insert";
    values[System::Windows::Forms::Keys::Delete] = "Delete";
    values[System::Windows::Forms::Keys::Help] = "Help";
    values[System::Windows::Forms::Keys::D0] = "D0";
    values[System::Windows::Forms::Keys::D1] = "D1";
    values[System::Windows::Forms::Keys::D2] = "D2";
    values[System::Windows::Forms::Keys::D3] = "D3";
    values[System::Windows::Forms::Keys::D4] = "D4";
    values[System::Windows::Forms::Keys::D5] = "D5";
    values[System::Windows::Forms::Keys::D6] = "D6";
    values[System::Windows::Forms::Keys::D7] = "D7";
    values[System::Windows::Forms::Keys::D8] = "D8";
    values[System::Windows::Forms::Keys::D9] = "D9";
    values[System::Windows::Forms::Keys::A] = "A";
    values[System::Windows::Forms::Keys::B] = "B";
    values[System::Windows::Forms::Keys::C] = "C";
    values[System::Windows::Forms::Keys::D] = "D";
    values[System::Windows::Forms::Keys::E] = "E";
    values[System::Windows::Forms::Keys::F] = "F";
    values[System::Windows::Forms::Keys::G] = "G";
    values[System::Windows::Forms::Keys::H] = "H";
    values[System::Windows::Forms::Keys::I] = "I";
    values[System::Windows::Forms::Keys::J] = "J";
    values[System::Windows::Forms::Keys::K] = "K";
    values[System::Windows::Forms::Keys::L] = "L";
    values[System::Windows::Forms::Keys::M] = "M";
    values[System::Windows::Forms::Keys::N] = "N";
    values[System::Windows::Forms::Keys::O] = "O";
    values[System::Windows::Forms::Keys::P] = "P";
    values[System::Windows::Forms::Keys::Q] = "Q";
    values[System::Windows::Forms::Keys::R] = "R";
    values[System::Windows::Forms::Keys::S] = "S";
    values[System::Windows::Forms::Keys::T] = "T";
    values[System::Windows::Forms::Keys::U] = "U";
    values[System::Windows::Forms::Keys::V] = "V";
    values[System::Windows::Forms::Keys::W] = "W";
    values[System::Windows::Forms::Keys::X] = "X";
    values[System::Windows::Forms::Keys::Y] = "Y";
    values[System::Windows::Forms::Keys::Z] = "Z";
    values[System::Windows::Forms::Keys::LWin] = "LWin";
    values[System::Windows::Forms::Keys::RWin] = "RWin";
    values[System::Windows::Forms::Keys::Apps] = "Apps";
    values[System::Windows::Forms::Keys::NumPad0] = "NumPad0";
    values[System::Windows::Forms::Keys::NumPad1] = "NumPad1";
    values[System::Windows::Forms::Keys::NumPad2] = "NumPad2";
    values[System::Windows::Forms::Keys::NumPad3] = "NumPad3";
    values[System::Windows::Forms::Keys::NumPad4] = "NumPad4";
    values[System::Windows::Forms::Keys::NumPad5] = "NumPad5";
    values[System::Windows::Forms::Keys::NumPad6] = "NumPad6";
    values[System::Windows::Forms::Keys::NumPad7] = "NumPad7";
    values[System::Windows::Forms::Keys::NumPad8] = "NumPad8";
    values[System::Windows::Forms::Keys::NumPad9] = "NumPad9";
    values[System::Windows::Forms::Keys::Multiply] = "Multiply";
    values[System::Windows::Forms::Keys::Add] = "Add";
    values[System::Windows::Forms::Keys::Separator] = "Separator";
    values[System::Windows::Forms::Keys::Subtract] = "Subtract";
    values[System::Windows::Forms::Keys::Decimal] = "Decimal";
    values[System::Windows::Forms::Keys::Divide] = "Divide";
    values[System::Windows::Forms::Keys::F1] = "F1";
    values[System::Windows::Forms::Keys::F2] = "F2";
    values[System::Windows::Forms::Keys::F3] = "F3";
    values[System::Windows::Forms::Keys::F4] = "F4";
    values[System::Windows::Forms::Keys::F5] = "F5";
    values[System::Windows::Forms::Keys::F6] = "F6";
    values[System::Windows::Forms::Keys::F7] = "F7";
    values[System::Windows::Forms::Keys::F8] = "F8";
    values[System::Windows::Forms::Keys::F9] = "F9";
    values[System::Windows::Forms::Keys::F10] = "F10";
    values[System::Windows::Forms::Keys::F11] = "F11";
    values[System::Windows::Forms::Keys::F12] = "F12";
    values[System::Windows::Forms::Keys::F13] = "F13";
    values[System::Windows::Forms::Keys::F14] = "F14";
    values[System::Windows::Forms::Keys::F15] = "F15";
    values[System::Windows::Forms::Keys::F16] = "F16";
    values[System::Windows::Forms::Keys::F17] = "F17";
    values[System::Windows::Forms::Keys::F18] = "F18";
    values[System::Windows::Forms::Keys::F19] = "F19";
    values[System::Windows::Forms::Keys::F20] = "F20";
    values[System::Windows::Forms::Keys::F21] = "F21";
    values[System::Windows::Forms::Keys::F22] = "F22";
    values[System::Windows::Forms::Keys::F23] = "F23";
    values[System::Windows::Forms::Keys::F24] = "F24";
    values[System::Windows::Forms::Keys::NumLock] = "NumLock";
    values[System::Windows::Forms::Keys::Scroll] = "Scroll";
    values[System::Windows::Forms::Keys::LShiftKey] = "LShiftKey";
    values[System::Windows::Forms::Keys::RShiftKey] = "RShiftKey";
    values[System::Windows::Forms::Keys::LControlKey] = "LControlKey";
    values[System::Windows::Forms::Keys::RControlKey] = "RControlKey";
    values[System::Windows::Forms::Keys::LMenu] = "LMenu";
    values[System::Windows::Forms::Keys::RMenu] = "RMenu";
    values[System::Windows::Forms::Keys::BrowserBack] = "BrowserBack";
    values[System::Windows::Forms::Keys::BrowserFavorites] = "BrowserFavorites";
    values[System::Windows::Forms::Keys::BrowserForward] = "BrowserForward";
    values[System::Windows::Forms::Keys::BrowserHome] = "BrowserHome";
    values[System::Windows::Forms::Keys::BrowserRefresh] = "BrowserRefresh";
    values[System::Windows::Forms::Keys::BrowserSearch] = "BrowserSearch";
    values[System::Windows::Forms::Keys::BrowserStop] = "BrowserStop";
    values[System::Windows::Forms::Keys::VolumeDown] = "VolumeDown";
    values[System::Windows::Forms::Keys::VolumeMute] = "VolumeMute";
    values[System::Windows::Forms::Keys::VolumeUp] = "VolumeUp";
    values[System::Windows::Forms::Keys::MediaNextTrack] = "MediaNextTrack";
    values[System::Windows::Forms::Keys::MediaPlayPause] = "MediaPlayPause";
    values[System::Windows::Forms::Keys::MediaPreviousTrack] = "MediaPreviousTrack";
    values[System::Windows::Forms::Keys::MediaStop] = "MediaStop";
    values[System::Windows::Forms::Keys::LaunchMail] = "LaunchMail";
    values[System::Windows::Forms::Keys::SelectMedia] = "SelectMedia";
    values[System::Windows::Forms::Keys::LaunchApplication1] = "LaunchApplication1";
    values[System::Windows::Forms::Keys::LaunchApplication2] = "LaunchApplication2";
    values[System::Windows::Forms::Keys::Oemplus] = "Oemplus";
    values[System::Windows::Forms::Keys::Oemcomma] = "Oemcomma";
    values[System::Windows::Forms::Keys::OemMinus] = "OemMinus";
    values[System::Windows::Forms::Keys::OemPeriod] = "OemPeriod";
    values[System::Windows::Forms::Keys::OemQuestion] = "OemQuestion";
    values[System::Windows::Forms::Keys::Oemtilde] = "Oemtilde";
    values[System::Windows::Forms::Keys::OemOpenBrackets] = "OemOpenBrackets";
    values[System::Windows::Forms::Keys::OemPipe] = "OemPipe";
    values[System::Windows::Forms::Keys::OemCloseBrackets] = "OemCloseBrackets";
    values[System::Windows::Forms::Keys::OemQuotes] = "OemQuotes";
    values[System::Windows::Forms::Keys::Oem8] = "Oem8";
    values[System::Windows::Forms::Keys::OemBackslash] = "OemBackslash";
    values[System::Windows::Forms::Keys::ProcessKey] = "ProcessKey";
    values[System::Windows::Forms::Keys::Attn] = "Attn";
    values[System::Windows::Forms::Keys::Crsel] = "Crsel";
    values[System::Windows::Forms::Keys::Exsel] = "Exsel";
    values[System::Windows::Forms::Keys::EraseEof] = "EraseEof";
    values[System::Windows::Forms::Keys::Play] = "Play";
    values[System::Windows::Forms::Keys::Zoom] = "Zoom";
    values[System::Windows::Forms::Keys::NoName] = "NoName";
    values[System::Windows::Forms::Keys::Pa1] = "Pa1";
    values[System::Windows::Forms::Keys::OemClear] = "OemClear";
    values[System::Windows::Forms::Keys::KeyCode] = "KeyCode";
    values[System::Windows::Forms::Keys::Shift] = "Shift";
    values[System::Windows::Forms::Keys::Control] = "Control";
    values[System::Windows::Forms::Keys::Alt] = "Alt";
    values[System::Windows::Forms::Keys::Command] = "Command";
    values[System::Windows::Forms::Keys::Modifiers] = "Modifiers";
    values[System::Windows::Forms::Keys::IMEAccept] = "IMEAccept";
    values[System::Windows::Forms::Keys::Oem1] = "Oem1";
    //values[System::Windows::Forms::Keys::Oem102] = "Oem102";
    //values[System::Windows::Forms::Keys::Oem2] = "Oem2";
    //values[System::Windows::Forms::Keys::Oem3] = "Oem3";
    //values[System::Windows::Forms::Keys::Oem4] = "Oem4";
    //values[System::Windows::Forms::Keys::Oem5] = "Oem5";
    //values[System::Windows::Forms::Keys::Oem6] = "Oem6";
    //values[System::Windows::Forms::Keys::Oem7] = "Oem7";
    values[System::Windows::Forms::Keys::Packet] = "Packet";
    values[System::Windows::Forms::Keys::Sleep] = "Sleep";
    values[System::Windows::Forms::Keys::CommandKey] = "CommandKey";
    values[System::Windows::Forms::Keys::LCommandKey] = "LCommandKey";
    values[System::Windows::Forms::Keys::RCommandKey] = "RCommandKey";
    flags = true;
  }
};
/// @endcond
