#if defined(__linux__)

#include <gdk/gdk.h>
#include <gdkmm.h>
#include "Api.hpp"
#include "../../include/Switch/System/Windows/Forms/Cursor.hpp"
#include "../../include/Switch/System/Windows/Forms/Screen.hpp"

using namespace System;
using namespace System::Windows::Forms;

intptr Native::CursorsApi::AppStarting() {
  return (intptr)"progress";
}

intptr Native::CursorsApi::Arrow() {
  return (intptr)"default";
}

intptr Native::CursorsApi::CloseHand() {
  return (intptr)"grabbing";
}

intptr Native::CursorsApi::ContextualMenu() {
  return (intptr)"context-menu";
}

intptr Native::CursorsApi::Cross() {
  return (intptr)"crosshair";
}

intptr Native::CursorsApi::Default() {
  return (intptr)"default";
}

intptr Native::CursorsApi::DisappearingItem() {
  return (intptr)"default";
}

intptr Native::CursorsApi::DragCopy() {
  return (intptr)"copy";
}

intptr Native::CursorsApi::DragLink() {
  return (intptr)"alias";
}

intptr Native::CursorsApi::Hand() {
  return (intptr)"pointer";
}

intptr Native::CursorsApi::Help() {
  return (intptr)"help";
}

intptr Native::CursorsApi::HSplit() {
  return (intptr)"col-resize";
}

intptr Native::CursorsApi::IBeam() {
  return (intptr)"text";
}

intptr Native::CursorsApi::No() {
  return (intptr)"not-allowed";
}

intptr Native::CursorsApi::NoMove2D() {
  return (intptr)"default";
}

intptr Native::CursorsApi::NoMoveHoriz() {
  return (intptr)"default";
}

intptr Native::CursorsApi::NoMoveVert() {
  return (intptr)"default";
}

intptr Native::CursorsApi::OpenHand() {
  return (intptr)"grab";
}

intptr Native::CursorsApi::PanEast() {
  return (intptr)"e-resize";
}

intptr Native::CursorsApi::PanNE() {
  return (intptr)"ne-resize";
}

intptr Native::CursorsApi::PanNorth() {
  return (intptr)"n-resize";
}

intptr Native::CursorsApi::PanNW() {
  return (intptr)"nw-resize";
}

intptr Native::CursorsApi::PanSE() {
  return (intptr)"se-resize";
}

intptr Native::CursorsApi::PanSouth() {
  return (intptr)"s-resize";
}

intptr Native::CursorsApi::PanSW() {
  return (intptr)"sw-resize";
}

intptr Native::CursorsApi::PanWest() {
  return (intptr)"w-resize";
}

intptr Native::CursorsApi::SizeAll() {
  return (intptr)"move";
}

intptr Native::CursorsApi::SizeNESW() {
  return (intptr)"nesw-resize";
}

intptr Native::CursorsApi::SizeNS() {
  return (intptr)"ns-resize";
}

intptr Native::CursorsApi::SizeNWSE() {
  return (intptr)"nwse-resize";
}

intptr Native::CursorsApi::SizeWE() {
  return (intptr)"we-resize";
}

intptr Native::CursorsApi::UpArrow() {
  return (intptr)"default";
}

intptr Native::CursorsApi::VIBeam() {
  return (intptr)"vertical-text";
}

intptr Native::CursorsApi::VSplit() {
  return (intptr)"row-resize";
}

intptr Native::CursorsApi::WaitCursor() {
  return (intptr)"wait";
}

#endif
