/// @file
/// @brief Contains Switch::System::Windows::Forms::Application class.
#pragma once

#include <Switch/Static.hpp>
#include <Switch/Microsoft/Win32/RegistryKey.hpp>
#include <Switch/System/EventHandler.hpp>
#include <Switch/System/Threading/ThreadExceptionEventHandler.hpp>
#include "../../../SystemWindowsFormsExport.hpp"
#include "Form.hpp"
#include "FormCollection.hpp"

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
          /// @brief Gets a value indicating whether the caller can quit this application.
          /// @return true if the caller can quit this application; otherwise, false.
          /// @remarks This property returns false if it is called from a Control being hosted within a Web browser. Thus, the Control cannot quit the Application.
          static property_<bool, readonly_> AllowQuit;

          /// @brief Gets the path for the application data that is shared among all users.
          /// @return The path for the application data that is shared among all users.
          /// @remarks If a path does not exist, one is created in the following format:
          /// @remarks Base Path\CompanyName\ProductName\ProductVersion
          /// @remarks ProductVersion first looks to see if the assembly containing the main executable has the AssemblyInformationalVersion attribute on it. If this attribute exists, it is used for both ProductVersion and CommonAppDataPath. If this attribute does not exist, both properties use the version of the executable file instead.
          /// @remarks The path will be different depending on whether the Windows Forms application is deployed using ClickOnce. ClickOnce applications are stored in a per-user application cache in the C:\Documents and Settings\username directory. For more information, see Accessing Local and Remote Data in ClickOnce Applications.
          static property_<string, readonly_> CommonAppDataPath;
          
          /// @brief Gets the registry key for the application data that is shared among all users.
          /// @return A RegistryKey representing the registry key of the application data that is shared among all users.
          /// @remarks If the key does not exist, it is created in the following format:
          /// @remarks LocalMachine\Software\CompanyName\ProductName\ProductVersion
          static property_<Microsoft::Win32::RegistryKey, readonly_> CommonAppDataRegistry;
          
          /// @brief Gets the company name associated with the application.
          /// @return The company name.
          /// @par Examples
          /// The following code example gets this property and displays its value in a text box. The example requires that textBox1 has been placed on a form.
          /// @code
          /// void PrintCompanyName() {
          ///   textBox1::Text = string::Format("The company name is: {0}", Application::CompanyName);
          /// }
          /// @endcode
          static property_<string, readonly_> CompanyName;

          /// @brief Gets the path for the executable file that started the application, including the executable name.
          /// @return The path and executable name for the executable file that started the application.<br><br>
          /// This path will be different depending on whether the Windows Forms application is deployed using ClickOnce. ClickOnce applications are stored in a per-user application cache in the C:\Documents and Settings\username directory. For more information, see Accessing Local and Remote Data in ClickOnce Applications.
          static property_<string, readonly_> ExecutablePath;

          /// @brief Gets the path for the application data of a local, non-roaming user.
          /// @return The path for the application data of a local, non-roaming user.
          /// @remarks A local user is one whose user profile is stored on the system on which the user logged on. If a path does not exist, one is created in the following format:
          /// @remarks Base Path\CompanyName\ProductName\ProductVersion
          /// @remarks A typical base path is C:\Documents and Settings\username\Local Settings\Application Data. This path will be different, however, if the Windows Forms application is deployed by using ClickOnce. ClickOnce creates its own application data directory that is isolated from all other applications. For more information, see Accessing Local and Remote Data in ClickOnce Applications.
          static property_<string, readonly_> LocalUserAppDataPath;
          
          /// @brief Gets a value indicating whether a message loop exists on this thread.
          /// @return true if a message loop exists; otherwise, false.
          /// @remarks When hosting Windows Forms in other environments, such as unmanaged applications, this property will always return false. Use RegisterMessageLoop to instruct Windows Forms if the hosting environment still has an active message loop.
          static property_<bool, readonly_> MessageLoop;

          /// @brief Gets a collection of open forms owned by the application.
          /// @return A FormCollection containing all the currently open forms owned by this application.
          /// @remarks The OpenForms property represents a read-only collection of forms owned by the application. This collection can be searched by index position or by the Name of the Form.
          static property_<FormCollection, readonly_> OpenForms;
          
          /// @brief Gets the product name associated with this application.
          /// @return The product name.
          /// @remarks ProductName is taken from the metadata of the assembly containing the main form of the current application. You can set it by setting AssemblyProductAttribute inside of your assembly manifest. For more information, see Assembly Manifest.
          /// @par Examples
          /// The following code example gets this property and displays its value in a text box. The example requires that textBox1 has been placed on a form.
          /// @code
          /// void PrintProductName() {
          ///   textBox1.Text = string::Format("The product name is: {0}", Application::ProductName);
          /// }
          /// @endcode
          static property_<string, readonly_> ProductName;

          /// @brief Gets the product version associated with this application.
          /// @return The product version.
          /// @remarks Typically, a version number displays as major number.minor number.build number.private part number. You can set it explicitly by setting the assembly version within your assembly manifest. For more information, see Assembly Manifest.
          /// @remarks ProductVersion first looks to see if the assembly containing the main executable has the AssemblyInformationalVersion attribute on it. If this attribute exists, it is used for both ProductVersion and CommonAppDataPath. If this attribute does not exist, both properties use the version of the executable file instead.
          /// @par Examples
          /// The following code example gets this property and displays its value in a text box. The example requires that textBox1 has been placed on a form.
          /// @code
          /// void PrintProductVersion() {
          ///   textBox1.Text = strring::Format("The product version is: {0}", Application::ProductVersion;
          /// }
          /// @endcode
          static property_<string, readonly_> ProductVersion;
          
          /// @brief Occurs when the application is about to shut down.
          /// @remarks You must attach the event handlers to the Exit event to perform unhandled, required tasks before the application stops running. You can close files opened by this application, or dispose of objects that garbage collection did not reclaim.
          /// @remarks Because this is a static event, you must detach any event handlers attached to this event in the ApplicationExit event handler itself. If you do not detach these handlers, they will remain attached to the event and continue to consume memory.
          static EventHandler ApplicationExit;

          /// @brief Occurs when the application is about to enter a modal state.
          /// @warning Because this is a static event, you must detach your event handlers when your application is disposed, or memory leaks will result.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the EnterThreadModal event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a Windows Forms and ensure that the event handler is associated with the EnterThreadModal event.
          /// @code
          /// void Application_EnterThreadModal(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Application::EnterThreadModal event.");
          /// }
          /// @endcode
          static EventHandler EnterThreadModal;

          /// @brief Occurs when the application finishes processing and is about to enter the idle state.
          /// @remarks If you have tasks that you must perform before the thread becomes idle, attach them to this event.
          /// @warning Because this is a static event, you must detach your event handlers when your application is disposed, or memory leaks will result.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the Idle event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a Windows Form and make sure that the event handler is associated with the Idle event.
          /// @code
          /// void Application_Idle(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Application::Idle event.");
          /// }
          /// @endcode
          static EventHandler Idle;

          /// @brief Occurs when the application is about to leave a modal state.
          /// @warning Because this is a static event, you must detach your event handlers when your application is disposed, or memory leaks will result.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the LeaveThreadModal event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a Windows Forms and ensure that the event handler is associated with the LeaveThreadModal event.
          /// @code
          /// void Application_LeaveThreadModal(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Application::LeaveThreadModal event.");
          /// }
          /// @endcode
          static EventHandler LeaveThreadModal;
          
          /// @brief Occurs when an untrapped thread exception is thrown.
          /// @remarks This event allows your Windows Forms application to handle otherwise unhandled exceptions that occur in Windows Forms threads. Attach your event handlers to the ThreadException event to deal with these exceptions, which will leave your application in an unknown state. Where possible, exceptions should be handled by a structured exception handling block.
          /// @remarks You can change whether this callback is used for unhandled Windows Forms thread exceptions by setting SetUnhandledExceptionMode. To catch exceptions that occur in threads not created and owned by Windows Forms, use the UnhandledException event handler.
          /// @note To guarantee that no activations of this event are missed, you must attach a handler before you call Application.Run.
          /// @warning Because this is a static event, you must detach your event handlers when your application is disposed, or memory leaks will result.
          static System::Threading::ThreadExceptionEventHandler ThreadException;
          
          /// @brief Occurs when a thread is about to shut down. When the main thread for an application is about to be shut down, this event is raised first, followed by an ApplicationExit event.
          /// @remarks You must attach the event handlers to the ThreadExit event to perform any unhandled, required tasks before the thread stops running. Close files opened by this thread, or dispose of objects that the garbage collector did not reclaim.
          /// @warning Because this is a static event, you must detach your event handlers when your application is disposed, or memory leaks will result.
          /// @par Examples
          /// The following code example demonstrates the use of this member. In the example, an event handler reports on the occurrence of the ThreadExit event. This report helps you to learn when the event occurs and can assist you in debugging. To report on multiple events or on events that occur frequently, consider replacing MessageBox.Show with Console.WriteLine or appending the message to a multiline TextBox.<br><br>
          /// To run the example code, paste it into a Windows Forms and ensure that the event handler is associated with the ThreadExit event.
          /// @code
          /// void Application_ThreadExit(const Object& sender, const EventArgs& e) {
          ///   MessageBox::Show("You are in the Application::ThreadExit event.");
          /// }
          /// @endcode
          static EventHandler ThreadExit;

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
          
          /// @brief Exits the message loop on the current thread and closes all windows on the thread.
          /// @remarks Use this method to exit the message loop of the current thread. This method causes the call to Run for the current thread to return. To exit the entire application, call Exit.
          static void ExitThread();

          /// @brief Raises the ThreadException event.
          /// @param exception An Exception that represents the exception that was thrown.
          /// @remarks Call OnThreadException to raise an exception that will halt processing of the application.
          /// @remarks The Application class has a ThreadException event. You can attach an event handler to this event to do whatever custom processing you need for unhandled exceptions. If you do not attach an event handler, OnThreadException will execute the default behavior, which involves displaying a dialog box to inform the user that there has been an error.
          /// @remarks OnThreadException only implements default exception behavior for unhandled exceptions that occur on threads owned by Windows Forms. Unhandled exceptions on other threads are handled by the UnhandledException event.
          static void OnThreadException(const Exception& exception);

          /// @brief Begins running a standard application message loop on the current thread, without a form.
          /// @exception InvalidOperationException A main message loop is already running on this thread.
          /// @remarks In a Win32-based or Windows Forms application, a message loop is a routine in code that processes user events, such as mouse clicks and keyboard strokes. Every running Windows-based application requires an active message loop, called the main message loop. When the main message loop is closed, the application exits. In Windows Forms, this loop is closed when the Exit method is called, or when the ExitThread method is called on the thread that is running the main message loop.
          /// @remarks Most Windows Forms developers will not need to use this version of the method. You should use the Run(Form) overload to start an application with a main form, so that the application terminates when the main form is closed. For all other situations, use the Run(ApplicationContext) overload, which supports supplying an ApplicationContext object for better control over the lifetime of the application.
          static void Run();

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
          static void Run(ref<System::Windows::Forms::Form> form);

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
          static void RunMessageLoop();
          static ref<Form> mainForm;
        };
      }
    }
  }
}
