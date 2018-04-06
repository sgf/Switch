#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/ControlEventArgs.hpp>

using namespace System;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(ControlEventArgsTest, ConstructorWithControl) {
    Control control;
    ControlEventArgs controlEventArgs(control);

    ASSERT_TRUE(object::ReferenceEquals(control, controlEventArgs.Control()));
  }

  TEST(ControlEventArgsTest, ConstructorWithNull) {
    Control control;
    ControlEventArgs controlEventArgs(null);

    ASSERT_TRUE(controlEventArgs.Control == null);
  }

  TEST(ControlEventArgsTest, CopyConstructor) {
    Control control;
    ControlEventArgs controlEventArgs = ControlEventArgs(control);

    ASSERT_TRUE(object::ReferenceEquals(control, controlEventArgs.Control()));
  }

  TEST(ControlEventArgsTest, CopyOperator) {
    Control control;
    ControlEventArgs controlEventArgs(null);
    controlEventArgs = ControlEventArgs(control);

    ASSERT_TRUE(object::ReferenceEquals(control, controlEventArgs.Control()));
  }
}
