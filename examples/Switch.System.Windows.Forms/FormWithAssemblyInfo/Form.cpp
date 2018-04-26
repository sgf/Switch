#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace FormExample {
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
      this->companyName.Location = Point(120, 10);
      this->companyName.Width = 170;

      this->productName.Text = Application::ProductName;
      this->productName.BorderStyle = BorderStyle::Fixed3D;
      this->productName.Location = Point(120, 40);
      this->productName.Width = 170;

      this->productVersion.Text = Application::ProductVersion;
      this->productVersion.BorderStyle = BorderStyle::Fixed3D;
      this->productVersion.Location = Point(120, 70);
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

startup_(FormExample::Form1);
