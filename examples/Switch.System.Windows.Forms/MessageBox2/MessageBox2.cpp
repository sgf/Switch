#include <Switch/Switch>

using namespace System;
using namespace System::Windows::Forms;

namespace MessageBoxExample {
  class Form1 : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Form1());
    }

    Form1() {
      this->labelCaption.Text = "Caption :";
      this->labelCaption.Location = System::Drawing::Point(10, 13);
      this->labelCaption.Width = 50;

      this->editCaption.Text = "Switch";
      this->editCaption.Location = System::Drawing::Point(70, 10);
      this->editCaption.Width = 350;
      this->editCaption.Height = 20;
      this->editCaption.BackColor = System::Drawing::Color::White;

      this->labelMessage.Text = "Message :";
      this->labelMessage.Location = System::Drawing::Point(10, 43);
      this->labelMessage.Width = 50;

      this->editMessage.Text = "It's fantastic !";
      this->editMessage.Location = System::Drawing::Point(70, 40);
      this->editMessage.Width = 350;
      this->editMessage.Height = 20;
      this->editMessage.BackColor = System::Drawing::Color::White;

      this->radioButtonOk.Text = "Ok";
      this->radioButtonOk.Location = System::Drawing::Point(10, 30);
      this->radioButtonOk.Checked = true;
      this->radioButtonOk.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxButtons = MessageBoxButtons::OK;
      };

      this->radioButtonOkCancel.Text = "OkCancel";
      this->radioButtonOkCancel.Location = System::Drawing::Point(10, 60);
      this->radioButtonOkCancel.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxButtons = MessageBoxButtons::OKCancel;
      };

      this->radioButtonAbortRetryIgnore.Text = "AbortRetryIgnore";
      this->radioButtonAbortRetryIgnore.Location = System::Drawing::Point(10, 90);
      this->radioButtonAbortRetryIgnore.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxButtons = MessageBoxButtons::AbortRetryIgnore;
      };

      this->radioButtonYesNoCancel.Text = "YesNoCancel";
      this->radioButtonYesNoCancel.Location = System::Drawing::Point(10, 120);
      this->radioButtonYesNoCancel.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxButtons = MessageBoxButtons::YesNoCancel;
      };

      this->radioButtonYesNo.Text = "YesNo";
      this->radioButtonYesNo.Location = System::Drawing::Point(10, 150);
      this->radioButtonYesNo.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxButtons = MessageBoxButtons::YesNo;
      };

      this->radioButtonRetryCancel.Text = "RetryCancel";
      this->radioButtonRetryCancel.Location = System::Drawing::Point(10, 180);
      this->radioButtonRetryCancel.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxButtons = MessageBoxButtons::RetryCancel;
      };

      this->groupBoxMessageBoxButtons.Text = "MessageBoxButtons";
      this->groupBoxMessageBoxButtons.Location = System::Drawing::Point(10, 70);
      this->groupBoxMessageBoxButtons.Height = 310;
      this->groupBoxMessageBoxButtons.Controls().AddRange({this->radioButtonOk, this->radioButtonOkCancel, this->radioButtonAbortRetryIgnore, this->radioButtonYesNoCancel, this->radioButtonYesNo, this->radioButtonRetryCancel});

      this->radioButtonNone.Text = "None";
      this->radioButtonNone.Location = System::Drawing::Point(10, 30);
      this->radioButtonNone.Checked = true;
      this->radioButtonNone.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::None;
      };

      this->radioButtonHand.Text = "Hand";
      this->radioButtonHand.Location = System::Drawing::Point(10, 60);
      this->radioButtonHand.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Hand;
      };

      this->radioButtonStop.Text = "Stop";
      this->radioButtonStop.Location = System::Drawing::Point(10, 90);
      this->radioButtonStop.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Stop;
      };

      this->radioButtonError.Text = "Error";
      this->radioButtonError.Location = System::Drawing::Point(10, 120);
      this->radioButtonError.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Error;
      };

      this->radioButtonQuestion.Text = "Question";
      this->radioButtonQuestion.Location = System::Drawing::Point(10, 150);
      this->radioButtonQuestion.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Question;
      };

      this->radioButtonExclamation.Text = "Exclamation";
      this->radioButtonExclamation.Location = System::Drawing::Point(10, 180);
      this->radioButtonExclamation.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Exclamation;
      };

      this->radioButtonWarning.Text = "Warning";
      this->radioButtonWarning.Location = System::Drawing::Point(10, 210);
      this->radioButtonWarning.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Warning;
      };

      this->radioButtonAsterisk.Text = "Asterisk";
      this->radioButtonAsterisk.Location = System::Drawing::Point(10, 240);
      this->radioButtonAsterisk.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Asterisk;
      };

      this->radioButtonInformation.Text = "Information";
      this->radioButtonInformation.Location = System::Drawing::Point(10, 270);
      this->radioButtonInformation.Click += delegate_(const object& sender, const EventArgs& e) {
        this->messageBoxIcon = MessageBoxIcon::Information;
      };

      this->groupBoxMessageBoxIcon.Text = "MessageBoxIcons";
      this->groupBoxMessageBoxIcon.Location = System::Drawing::Point(220, 70);
      this->groupBoxMessageBoxIcon.Height = 310;
      this->groupBoxMessageBoxIcon.Controls().AddRange({this->radioButtonNone, this->radioButtonHand, this->radioButtonStop, this->radioButtonError, this->radioButtonQuestion, this->radioButtonExclamation, this->radioButtonWarning, this->radioButtonAsterisk, this->radioButtonInformation});

      this->buttonTryIt.Location = System::Drawing::Point(10, 390);
      this->buttonTryIt.Width = 100;
      this->buttonTryIt.Text = "Try it";
      this->buttonTryIt.Click += delegate_(const object & sender, const EventArgs & e) {
        System::Windows::Forms::DialogResult result = MessageBox::Show(this->editMessage.Text, this->editCaption.Text, this->messageBoxButtons, this->messageBoxIcon);
        this->labelDialogResult.Text = string::Format("DialogResult = {0}", result);
      };

      this->labelDialogResult.Text = "DialogResult = ";
      this->labelDialogResult.Location = System::Drawing::Point(130, 395);
      this->labelDialogResult.Width = 200;

      this->Text = "MessageBox example";
      this->ClientSize = System::Drawing::Size(430, 430);
      this->Controls().AddRange({this->labelCaption, this->editCaption, this->labelMessage, this->editMessage, this->groupBoxMessageBoxButtons, this->groupBoxMessageBoxIcon, this->buttonTryIt, this->labelDialogResult});
    }

  private:
    Label labelCaption;
    Label editCaption;
    Label labelMessage;
    Label editMessage;
    RadioButton radioButtonOk;
    RadioButton radioButtonOkCancel;
    RadioButton radioButtonAbortRetryIgnore;
    RadioButton radioButtonYesNoCancel;
    RadioButton radioButtonYesNo;
    RadioButton radioButtonRetryCancel;
    GroupBox groupBoxMessageBoxButtons;
    RadioButton radioButtonNone;
    RadioButton radioButtonHand;
    RadioButton radioButtonStop;
    RadioButton radioButtonError;
    RadioButton radioButtonQuestion;
    RadioButton radioButtonExclamation;
    RadioButton radioButtonWarning;
    RadioButton radioButtonAsterisk;
    RadioButton radioButtonInformation;
    GroupBox groupBoxMessageBoxIcon;
    Button buttonTryIt;
    Label labelDialogResult;
    MessageBoxButtons messageBoxButtons = MessageBoxButtons::OK;
    MessageBoxIcon messageBoxIcon = MessageBoxIcon::None;
  };
}

startup_(MessageBoxExample::Form1);
