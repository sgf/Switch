#if defined(__linux__)

#include <gtkmm/notebook.h>
#include <gtkmm/scrolledwindow.h>
#include "WidgetGtk.hpp"
#include "../../include/Switch/System/Windows/Forms/TabControl.hpp"
#include "../../include/Switch/System/Windows/Forms/TabPage.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Native {
  class TabControl : public Widget, public Gtk::Notebook {
  public:
    TabControl() {
      this->RegisterEvent();
    }

    void Text(const string& text) override {}
  };
}

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  Native::TabControl* handle = new Native::TabControl();
  handle->Move(tabControl.Location().X, tabControl.Location().Y);
  handle->show();
  return (intptr)handle;
}

int32 Native::TabControlApi::GetSelectedTabPageIndex(const System::Windows::Forms::TabControl& tabControl) {
  return 0;
}

System::Drawing::Rectangle Native::TabControlApi::GetTabPageRectangle(const System::Windows::Forms::TabControl& tabControl) {
  return System::Drawing::Rectangle();
}

void Native::TabControlApi::SetAlignment(const System::Windows::Forms::TabControl& tabControl) {

}

void Native::TabControlApi::InsertTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  ((Native::TabControl*)tabControl.Handle())->insert_page(((Native::TabControl*)tabPage.Handle())->ToWidget(), tabPage.Text().c_str(), index);
}

void Native::TabControlApi::RemoveTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  ((Native::TabControl*)tabControl.Handle())->remove_page(index);
}
#endif
