#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaTabPagePanel : NSScrollView
@property (strong) NSCursor* cursor;
@end

@implementation CocoaTabPagePanel
- (id)init {
  [super init];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setBorderType:NSNoBorder];
  [self setDrawsBackground:NO];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}
@end

@interface CocoaTabPage : NSTabViewItem
@property Native::IWidget* widget;
@end

@implementation CocoaTabPage
- (id)initWithTitle:(NSString*)title IWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setLabel:title];
  [self setWidget:iWidget];
  [self setView:[[CocoaTabPagePanel alloc] init]];
 return self;
}

- (void)resetCursorRects {
  [self resetCursorRects];
}

-(void)setBackgroundColor:(NSColor *)backgroundColor {
  [(CocoaTabPagePanel*)[self view] setDrawsBackground:YES];
  [(CocoaTabPagePanel*)[self view] setBackgroundColor:backgroundColor];
}

- (void)sizeToFit {
  
  
}
@end

namespace Native {
  class TabPage : public Widget<CocoaTabPage> {
  public:
    TabPage(const string& text) {this->handle = [[CocoaTabPage alloc] initWithTitle:[NSString stringWithUTF8String:text.c_str()] IWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size();}
    void ClientSize(const System::Drawing::Size& size) override {}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[(CocoaTabPagePanel*)[this->handle view] setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {}
    void Font(const System::Drawing::Font& font) override {}
    void ForeColor(const System::Drawing::Color& color) override {}
    void IsDefault(bool isDefault) {}
    void Location(IWidget* parent, const System::Drawing::Point& location) override {}
    void RemoveParent() override {}
    System::Drawing::Size Size() const override {return System::Drawing::Size();}
    void Size(const System::Drawing::Size& size) override {}
    void Text(const string& text) override {}
    NSView* View() override {return [this->handle view];}
    void Visible(bool visible) override {}
  };
}

intptr Native::TabPageApi::Create(const System::Windows::Forms::TabPage& tabPage) {
  Native::TabPage* widget = new Native::TabPage(tabPage.Text);
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = tabPage;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

void Native::TabPageApi::SetBorderStyle(const System::Windows::Forms::TabPage& tabPage) {
}

#endif
