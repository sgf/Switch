#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/ProgressBar.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaProgressBar : NSProgressIndicator
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;

- (id)initWithMarquee:(BOOL)marquee withIWidget:(Native::IWidget*)iWidget;
- (void)resetCursorRects;
- (void)setBackgroundColor:(NSColor*)color;
- (void)setSize:(NSSize)size;
@end

@implementation CocoaProgressBar
- (id)initWithMarquee:(BOOL)marquee withIWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
  [self setMarquee:marquee];
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

- (void)setMarquee:(BOOL)marquee {
  [self setIndeterminate:marquee];
  if (marquee)
    [self startAnimation:self];
  else
    [self stopAnimation:self];
}

- (void)setSize:(NSSize)size {
  [self setFrameSize:size];
}
@end

namespace Native {
  class ProgressBar : public WidgetControl<CocoaProgressBar> {
  public:
    ProgressBar(bool marquee) {this->handle = [[CocoaProgressBar alloc] initWithMarquee:marquee ? YES : NO withIWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {}
    void Font(const System::Drawing::Font& font) override {}
    void ForeColor(const System::Drawing::Color& color) override {}
    void Marquee(bool marquee) {[this->handle setMarquee:marquee ? YES: NO];}
    void Maximum(int32 maximum) {[this->handle setMaxValue:maximum];}
    void Minimum(int32 minimum) {[this->handle setMinValue:minimum];}
    void RemoveParent() override {[this->handle removeFromSuperview];}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {[this->handle setSize:NSMakeSize(size.Width, size.Height)];}
    void Text(const string& text) override {}
    void Value(int32 value) {[this->handle setDoubleValue:value];}
    NSView* View() override {return this->handle;}
    void Visible(bool visible) override {[this->handle setHidden:visible ? NO : YES];}
  };
}

intptr Native::ProgressBarApi::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  Native::ProgressBar* widget = new Native::ProgressBar(progressBar.Style == ProgressBarStyle::Marquee);
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = progressBar;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

System::Drawing::Size Native::ProgressBarApi::GetDefaultSize() {
  return System::Drawing::Size(100, 20);
}

void Native::ProgressBarApi::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Maximum(progressBar.Maximum);
}

void Native::ProgressBarApi::SetMinimum(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Minimum(progressBar.Minimum);
}

void Native::ProgressBarApi::SetMarquee(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Marquee(progressBar.Style == ProgressBarStyle::Marquee);
}

void Native::ProgressBarApi::SetValue(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Native::ProgressBar*)progressBar.Handle())->Value(progressBar.Value);
}

#endif
