/// @file
/// @brief Contains Switch::System::Windows::Forms::Timer class.
#pragma once

#include <Switch/System/ComponentModel/Component.hpp>
#include <Switch/System/EventHandler.hpp>
#include <Switch/System/IntPtr.hpp>
#include "../../../SystemWindowsFormsExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Implements a timer that raises an event at user-defined intervals. This timer is optimized for use in Windows Forms applications and must be used in a window.
        /// @par Library
        /// Switch.System.Windows.Forms
        /// @remarks A Timer is used to raise an event at user-defined intervals. This Windows timer is designed for a single-threaded environment where UI threads are used to perform processing. It requires that the user code have a UI message pump available and always operate from the same thread, or marshal the call onto another thread.
        /// @remarks When you use this timer, use the Tick event to perform a polling operation or to display a splash screen for a specified period of time. Whenever the Enabled property is set to true and the Interval property is greater than zero, the Tick event is raised at intervals based on the Interval property setting.
        /// @remarks This class provides methods to set the interval, and to start and stop the timer.
        /// @note The Windows Forms Timer component is single-threaded, and is limited to an accuracy of 55 milliseconds. If you require a multithreaded timer with greater accuracy, use the Timer class in the System.Timers namespace.
        /// @par Examples
        /// The following code example implements a simple interval timer, which sets off an alarm every five seconds. When the alarm occurs, a MessageBox displays a count of the number of times the alarm has started and prompts the user whether the timer should continue to run.
        /// @code
        /// #include <Switch/Switch>
        ///
        /// class Class1 {
        /// private:
        ///   static System::Windows::Forms::Timer myTimer;
        ///   static int alarmCounter;
        ///   static bool exitFlag;
        ///
        ///   // This is the method to run when the timer is raised.
        ///   static void TimerEventProcessor(const object& myObject, const System::EventArgs& myEventArgs) {
        ///     myTimer.Stop();
        ///
        ///     // Displays a message box asking whether to continue running the timer.
        ///     if (System::Windows::Forms::MessageBox::Show("Continue running?", "Count is: "_s + alarmCounter, System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
        ///       // Restarts the timer and increments the counter.
        ///       alarmCounter += 1;
        ///       myTimer.Enabled = true;
        ///     } else {
        ///       // Stops the timer.
        ///       exitFlag = true;
        ///     }
        ///   }
        ///
        /// public:
        ///   static int Main() {
        ///     /* Adds the event and the event handler for the method that will
        ///      process the timer event to the timer. */
        ///     myTimer.Tick += System::EventHandler(&TimerEventProcessor);
        ///
        ///     // Sets the timer interval to 5 seconds.
        ///     myTimer.Interval = 5000;
        ///     myTimer.Start();
        ///
        ///     // Runs the timer, and raises the event.
        ///     while(exitFlag == false) {
        ///       // Processes all the events in the queue.
        ///       System::Windows::Forms::Application::DoEvents();
        ///     }
        ///     return 0;
        ///   }
        /// }
        ///
        /// System::Windows::Forms::Timer Class1::myTimer;
        /// int Class1::alarmCounter = 1;
        /// bool Class1::exitFlag = false;
        ///
        /// startup_(Class1);
        /// @endcode
        class system_windows_forms_export_ Timer : public System::ComponentModel::Component {
        public:
          /// @brief Initializes a new instance of the Timer class.
          /// @remarks When a new timer is created, it is disabled; that is, Enabled is set to false. To enable the timer, call the Start method or set Enabled to true.
          /// @remarks If the timer is disabled and the timer is out of scope, the timer will be disposed when garbage collection occurs. If the timer is enabled, even if it is out of scope, it is not subject to garbage collection.
          Timer() {}

          /// @cond
          ~Timer() {this->Enabled = false;}
          /// @endcond

          /// @brief Gets or sets whether the timer is running.
          /// @return true if the timer is currently enabled; otherwise, false. The default is false.
          /// @remarks The timer is not subject to garbage collection when the value is true.
          /// @remarks Calling the Start method is the same as setting Enabled to true. Likewise, calling the Stop method is the same as setting Enabled to false.
          /// @par Examples
          /// The following code example implements a simple interval timer, which sets off an alarm every five seconds. When the alarm occurs, a MessageBox displays a count of the number of times the alarm has started and prompts the user whether the timer should continue to run.
          /// @code
          /// #include <Switch/Switch>
          ///
          /// class Class1 {
          /// private:
          ///   static System::Windows::Forms::Timer myTimer;
          ///   static int alarmCounter;
          ///   static bool exitFlag;
          ///
          ///   // This is the method to run when the timer is raised.
          ///   static void TimerEventProcessor(const object& myObject, const System::EventArgs& myEventArgs) {
          ///     myTimer.Stop();
          ///
          ///     // Displays a message box asking whether to continue running the timer.
          ///     if (System::Windows::Forms::MessageBox::Show("Continue running?", "Count is: "_s + alarmCounter, System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
          ///       // Restarts the timer and increments the counter.
          ///       alarmCounter += 1;
          ///       myTimer.Enabled = true;
          ///     } else {
          ///       // Stops the timer.
          ///       exitFlag = true;
          ///     }
          ///   }
          ///
          /// public:
          ///   static int Main() {
          ///     /* Adds the event and the event handler for the method that will
          ///      process the timer event to the timer. */
          ///     myTimer.Tick += System::EventHandler(&TimerEventProcessor);
          ///
          ///     // Sets the timer interval to 5 seconds.
          ///     myTimer.Interval = 5000;
          ///     myTimer.Start();
          ///
          ///     // Runs the timer, and raises the event.
          ///     while(exitFlag == false) {
          ///       // Processes all the events in the queue.
          ///       System::Windows::Forms::Application::DoEvents();
          ///     }
          ///     return 0;
          ///   }
          /// }
          ///
          /// System::Windows::Forms::Timer Class1::myTimer;
          /// int Class1::alarmCounter = 1;
          /// bool Class1::exitFlag = false;
          ///
          /// startup_(Class1);
          /// @endcode
          property_<bool> Enabled {
            get_ {return this->enabled;},
            set_ {this->SetEnabled(value);}
          };

          /// @brief Gets or sets the time, in milliseconds, before the Tick event is raised relative to the last occurrence of the Tick event.
          /// @return An Int32 specifying the number of milliseconds before the Tick event is raised relative to the last occurrence of the Tick event. The value cannot be less than one.
          /// @remarks o get the number of seconds in the interval, divide this number by 1,000.
          /// @par Examples
          /// The following code example implements a simple interval timer, which sets off an alarm every five seconds. When the alarm occurs, a MessageBox displays a count of the number of times the alarm has started and prompts the user whether the timer should continue to run.
          /// @code
          /// #include <Switch/Switch>
          ///
          /// class Class1 {
          /// private:
          ///   static System::Windows::Forms::Timer myTimer;
          ///   static int alarmCounter;
          ///   static bool exitFlag;
          ///
          ///   // This is the method to run when the timer is raised.
          ///   static void TimerEventProcessor(const object& myObject, const System::EventArgs& myEventArgs) {
          ///     myTimer.Stop();
          ///
          ///     // Displays a message box asking whether to continue running the timer.
          ///     if (System::Windows::Forms::MessageBox::Show("Continue running?", "Count is: "_s + alarmCounter, System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
          ///       // Restarts the timer and increments the counter.
          ///       alarmCounter += 1;
          ///       myTimer.Enabled = true;
          ///     } else {
          ///       // Stops the timer.
          ///       exitFlag = true;
          ///     }
          ///   }
          ///
          /// public:
          ///   static int Main() {
          ///     /* Adds the event and the event handler for the method that will
          ///      process the timer event to the timer. */
          ///     myTimer.Tick += System::EventHandler(&TimerEventProcessor);
          ///
          ///     // Sets the timer interval to 5 seconds.
          ///     myTimer.Interval = 5000;
          ///     myTimer.Start();
          ///
          ///     // Runs the timer, and raises the event.
          ///     while(exitFlag == false) {
          ///       // Processes all the events in the queue.
          ///       System::Windows::Forms::Application::DoEvents();
          ///     }
          ///     return 0;
          ///   }
          /// }
          ///
          /// System::Windows::Forms::Timer Class1::myTimer;
          /// int Class1::alarmCounter = 1;
          /// bool Class1::exitFlag = false;
          ///
          /// startup_(Class1);
          /// @endcode
          property_<int32> Interval {
            get_ {return this->interval;},
            set_ {this->SetInterval(value);}
          };

          /// @brief Occurs when the specified timer interval has elapsed and the timer is enabled.
          /// @remarks Calling the Assert method on the Debug class from within the Tick event may not behave as expected, as displaying the assertion dialog box may cause Windows to raise the Tick event repeatedly. We recommend that you refrain from testing assertions within this event, and use the Write, WriteIf, WriteLine, or WriteLineIf methods instead.
          /// @remarks For more information about handling events, see Handling and Raising Events.
          /// @par Examples
          /// The following code example implements a simple interval timer, which sets off an alarm every five seconds. When the alarm occurs, a MessageBox displays a count of the number of times the alarm has started and prompts the user whether the timer should continue to run.
          /// @code
          /// #include <Switch/Switch>
          ///
          /// class Class1 {
          /// private:
          ///   static System::Windows::Forms::Timer myTimer;
          ///   static int alarmCounter;
          ///   static bool exitFlag;
          ///
          ///   // This is the method to run when the timer is raised.
          ///   static void TimerEventProcessor(const object& myObject, const System::EventArgs& myEventArgs) {
          ///     myTimer.Stop();
          ///
          ///     // Displays a message box asking whether to continue running the timer.
          ///     if (System::Windows::Forms::MessageBox::Show("Continue running?", "Count is: "_s + alarmCounter, System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
          ///       // Restarts the timer and increments the counter.
          ///       alarmCounter += 1;
          ///       myTimer.Enabled = true;
          ///     } else {
          ///       // Stops the timer.
          ///       exitFlag = true;
          ///     }
          ///   }
          ///
          /// public:
          ///   static int Main() {
          ///     /* Adds the event and the event handler for the method that will
          ///      process the timer event to the timer. */
          ///     myTimer.Tick += System::EventHandler(&TimerEventProcessor);
          ///
          ///     // Sets the timer interval to 5 seconds.
          ///     myTimer.Interval = 5000;
          ///     myTimer.Start();
          ///
          ///     // Runs the timer, and raises the event.
          ///     while(exitFlag == false) {
          ///       // Processes all the events in the queue.
          ///       System::Windows::Forms::Application::DoEvents();
          ///     }
          ///     return 0;
          ///   }
          /// }
          ///
          /// System::Windows::Forms::Timer Class1::myTimer;
          /// int Class1::alarmCounter = 1;
          /// bool Class1::exitFlag = false;
          ///
          /// startup_(Class1);
          /// @endcode
          Switch::System::EventHandler Tick;
          
          /// @brief Starts the timer.
          /// @remarks You can also start the timer by setting the Enabled property to true.
          /// @par Examples
          /// The following code example implements a simple interval timer, which sets off an alarm every five seconds. When the alarm occurs, a MessageBox displays a count of the number of times the alarm has started and prompts the user whether the timer should continue to run.
          /// @code
          /// #include <Switch/Switch>
          ///
          /// class Class1 {
          /// private:
          ///   static System::Windows::Forms::Timer myTimer;
          ///   static int alarmCounter;
          ///   static bool exitFlag;
          ///
          ///   // This is the method to run when the timer is raised.
          ///   static void TimerEventProcessor(const object& myObject, const System::EventArgs& myEventArgs) {
          ///     myTimer.Stop();
          ///
          ///     // Displays a message box asking whether to continue running the timer.
          ///     if (System::Windows::Forms::MessageBox::Show("Continue running?", "Count is: "_s + alarmCounter, System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
          ///       // Restarts the timer and increments the counter.
          ///       alarmCounter += 1;
          ///       myTimer.Enabled = true;
          ///     } else {
          ///       // Stops the timer.
          ///       exitFlag = true;
          ///     }
          ///   }
          ///
          /// public:
          ///   static int Main() {
          ///     /* Adds the event and the event handler for the method that will
          ///      process the timer event to the timer. */
          ///     myTimer.Tick += System::EventHandler(&TimerEventProcessor);
          ///
          ///     // Sets the timer interval to 5 seconds.
          ///     myTimer.Interval = 5000;
          ///     myTimer.Start();
          ///
          ///     // Runs the timer, and raises the event.
          ///     while(exitFlag == false) {
          ///       // Processes all the events in the queue.
          ///       System::Windows::Forms::Application::DoEvents();
          ///     }
          ///     return 0;
          ///   }
          /// }
          ///
          /// System::Windows::Forms::Timer Class1::myTimer;
          /// int Class1::alarmCounter = 1;
          /// bool Class1::exitFlag = false;
          ///
          /// startup_(Class1);
          /// @endcode
          void Start() {this->Enabled = true;}
          
          /// @brief Stops the timer.
          /// @remarks You can also stop the timer by setting the Enabled property to false. A Timer object may be enabled and disabled multiple times within the same application session.
          /// @remarks Calling Start after you have disabled a Timer by calling Stop will cause the Timer to restart the interrupted interval. If your Timer is set for a 5000-millisecond interval, and you call Stop at around 3000 milliseconds, calling Start will cause the Timer to wait 5000 milliseconds before raising the Tick event.
          /// @remarks Calling Stop on any Timer within a Windows Forms application can cause messages from other Timer components in the application to be processed immediately, because all Timer components operate on the main application thread. If you have two Timer components, one set to 700 milliseconds and one set to 500 milliseconds, and you call Stop on the first Timer, your application may receive an event callback for the second component first. If this proves problematic, consider using the Timer class in the System.Threading namespace instead.
          /// @par Examples
          /// The following code example implements a simple interval timer, which sets off an alarm every five seconds. When the alarm occurs, a MessageBox displays a count of the number of times the alarm has started and prompts the user whether the timer should continue to run.
          /// @code
          /// #include <Switch/Switch>
          ///
          /// class Class1 {
          /// private:
          ///   static System::Windows::Forms::Timer myTimer;
          ///   static int alarmCounter;
          ///   static bool exitFlag;
          ///
          ///   // This is the method to run when the timer is raised.
          ///   static void TimerEventProcessor(const object& myObject, const System::EventArgs& myEventArgs) {
          ///     myTimer.Stop();
          ///
          ///     // Displays a message box asking whether to continue running the timer.
          ///     if (System::Windows::Forms::MessageBox::Show("Continue running?", "Count is: "_s + alarmCounter, System::Windows::Forms::MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
          ///       // Restarts the timer and increments the counter.
          ///       alarmCounter += 1;
          ///       myTimer.Enabled = true;
          ///     } else {
          ///       // Stops the timer.
          ///       exitFlag = true;
          ///     }
          ///   }
          ///
          /// public:
          ///   static int Main() {
          ///     /* Adds the event and the event handler for the method that will
          ///      process the timer event to the timer. */
          ///     myTimer.Tick += System::EventHandler(&TimerEventProcessor);
          ///
          ///     // Sets the timer interval to 5 seconds.
          ///     myTimer.Interval = 5000;
          ///     myTimer.Start();
          ///
          ///     // Runs the timer, and raises the event.
          ///     while(exitFlag == false) {
          ///       // Processes all the events in the queue.
          ///       System::Windows::Forms::Application::DoEvents();
          ///     }
          ///     return 0;
          ///   }
          /// }
          ///
          /// System::Windows::Forms::Timer Class1::myTimer;
          /// int Class1::alarmCounter = 1;
          /// bool Class1::exitFlag = false;
          ///
          /// startup_(Class1);
          /// @endcode
          void Stop() {this->Enabled = false;}

        protected:
          /// @brief Raises the Tick event.
          /// @param e An EventArgs that contains the event data. This is always Empty.
          /// @remarks This method is called for each timer tick. It calls any methods that are added through Tick. If you are inheriting from Timer, you can override this method.
          /// @remarks Raising an event invokes the event handler through a delegate. For more information, see Handling and Raising Events.
          virtual void OnTick(const EventArgs& e);
          
        private:
          void SetEnabled(bool enabled);
          void SetInterval(int32 interval);

          int32 interval = 100;
          bool enabled = false;
          intptr handle = IntPtr::Zero;
          delegate<void> tick = delegate_ {
            this->OnTick(System::EventArgs::Empty);
          };
        };
      }
    }
  }
}
