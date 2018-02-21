#include <Switch/Switch>

using namespace TUnit::Framework;
using namespace System;

namespace UnitTests {
  // The class DirectoryTest must be declared with TestFixture_
  class TestFixture_(Test) {
    void OneTimeSetUp_(OneTimeInit) {
    }

    void OneTimeTearDown_(OneTimeCleanup) {
    }

    // This is the method that is called before any tests in a fixture are run.
    void SetUp_(Init) {
    }

    // This is the method that is called after any tests in a fixture are run.
    void TearDown_(Cleanup) {
    }

    void Test_(TestCase1) {
    }

    void Test_(TestCase2) {
    }

    void IgnoreTest_(TestCase3) {
    }
  };

  // Used AddTestFixture_ to add unit test suit.
  AddTestFixture_(Test);

  class Program static_ {
  public:
    static int Main(const Array<string>& args) {
      return UnitTest(args).Run();
    }
  };
}

startup_(UnitTests::Program);
