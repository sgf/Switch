#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/Panel.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaPanel : NSScrollView
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;
@end

@implementation CocoaPanel
- (id)initWithIWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setDrawsBackground:NO];
  [self setBorderType:NSNoBorder];
  [self setWidget:iWidget];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}

- (void)sizeToFit {

}
@end

namespace Native {
  class Panel : public WidgetControl<CocoaPanel> {
  public:
    Panel() {this->handle = [[CocoaPanel alloc] initWithIWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {
      [this->handle setDrawsBackground:color != System::Drawing::Color::Transparent ? YES : NO];
      [this->handle setBackgroundColor:ToNSColor(color)];
    }

    void BorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
      this->borderStyle = borderStyle;
      switch (this->borderStyle) {
        case BorderStyle::None : [this->handle setBorderType:NSNoBorder]; break;
        case BorderStyle::FixedSingle : [this->handle setBorderType:NSLineBorder]; break;
        case BorderStyle::Fixed3D : [this->handle setBorderType:NSBezelBorder]; break;
      }
    }

    System::Drawing::Point ClientLocation() const override {
      switch (this->borderStyle) {
        case BorderStyle::None : return {0, 0};
        case BorderStyle::FixedSingle : return {1, 1};
        case BorderStyle::Fixed3D : return {2, 2};
      }
    }
    System::Drawing::Size ClientSize() const override {
      switch (this->borderStyle) {
        case BorderStyle::None : return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);
        case BorderStyle::FixedSingle : return System::Drawing::Size([this->handle frame].size.width - 2, [this->handle frame].size.height - 2);
        case BorderStyle::Fixed3D : return System::Drawing::Size([this->handle frame].size.width - 4, [this->handle frame].size.height - 4);
      }
    }
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {}
    void Font(const System::Drawing::Font& font) override {}
    void ForeColor(const System::Drawing::Color& color) override {}
    void IsDefault(bool isDefault) {}
    void RemoveParent() override {[this->handle removeFromSuperview];}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Text(const string& text) override {}
    NSView* View() override {return this->handle;}
    void Visible(bool visible) override {[this->handle setHidden:visible ? NO : YES];}

  private:
    System::Windows::Forms::BorderStyle borderStyle = System::Windows::Forms::BorderStyle::None;
  };
}

intptr Native::PanelApi::Create(const System::Windows::Forms::Panel& panel) {
  Native::Panel* widget = new Native::Panel();
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = panel;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

System::Drawing::Size Native::PanelApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
}

void Native::PanelApi::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  ((Native::Panel*)panel.Handle())->BorderStyle(panel.BorderStyle);
}

#endif
