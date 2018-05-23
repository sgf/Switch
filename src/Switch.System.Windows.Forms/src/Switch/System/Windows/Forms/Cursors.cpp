#include "../../../../../include/Switch/System/Windows/Forms/Cursors.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

property_<Cursor, readonly_> Cursors::AppStarting {
  []() {return Cursor(Native::CursorsApi::AppStarting());}
};

property_<Cursor, readonly_> Cursors::Arrow {
  []() {return Cursor(Native::CursorsApi::Arrow());}
};

property_<Cursor, readonly_> Cursors::CloseHand {
  []() {return Cursor(Native::CursorsApi::CloseHand());}
};

property_<Cursor, readonly_> Cursors::ContextualMenu {
  []() {return Cursor(Native::CursorsApi::ContextualMenu());}
};

property_<Cursor, readonly_> Cursors::Cross {
  []() {return Cursor(Native::CursorsApi::Cross());}
};

property_<Cursor, readonly_> Cursors::Default {
  []() {return Cursor(Native::CursorsApi::Default());}
};

property_<Cursor, readonly_> Cursors::DisappearingItem {
  []() {return Cursor(Native::CursorsApi::DisappearingItem());}
};

property_<Cursor, readonly_> Cursors::DragCopy {
  []() {return Cursor(Native::CursorsApi::DragCopy());}
};

property_<Cursor, readonly_> Cursors::DragLink {
  []() {return Cursor(Native::CursorsApi::DragLink());}
};

property_<Cursor, readonly_> Cursors::Hand {
  []() {return Cursor(Native::CursorsApi::Hand());}
};

property_<Cursor, readonly_> Cursors::Help {
  []() {return Cursor(Native::CursorsApi::Help());}
};

property_<Cursor, readonly_> Cursors::HSplit {
  []() {return Cursor(Native::CursorsApi::HSplit());}
};

property_<Cursor, readonly_> Cursors::IBeam {
  []() {return Cursor(Native::CursorsApi::IBeam());}
};

property_<Cursor, readonly_> Cursors::No {
  []() {return Cursor(Native::CursorsApi::No());}
};

property_<Cursor, readonly_> Cursors::NoMove2D {
  []() {return Cursor(Native::CursorsApi::NoMove2D());}
};

property_<Cursor, readonly_> Cursors::NoMoveHoriz {
  []() {return Cursor(Native::CursorsApi::NoMoveHoriz());}
};

property_<Cursor, readonly_> Cursors::NoMoveVert {
  []() {return Cursor(Native::CursorsApi::NoMoveVert());}
};

property_<Cursor, readonly_> Cursors::OpenHand {
  []() {return Cursor(Native::CursorsApi::OpenHand());}
};

property_<Cursor, readonly_> Cursors::PanEast {
  []() {return Cursor(Native::CursorsApi::PanEast());}
};

property_<Cursor, readonly_> Cursors::PanNE {
  []() {return Cursor(Native::CursorsApi::PanNE());}
};

property_<Cursor, readonly_> Cursors::PanNorth {
  []() {return Cursor(Native::CursorsApi::PanNorth());}
};

property_<Cursor, readonly_> Cursors::PanNW {
  []() {return Cursor(Native::CursorsApi::PanNW());}
};

property_<Cursor, readonly_> Cursors::PanSE {
  []() {return Cursor(Native::CursorsApi::PanSE());}
};

property_<Cursor, readonly_> Cursors::PanSouth {
  []() {return Cursor(Native::CursorsApi::PanSouth());}
};

property_<Cursor, readonly_> Cursors::PanSW {
  []() {return Cursor(Native::CursorsApi::PanSW());}
};

property_<Cursor, readonly_> Cursors::PanWest {
  []() {return Cursor(Native::CursorsApi::PanWest());}
};

property_<Cursor, readonly_> Cursors::SizeAll {
  []() {return Cursor(Native::CursorsApi::SizeAll());}
};

property_<Cursor, readonly_> Cursors::SizeNESW {
  []() {return Cursor(Native::CursorsApi::SizeNESW());}
};

property_<Cursor, readonly_> Cursors::SizeNS {
  []() {return Cursor(Native::CursorsApi::SizeNS());}
};

property_<Cursor, readonly_> Cursors::SizeNWSE {
  []() {return Cursor(Native::CursorsApi::SizeNS());}
};

property_<Cursor, readonly_> Cursors::SizeWE {
  []() {return Cursor(Native::CursorsApi::SizeWE());}
};

property_<Cursor, readonly_> Cursors::UpArrow {
  []() {return Cursor(Native::CursorsApi::UpArrow());}
};

property_<Cursor, readonly_> Cursors::VIBeam {
  []() {return Cursor(Native::CursorsApi::VIBeam());}
};

property_<Cursor, readonly_> Cursors::VSplit {
  []() {return Cursor(Native::CursorsApi::VSplit());}
};

property_<Cursor, readonly_> Cursors::WaitCursor {
  []() {return Cursor(Native::CursorsApi::WaitCursor());}
};
