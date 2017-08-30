#include <Switch/System/Version.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class VersionTest : public TestFixture {
  protected:
    void CreateVersionWithDefaultConstructor() {
      Version version;
      
      Assert::AreEqual(0, version.Major, sw_current_information);
      Assert::AreEqual(0, version.Minor, sw_current_information);
      Assert::AreEqual(-1, version.Build, sw_current_information);
      Assert::AreEqual(-1, version.Revision, sw_current_information);
    }
    
    void CreateVersionWithSpecifiedMajorAndMinor() {
      Version version(4, 2);
      
      Assert::AreEqual(4, version.Major, sw_current_information);
      Assert::AreEqual(2, version.Minor, sw_current_information);
      Assert::AreEqual(-1, version.Build, sw_current_information);
      Assert::AreEqual(-1, version.Revision, sw_current_information);
    }
    
    void CreateVersionWithSpecifiedMajorMinorAndRevision() {
      Version version(4, 2, 1);
      
      Assert::AreEqual(4, version.Major, sw_current_information);
      Assert::AreEqual(2, version.Minor, sw_current_information);
      Assert::AreEqual(1, version.Build, sw_current_information);
      Assert::AreEqual(-1, version.Revision, sw_current_information);
    }
    
    void CreateVersionWithSpecifiedMajorMinorRevisionAndBuild() {
      Version version(4, 2, 1, 3);
      
      Assert::AreEqual(4, version.Major, sw_current_information);
      Assert::AreEqual(2, version.Minor, sw_current_information);
      Assert::AreEqual(1, version.Build, sw_current_information);
      Assert::AreEqual(3, version.Revision, sw_current_information);
    }
    
    void CreateVersionWithSpecifiedMajorMinorRevisionAndBuildToZero() {
      Version version(0, 0, 0, 0);
      
      Assert::AreEqual(0, version.Major, sw_current_information);
      Assert::AreEqual(0, version.Minor, sw_current_information);
      Assert::AreEqual(0, version.Build, sw_current_information);
      Assert::AreEqual(0, version.Revision, sw_current_information);
    }
  };

  sw_test(VersionTest, CreateVersionWithDefaultConstructor)
  sw_test(VersionTest, CreateVersionWithSpecifiedMajorAndMinor)
  sw_test(VersionTest, CreateVersionWithSpecifiedMajorMinorAndRevision)
  sw_test(VersionTest, CreateVersionWithSpecifiedMajorMinorRevisionAndBuild)
  sw_test(VersionTest, CreateVersionWithSpecifiedMajorMinorRevisionAndBuildToZero)

  TEST(Version, Constructor) {
    EXPECT_EQ(Version().ToString(), "0.0");
    EXPECT_EQ(Version(1, 0).ToString(), "1.0");
    EXPECT_EQ(Version(1, 2).ToString(), "1.2");
    EXPECT_EQ(Version(Int32::MaxValue, 2).ToString(), "2147483647.2");
    EXPECT_EQ(Version(1, 2, 3).ToString(), "1.2.3");
    EXPECT_EQ(Version(1, 2, 3, 4).ToString(), "1.2.3.4");
    EXPECT_THROW(Version(-1, 0), ArgumentOutOfRangeException);
    EXPECT_THROW(Version(0, -25), ArgumentOutOfRangeException);
  }

  TEST(Version, Parse) {
    EXPECT_EQ(Version::Parse("11.0.2"), Version(11, 0, 2));
    EXPECT_EQ(Version::Parse("11.00.02"), Version(11, 0, 2));
  }

}