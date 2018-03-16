/// @file
/// @brief Contains include files of TUnit::Framework::RegisteredMethod struct.
#pragma once

#include <Switch/System/Runtime/CompilerServices/Caller.hpp>
#include <Switch/System/Delegate.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include "../../TUnitFrameworkExport.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      /// @cond
      struct TestFixture;
      class UnitTest;
      /// @endcond

      /// @par Library
      /// Switch.TUnit.Framework
      struct tunit_framework_export_ RegisteredMethod : public object {
        RegisteredMethod(const string& name, delegate<void> method, const System::Runtime::CompilerServices::Caller& caller) : RegisteredMethod(name, method, false, caller) {}
        RegisteredMethod(const string& name, delegate<void> method, bool ignore, const System::Runtime::CompilerServices::Caller& caller) : name(name), method(method), ignore(ignore), caller(caller) {}

      private:
        friend struct Switch::TUnit::Framework::TestFixture;
        friend class Switch::TUnit::Framework::UnitTest;

        string name;
        delegate<void> method;
        bool ignore = false;
        System::Runtime::CompilerServices::Caller caller;
      };
    }
  }
}

using namespace Switch;
