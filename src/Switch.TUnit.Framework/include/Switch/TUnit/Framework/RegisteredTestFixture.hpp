/// @file
/// @brief Contains include files of TUnit::Framework::RegisteredMethod struct.
#pragma once

#include "TestFixture.hpp"
#include "../../TUnitFrameworkExport.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      /// @par Library
      /// Switch.TUnit.Framework
      struct tunit_framework_export_ RegisteredTestFixture : public object {
        RegisteredTestFixture(const string& name, refptr<TUnit::Framework::TestFixture> testFixture) : name(name), testFixture(testFixture) {}

      private:
        friend class Switch::TUnit::Framework::UnitTest;
        string name;
        refptr<TestFixture> testFixture;
      };
    }
  }
}

using namespace Switch;
