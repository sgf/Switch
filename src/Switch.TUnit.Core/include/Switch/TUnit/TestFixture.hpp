/// @file
/// @brief Contains Switch::TUnit::TestFixture class.
#pragma once

#include <gtest/gtest.h>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/SystemException.hpp>
#include "../TUnitCoreExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace TUnit {
    /// @brief The base class that all unit tests inherit from.
    /// @par Library
    /// Switch.TUnit.Core
    /// @par Exmaples
    /// This example code shows how to use TestFixture class:
    /// @include TestFixture.cpp
    class TestFixture : public testing::Test {
    protected:
      /// @cond
      TestFixture() {}
      TestFixture(const TestFixture&) = delete;
      TestFixture& operator =(const TestFixture&) = delete;
      /// @endcond

      /// @brief This is the method that is called before any tests in a fixture are run. Override it for used.
      void SetUp() override {}

      /// @brief This is the method that is called after any tests in a fixture are run. Override it for used.
      void TearDown() override {}
    };


#define TestFixture_(name) \
  name##_unused {}; \
  struct name : public TUnit::TestFixture

#define SetUp_(name) \
  SetUp() override {name();} \
  void name()

#define TearDown_(name) \
  TearDown() override {name();} \
  void name()

#define Test_(name) \
  name()

#define IgnoreTest_(name) \
  name()

    /// @brief Add spacified unit test to execute at the unit test suit.
    /// @param fixture The class inerited from TestFixture class that contains the unit test method to execute
    /// @param method The method that contains the unit test to execute
    /// @par Examples
    /// This example how to use TestFixture class, Expect class and #AddTest_ method:
    /// @include Expect.cpp
    /// @ingroup TUnit
#define AddTest_(fixture, method) \
  GTEST_TEST_(fixture, method, fixture, ::testing::internal::GetTypeId<fixture>()) { \
    try { \
      method(); \
    } catch(const TUnit::AssertionException) { \
      return ; \
    } \
  } \
  int __add_##fixture##_##method##_force_to_end_with_semicolon__ = 0

    /// @brief Add specified ignored unit test to execute at the unit test suit.
    /// @param fixture The class inerited from TestFixture class that contains the unit test method to execute
    /// @param method The method that contains the unit test to execute
    /// @par Examples
    /// This example how to use TestFixture class, Expect class and #AddTest_ method:
    /// @include Expect.cpp
    /// @ingroup TUnit
#define AddIgnoreTest_(fixture, method) \
  GTEST_TEST_(fixture, DISABLED_##method, fixture, ::testing::internal::GetTypeId<fixture>()) { \
    try { \
      method(); \
    } catch(const TUnit::AssertionException) { \
      return ; \
    } \
  } \
  int __add_##fixture##_##method##_force_to_end_witch_semicolon__ = 0
  }
}

using namespace Switch;
