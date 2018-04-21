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
  [self setBorderType:NSNoBorder];
  [self setWidget:iWidget];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}
@end

namespace Native {
  class Panel : public Control<CocoaPanel> {
  public:
    Panel() {this->handle = [[CocoaPanel alloc] initWithIWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    void BorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
      switch (borderStyle) {
        case BorderStyle::None : [this->handle setBorderType:NSNoBorder]; break;
        case BorderStyle::FixedSingle : [this->handle setBorderType:NSLineBorder]; break;
        case BorderStyle::Fixed3D : [this->handle setBorderType:NSBezelBorder]; break;
      }
    }
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
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
  };
}

intptr Native::PanelApi::Create(const System::Windows::Forms::Panel& panel) {
  Native::Panel* widget = new Native::Panel();
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = panel;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

void Native::PanelApi::SetBorderStyle(const System::Windows::Forms::Panel& panel) {
  ((Native::Panel*)panel.Handle())->BorderStyle(panel.BorderStyle);
}

#endif
