# Pomodoro Timer (C++)

A simple command line Pomodoro timer made in C++. It helps you work in focused time blocks with short breaks in between, and keeps a log of your sessions.

## What it does

- Lets you pick between a Default mode (25 min work / 5 min break) or a Custom mode where you set your own times.
- Runs a countdown timer for work and break periods, and beeps when time is up.
- Keeps asking if you want to continue after each round.
- Saves your session details (date, time, work time, break time, number of pomodoros) into a CSV file so you can track your progress.

## How it works

The project uses basic OOP concepts:

- TimerMode is an abstract base class with DefaultMode and CustomMode as its child classes.
- PomodoroTimer handles the actual countdown and uses function overloading (one version of start() with a message, one without).
- SessionLogger saves the session info into pomodoro_logs/session_log.csv.

## How to run

This project uses windows.h, so it only works on Windows.

1. Compile it with any C++ compiler, for example:
   g++ pomodoro.cpp -o pomodoro.exe

2. Run the exe:
   pomodoro.exe

3. Choose a mode, and follow the prompts.

## Notes

- Logs are saved in a folder called pomodoro_logs, which gets created automatically if it doesn't exist.
- This was made as a learning project to practice OOP concepts like inheritance, polymorphism, and function overloading in C++.