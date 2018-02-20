#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class TestFixture_(UserTest) {
    void Test_(PassedTestAreEqual) {
      string s = "One";
      Assert::AreEqual("One", s, caller_);
    }

    void Test_(FailedTestAreEqual) {
      int32 i = 42;
      Assert::AreEqual(123, i, caller_);
    }
  };

  AddTest_(UserTest, PassedTestAreEqual);
  AddTest_(UserTest, FailedTestAreEqual);
}

// This code produces the following output:
//
// Start 2 tests from 1 test case
//   Start 2 tests from UserTest
//     PASSED UserTest.PassedTestAreEqual (0 ms)
// Expected: 123
// But was:  42
// error: !---OMITTED---!/AssertAreEqual/AssertAreEqual.cpp:15
// *** FAILED UserTest.FailedTestAreEqual (1 ms)
//   End 2 tests from UserTest (2 ms total)
//
//   Summary :
//     PASSED 1 test.
// *** FAILED 1 test, listed below:
// *** FAILED UserTest.FailedTestAreEqual
//
// 1 FAILED TEST
// End 2 tests from 1 test case ran. (3 ms total)
