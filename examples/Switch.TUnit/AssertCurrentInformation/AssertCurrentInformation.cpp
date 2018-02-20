#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class TestFixture_(UserTest) {
    // With current information
    void Test_(TestWithCurrentInformation) {
      Assert::False(true, caller_);
    }

    // Without current information
    void TestWithoutCurrentInformation() {
      Assert::False(true);
    }
  };

  AddTest_(UserTest, TestWithCurrentInformation);
  AddTest_(UserTest, TestWithoutCurrentInformation);
}

// This code produces the following output:
//
// Start 2 tests from 1 test cases
//   Start 2 test from UserTest
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertCurrentInformation/AssertCurrentInformation.cpp:10
// *** FAILED UserTest.TestWithCurrentInformation (2 ms)
// Expected: False
// But was:  True
// *** FAILED UserTest.TestWithoutCurrentInformation (0 ms)
//   End 2 test from UserTest2 (3 ms total)
//
//   Summary :
//     PASSED 0 tests.
// *** FAILED 2 tests, listed below:
// *** FAILED UserTest.TestWithCurrentInformation
// *** FAILED UserTest.TestWithoutCurrentInformation
//
// 2 FAILED TESTS
// End 2 tests from 1 test case ran. (3 ms total)
