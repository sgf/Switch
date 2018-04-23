#if defined(__APPLE__)
#include "WidgetCocoa.hpp"
#include "../../include/Switch/System/Windows/Forms/TrackBar.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

@interface CocoaForm : NSWindow
@property Native::IWidget* widget;
- (BOOL)windowShouldClose:(id)sender;
@end

@interface CocoaTrackBar : NSSlider
@property (strong) NSCursor* cursor;
@property Native::IWidget* widget;

- (id)initWithIWidget:(Native::IWidget*)iWidget;
- (void)resetCursorRects;
- (void)setBackgroundColor:(NSColor*)color;
- (void)setForeColor:(NSColor*)color;
- (void)setSize:(NSSize)size;
- (IBAction) ValueChanged:(id)sender;
@end

@implementation CocoaTrackBar
- (id)initWithIWidget:(Native::IWidget*)iWidget {
  [super init];
  [self setAction:@selector(ValueChanged:)];
  [self setAutoresizingMask:NSViewMaxXMargin | NSViewMinYMargin];
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
  [self setWantsLayer:YES];
  [[self layer] setBackgroundColor:[color CGColor]];
}

- (void)setForeColor:(NSColor*)color {
}

- (void)setSize:(NSSize)size {
  [self setFrameSize:size];
}

- (IBAction) ValueChanged:(id)sender {
  [(CocoaForm*)[self window] widget]->SendMessage((intptr)self, [self isVertical] ? WM_VSCROLL : WM_HSCROLL, IntPtr::Zero, (intptr)[self widget]);
}
@end

namespace Native {
  class TrackBar : public WidgetControl<CocoaTrackBar> {
  public:
    TrackBar() {this->handle = [[CocoaTrackBar alloc] initWithIWidget:this];}
    void BackColor(const System::Drawing::Color& color) override {[this->handle setBackgroundColor:ToNSColor(color)];}
    System::Drawing::Size ClientSize() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void ClientSize(const System::Drawing::Size& size) override {[this->handle setFrameSize:NSMakeSize(size.Width, size.Height)];}
    void Cursor(const System::Windows::Forms::Cursor& cursor) override {[this->handle setCursor:(NSCursor *)cursor.Handle()];}
    void Enabled(bool enabled) override {[this->handle setEnabled:enabled];}
    void Font(const System::Drawing::Font& font) override {[this->handle setFont:((NSFont*)font.ToHFont())];}
    void ForeColor(const System::Drawing::Color& color) override {[this->handle setForeColor:ToNSColor(color)];}
    void Maximum(int32 maximum) {[this->handle setMaxValue:maximum];}
    void Minimum(int32 minimum) {[this->handle setMinValue:minimum];}
    void NumberOfTickMarks(int32 numberOfTickMarks) {[this->handle setNumberOfTickMarks:numberOfTickMarks];}
    void Orientation(System::Windows::Forms::Orientation orientation) {[this->handle setVertical:orientation == Orientation::Vertical];}
    void RemoveParent() override {[this->handle removeFromSuperview];}
    System::Drawing::Size Size() const override {return System::Drawing::Size([this->handle frame].size.width, [this->handle frame].size.height);}
    void Size(const System::Drawing::Size& size) override {[this->handle setSize:NSMakeSize(size.Width, size.Height)];}
    void Text(const string& text) override {}
    void TickMarkPosition(System::Windows::Forms::TickStyle tickStyle) {
      switch (tickStyle) {
        case TickStyle::None: [this->handle setNumberOfTickMarks:0]; break;
        case TickStyle::TopLeft: [this->handle setTickMarkPosition:NSTickMarkPositionAbove]; break;
        case TickStyle::BottomRight: [this->handle setTickMarkPosition:NSTickMarkPositionBelow]; break;
        case TickStyle::Both: [this->handle setTickMarkPosition:NSTickMarkPositionBelow]; break;
      }
    }
    int32 Value() const {return [this->handle integerValue];}
    void Value(int32 value) {[this->handle setIntegerValue:value];}
    NSView* View() override {return this->handle;}
    void Visible(bool visible) override {[this->handle setHidden:visible ? NO : YES];}
  };
}

intptr Native::TrackBarApi::Create(const System::Windows::Forms::TrackBar& trackBar) {
  Native::TrackBar* widget = new Native::TrackBar();
  Native::WindowProcedure::Controls[(intptr)widget->Handle()] = trackBar;
  widget->SendMessage((intptr)widget->Handle(), WM_CREATE, IntPtr::Zero, IntPtr::Zero);
  return (intptr)widget;
}

void Native::TrackBarApi::SetLargeChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void Native::TrackBarApi::SetMaximum(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->Maximum(trackBar.Maximum);
}

void Native::TrackBarApi::SetMinimum(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->Minimum(trackBar.Minimum);
}

void Native::TrackBarApi::SetOrientation(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->Orientation(trackBar.Orientation);
}

void Native::TrackBarApi::SetSmallChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void Native::TrackBarApi::SetTickFrequency(const System::Windows::Forms::TrackBar& trackBar) {
  if (trackBar.TickStyle == TickStyle::None)
    ((Native::TrackBar*)trackBar.Handle())->NumberOfTickMarks(0);
  else
    ((Native::TrackBar*)trackBar.Handle())->NumberOfTickMarks((trackBar.Maximum - trackBar.Minimum) / trackBar.TickFrequency);
}

void Native::TrackBarApi::SetTickStyle(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->TickMarkPosition(trackBar.TickStyle);
}

int32 Native::TrackBarApi::GetValue(const System::Windows::Forms::TrackBar& trackBar) {
  return ((Native::TrackBar*)trackBar.Handle())->Value();
}

void Native::TrackBarApi::SetValue(const System::Windows::Forms::TrackBar& trackBar) {
  ((Native::TrackBar*)trackBar.Handle())->Value(trackBar.Value);
}

#endif
