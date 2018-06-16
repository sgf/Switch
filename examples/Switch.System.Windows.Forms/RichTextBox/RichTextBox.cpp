#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Windows::Forms;

namespace Examples {
  class Form1: Form {
  private:
    RichTextBox richTextBox1;
    Button button1;
    RichTextBox richTextBox2;
    Button button2;
    SaveFileDialog saveFileDialog1;
    
  public:
    Form1() {
      this->SuspendLayout();
      this->richTextBox1.Location = System::Drawing::Point(24, 64);
      this->richTextBox1.Name = "richTextBox1";
      this->richTextBox1.TabIndex = 0;
      this->richTextBox1.Text = "Type something here.";
      this->button1.Location = System::Drawing::Point(96, 16);
      this->button1.Name = "button1";
      this->button1.Size = System::Drawing::Size(96, 24);
      this->button1.TabIndex = 1;
      this->button1.Text = "Save To Stream";
      this->button1.Click += EventHandler(*this, &Form1::button1_Click);
      this->richTextBox2.Location = System::Drawing::Point(152, 64);
      this->richTextBox2.Name = "richTextBox2";
      this->richTextBox2.TabIndex = 3;
      this->richTextBox2.Text =
      "It will be added to the stream and appear here.";
      this->button2.Location = System::Drawing::Point(104, 200);
      this->button2.Name = "button2";
      this->button2.Size = System::Drawing::Size(88, 32);
      this->button2.TabIndex = 4;
      this->button2.Text = "Save Stream To File";
      this->button2.Click += EventHandler(*this, &Form1::button2_Click);
      this->ClientSize = System::Drawing::Size(292, 266);
      this->Controls().Add(this->button2);
      this->Controls().Add(this->richTextBox2);
      this->Controls().Add(this->button1);
      this->Controls().Add(this->richTextBox1);
      this->Name = "Form1";
      this->Text = "Form1";
      this->ResumeLayout(false);
    }
    
    static void Main() {
      Application::Run(Form1());
    }
    
  private:
    // Declare a new memory stream.
    MemoryStream userInput;
    
    // Save the content of richTextBox1 to the memory stream,
    // appending a LineFeed character.
    void button1_Click(const Object& sender, const EventArgs& e) {
      richTextBox1.SaveFile(userInput, RichTextBoxStreamType::PlainText);
      userInput.WriteByte(13);
      
      // Display the entire contents of the stream,
      // by setting its position to 0, to richTextBox2.
      userInput.Position = 0;
      richTextBox2.LoadFile(userInput, RichTextBoxStreamType::PlainText);
    }
    
    // Shows the use of a SaveFileDialog to save a MemoryStream to a file.
    void button2_Click(const Object& sender, const EventArgs& e) {
      // Set the properties on saveFileDialog1 so the user is
      // prompted to create the file if it doesn't exist
      // or overwrite the file if it does exist.
      saveFileDialog1.CreatePrompt = true;
      saveFileDialog1.OverwritePrompt = true;
      
      // Set the file name to myText.txt, set the type filter
      // to text files, and set the initial directory to the
      // MyDocuments folder.
      saveFileDialog1.FileName = "myText";
      // DefaultExt is only used when "All files" is selected from
      // the filter box and no extension is specified by the user.
      saveFileDialog1.DefaultExt = "txt";
      saveFileDialog1.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
      saveFileDialog1.InitialDirectory =
      Environment.GetFolderPath(Environment::SpecialFolder::MyDocuments);
      
      // Call ShowDialog and check for a return value of DialogResult.OK,
      // which indicates that the file was saved.
      DialogResult result = saveFileDialog1.ShowDialog();
      Stream fileStream;
      
      if (result == DialogResult::OK) {
        // Open the file, copy the contents of memoryStream to fileStream,
        // and close fileStream. Set the memoryStream.Position value to 0
        // to copy the entire stream.
        fileStream = saveFileDialog1.OpenFile();
        userInput.Position = 0;
        userInput.WriteTo(fileStream);
        fileStream.Close();
      }
    }
  };
}

startup_(Examples::Form1);

