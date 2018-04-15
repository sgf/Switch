#if defined(_WIN32)

#define UNICODE

#include <windows.h>
#include <Switch/Undef.hpp>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/Cursor.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::CursorsApi::AppStarting() {
  return (intptr)LoadCursor(null, IDC_APPSTARTING);
}

intptr Native::CursorsApi::Arrow() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::CloseHand() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::ContextualMenu() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::Cross() {
  return (intptr)LoadCursor(null, IDC_CROSS);
}

intptr Native::CursorsApi::Default() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::DisappearingItem() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::DragCopy() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::DragLink() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::Hand() {
  return (intptr)LoadCursor(null, IDC_HAND);
}

intptr Native::CursorsApi::Help() {
  return (intptr)LoadCursor(null, IDC_HELP);
}

intptr Native::CursorsApi::HSplit() {
  return (intptr)LoadCursor(null, IDC_SIZEWE);
}

intptr Native::CursorsApi::IBeam() {
  return (intptr)LoadCursor(null, IDC_IBEAM);
}

intptr Native::CursorsApi::No() {
  return (intptr)LoadCursor(null, IDC_NO);
}

intptr Native::CursorsApi::NoMove2D() {
  return (intptr)LoadCursor(null, IDC_NO);
}

intptr Native::CursorsApi::NoMoveHoriz() {
  return (intptr)LoadCursor(null, IDC_NO);
}

intptr Native::CursorsApi::NoMoveVert() {
  return (intptr)LoadCursor(null, IDC_NO);
}

intptr Native::CursorsApi::OpenHand() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanEast() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanNE() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanNorth() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanNW() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanSE() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanSouth() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanSW() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::PanWest() {
  return (intptr)LoadCursor(null, IDC_ARROW);
}

intptr Native::CursorsApi::SizeAll() {
  return (intptr)LoadCursor(null, IDC_SIZEALL);
}

intptr Native::CursorsApi::SizeNESW() {
  return (intptr)LoadCursor(null, IDC_SIZENESW);
}

intptr Native::CursorsApi::SizeNS() {
  return (intptr)LoadCursor(null, IDC_SIZENS);
}

intptr Native::CursorsApi::SizeNWSE() {
  return (intptr)LoadCursor(null, IDC_SIZENWSE);
}

intptr Native::CursorsApi::SizeWE() {
  return (intptr)LoadCursor(null, IDC_SIZEWE);
}

intptr Native::CursorsApi::UpArrow() {
  return (intptr)LoadCursor(null, IDC_UPARROW);
}

intptr Native::CursorsApi::VIBeam() {
  return (intptr)LoadCursor(null, IDC_IBEAM);
}

intptr Native::CursorsApi::VSplit() {
  return (intptr)LoadCursor(null, IDC_SIZENS);
}

intptr Native::CursorsApi::WaitCursor() {
  return (intptr)LoadCursor(null, IDC_WAIT);
}

#endif
