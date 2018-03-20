#include <gtest/gtest.h>
#include <Switch/System/Windows/Forms/Control.hpp>
#include <Switch/System/Windows/Forms/Form.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace SwitchUnitTests {
  TEST(ControlTest, DefaultConstructor) {
    Control control;

    ASSERT_EQ(Control::DefaultBackColor, control.BackColor);
    ASSERT_EQ(0, control.Bottom);
    ASSERT_EQ(Rectangle(0, 0, 0, 0), control.Bounds);
    ASSERT_EQ(Size(0, 0), control.ClientSize);
    ASSERT_EQ(0, control.Controls().Count);
    ASSERT_EQ(Control::DefaultForeColor, control.ForeColor);
    ASSERT_FALSE(control.HasChildren);
    ASSERT_EQ(0, control.Height);
    ASSERT_TRUE(control.Enabled);
    ASSERT_EQ(Control::DefaultForeColor, control.ForeColor);
    ASSERT_FALSE(control.IsHandleCreated);
    ASSERT_EQ(0, control.Left);
    ASSERT_EQ(Point(0, 0), control.Location);
    ASSERT_EQ("", control.Name);
    ASSERT_TRUE(control.Parent == null);
    ASSERT_EQ(0, control.Right);
    ASSERT_EQ(Size(0, 0), control.Size);
    ASSERT_TRUE(control.TabStop);
    ASSERT_EQ("", control.Text);
    ASSERT_EQ(0, control.Top);
    ASSERT_TRUE(control.Visible);
    ASSERT_EQ(0, control.Width);
  }

  TEST(ControlTest, ConstructorWithParentAndText) {
    Control control1;
    Control control2(control1, "control2");

    ASSERT_EQ(control1, control2.Parent());
    ASSERT_EQ("control2", control2.Text);
  }

  TEST(ControlTest, ConstructorWithParentTextAndBounds) {
    Control control1;
    Control control2(control1, "control2", 1, 2, 3, 4);

    ASSERT_EQ(Rectangle(1, 2, 3, 4), control2.Bounds);
    ASSERT_EQ(control1, control2.Parent());
    ASSERT_EQ("control2", control2.Text);
  }

  TEST(ControlTest, ConstructorWithText) {
    Control control("control");

    ASSERT_EQ("control", control.Text);
  }

  TEST(ControlTest, ConstructorWithTextAndBounds) {
    Control control("control", 1, 2, 3, 4);

    ASSERT_EQ(Rectangle(1, 2, 3, 4), control.Bounds);
    ASSERT_EQ("control", control.Text);
  }

  TEST(ControlTest, BackColor) {
    Control control;
    Color result;
    control.BackColorChanged += delegate_(const object & sender, const EventArgs & e) {
      result = as<Control>(sender).BackColor;
    };

    control.BackColor = Color::SpringGreen;

    ASSERT_EQ(Color::SpringGreen, control.BackColor);
    ASSERT_EQ(Color::SpringGreen, result);
  }

  TEST(ControlTest, Bottom) {
    Control control;

    control.SetBounds(1, 2, 3, 4);

    ASSERT_EQ(6, control.Bottom);
  }

  TEST(ControlTest, Bounds) {
    Control control;
    int32 result = 1;
    control.LocationChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };
    control.SizeChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 3;
    };

    control.Bounds = System::Drawing::Rectangle(1, 2, 3, 4);

    ASSERT_EQ(6, result);
    ASSERT_EQ(1, control.Left);
    ASSERT_EQ(2, control.Top);
    ASSERT_EQ(3, control.Width);
    ASSERT_EQ(4, control.Height);
  }

  TEST(ControlTest, ClientRectangle) {
    Control control;

    control.ClientSize = System::Drawing::Size(3, 4);

    ASSERT_EQ(System::Drawing::Rectangle(0, 0, 3, 4), control.ClientRectangle);
  }

  TEST(ControlTest, ClientSize) {
    Control control;

    control.ClientSize = System::Drawing::Size(3, 4);

    ASSERT_EQ(System::Drawing::Size(3, 4), control.ClientSize);
  }

  TEST(ControlTest, Controls) {
    Control control1, control2, control3;
    int32 result = 1;
    control2.ParentChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };
    control3.ParentChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 3;
    };

    control1.Controls().AddRange({control2, control3});

    ASSERT_EQ(6, result);
    ASSERT_EQ(control1, control2.Parent());
    ASSERT_EQ(control2, control1.Controls()[0]());
    ASSERT_EQ(control1, control3.Parent());
    ASSERT_EQ(control3, control1.Controls()[1]());
  }

  TEST(ControlTest, DefaultBackColor) {
    ASSERT_EQ(SystemColors::Control, Control::DefaultBackColor);
  }

  TEST(ControlTest, DefaultForeColor) {
    ASSERT_EQ(SystemColors::ControlText, Control::DefaultForeColor);
  }

  TEST(ControlTest, Enabled) {
    Control control;
    int32 result = 1;
    control.EnabledChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.Enabled = false;

    ASSERT_EQ(3, result);
    ASSERT_FALSE(control.Enabled);
  }

  TEST(ControlTest, ForeColor) {
    Control control;
    Color result;
    control.ForeColorChanged += delegate_(const object & sender, const EventArgs & e) {
      result = as<Control>(sender).ForeColor;
    };

    control.ForeColor = Color::SpringGreen;

    ASSERT_EQ(Color::SpringGreen, control.ForeColor);
    ASSERT_EQ(Color::SpringGreen, result);
  }

  TEST(ControlTest, HasChildren) {
    Control control1, control2, control3;

    control1.Controls().AddRange({control2, control3});

    ASSERT_TRUE(control1.HasChildren);
  }

  TEST(ControlTest, Height) {
    Control control;
    int32 result = 1;
    control.SizeChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 3;
    };

    control.Height = 4;

    ASSERT_EQ(4, result);
    ASSERT_EQ(4, control.Height);
  }

  TEST(ControlTest, IsHandleCreated) {
    Form control;

    control.Visible = true;
    control.CreateControl(); // Only visible Form can create with parent null.

    ASSERT_TRUE(control.IsHandleCreated);
  }

  TEST(ControlTest, Left) {
    Control control;
    int32 result = 1;
    control.LocationChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.Left = 1;

    ASSERT_EQ(3, result);
    ASSERT_EQ(1, control.Left);
  }

  TEST(ControlTest, Location) {
    Control control;
    int32 result = 1;
    control.LocationChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.Location = System::Drawing::Point(1, 2);

    ASSERT_EQ(3, result);
    ASSERT_EQ(System::Drawing::Point(1, 2), control.Location);
  }

  TEST(ControlTest, Name) {
    Control control;

    control.Name = "control";

    ASSERT_EQ("control", control.Name);
  }

  TEST(ControlTest, Parent) {
    Control control1, control2;
    int32 result = 1;
    control2.ParentChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control2.Parent = control1;

    ASSERT_EQ(3, result);
    ASSERT_EQ(control1, control2.Parent());
    ASSERT_EQ(control2, control1.Controls()[0]());
  }

  TEST(ControlTest, Right) {
    Control control;
    control.SetBounds(1, 2, 3, 4);
    ASSERT_EQ(4, control.Right);
  }

  TEST(ControlTest, Size) {
    Control control;
    int32 result = 1;
    control.SizeChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 3;
    };

    control.Size = System::Drawing::Size(3, 4);

    ASSERT_EQ(4, result);
    ASSERT_EQ(System::Drawing::Size(3, 4), control.Size);
  }

  TEST(ControlTest, TabStop) {
    Control control;
    int32 result = 1;
    control.TabStopChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.TabStop = false;

    ASSERT_EQ(3, result);
    ASSERT_FALSE(control.TabStop);
  }

  TEST(ControlTest, Text) {
    Control control;
    int32 result = 1;
    control.TextChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.Text = "control";

    ASSERT_EQ(3, result);
    ASSERT_EQ("control", control.Text);
  }

  TEST(ControlTest, Top) {
    Control control;
    int32 result = 1;
    control.LocationChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.Top = 2;

    ASSERT_EQ(3, result);
    ASSERT_EQ(2, control.Top);
  }

  TEST(ControlTest, Visible) {
    Control control;
    int32 result = 1;
    control.VisibleChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.Visible = false;

    ASSERT_EQ(3, result);
    ASSERT_FALSE(control.Visible);
  }

  TEST(ControlTest, Width) {
    Control control;
    int32 result = 1;
    control.SizeChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 3;
    };

    control.Width = 3;

    ASSERT_EQ(4, result);
    ASSERT_EQ(3, control.Width);
  }

  TEST(ControlTest, FindFormFromOneChild) {
    Form form1;
    Control control1;

    form1.Controls().Add(control1);

    ASSERT_EQ(form1, control1.FindForm());
  }

  TEST(ControlTest, FindFormFromMoreThanOneChild) {
    Form form1;
    Control control1, control2;

    control1.Controls().Add(control2);
    form1.Controls().Add(control1);

    ASSERT_EQ(form1, control2.FindForm());
  }

  TEST(ControlTest, FindFormWithoutFormParent) {
    Control control1, control2;

    control1.Controls().Add(control2);

    ASSERT_TRUE(control2.FindForm() == null);
  }

  TEST(ControlTest, Focus) {
    Control control;

    ASSERT_TRUE(control.Focus());
  }

  TEST(ControlTest, FromChildHandle) {
    Form form1;
    Control control1, control2, control3;

    control2.Controls().Add(control3);
    control1.Controls().Add(control2);
    form1.Controls().Add(control1);

    form1.Visible = true;
    form1.CreateControl();

    ASSERT_EQ(control2, Control::FromChildHandle(control3.Handle));
  }

  TEST(ControlTest, FromChildHandleWithInvalidHandle) {
    Form form1;
    Control control1, control2, control3;

    control2.Controls().Add(control3);
    control1.Controls().Add(control2);
    form1.Controls().Add(control1);

    form1.Visible = true;
    form1.CreateControl();

    ASSERT_TRUE(Control::FromChildHandle(-1) == null);
  }

  TEST(ControlTest, FromHandle) {
    Form form1;
    Control control1, control2, control3;

    control2.Controls().Add(control3);
    control1.Controls().Add(control2);
    form1.Controls().Add(control1);

    form1.Visible = true;
    form1.CreateControl();

    ASSERT_EQ(control3, Control::FromHandle(control3.Handle));
  }

  TEST(ControlTest, FromHandleWithInvalidHandle) {
    Form form1;
    Control control1, control2, control3;

    control2.Controls().Add(control3);
    control1.Controls().Add(control2);
    form1.Controls().Add(control1);

    form1.Visible = true;
    form1.CreateControl();

    ASSERT_TRUE(Control::FromHandle(-1) == null);
  }

  TEST(ControlTest, Hide) {
    Control control;
    int32 result = 1;
    control.VisibleChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };

    control.Hide();

    ASSERT_EQ(3, result);
    ASSERT_FALSE(control.Visible);
  }

  TEST(ControlTest, SetBounds) {
    Control control;
    int32 result = 1;
    control.LocationChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 2;
    };
    control.SizeChanged += delegate_(const object & sender, const EventArgs & e) {
      result += 3;
    };

    control.SetBounds(1, 2, 3, 4);

    ASSERT_EQ(6, result);
    ASSERT_EQ(1, control.Left);
    ASSERT_EQ(2, control.Top);
    ASSERT_EQ(3, control.Width);
    ASSERT_EQ(4, control.Height);
  }
}

