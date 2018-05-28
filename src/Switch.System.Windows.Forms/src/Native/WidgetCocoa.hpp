#pragma once

#if defined(__APPLE__)

#import <Cocoa/Cocoa.h>
#include "WindowProcedureApiCocoa.hpp"
#include <Switch/System/Drawing/Color.hpp>
#include <Switch/System/Drawing/Font.hpp>
#include <Switch/System/Drawing/Point.hpp>
#include <Switch/System/Drawing/Size.hpp>
#include "Api.hpp"

namespace Native {
  /* enum class LocationOffset {
    None,
    GroupBox,
  }; */

  class IWidget interface_ {
  public:
    virtual void AddChild(IWidget* child) = 0;
    virtual void AutoSize() = 0;
    virtual void BackColor(const System::Drawing::Color& color) = 0;
    virtual System::Drawing::Point ClientLocation() const = 0;
    virtual System::Drawing::Size ClientSize() const = 0;
    virtual void ClientSize(const System::Drawing::Size& size) = 0;
    virtual void Cursor(const System::Windows::Forms::Cursor& cursor) = 0;
    virtual void Enabled(bool enabled) = 0;
    virtual void Font(const System::Drawing::Font& font) = 0;
    virtual void ForeColor(const System::Drawing::Color& color) = 0;
    virtual NSObject* Handle() = 0;
    virtual void Location(IWidget* parent, const System::Drawing::Point& location) = 0;
    //virtual Native::LocationOffset LocationOffset() const = 0;
    virtual void RemoveParent() = 0;
    virtual intptr SendMessage(intptr handle, int32 msg, intptr wparam, intptr lparam) = 0;
    virtual System::Drawing::Size Size() const = 0;
    virtual void Size(const System::Drawing::Size& size) = 0;
    virtual void Text(const string& text) = 0;
    virtual void Visible(bool visible) = 0;
    virtual NSView* View() = 0;

  protected:
  };

  template<typename T>
  class Widget : public IWidget {
  public:
    Widget() {}
    ~Widget() {
      if (this->handle != null)
        [this->handle release];
    }

    void AddChild(IWidget* child) override {[this->View() addSubview:child->View()];}
    virtual void AutoSize() override {[this->handle sizeToFit];}
    NSObject* Handle() override {return this->handle;}
    System::Drawing::Point ClientLocation() const override {return {0, 0};}
    System::Drawing::Size ClientSize() const override {return this->Size();}
    void ClientSize(const System::Drawing::Size& clientSize) override {this->Size(clientSize);}
    //Native::LocationOffset LocationOffset() const override {return Native::LocationOffset::None;}
    static NSColor* ToNSColor(const System::Drawing::Color& color) {return [NSColor colorWithCalibratedRed:as<double>(color.R()) / 0xFF green:as<double>(color.G()) / 0xFF blue:as<double>(color.B()) / 0xFF alpha:as<double>(color.A()) / 0xFF];}
    intptr SendMessage(intptr handle, int32 msg, intptr wparam, intptr lparam) override {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create(handle, msg, wparam, lparam, 0);
      const_cast<System::Windows::Forms::Control&>(Native::WindowProcedure::Controls[(intptr)this->handle]()).WndProc(message);
      return message.Result;
    }

  protected:
    T* handle = null;
  };

  template<typename T>
  class WidgetControl : public Widget<T> {
  public:
    WidgetControl() {}

    void Location(IWidget* parent, const System::Drawing::Point& location) override {[this->handle setFrameOrigin:NSMakePoint(location.X + this->ClientLocation().X, location.Y + this->ClientLocation().Y)];}

    /*
    void Location(IWidget* parent, const System::Drawing::Point& location) override {
      switch (parent->LocationOffset()) {
        case Native::LocationOffset::None: [this->handle setFrameOrigin:NSMakePoint(location.X + this->ClientLocation().X, location.Y + this->ClientLocation().Y)]; break;
        case Native::LocationOffset::GroupBox: [this->handle setFrameOrigin:NSMakePoint(location.X + this->ClientLocation().X, [parent->View() frame].size.height - [this->View() frame].size.height - location.Y  - this->ClientLocation().Y)]; break;
      }
    }
    Native::LocationOffset LocationOffset() const override {return Native::LocationOffset::None;}
     */
  };

}

#endif
