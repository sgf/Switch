/// @file
/// @brief Contains Switch::System::FormatException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when the format of an argument does not meet the parameter specifications of the invoked method.
    /// @par Library
    /// Switch.Core
    class core_export_ FormatException : public SystemException {
    public:
      /// @brief Create a new instance of class FormatException
      /// @remarks Message is set with the default message associate to the error.
      FormatException() : SystemException() {}

      /// @brief Create a new instance of class FormatException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      FormatException(const FormatException& value) : SystemException(value) {}

      /// @brief Create a new instance of class FormatException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      explicit FormatException(const System::Runtime::CompilerServices::Caller& information) : SystemException(information) {}

      /// @brief Create a new instance of class FormatException
      /// @param message Message string associate to the error.
      explicit FormatException(const System::String& message) : SystemException(message) {}

      /// @brief Create a new instance of class FormatException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      FormatException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, information) {}

      /// @brief Create a new instance of class FormatException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      FormatException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : SystemException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "One of identified items is an invalid format."; }
    };
  }
}

using namespace Switch;

