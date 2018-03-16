/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/Static.hpp>
#include <Switch/System/EventHandler.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Form.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Provides static methods and properties to manage an application, such as methods to start and stop an application, to process Windows messages, and properties to get information about an application. This class cannot be inherited.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks The Application class has methods to start and stop applications and threads, and to process Windows messages, as follows:
        /// * Run starts an application message loop on the current thread and, optionally, makes a form visible.
        /// * Exit or ExitThread stops a message loop.
        /// * DoEvents processes messages while your program is in a loop.
        /// * AddMessageFilter adds a message filter to the application message pump to monitor Windows messages.
        /// * IMessageFilter lets you stop an event from being raised or perform special operations before invoking an event handler.
        /// @remarks This class has CurrentCulture and CurrentInputLanguage properties to get or set culture information for the current thread.
        /// @remarks You cannot create an instance of this class.
        /// @par Example
        /// The following code example demonstrate the use of Application class.
        /// @include Application.cpp
        class system_windows_forms_export_ Application static_ {
        public:
          /// @brief Occurs when the application finishes processing and is about to enter the idle state.
          /// @remarks If you have tasks that you must perform before the thread becomes idle, attach them to this event.
          /// @par Caution
          /// Because this is a static event, you must detach your event handlers when your application is disposed, or memory leaks will result.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Idle event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a Windows Form and make sure that the event handler is associated with the Idle event.
          /// @code
          /// void Application_Idle(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Application::Idle event.");
          /// }
          /// @endcode
          static EventHandler Idle;

          /// @brief Enables visual styles for the application.
          /// @remarks This method enables visual styles for the application. Visual styles are the colors, fonts, and other visual elements that form an operating system theme. Controls will draw with visual styles if the control and the operating system support it. To have an effect, EnableVisualStyles() must be called before creating any controls in the application; typically, EnableVisualStyles() is the first line in the Main function. A separate manifest is not required to enable visual styles when calling EnableVisualStyles().
          /// @par Examples
          /// The following code example demonstrates calling EnableVisualStyles in the Main function to enable visual styles for the application.
          /// @include ApplicationEnableVisualStyle.cpp
          static void EnableVisualStyles();

          /// @brief Informs all message pumps that they must terminate, and then closes all application windows after the messages have been processed.
          /// @remarks The Exit method stops all running message loops on all threads and closes all windows of the application. This method does not necessarily force the application to exit. The Exit method is typically called from within a message loop, and forces Run to return. To exit a message loop for the current thread only, call ExitThread.
          /// @remarks Exit raises the following events and performs the associated conditional actions:
          /// * A FormClosing event is raised for every form represented by the OpenForms property. This event can be canceled by setting the Cancel property of their FormClosingEventArgs parameter to true.
          /// * If one of more of the handlers cancels the event, then Exit returns without further action. Otherwise, a FormClosed event is raised for every open form, then all running message loops and forms are closed.
          /// @note The Exit method does not raise the Closed and Closing events
          /// @par Examples
          /// The following code example lists numbers in a list box on a form. Each time you click button1, the application adds another number to the list.<br><br>
          /// The Main method calls Run to start the application, which creates the form, listBox1, and button1. When the user clicks button1, the button1_Click method adds numbers one to three to the list box, and displays a MessageBox. If the user clicks No on the MessageBox, the button1_Click method adds another number to the list. If the user clicks Yes, the application calls Exit, to process all remaining messages in the queue and then to quit.<br><br>
          /// The example requires that listBox1 and button1 have been instantiated and placed on a form.
          /// @code
          /// static void Main(const Array<string>& args) {
          ///   // Starts the application.
          ///   Application::Run(Form1());
          /// }
          ///
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   // Populates a list box with three numbers.
          ///   int i = 3;
          ///   for(int j = 1; j <= i; j++) {
          ///     listBox1.Items().Add(j);
          ///   }
          ///
          ///   /* Determines whether the user wants to exit the application.
          ///    * If not, adds another number to the list box. */
          ///   while (MessageBox::Show("Exit application?", "", MessageBoxButtons::YesNo) == DialogResult::No) {
          ///     // Increments the counter ands add the number to the list box.
          ///     i++;
          ///     listBox1.Items().Add(i);
          ///   }
          ///
          ///   // The user wants to exit the application. Close everything down.
          ///   Application::Exit();
          /// }
          /// @endcode
          static void Exit();

          /// @brief Begins running a standard application message loop on the current thread, without a form.
          /// @exception InvalidOperationException A main message loop is already running on this thread.
          /// @remarks In a Win32-based or Windows Forms application, a message loop is a routine in code that processes user events, such as mouse clicks and keyboard strokes. Every running Windows-based application requires an active message loop, called the main message loop. When the main message loop is closed, the application exits. In Windows Forms, this loop is closed when the Exit method is called, or when the ExitThread method is called on the thread that is running the main message loop.
          /// @remarks Most Windows Forms developers will not need to use this version of the method. You should use the Run(Form) overload to start an application with a main form, so that the application terminates when the main form is closed. For all other situations, use the Run(ApplicationContext) overload, which supports supplying an ApplicationContext object for better control over the lifetime of the application.
          static void Run() {
            Init();
            MessageLoop();
          }

          /// @brief Begins running a standard application message loop on the current thread, and makes the specified form visible.
          /// @param mainForm A Form that represents the form to make visible.
          /// @remarks Typically, the main function of an application calls this method and passes to it the main window of the application.
          /// @remarks This method adds an event handler to the mainForm parameter for the Closed event. The event handler calls ExitThread to clean up the application.
          /// @par Examples
          /// The following code example lists numbers in a list box on a form. Each time you click button1, the application adds another number to the list.<br><br>
          /// The Main method calls Run to start the application, which creates the form, listBox1, and button1. When the user clicks button1, the button1_Click method adds numbers one to three to the list box, and displays a MessageBox. If the user clicks No on the MessageBox, the button1_Click method adds another number to the list. If the user clicks Yes, the application calls Exit, to process all remaining messages in the queue and then to quit.<br><br>
          /// The example requires that listBox1 and button1 have been instantiated and placed on a form.
          /// @code
          /// static void Main(const Array<string>& args) {
          ///   // Starts the application.
          ///   Application::Run(Form1());
          /// }
          ///
          /// void button1_Click(const object& sender, const System::EventArgs& e) {
          ///   // Populates a list box with three numbers.
          ///   int i = 3;
          ///   for(int j = 1; j <= i; j++) {
          ///     listBox1.Items().Add(j);
          ///   }
          ///
          ///   /* Determines whether the user wants to exit the application.
          ///    * If not, adds another number to the list box. */
          ///   while (MessageBox::Show("Exit application?", "", MessageBoxButtons::YesNo) == DialogResult::No) {
          ///     // Increments the counter ands add the number to the list box.
          ///     i++;
          ///     listBox1.Items().Add(i);
          ///   }
          ///
          ///   // The user wants to exit the application. Close everything down.
          ///   Application::Exit();
          /// }
          /// @endcode
          template <typename TForm>
          static void Run(const TForm& mainForm) {as<System::Windows::Forms::Form>(mainForm).ShowDialog();}

          /// @brief Sets the application-wide default for the UseCompatibleTextRendering property defined on certain controls.
          /// @param defaultValue The default value to use for new controls. If true, new controls that support UseCompatibleTextRendering use the GDI+ based Graphics class for text rendering; if false, new controls use the GDI based TextRenderer class.
          /// @exception InvalidOperationException You can only call this method before the first window is created by your Windows Forms application.
          /// @remarks Certain Windows Forms controls can render their text using either the TextRenderer class, which is based on the GDI graphics library, or the Graphics class, which is based on the GDI+ graphics library. This change was made in the .NET Framework 2.0 because of performance and localization issues with GDI+. Use SetCompatibleTextRenderingDefault to set the default value of the UseCompatibleTextRendering property for controls that support it.
          /// @remarks The UseCompatibleTextRendering property is intended to provide visual compatibility between Windows Forms controls that render text using the TextRenderer class and .NET Framework 1.0 and .NET Framework 1.1 applications that perform custom text rendering using the Graphics class. In most cases, if your application is not being upgraded from .NET Framework 1.0 or .NET Framework 1.1, it is recommended that you leave UseCompatibleTextRendering set to the default value of false.
          /// @remarks The GDI based TextRenderer class was introduced in the .NET Framework 2.0 to improve performance, make text look better, and improve support for international fonts. In earlier versions of the .NET Framework, the GDI+ based Graphics class was used to perform all text rendering. GDI calculates character spacing and word wrapping differently from GDI+. In a Windows Forms application that uses the Graphics class to render text, this could cause the text for controls that use TextRenderer to appear different from the other text in the application. To resolve this incompatibility, you can set the UseCompatibleTextRendering property to true. To set UseCompatibleTextRendering to true for all supported controls in the application, call the SetCompatibleTextRenderingDefault method with a parameter of true.
          /// @remarks You should never call this method if your Windows Forms code is hosted in another application, such as Internet Explorer. Only call this method in stand-alone Windows Forms applications.
          /// @par Examples
          /// @code
          /// class Program static_ {
          /// public:
          ///   /// The main entry point for the application.
          ///   static void Main() {
          ///     Application::EnableVisualStyles();
          ///     Application::SetCompatibleTextRenderingDefault(false);
          ///     Application::Run(Form1());
          ///   }
          /// }
          ///
          /// startup_(Program);
          /// @endcode
          static void SetCompatibleTextRenderingDefault(bool defaultValue);

        private:
          /// @cond
          friend class Form;
          /// @endcond
          static void AddForm();
          static void Init();
          static void MessageLoop();
          static ref<Form> mainForm;
        };
      }
    }
  }
}
