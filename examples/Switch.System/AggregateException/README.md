# AggregateException

The following example catches the AggregateException exception and calls the Handle method to handle each exception it contains. Compiling and running the example with the first task1 variable should result in an AggregateException object that contains an UnauthorizedAccessException exception. Commenting out that line, uncommenting the second task1 variable, and compiling and running the example produces an AggregateException object that contains an IndexOutOfRangeException exception.
