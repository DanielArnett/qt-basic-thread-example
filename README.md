A sample program showing basic threading in Qt.

This program shows how a UI can generate a worker thread which does some 'intense' process without sacrificing UI response time. To use the program do the following:

1. Open the .pro file in Qt Creator and press F5 to debug.
2. Enter a number into the newly opened program.
3. Press enter. 
4. The number you entered will be displayed on the GUI. In the background this program has opened a seperate thread where it continuously adds 1 to your original number. If you press Enter again the program will retrieve the most recent value of that number.  Entering a different value will stop the worker thread and restart it at the new value.
5. If you open your "Task Manager"/"System Monitor"/"Activity Monitor" you will notice that one of your processor cores will continuously run at around 100%.
