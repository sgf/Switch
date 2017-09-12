/// @file
/// @brief Contains Switch::Caller class and #_caller keyword.
#pragma once

#include "../../../Types.hpp"
#include "../../Object.hpp"
#include "../../_String.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Runtime namespaces contain types that support an application's interaction with the common language runtime, and types that enable features such as application data caching, advanced exception handling, application activation within application domains, COM interop, distributed applications, serialization and deserialization, and versioning.
    namespace Runtime {
      /// @brief The System::Runtime::CompilerServices namespace provides functionality for compiler writers who use managed code to specify attributes in metadata that affect the run-time behavior.
      namespace CompilerServices {
        /// @brief Caller information class is used to store current file, current line and current function information.
        /// @par Examples
        /// The following example shows how to use the Caller
        /// @include Caller.cpp
        class _export Caller : public System::Object {
        public:
          Caller() {}
          Caller(const System::String& filePath, int32 lineNumber) : filePath(filePath), lineNumber(lineNumber) {}
          Caller(const System::String& memberNamne, const System::String& filePath, int32 lineNumber) : memberNamne(memberNamne), filePath(filePath), lineNumber(lineNumber) {}
          
          /// @cond
          Caller(const Caller& caller) : memberNamne(caller.memberNamne), filePath(caller.filePath),  lineNumber(caller.lineNumber) {}
          /// @endcond
          
          /// @brief Gets the member name
          /// @return string member name
          _property<const System::String&, _readonly> MemberNamne {
            _get->const System::String& {return this->memberNamne;}
          };
          
          /// @brief Gets the file path
          /// @return string file path
          _property<const System::String&, _readonly> FilePath {
            _get->const System::String& {return this->filePath;}
          };
          
          /// @brief Gets the line number
          /// @return int32 line number
          _property<int32, _readonly> LineNumber {
            _get {return this->lineNumber;}
          };
          
          System::String ToString() const override {
            if (string::IsNullOrEmpty(this->filePath) && this->lineNumber == 0 && string::IsNullOrEmpty(this->memberNamne))
              return "{Empty}";
            if (string::IsNullOrEmpty(this->memberNamne))
              return System::String::Format("{{FilePath=\"{0}\", LineNumber={1}}}", this->filePath, this->lineNumber);
            return System::String::Format("{{MemberName=\"{0}\", FilePath=\"{1}\", LineNumber={2}}}", this->memberNamne, this->filePath, this->lineNumber);
          }
          
        private:
          System::String memberNamne;
          System::String filePath;
          int32 lineNumber = 0;
        };
      }
    }
  }
  
  /// @brief Get Caller informations
  /// @return Caller caller informations.
  /// @par Examples
  /// The following example shows how to use the _#aller
  /// @include Caller.cpp
  /// @ingroup Keywords
  #define _caller \
  Switch::System::Runtime::CompilerServices::Caller(__func__, __FILE__, __LINE__)
}

using namespace Switch;