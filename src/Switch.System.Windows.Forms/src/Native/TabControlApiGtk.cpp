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
  class TabControl : public Widget<Gtk::Notebook> {
  public:
    TabControl() {}

    void InsertPage(IWidget* tabPage, const string& text, int32 index) {this->handle->insert_page(*tabPage->Handle(), text.c_str(), index);}
    void RemovePage(int32 index) {this->handle->remove_page(index);}
    void Text(const string& text) override {}
  };
}

intptr Native::TabControlApi::Create(const System::Windows::Forms::TabControl& tabControl) {
  Native::TabControl* handle = new Native::TabControl();
  handle->Move(tabControl.Location().X, tabControl.Location().Y);
  handle->Visible(true);
  return (intptr)handle;
}

System::Drawing::Size Native::TabControlApi::GetDefaultSize() {
  return System::Drawing::Size(200, 100);
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
  ((Native::TabControl*)tabControl.Handle())->InsertPage((Native::IWidget*)tabPage.Handle(), tabPage.Text, index);
}

void Native::TabControlApi::RemoveTabPage(const System::Windows::Forms::TabControl& tabControl, int32 index, const System::Windows::Forms::TabPage& tabPage) {
  ((Native::TabControl*)tabControl.Handle())->RemovePage(index);
}
#endif
