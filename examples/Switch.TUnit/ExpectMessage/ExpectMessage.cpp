#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class TestFixture_(UserTest) {
    // With your own message
    void TestWithUserMessage() {
      Expect::False(true, "true can never be equal to false", caller_);
    }

    // Without your own message
    void TestWithoutUserMessage() {
      Expect::False(true, caller_);
    }
  };

  AddTest_(UserTest, TestWithUserMessage);
  AddTest_(UserTest, TestWithoutUserMessage);
}

// This code produces the following output:
//
// Start 2 tests from 2 test cases
//   Start 2 test from UserTest
// true can never be equal to false
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertMessage/ExpectMessage.cpp:10
// *** FAILED UserTest1.TestWithUserMessage (2 ms)
// Expected: False
// But was:  True
// error: !---OMITTED---!/AssertMessage/ExpectMessage.cpp:15
// *** FAILED UserTest2.TestWithoutUserMessage (0 ms)
//   End 2 test from UserTest (3 ms total)
//
//   Summary :
//     PASSED 0 tests.
// *** FAILED 2 tests, listed below:
// *** FAILED UserTest.TestWithUserMessage
// *** FAILED UserTest.TestWithoutUserMessage
//
// 2 FAILED TESTS
// End 2 tests from 1 test cases ran. (3 ms total)
