#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  // The class PointTest must be inherited from TestFixture
  class _TestFixture(TimeSpanTest) {
    // Used Expect::AreEqual method to test value
    void _Test(CreateTimeSpanFromDateTime) {
      DateTime n = DateTime(2015, 9, 5, 9, 15, 0);
      TimeSpan ts(n.Ticks);
      Expect::AreEqual(9, ts.Hours, _caller);
      Expect::AreEqual(15, ts.Minutes, _caller);
    }

    // Used Expect::IsTrue to virifie if a condition is true
    void _Test(TimeSpanIsEqualToAnotherTimeSpan) {
      TimeSpan ts(10, 42, 24);
      Expect::IsTrue(ts.Equals(TimeSpan(10, 42, 24)), _caller);
    }

    // Used Expect::IsFalse to virifie if a condition is false
    void _Test(DefaultTimeSpanIsEqualToZero) {
      Expect::IsFalse(TimeSpan(1) == TimeSpan::Zero(), _caller);
    }
  };

  // Used _Test to add unit test to execute at the unit test suit.
  _AddTestFixture(TimeSpanTest);
  _AddTest(TimeSpanTest, CreateTimeSpanFromDateTime);
  _AddTest(TimeSpanTest, TimeSpanIsEqualToAnotherTimeSpan);
  _AddTest(TimeSpanTest, DefaultTimeSpanIsEqualToZero);
}

// This code produces the following output:
//
// Start 3 tests from 1 test case
//   Start 3 tests from TimeSpanTest
//     PASSED TimeSpanTest.CreateTimeSpanFromDateTime (1 ms)
//     PASSED TimeSpanTest.TimeSpanIsEqualToAnotherTimeSpan (0 ms)
//     PASSED TimeSpanTest.DefaultTimeSpanIsEqualToZero (0 ms)
//   End 3 tests from TimeSpanTest (4 ms total)
//
//   Summary :
//     PASSED 3 tests.
// End 3 tests from 1 test case ran. (5 ms total)
