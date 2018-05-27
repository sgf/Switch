#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/RadioButton.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaRadioButton : NSButton
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;

- (IBAction) Click:(id)sender;
- (id)initWithTitle:(NSString*)title withIWidget:(Native::IWidget*)iWidget;
- (void)resetCursorRects;
- (void)setBackgroundColor:(NSColor*)color;
- (void)setForeColor:(NSColor*)color;
- (void)setSize:(NSSize)size;
@end

@implementation CocoaRadioButton
- (IBAction) Click:(id)sender {
  System::Drawing::Point mouseDownLocation;
  [self widget]->SendMessage((intptr)sender, WM_LBUTTONUP, (intptr)(mouseDownLocation.X() + (mouseDownLocation.Y() << 16)), IntPtr::Zero);
}

- (id)initWithTitle:(NSString*)title withIWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAction:@selector(Click:)];
  [self setAllowsMixedState:YES];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setButtonType:NSButtonTypeRadio];
  [self setTarget:self];
  [self setTitle:title];
  [self setWidget:iWidget];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}

- (void)setBackgroundColor:(NSColor*)color {
  [self setWantsLayer:YES];
  [[self layer] setBackgroundColor:[color CGColor]];
}

- (void)setForeColor:(NSColor*)color {
  NSMutableParagraphStyle* style = [[NSMutableParagraphStyle alloc] init];
  [style setAlignment:NSTextAlignmentCenter];
  NSDictionary* attrsDictionary = [NSDictionary dictionaryWithObjectsAndKeys:color, NSForegroundColorAttributeName, style, NSParagraphStyleAttributeName, nil];
  NSAttributedString* attrString = [[NSAttributedString alloc]initWithString:[self title] attributes:attrsDictionary];
  [self setAttributedTitle:attrString];
}

- (void)setSize:(NSSize)size {
  [self setBezelStyle: size.height <= 32 ? NSBezelStyleRounded : NSBezelStyleTexturedSquare];
  [self setFrameSize:size];
}
@end

namespace Native {
  class RadioButton : public WidgetControl<CocoaRadioButton> {
  public:
    RadioButton(const string& text) {this->handle = [[CocoaRadioButton alloc] initWithTitle:[NSString stringWithUTF8String:text.c_str()] withIWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {[this->handle setEnabled:enabled];}
    void Font(const System::Drawing::Font& font) override {[this->handle setFont:((NSFont*)font.ToHFont())];}
    void ForeColor(const System::Drawing::Color& color) override {[this->handle setForeColor:ToNSColor(color)];}
    void IsDefault(bool isDefault) {[this->handle setKeyEquivalent: [NSString stringWithUTF8String:isDefault ? "\r" : ""]];}
    void RemoveParent() override {[this->handle removeFromSuperview];}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {[this->handle setSize:NSMakeSize(size.Width, size.Height)];}
    void State(int state) {[this->handle setState:state];}
    void Text(const string& text) override {[this->handle setTitle:[NSString stringWithUTF8String:text.c_str()]];}
    NSView* View() override {return this->handle;}
    void Visible(bool visible) override {[this->handle setHidden:visible ? NO : YES];}
  };
}
intptr Native::RadioButtonApi::Create(const System::Windows::Forms::RadioButton& radioButton) {
  Native::RadioButton* widget = new Native::RadioButton(radioButton.Text);
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = radioButton;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

System::Drawing::Size Native::RadioButtonApi::GetDefaultSize() {
  return System::Drawing::Size(104, 24);
}

void Native::RadioButtonApi::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  ((Native::RadioButton*)radioButton.Handle())->State((int32)radioButton.Checked());
}

void Native::RadioButtonApi::SetGroup(const System::Windows::Forms::RadioButton& radioButton) {
}

#endif
