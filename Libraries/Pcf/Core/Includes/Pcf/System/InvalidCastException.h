/// @file
/// @brief Contains Pcf::System::InvalidCastException exception.
#pragma once

#include "SystemException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown for invalid casting or explicit conversion.
    class InvalidCastException : public SystemException {
    public:
      /// @brief Create a new instance of class InvalidCastException
      /// @remarks Message is set with the default message associate to the error.
      InvalidCastException() : SystemException() {}
      
      /// @brief Create a new instance of class InvalidCastException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      InvalidCastException(const InvalidCastException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class InvalidCastException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      InvalidCastException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class InvalidCastException
      /// @param message Message string associate to the error.
      InvalidCastException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class InvalidCastException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      InvalidCastException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class InvalidCastException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      InvalidCastException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Specified cast is not valid."; }
    };
  }
}

using namespace Pcf;

