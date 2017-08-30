/// @file
/// @brief Contains Switch::CurrentInformation class and #sw_current_information keyword.
#pragma once

#include "Types.hpp"
#include "System/Object.hpp"
#include "System/_String.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Current information class is used to store current file, current line and current function information.
  /// @par Examples
  /// Use #sw_current_information to get current information.
  /// @code
  /// CurrentInformation currentInformation = sw_current_information;
  /// Console::WriteLine("File = {0}", currentInformation.FileName);
  /// Console::WriteLine("Line = {0}", currentInformation.Line);
  /// Console::WriteLine("Function = {0}", currentInformation.FunctionName);
  /// @endcode
  class sw_public CurrentInformation : public System::Object {
  public:
    CurrentInformation() {}
    CurrentInformation(const System::String& fileName, int32 line) : fileName(fileName), line(line) {}
    CurrentInformation(const System::String& fileName, int32 line, const System::String& functionName) : fileName(fileName), line(line), functionName(functionName) {}

    /// @cond
    CurrentInformation(const CurrentInformation& currentInformation) : fileName(currentInformation.fileName), line(currentInformation.line), functionName(currentInformation.functionName) {}
    CurrentInformation& operator =(const CurrentInformation& currentInformation) {
      this->fileName = currentInformation.fileName;
      this->line = currentInformation.line;
      this->functionName = currentInformation.functionName;
      return *this;
    }
    /// @endcond
    
    /// Gets the FileName
    Property<const System::String&, ReadOnly> FileName {
      sw_get->const System::String& {return this->fileName;}
    };
    
    Property<int32, ReadOnly> Line {
      sw_get {return this->line;}
    };
    
    Property<const System::String&, ReadOnly> FunctionName {
      sw_get->const System::String& {return this->functionName;}
    };
    
    System::String ToString() const override {
      if (this->fileName.IsEmpty() && this->line == 0 && this->functionName.IsEmpty())
        return "{Empty}";
      if (this->functionName.IsEmpty())
        return System::String::Format("{{File=\"{0}\", Line={1}}}", this->fileName, this->line);
      return System::String::Format("{{File=\"{0}\", Line={1}, Function=\"{2}\"}}", this->fileName, this->line, this->functionName);
    }
    
  private:
    System::String fileName;
    int32 line = 0;
    System::String functionName;
  };
  
  /// @brief Get Current informations
  /// @return CurrentInformation Current informations.
  /// @par Examples
  /// @code
  /// CurrentInformation currentInformation = sw_current_information;
  /// Console::WriteLine("File = {0}", currentInformation.FileName);
  /// Console::WriteLine("Line = {0}", currentInformation.Line);
  /// Console::WriteLine("Function = {0}", currentInformation.FunctionName);
  /// @endcode
  /// @ingroup Switch
  #define sw_current_information CurrentInformation(__FILE__, __LINE__, __func__)
}

using namespace Switch;