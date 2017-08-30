/// @file
/// @brief Contains Switch::System::Exception exception.
#pragma once

#include "../CurrentInformation.hpp"
#include "../Property.hpp"
#include "../RefPtr.hpp"
#include "../Types.hpp"
#include "Object.hpp"
#include "_String.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents errors that occur during application execution.
    class sw_public Exception: public Object, public std::exception {
    public:
      /// @brief Create a new instance of class Exception
      /// @remarks Message is set with the default message associate to the error.
      Exception();
      
      /// @brief Create a new instance of class Exception
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
      /// @remarks Message is set with the default message associate to the error.
      Exception(const CurrentInformation& information);
      
      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      Exception(const String& message);
      
      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
      Exception(const String& message, const CurrentInformation& information);
      
      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      Exception(const String& message, const Exception& innerException);
      
      /// @brief Create a new instance of class Exception
      /// @param message Message string associate to the error.
      /// @param innerException The exception that is the cause of the current exception, or a null reference if no inner exception is specified.
      /// @param information Conatains current information of file and Number of line in the file where the exception is occurred. Typically #sw_current_information.
      Exception(const String& message, const Exception& innerException, const CurrentInformation& information);
      
      /// @cond
      Exception(const Exception& value);
      const char* what() const noexcept override;
      /// @endcond
      
      /// @brief Get File where Exception occurred
      /// @return string A string represent File where Exception occurred
      Property<const String&, ReadOnly> File {
        sw_get->const string& {return this->currentInformation.FileName();}
      };
      
      /// @brief Gets a link to the help file associated with this exception.
      /// @return string A string represent a link to Help file associated with Exception
      Property<const String&, ReadOnly> HelpLink {
        sw_get->const string& {return this->helpLink;}
      };
      
      /// @brief Get Error associate to the Exception
      /// @return Error A ErrorCode represent a Error associate to the Exception
      Property<int32, ReadOnly> HResult {
        sw_get {return this->hresult;}
      };
      
      /// @brief Gets If other Exception instance that caused the current exception.
      /// @return Exception An instance of Exception that describes the error that caused the current exception. The InnerException property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
      Property<bool, ReadOnly> HasInnerException {
        sw_get {return !this->innerException.IsNull();}
      };
      
      /// @brief Gets the Exception instance that caused the current exception.
      /// @return Exception An instance of Exception that describes the error that caused the current exception. The InnerException property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
      Property<const Exception&, ReadOnly> InnerException {
        sw_get->const Exception& {return this->innerException();}
      };
      
      /// @brief Get Line where the Exception occurred
      /// @return Int32 the number of line where Exception occurred
      Property<int32, ReadOnly> Line {
        sw_get {return this->currentInformation.Line();}
      };
      
      /// @brief Get message associate to the Exception
      /// @return string A string represent a massage associate to the Exception
      Property<const String&, ReadOnly> Message {
        sw_get->const string& {return this->GetMessage();}
      };
      
      /// @brief Gets a string representation of the immediate frames on the call stack.
      /// @return string A string that describes the immediate frames of the call stack.
      Property<String, ReadOnly> StackTrace {
        sw_get {return this->GetStackTrace();}
      };
      
      /// @brief Determines whether this instance of Exception and a specified object, which must also be a DelegateItem object, have the same value.
      /// @param value The Exception to compare with the current object.
      /// @return bool true if the specified value is equal to the current object. otherwise, false.
      bool Equals(const Exception& value) const;
      
      /// @brief Determines whether this instance of Exception and a specified object, which must also be a Exception object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return bool true if the specified object is equal to the current object. otherwise, false.
      bool Equals(const Object& obj) const override;
      
      /// @brief Returns a string that represents the current DelegateItem.
      /// @return string A string that represents the current DelegateItem.
      String ToString() const override;
      
      /// @brief Explicit operator equal between Exception
      /// @param value Value to assign this instance.
      /// @return Exception& This instance assigned
      Exception& operator =(const Exception& value);

      /// @brief Check if the generation of the stack trace is enabled.
      /// @return true if stack trace generation is enabled.
      static bool StackTraceEnabled() { return Exception::stackTraceEnabled; }
      
      /// @brief Enable / disable the generation of the stack trace.
      /// @param enabled True to enable the stack trace generation.
      static void StackTraceEnabled(bool enabled) { Exception::stackTraceEnabled = enabled; }

    protected:
      /// @cond
      virtual String GetDefaultMessage() const;
      const String& GetMessage() const;
      String GetStackTrace() const;
      String GetStackTrace(const String& filter) const;
      void SetHResult(int32 hresult) {this->hresult = hresult;}
      void SetInnerException(ref<Exception> innerException) {this->innerException = innerException;}
      void SetStackTrace(const Exception& exception);
    
    //private:
      String message;
      String helpLink;
      CurrentInformation currentInformation;
      ref<Exception> innerException;
      int32 hresult = 0;
      refptr<Array<String>> stackTrace;
      mutable String whatMessage;
      static bool stackTraceEnabled;
      /// @endcond
    };
  }
}

using namespace Switch;