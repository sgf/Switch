/// @file
/// @brief Contains Switch::System::Media::SystemSounds class.
#pragma once

#include "SystemSound.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      /// @brief Retrieves sounds associated with a set of Windows operating system sound-event types. This class cannot be inherited.
      /// @par Library
      /// Switch.System
      class SystemSounds {
      public:
        static _property<SystemSound, _readonly> Asterisk;

        static _property<SystemSound, _readonly> Beep;

        static _property<SystemSound, _readonly> Exclamation;

        static _property<SystemSound, _readonly> Hand;

        static _property<SystemSound, _readonly> Question;
      };
    }
  }
}
