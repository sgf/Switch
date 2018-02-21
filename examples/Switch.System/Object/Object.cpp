#include <Switch/Switch>

using namespace System;

namespace ObjectTest {
  // The Point class is derived from System::Object.
  class Point : public object {
  public:
    Point(int x, int y) : x(x), y(y) { }

    bool Equals(const object& obj) const noexcept override {
      // If this and obj do not refer to the same type, then they are not equal.
      if (obj.GetType() != this->GetType()) return false;

      // Return true if x and y fields match.
      const Point& other = as<Point>(obj);
      return this->x == other.x && this->y == other.y;
    }

    // Return the XOR of the x and y fields.
    int GetHashCode() const noexcept override { return this->x ^ this->y; }

    // Return the point's value as a string.
    string ToString() const noexcept override { return string::Format("({0}, {1})", this->x, this->y); }

    // Return a copy of this point object by making a simple field copy.
    refptr<Point> Copy() { return as<Point>(this->MemberwiseClone<Point>()); }

  private:
    int x;
    int y;
  };

  class App static_ {
  public:
    static void Main() {
      // Construct a Point object.
      refptr<Point> p1 = new_<Point>(1, 2);

      // Make another Point object that is a copy of the first.
      refptr<Point> p2 = p1->Copy();

      // Make another variable that references the first Point object.
      refptr<Point> p3 = p1;

      // The line below displays false because point1 and point2 refer to two different objects.
      Console::WriteLine(Object::ReferenceEquals(*p1, *p2));

      // The line below displays true because point1 and point2 refer to two different objects that have the same value.
      Console::WriteLine(Object::Equals(*p1, *p2));

      // The line below displays true because point1 and point3 refer to one object.
      Console::WriteLine(Object::ReferenceEquals(*p1, *p3));

      // The line below displays: p1's value is: (1, 2)
      Console::WriteLine("p1's value is: {0}", *p1);
    }
  };
}

startup_(ObjectTest::App);

// This code produces the following output:
//
// False
// True
// True
// p1's value is: (1, 2)
