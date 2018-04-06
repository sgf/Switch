#include <Switch/System/Drawing/Brush.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Drawing;

namespace SwitchUnitTests {
  class Brush1 : public Brush {
  public:
    Brush1() : Brush() {this->SetNativeBrush(IntPtr::Zero);}
    Brush1(const Brush1&) = default;
    Brush1& operator=(const Brush1&) = default;

    $<object> Clone() const override {
      $<Brush1> brush1 = new_<Brush1>();
      brush1->SetNativeBrush(this->GetNativeBrush());
      brush1->SetNativeBrush(this->GetNativeBrush());
      return brush1;
    };

    intptr GetNativeBrush() const { return this->Brush::GetNativeBrush(); }

    void SetNativeBrush(intptr brush) {this->Brush::SetNativeBrush(brush);}
  };

  TEST(BrushTest, DefaultConstructor) {
    Brush1 brush1;

    ASSERT_EQ(IntPtr::Zero, brush1.GetNativeBrush());
  }

  TEST(BrushTest, SetNativeBrush) {
    Brush1 brush1;

    brush1.SetNativeBrush(42);

    ASSERT_EQ(42, brush1.GetNativeBrush());
  }

  TEST(BrushTest, CopyConstructor) {
    Brush1 brush1;
    brush1.SetNativeBrush(42);

    Brush1 brush2 = brush1;

    ASSERT_EQ(42, brush2.GetNativeBrush());
  }

  TEST(BrushTest, CopyOperator) {
    Brush1 brush1;
    brush1.SetNativeBrush(42);

    Brush1 brush2;
    brush2 = brush1;

    ASSERT_EQ(42, brush2.GetNativeBrush());
  }

  TEST(BrushTest, Copy) {
    $<Brush1> brush1 = new_<Brush1>();
    brush1->SetNativeBrush(42);

    $<Brush1> brush2 = new_<Brush1>(*brush1);
    brush1->SetNativeBrush(24);

    ASSERT_EQ(24, brush2->GetNativeBrush());
  }

  TEST(BrushTest, Clone) {
    $<Brush1> brush1 = new_<Brush1>();
    brush1->SetNativeBrush(42);

    $<Brush1> brush2 = as<Brush1>(brush1->Clone());
    brush1->SetNativeBrush(24);

    ASSERT_EQ(42, brush2->GetNativeBrush());
  }
}
