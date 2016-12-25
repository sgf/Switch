/// @file
/// @brief Contains Pcf::System::Security::HostProtectionException exception.
#pragma once

#include "../SystemException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System.Security namespaces contain classes that represent the Pcf Framework security system and permissions. Child namespaces provide types that control access to and audit securable objects, allow authentication, provide crytographic services, control access to operations and resources based on policy, and support rights management of application-created content.
    namespace Security {
      /// @brief The exception that is thrown when a denied host resource is detected.
      class HostProtectionException : public SystemException {
      public:
        /// @brief Create a new instance of class HostProtectionException
        /// @remarks Message is set with the default message associate to the error.
        HostProtectionException() : SystemException() {}
        
        /// @brief Create a new instance of class HostProtectionException
        /// @param value The Excetion to copy.
        /// @remarks Message is set with the default message associate to the error.
        HostProtectionException(const HostProtectionException& value) : SystemException(value) {}
        
        /// @brief Create a new instance of class HostProtectionException
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        /// @remarks Message is set with the default message associate to the error.
        HostProtectionException(const CurrentInformation& information) : SystemException(information) {}
        
        /// @brief Create a new instance of class HostProtectionException
        /// @param message Message string associate to the error.
        HostProtectionException(const System::String& message) : SystemException(message) {}
        
        /// @brief Create a new instance of class HostProtectionException
        /// @param message Message string associate to the error.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        HostProtectionException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
        
        /// @brief Create a new instance of class HostProtectionException
        /// @param message Message string associate to the error.
        /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
        /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
        HostProtectionException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
        
      private:
        System::String GetDefaultMessage() const override {return "Denied host resource detected."; }
      };
    }
  }
}

using namespace Pcf;
