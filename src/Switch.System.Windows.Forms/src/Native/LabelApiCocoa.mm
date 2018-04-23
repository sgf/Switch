#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/Label.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaLabel : NSTextField
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;

- (IBAction) Click:(id)sender;
- (id)initWithTitle:(NSString*)title withIWidget:(Native::IWidget*)iWidget;
- (void)resetCursorRects;
- (void)setBackgroundColor:(NSColor*)color;
- (void)setForeColor:(NSColor*)color;
- (void)setSize:(NSSize)size;
@end

@implementation CocoaLabel
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  [self widget]->SendMessage((intptr)sender, WM_LBUTTONUP, (intptr)(mouseDownLocation.X() + (mouseDownLocation.Y() << 16)), IntPtr::Zero);
}

- (id)initWithTitle:(NSString*)title withIWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAction:@selector(Click:)];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setBezeled:NO];
  [self setDrawsBackground:NO];
  [self setEditable:NO];
  [self setSelectable:NO];
  [self setStringValue:title];
  [self setTarget:self];
  [self setWidget:iWidget];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}

- (void)setBackgroundColor:(NSColor*)color {
  [self setDrawsBackground:YES];
  [super setBackgroundColor:color];
}

- (void)setForeColor:(NSColor*)color {
  [self setTextColor:color];
}

- (void)setSize:(NSSize)size {
  [self setFrameSize:size];
}
@end

namespace Native {
  class Label : public WidgetControl<CocoaLabel> {
  public:
    Label(const string& text) {this->handle = [[CocoaLabel alloc] initWithTitle:[NSString stringWithUTF8String:text.c_str()] withIWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {[this->handle setEnabled:enabled];}
    void Font(const System::Drawing::Font& font) override {[this->handle setFont:((NSFont*)font.ToHFont())];}
    void ForeColor(const System::Drawing::Color& color) override {[this->handle setForeColor:ToNSColor(color)];}
    void RemoveParent() override {[this->handle removeFromSuperview];}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {[this->handle setSize:NSMakeSize(size.Width, size.Height)];}
    void Text(const string& text) override {[this->handle setStringValue:[NSString stringWithUTF8String:text.c_str()]];}
    NSView* View() override {return this->handle;}
    void Visible(bool visible) override {[this->handle setHidden:visible ? NO : YES];}
  };
}

intptr Native::LabelApi::Create(const System::Windows::Forms::Label& label) {
  Native::Label* widget = new Native::Label(label.Text);
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = label;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

#endif
