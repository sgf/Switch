/// @file
/// @brief Contains Switch::System::Windows::Forms::Form class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "ContainerControl.hpp"
#include "TabAlignment.hpp"
#include "TabPage.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Used to group collections of controls.
        /// @par Example
        /// The following code example demonstrate the use of TabControl control.
        /// @include TabControl.cpp
        class system_windows_forms_export_ TabControl : public ContainerControl {
        public:
          class TabPageCollection : public System::Collections::Generic::List<ref<TabPage>> {
          public:
            /// @cond
            ~TabPageCollection() { this->Clear(); }
            /// @endcond
            void Add(const ref<TabPage>& tabPage) override {
              this->tabControlContainer().InsertTabPage(this->Count, tabPage());
              this->System::Collections::Generic::List<ref<TabPage>>::Add(tabPage);
            }

            void Add(const string& text) {
              $<TabPage> tabPage = new_<TabPage>();
              tabPage->Text = text;
              this->tabControlContainer().AddAutoCreateTabPage(tabPage);
              this->Add(*tabPage);
            }

            void Add(const string& key, const string& text) {
              $<TabPage> tabPage = new_<TabPage>();
              tabPage->Name = key;
              tabPage->Text = text;
              this->tabControlContainer().AddAutoCreateTabPage(tabPage);
              this->Add(*tabPage);
            }

            void Insert(int32 index, const ref<TabPage>& tabPage) override {
              this->tabControlContainer().InsertTabPage(index, tabPage());
              this->System::Collections::Generic::List<ref<TabPage>>::Insert(index, tabPage);
            }

            void Insert(int32 index, const string& text) {
              $<TabPage> tabPage = new_<TabPage>();
              tabPage->Text = text;
              this->tabControlContainer().AddAutoCreateTabPage(tabPage);
              this->Insert(index, *tabPage);
            }

            void Insert(int32 index, const string& key, const string& text) {
              $<TabPage> tabPage = new_<TabPage>();
              tabPage->Name = key;
              tabPage->Text = text;
              this->tabControlContainer().AddAutoCreateTabPage(tabPage);
              this->Insert(index, *tabPage);
            }

            bool Remove(const ref<TabPage>& tabPage) override {
              this->tabControlContainer().RemoveTabPage(this->IndexOf(tabPage), tabPage());
              this->tabControlContainer().RemoveAutoCreateTabPage(tabPage());
              return this->System::Collections::Generic::List<ref<TabPage>>::Remove(tabPage);
            }

            void RemoveAt(int32 index) override {
              this->tabControlContainer().RemoveAutoCreateTabPage(this->operator[](index)());
              this->System::Collections::Generic::List<ref<TabPage>>::RemoveAt(index);
            }

          private:
            friend TabControl;
            explicit TabPageCollection(ref<TabControl> tabControlContainer) : tabControlContainer(tabControlContainer) {}
            ref<TabControl> tabControlContainer;
          };

          TabControl() : ContainerControl("", 0, 0, 200, 100) {
            this->SetStyle(ControlStyles::UserPaint, false);
            this->SetStyle(ControlStyles::EnableNotifyMessage, true);
          }

          property_<TabAlignment> Alignment{
            get_ {return this->alignment;},
            set_ {this->SetAlignment(value);}
          };

          property_<TabPageCollection&, readonly_> TabPages{
            get_->TabPageCollection& {return this->tabPages;}
          };

        protected:
          void OnNotifyMessage(const Message& m) override;
          void OnSizeChanged(const EventArgs& e) override;

          /// @brief Creates a handle for the control
          /// @remarks You typically should not call the CreateHandle method directly. The preferred method is to call the CreateControl method, which forces a handle to be created for the control and its child controls when the control is created.
          /// @par Notes to Inheritors
          /// When overriding CreateHandle in a derived class, be sure to call the base class's CreateHandle method to ensure that the handle is created.
          void CreateHandle() override;

          /// @brief Gets the default size of the control.
          /// @return Switch::System::Drawing::Size The default Size of the control.
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(200, 100); }

          void SetAlignment(TabAlignment alignment);

          /// @cond
          TabPageCollection tabPages {*this};
          TabAlignment alignment = TabAlignment::Top;
          /// @endcond

        private:
          friend class TabPageCollection;
          System::Collections::Generic::List < $<TabPage >> autoCreateTabPages;
          void InsertTabPage(int32 index, const TabPage& tabPage);
          void RemoveTabPage(int32 index, const TabPage& tabPage);
          void AddAutoCreateTabPage($<TabPage> tabPage) { this->autoCreateTabPages.Add(tabPage); }
          void RemoveAutoCreateTabPage(const TabPage& tabPage) {
            $<TabPage> tabPageToRemove;
            for ($<TabPage> item : this->autoCreateTabPages)
              if (item.ToPointer() == &tabPage)
                tabPageToRemove = item;
            if (tabPageToRemove != null)
              this->autoCreateTabPages.Remove(tabPageToRemove);
          }
        };
      }
    }
  }
}
