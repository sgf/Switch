/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "UnitTest.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      template <typename TestFixture>
      struct TestFixtureAttribute {
        TestFixtureAttribute(const string& name) {TUnit::Framework::UnitTest::Add({name, new_<TestFixture>()});} \
      };
    }
  }
}

using namespace Switch;
