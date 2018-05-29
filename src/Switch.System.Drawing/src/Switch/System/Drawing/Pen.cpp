#include "../../../../include/Switch/System/Drawing/Pen.hpp"
#include "../../../Native/Api.hpp"

using namespace System;
using namespace System::Drawing;

void Pen::Create() {
  this->Destroy();
  this->data->pen = Native::PenApi::CreatePen(this->data->dashStyle, (int32)this->data->width, as<SolidBrush>(this->data->brush)->Color);
}

void Pen::Destroy() {
  if (this->data->pen != IntPtr::Zero)
    Native::PenApi::DeletePen(this->data->pen);
  this->data->pen = IntPtr::Zero;
}
