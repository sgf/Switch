/// @file
/// @brief Contains Switch::System::DuplicateWaitObjectException exception.
#pragma once

#include "ArgumentException.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an object appears more than once in an array of synchronization objects.
    /// @par Library
    /// Switch.Core
    class core_export_ DuplicateWaitObjectException : public ArgumentException {
    public:
      /// @brief Create a new instance of class DuplicateWaitObjectException
      /// @remarks Message is set with the default message associate to the error.
      DuplicateWaitObjectException() : ArgumentException() {}

      /// @brief Create a new instance of class DuplicateWaitObjectException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      DuplicateWaitObjectException(const DuplicateWaitObjectException& value) : ArgumentException(value) {}

      /// @brief Create a new instance of class DuplicateWaitObjectException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      /// @remarks Message is set with the default message associate to the error.
      DuplicateWaitObjectException(const System::Runtime::CompilerServices::Caller& information) : ArgumentException(information) {}

      /// @brief Create a new instance of class DuplicateWaitObjectException
      /// @param message Message string associate to the error.
      DuplicateWaitObjectException(const System::String& message) : ArgumentException(message) {}

      /// @brief Create a new instance of class DuplicateWaitObjectException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      DuplicateWaitObjectException(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : ArgumentException(message, information) {}

      /// @brief Create a new instance of class DuplicateWaitObjectException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
      DuplicateWaitObjectException(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : ArgumentException(message, innerException, information) {}

    private:
      System::String GetDefaultMessage() const override {return "Duplicate object in argument."; }
    };
  }
}

using namespace Switch;

