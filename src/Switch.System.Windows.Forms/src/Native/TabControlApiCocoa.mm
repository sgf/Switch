#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


@interface CocoaTabPage : NSTabViewItem
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;
@end

@interface CocoaTabControl : NSTabView
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;
@end

@implementation CocoaTabControl
- (id)initWithIWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setWidget:iWidget];
  return self;
}

- (void)resetCursorRects {
  [super resetCursorRects];
  if ([self cursor] != nil)
    [self addCursorRect:[self bounds] cursor:[self cursor]];
}

- (void)SetBackgroundColor:(NSColor*)backgroundColor {
  [self setTabViewBorderType:NSTabViewBorderTypeNone];
  [self setDrawsBackground:YES];
  [self setWantsLayer:YES];
  [[self layer] setBackgroundColor:[backgroundColor CGColor]];
}

@end

namespace Native {
  class TabControl : public Control<CocoaTabControl> {
  public:
    TabControl() {this->handle = [[CocoaTabControl alloc] initWithIWidget:this];}
    
    void InsertTabPage(int index, NSTabViewItem* item) {
      [this->handle insertTabViewItem:item atIndex:index];
   }
    void RemoveTabPage(NSTabViewItem* item) {[this->handle removeTabViewItem:item];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle SetBackgroundColor:ToNSColor(color)];}
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

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  Native::TabControl* widget = new Native::TabControl();
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = tabControl;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

void Native::TabControlApi::SetAlignment(const System::Windows::Forms::TabControl& tabControl) {
}


int32 Native::TabControlApi::GetSelectedTabPageIndex(const System::Windows::Forms::TabControl& tabControl) {
  return 0;
}

System::Drawing::Rectangle Native::TabControlApi::GetTabPageRectangle(const System::Windows::Forms::TabControl& tabControl) {
  return System::Drawing::Rectangle();
}

void Native::TabControlApi::InsertTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  ((Native::TabControl*)tabControl.Handle())->InsertTabPage(index, (NSTabViewItem*)((IWidget*)tabPage.Handle())->Handle());
}

void Native::TabControlApi::RemoveTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  ((Native::TabControl*)tabControl.Handle())->RemoveTabPage((NSTabViewItem*)((IWidget*)tabPage.Handle())->Handle());
}
#endif
