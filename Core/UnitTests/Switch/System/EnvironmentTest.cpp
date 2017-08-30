#include <Switch/System/Environment.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace SwitchUnitTests {
  class EnvironmentTest : public TestFixture {
  protected:
    void GetEnvironmentVariables() {
      Assert::Greater(Environment::GetEnvironmentVariables().Count, 0, sw_current_information);
    }
    
    void GetEnvironmentVariable() {
      Assert::IsFalse(Environment::GetEnvironmentVariable("PATH").IsEmpty(), sw_current_information);
    }
    
    void SetEnvironmentVariable() {
      Assert::IsTrue(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT").IsEmpty(), sw_current_information);
      Assert::DoesNotThrows(sw_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "1");}, sw_current_information);
      Assert::AreEqual("1", Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT"), sw_current_information);
      Assert::DoesNotThrows(sw_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "");}, sw_current_information);
      Assert::IsTrue(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT").IsEmpty(), sw_current_information);
    }
  };
  
  //sw_test(EnvironmentTest, GetEnvironmentVariables)
  sw_test(EnvironmentTest, GetEnvironmentVariable)
  //sw_test(EnvironmentTest, SetEnvironmentVariable)
}