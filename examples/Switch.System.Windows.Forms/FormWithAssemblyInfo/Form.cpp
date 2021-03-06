#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace Examples {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->company.Text = "Company name";
      this->company.Location = Point(10, 12);

      this->product.Text = "Product name";
      this->product.Location = Point(10, 42);

      this->version.Text = "Product version";
      this->version.Location = Point(10, 72);

      this->companyName.Text = Application::CompanyName;
      this->companyName.BorderStyle = BorderStyle::Fixed3D;
      this->companyName.BackColor = System::Drawing::Color::White;
      this->companyName.ForeColor = System::Drawing::Color::Black;
      this->companyName.Location = Point(120, 10);
      this->companyName.TextAlign = ContentAlignment::MiddleLeft;
      this->companyName.Width = 170;

      this->productName.Text = Application::ProductName;
      this->productName.BorderStyle = BorderStyle::Fixed3D;
      this->productName.BackColor = System::Drawing::Color::White;
      this->productName.ForeColor = System::Drawing::Color::Black;
      this->productName.Location = Point(120, 40);
      this->productName.TextAlign = ContentAlignment::MiddleLeft;
      this->productName.Width = 170;

      this->productVersion.Text = Application::ProductVersion;
      this->productVersion.BorderStyle = BorderStyle::Fixed3D;
      this->productVersion.BackColor = System::Drawing::Color::White;
      this->productVersion.ForeColor = System::Drawing::Color::Black;
      this->productVersion.Location = Point(120, 70);
      this->productVersion.TextAlign = ContentAlignment::MiddleLeft;
      this->productVersion.Width = 170;

      this->Text = "Form with assembly info";
      this->Controls().AddRange({this->company, this->product, this->version, this->companyName, this->productName, this->productVersion});
      this->ClientSize = System::Drawing::Size(300, 105);
    }

  private:
    Label company;
    Label product;
    Label version;

    Label companyName;
    Label productName;
    Label productVersion;
  };
}

startup_(Examples::Form1);
