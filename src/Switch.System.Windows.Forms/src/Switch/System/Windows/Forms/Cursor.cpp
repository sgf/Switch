#include "../../../../../include/Switch/System/Windows/Forms/Cursor.hpp"
#include "../../../../Native/Api.hpp"

using namespace System;
using namespace System::Windows::Forms;

Cursor::Cursor(intptr handle) {
  this->data->handle = handle;
}

Cursor::~Cursor() {
  if (this->data.IsUnique())
    Native::CursorApi::Destroy(this->data->handle);
}

property_<System::Drawing::Point> Cursor::Position {
  []() {return Native::CursorApi::GetPosition();},
  [](const auto & value) {Native::CursorApi::SetPosition(value);}
};

void Cursor::Hide() {
  Native::CursorApi::Hide();
}

void Cursor::Show() {
  Native::CursorApi::Show();
}
