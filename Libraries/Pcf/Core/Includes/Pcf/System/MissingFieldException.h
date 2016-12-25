/// @file
/// @brief Contains Pcf::System::MissingFieldException class.
#pragma once

#include "MissingMemberException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to dynamically access a field that does not exist.
    class MissingFieldException : public MissingMemberException {
    public:
      /// @brief Create a new instance of class MissingFieldException
      /// @remarks Message is set with the default message associate to the error.
      MissingFieldException() : MissingMemberException() {}
      
      /// @brief Create a new instance of class MissingFieldException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      MissingFieldException(const MissingFieldException& value) : MissingMemberException(value) {}
      
      /// @brief Create a new instance of class MissingFieldException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      MissingFieldException(const CurrentInformation& information) : MissingMemberException(information) {}
      
      /// @brief Create a new instance of class MissingFieldException
      /// @param message Message string associate to the error.
      MissingFieldException(const System::String& message) : MissingMemberException(message) {}
      
      /// @brief Create a new instance of class MissingFieldException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      MissingFieldException(const System::String& message, const CurrentInformation& information) : MissingMemberException(message, information) {}
      
      /// @brief Create a new instance of class MissingFieldException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      MissingFieldException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : MissingMemberException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Attempt to acces a non-existing field."; }
    };
  }
}

using namespace Pcf;

