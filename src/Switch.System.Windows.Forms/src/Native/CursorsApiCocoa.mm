#if defined(__APPLE__)
#include <Quartz/Quartz.h>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/Cursor.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::CursorsApi::AppStarting() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load application starting cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::Arrow() {
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::CloseHand() {
  return (intptr)[NSCursor closedHandCursor];
}

intptr Native::CursorsApi::ContextualMenu() {
  return (intptr)[NSCursor contextualMenuCursor];
}

intptr Native::CursorsApi::Cross() {
  return (intptr)[NSCursor crosshairCursor];
}

intptr Native::CursorsApi::Default() {
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::DisappearingItem() {
  return (intptr)[NSCursor disappearingItemCursor];
}

intptr Native::CursorsApi::DragCopy() {
  return (intptr)[NSCursor dragCopyCursor];
}

intptr Native::CursorsApi::DragLink() {
  return (intptr)[NSCursor dragLinkCursor];
}

intptr Native::CursorsApi::Hand() {
  return (intptr)[NSCursor pointingHandCursor];
}

intptr Native::CursorsApi::Help() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load help cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::HSplit() {
  return (intptr)[NSCursor resizeUpDownCursor];
}

intptr Native::CursorsApi::IBeam() {
  return (intptr)[NSCursor IBeamCursor];
}

intptr Native::CursorsApi::No() {
  return (intptr)[NSCursor operationNotAllowedCursor];
}

intptr Native::CursorsApi::NoMove2D() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load n o move two direction cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::NoMoveHoriz() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load n o move horizontal cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::NoMoveVert() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load no move vertical cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::OpenHand() {
  return (intptr)[NSCursor openHandCursor];
}

intptr Native::CursorsApi::PanEast() {
  return (intptr)[NSCursor resizeRightCursor];
}

intptr Native::CursorsApi::PanNE() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load north east cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::PanNorth() {
  return (intptr)[NSCursor resizeUpCursor];
}

intptr Native::CursorsApi::PanNW() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load north west cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::PanSE() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load south east cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::PanSouth() {
  return (intptr)[NSCursor resizeDownCursor];
}

intptr Native::CursorsApi::PanSW() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load south west cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::PanWest() {
  return (intptr)[NSCursor resizeLeftCursor];
}

intptr Native::CursorsApi::SizeAll() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load size all cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::SizeNESW() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load size all cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::SizeNS() {
  return (intptr)[NSCursor resizeUpDownCursor];
}

intptr Native::CursorsApi::SizeNWSE() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load size all cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::SizeWE() {
  return (intptr)[NSCursor resizeLeftRightCursor];
}

intptr Native::CursorsApi::UpArrow() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load size all cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

intptr Native::CursorsApi::VIBeam() {
  return (intptr)[NSCursor IBeamCursorForVerticalLayout];
}

intptr Native::CursorsApi::VSplit() {
  return (intptr)[NSCursor resizeLeftRightCursor];
}

intptr Native::CursorsApi::WaitCursor() {
  /*
  NSImage* image = [[NSImage alloc] initWithSize:NSMakeSize(32, 32)];
  // load size all cursor image...
  NSCursor* cursor = [[NSCursor alloc] initWithImage:image hotSpot:NSMakePoint(0, 0)];
  return (intptr)cursor;
   */
  return (intptr)[NSCursor arrowCursor];
}

#endif
