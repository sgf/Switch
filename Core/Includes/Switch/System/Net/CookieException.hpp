/// @file
/// @brief Contains Switch::System::Net::CookieException exception.
#pragma once

#include "../SystemException.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Net namespace provides a simple programming interface for many of the protocols used on networks today.
    /// The WebRequest and WebResponse classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
    namespace Net {
      /// @brief The exception that is thrown when an error is made adding a Cookie to a CookieContainer.
      class sw_public CookieException : public FormatException {
      public:
        /// @brief Create a new instance of class CookieException
        /// @remarks Message is set with the default message associate to the error.
        CookieException() : FormatException() {}
        
        /// @brief Create a new instance of class CookieException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        CookieException(const CookieException& value) : FormatException(value) {}
        
        /// @brief Create a new instance of class CookieException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
        /// @remarks Message is set with the default message associate to the error.
        CookieException(const CurrentInformation& information) : FormatException(information) {}
        
        /// @brief Create a new instance of class CookieException
        /// @param message Message string associate to the error.
        CookieException(const System::String& message) : FormatException(message) {}
        
        /// @brief Create a new instance of class CookieException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
        CookieException(const System::String& message, const CurrentInformation& information) : FormatException(message, information) {}
        
        /// @brief Create a new instance of class CookieException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
        CookieException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : FormatException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "One of identified items is an invalid format."; }
      };
    }
  }
}

using namespace Switch;
