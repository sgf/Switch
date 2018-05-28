#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/GroupBox.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaGroupBoxPanel : NSScrollView
@end

@implementation CocoaGroupBoxPanel
- (id)initWithFrame:(NSRect)bounds {
  [super initWithFrame:bounds];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setBorderType:NSNoBorder];
  [self setDrawsBackground:NO];
  return self;
}
@end

@interface CocoaGroupBox : NSBox
@property (strong) NSCursor* cursor;
@property (strong)CocoaGroupBoxPanel* panel;
@property Native::IWidget* widget;
@end

@implementation CocoaGroupBox
- (id)initWithTitle:(NSString*)title IWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setTitle:title];
  [self setFrame:NSMakeRect(0, 0, 200, 100)];
  _panel = [[CocoaGroupBoxPanel alloc] initWithFrame:NSMakeRect(0, 0, [self frame].size.width, [self frame].size.height)];
  [self setWidget:iWidget];
  [self addSubview:[self panel]];
  [self setAutoresizesSubviews:YES];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}

-(void) viewDidEndLiveResize {
  [_panel setFrame:NSMakeRect(0, 0, [self frame].size.width, [self frame].size.height)];
}

- (void)setBackgroundColor:(NSColor*)color {
  [self setBoxType:NSBoxCustom];
  [self setBorderType:NSLineBorder];
  [self setFillColor:color];
}
@end

namespace Native {
  class GroupBox : public WidgetControl<CocoaGroupBox> {
  public:
    GroupBox(const string& text) {this->handle = [[CocoaGroupBox alloc] initWithTitle:[NSString stringWithUTF8String:text.c_str()] IWidget:this];}
    
    void AddChild(IWidget* child) override {[[this->handle panel] addSubview:child->View()];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {}
    void Font(const System::Drawing::Font& font) override {[this->handle setTitleFont:((NSFont*)font.ToHFont())];}
    void ForeColor(const System::Drawing::Color& color) override {}
    //Native::LocationOffset LocationOffset() const override {return Native::LocationOffset::GroupBox;}
    void IsDefault(bool isDefault) {}
    void RemoveParent() override {[this->handle removeFromSuperview];}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {
      [this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];
      [this->handle viewDidEndLiveResize];

    }
    void Text(const string& text) override {}
    NSView* View() override {return this->handle;}
    void Visible(bool visible) override {[this->handle setHidden:visible ? NO : YES];}
  };
}

intptr Native::GroupBoxApi::Create(const System::Windows::Forms::GroupBox& groupBox) {
  @autoreleasepool {
    Native::GroupBox* widget = new Native::GroupBox(groupBox.Text);
    Native::WindowProcedure::Controls[(intptr)widget->Handle()] = groupBox;
    widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
    return (intptr)widget;
  }
}

System::Drawing::Size Native::GroupBoxApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
}

#endif
