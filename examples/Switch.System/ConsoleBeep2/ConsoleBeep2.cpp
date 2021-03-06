#include <Switch/Switch>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
    // Define the frequencies of notes in an octave, as well as
    // silence (rest).
    enum class Tone {
      REST   = 0,
      GbelowC = 196,
      A      = 220,
      Asharp = 233,
      B      = 247,
      C      = 262,
      Csharp = 277,
      D      = 294,
      Dsharp = 311,
      E      = 330,
      F      = 349,
      Fsharp = 370,
      G      = 392,
      Gsharp = 415,
    };

    // Define the duration of a note in units of milliseconds.
    enum class Duration {
      WHOLE     = 1600,
      HALF      = WHOLE / 2,
      QUARTER   = HALF / 2,
      EIGHTH    = QUARTER / 2,
      SIXTEENTH = EIGHTH / 2,
    };

    // Define a note as a frequency (tone) and the amount of
    // time (duration) the note plays.
    struct Note : public object {
      Tone     toneVal;
      Duration durVal;

      // Define a constructor to create a specific note.
      Note(Tone frequency, Duration time) {
        toneVal = frequency;
        durVal  = time;
      };

      Note() : toneVal((Tone)0), durVal((Duration)0) {}
      Note(const Note& note) : toneVal(note.toneVal), durVal(note.durVal) {}
      Note& operator=(const Note& note) {
        this->toneVal = note.toneVal;
        this->durVal = note.durVal;
        return *this;
      }

      // Define properties to return the note's tone and duration.
      property_<Tone, readonly_> NoteTone { get_{ return toneVal; } };
      property_<Duration, readonly_> NoteDuration { get_{ return durVal; } };
    };

  public:
    // The main entry point for the application.
    static void Main() {
      // Declare the first few notes of the song, "Mary Had A Little Lamb".
      Array<Note> Mary = {
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::GbelowC, Duration::QUARTER),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::B, Duration::HALF),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::A, Duration::HALF),
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::D, Duration::QUARTER),
        Note(Tone::D, Duration::HALF)
      };
      // Play the song
      Play(Mary);
    }

  protected:
    // Play the notes in a song.
    static void Play(const Array<Note>& tune) {
      for (Note n : tune) {
        if (n.NoteTone == Tone::REST)
          Thread::Sleep((int)n.NoteDuration());
        else
          Console::Beep((int)n.NoteTone(), (int)n.NoteDuration());
      }
    }
  };
}

startup_(Examples::Program);

// This code produces the following result:
//
// This example plays the first few notes of "Mary Had A Little Lamb"
// through the console speaker.
