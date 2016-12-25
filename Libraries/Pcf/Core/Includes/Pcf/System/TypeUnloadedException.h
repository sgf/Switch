/// @file
/// @brief Contains Pcf::System::TypeUnloadedException exception.
#pragma once

#include "SystemException.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The exception that is thrown when there is an attempt to access an unloaded class.
    class TypeUnloadedException : public SystemException {
    public:
      /// @brief Create a new instance of class TypeUnloadedException
      /// @remarks Message is set with the default message associate to the error.
      TypeUnloadedException() : SystemException() {}
      
      /// @brief Create a new instance of class TypeUnloadedException
      /// @param value The Excetion to copy.
      /// @remarks Message is set with the default message associate to the error.
      TypeUnloadedException(const TypeUnloadedException& value) : SystemException(value) {}
      
      /// @brief Create a new instance of class TypeUnloadedException
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      /// @remarks Message is set with the default message associate to the error.
      TypeUnloadedException(const CurrentInformation& information) : SystemException(information) {}
      
      /// @brief Create a new instance of class TypeUnloadedException
      /// @param message Message string associate to the error.
      TypeUnloadedException(const System::String& message) : SystemException(message) {}
      
      /// @brief Create a new instance of class TypeUnloadedException
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      TypeUnloadedException(const System::String& message, const CurrentInformation& information) : SystemException(message, information) {}
      
      /// @brief Create a new instance of class TypeUnloadedException
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #pcf_current_information.
      TypeUnloadedException(const System::String& message, const System::Exception& innerException, const CurrentInformation& information) : SystemException(message, innerException, information) {}
      
    private:
      System::String GetDefaultMessage() const override {return "Type had been unloaded."; }
    };
  }
}

using namespace Pcf;

