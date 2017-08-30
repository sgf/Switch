﻿#include <Switch/System/Drawing/Rectangle.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Drawing;
using namespace TUnit;

namespace SwitchUnitTests {
  class RectangleTest : public TestFixture {
  public:
    void Empty() {
      Assert::AreEqual(0, Rectangle::Empty().X(), sw_current_information);
      Assert::AreEqual(0, Rectangle::Empty().Y(), sw_current_information);
      Assert::AreEqual(0, Rectangle::Empty().Width(), sw_current_information);
      Assert::AreEqual(0, Rectangle::Empty().Height(), sw_current_information);
    }
    
    void CreateEmpty() {
      Drawing::Rectangle rect;
      Assert::AreEqual(0, rect.X(), sw_current_information);
      Assert::AreEqual(0, rect.Y(), sw_current_information);
      Assert::AreEqual(0, rect.Width(), sw_current_information);
      Assert::AreEqual(0, rect.Height(), sw_current_information);
    }
    
    void CreateRectangleFromXYWidthHeight() {
      Drawing::Rectangle rect(12, 346, 244, 578);
      Assert::AreEqual(12, rect.X(), sw_current_information);
      Assert::AreEqual(346, rect.Y(), sw_current_information);
      Assert::AreEqual(244, rect.Width(), sw_current_information);
      Assert::AreEqual(578, rect.Height(), sw_current_information);
    }
    
    void CreateRectangleFromEmptyRectangle() {
      Drawing::Rectangle r;
      Drawing::Rectangle rect(r);
      Assert::AreEqual(0, rect.X(), sw_current_information);
      Assert::AreEqual(0, rect.Y(), sw_current_information);
      Assert::AreEqual(0, rect.Width(), sw_current_information);
      Assert::AreEqual(0, rect.Height(), sw_current_information);
    }
    
    void CreateRectangleFromRectangle() {
      Drawing::Rectangle r(123, 456, 244, 578);
      Drawing::Rectangle rect(r);
      Assert::AreEqual(123, rect.X(), sw_current_information);
      Assert::AreEqual(456, rect.Y(), sw_current_information);
      Assert::AreEqual(244, rect.Width(), sw_current_information);
      Assert::AreEqual(578, rect.Height(), sw_current_information);
    }
    
    void CreateRectangleFromEmptyPointAndEmtpySize() {
      Drawing::Point p;
      Drawing::Size s;
      Drawing::Rectangle rect(p, s);
      Assert::AreEqual(0, rect.X(), sw_current_information);
      Assert::AreEqual(0, rect.Y(), sw_current_information);
      Assert::AreEqual(0, rect.Width(), sw_current_information);
      Assert::AreEqual(0, rect.Height(), sw_current_information);
    }
    
    void CreateRectangleFromPointAndSize() {
      Drawing::Point p(123, 456);
      Drawing::Point s(244, 578);
      Drawing::Rectangle rect(p, s);
      Assert::AreEqual(123, rect.X(), sw_current_information);
      Assert::AreEqual(456, rect.Y(), sw_current_information);
      Assert::AreEqual(244, rect.Width(), sw_current_information);
      Assert::AreEqual(578, rect.Height(), sw_current_information);
    }
    
    void EmptyRectangleIsEmpty() {
      Assert::IsTrue(Rectangle::Empty().IsEmpty(), sw_current_information);
    }
    
    void RectangleIsEmpty() {
      Assert::IsFalse(Drawing::Rectangle(125, 679, 244, 567).IsEmpty(), sw_current_information);
    }
    
    void EmptyRectangleToString() {
      Assert::AreEqual("{X=0,Y=0,Width=0,Height=0}", Rectangle::Empty().ToString(), sw_current_information);
    }
    
    void RectangleToString() {
      Assert::AreEqual("{X=10,Y=24,Width=54,Height=987}", Drawing::Rectangle(10, 24, 54, 987).ToString(), sw_current_information);
    }
    
