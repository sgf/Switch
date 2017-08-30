/// @file
/// @brief Contains Switch::System::NotSupportedException exception.
#pragma once

#include "SystemException.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when an invoked method is not supported, or when there is an attempt to read, seek, or write to a stream that does not support the invoked functionality.
    class sw_public NotSupportedException : public SystemException {
    public:
      /// @brief Create a new instance of class NotSupportedException
      /// @remarks Message is set with the default message associate to the error.
      NotSupportedException() : SystemException() {}
      
      /// @brief Create a new instance of class NotSupportedException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      NotSupportedException(const NotSupportedException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class NotSupportedException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
      /// @remarks Message is set with the default message associate to the error.
      NotSupportedException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class NotSupportedException
      /// @param message Message string associate to the error.
      NotSupportedException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class NotSupportedException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
      NotSupportedException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class NotSupportedException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
      NotSupportedException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Specified method is not supported."; }
    };
  }
}

using namespace Switch;
