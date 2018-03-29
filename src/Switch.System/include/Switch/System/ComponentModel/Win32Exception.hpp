/// @file
/// @brief Contains Switch::System::ArgumentNullException exception.
#pragma once

#include <Switch/System/Exception.hpp>
#include "../../SystemExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::ComponentModel namespace provides classes that are used to implement the run-time and design-time behavior of components and controls. This namespace includes the base classes and interfaces for implementing attributes and type converters, binding to data sources, and licensing components.
    namespace ComponentModel {
      /// @brief Throws an exception for a Win32 error code.
      /// @par Library
      /// Switch.System
      class system_export_ Win32Exception : public Exception {
      public:
        /// @brief Gets the HRESULT of the error.
        /// @return int32 The HRESULT of the error.
        /// @remarks See Common HRESULT values for a list of the more frequently encountered error codes. HRESULT values are defined in the Winerror.h header file.
        property_<int32, readonly_> ErrorCode {
          get_ {return this->errorCode;}
        };

        /// @brief Create a new instance of class Win32Exception
        /// @remarks Message is set with the default message associate to the error.
        Win32Exception() : Exception() {}

        /// @brief Create a new instance of class Win32Exception
        /// @remarks Message is set with the default message associate to the error.
        Win32Exception(int32 error) : Exception(), errorCode(error) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        Win32Exception(const Win32Exception& value) : Exception(value) {}
        /// @cond
        Win32Exception& operator=(const Win32Exception& value) = default;
        /// @endcond

        /// @brief Create a new instance of class Win32Exception
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        Win32Exception(const System::Runtime::CompilerServices::Caller& information) : Exception(information) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        /// @remarks Message is set with the default message associate to the error.
        Win32Exception(int32 error, const System::Runtime::CompilerServices::Caller& information) : Exception(information), errorCode(error) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param message Message string associate to the error.
        Win32Exception(const System::String& message) : Exception(message) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param message Message string associate to the error.
        Win32Exception(int32 error, const System::String& message) : Exception(message), errorCode(error) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        Win32Exception(const System::String& message, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        Win32Exception(int32 error, const System::String& message, const System::Runtime::CompilerServices::Caller& information) : Exception(message, information), errorCode(error) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        Win32Exception(const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : Exception(message, innerException, information) {}

        /// @brief Create a new instance of class Win32Exception
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #caller_.
        Win32Exception(int32 error, const System::String& message, const System::Exception& innerException, const System::Runtime::CompilerServices::Caller& information) : Exception(message, innerException, information), errorCode(error) {}

      private:
        int32 errorCode = 0;
      };
    }
  }
}

using namespace Switch;