    void FromLTRB() {
      Drawing::Rectangle rect = Rectangle::FromLTRB(10, 20, 100, 50);
      Assert::AreEqual(10, rect.X(), sw_current_information);
      Assert::AreEqual(20, rect.Y(), sw_current_information);
      Assert::AreEqual(90, rect.Width(), sw_current_information);
      Assert::AreEqual(30, rect.Height(), sw_current_information);
    }
    
    void GetLeftTopRightBottom() {
      Drawing::Rectangle rect(10, 20, 100, 50);

      Assert::AreEqual(rect.Y(), rect.Top(), sw_current_information);
      Assert::AreEqual(rect.X(), rect.Left(), sw_current_information);
      Assert::AreEqual(rect.X() + rect.Width(), rect.Right(), sw_current_information);
      Assert::AreEqual(rect.Y() + rect.Height(), rect.Bottom(), sw_current_information);
      
      Assert::AreEqual(10, rect.X(), sw_current_information);
      Assert::AreEqual(20, rect.Y(), sw_current_information);
      Assert::AreEqual(100, rect.Width(), sw_current_information);
      Assert::AreEqual(50, rect.Height(), sw_current_information);
      
      Assert::AreEqual(10, rect.Left(), sw_current_information);
      Assert::AreEqual(20, rect.Top(), sw_current_information);
      Assert::AreEqual(110, rect.Right(), sw_current_information);
      Assert::AreEqual(70, rect.Bottom(), sw_current_information);
    }
    
    void RectangleInflateFromXY() {
      Drawing::Rectangle rect(100, 100, 300, 200);
      
      rect.Inflate(50, 20);
      
      Assert::AreEqual(50, rect.X(), sw_current_information);
      Assert::AreEqual(80, rect.Y(), sw_current_information);
      Assert::AreEqual(400, rect.Width(), sw_current_information);
      Assert::AreEqual(240, rect.Height(), sw_current_information);

      Drawing::Rectangle rect2 = Rectangle::Inflate(rect, 50, 20);
      
      Assert::AreEqual(0, rect2.X(), sw_current_information);
      Assert::AreEqual(60, rect2.Y(), sw_current_information);
      Assert::AreEqual(500, rect2.Width(), sw_current_information);
      Assert::AreEqual(280, rect2.Height(), sw_current_information);
    }
    
    void RectangleInflateFromSize() {
      Drawing::Rectangle rect(100, 100, 300, 200);
      
      rect.Inflate(Drawing::Size(50, 20));
      
      Assert::AreEqual(50, rect.X(), sw_current_information);
      Assert::AreEqual(80, rect.Y(), sw_current_information);
      Assert::AreEqual(400, rect.Width(), sw_current_information);
      Assert::AreEqual(240, rect.Height(), sw_current_information);
    }
    
    void Intersect() {
      Drawing::Rectangle rectangle1(50, 50, 200, 100);
      Drawing::Rectangle rectangle2(70, 20, 100, 200);
      Drawing::Rectangle rectangle3 = Rectangle::Intersect(rectangle1, rectangle2);
      Assert::IsTrue(rectangle3.IsEmpty());
    }
  };
  
  sw_test(RectangleTest, Empty)
  sw_test(RectangleTest, CreateEmpty)
  sw_test(RectangleTest, CreateRectangleFromXYWidthHeight)
  sw_test(RectangleTest, CreateRectangleFromEmptyRectangle)
  sw_test(RectangleTest, CreateRectangleFromRectangle)
  sw_test(RectangleTest, CreateRectangleFromEmptyPointAndEmtpySize)
  sw_test(RectangleTest, CreateRectangleFromPointAndSize)
  sw_test(RectangleTest, EmptyRectangleIsEmpty)
  sw_test(RectangleTest, RectangleIsEmpty)
  sw_test(RectangleTest, EmptyRectangleToString)
  sw_test(RectangleTest, RectangleToString)
  sw_test(RectangleTest, FromLTRB)
  sw_test(RectangleTest, GetLeftTopRightBottom)
  sw_test(RectangleTest, RectangleInflateFromXY)
  sw_test(RectangleTest, RectangleInflateFromSize)
  sw_test(RectangleTest, Intersect)
}
