#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <direct.h>

using namespace std;

// Base abstract class

class TimerMode
{
protected:
    int workTime;
    int breakTime;

public:

    // Pure virtual function
    virtual void setTime() = 0;

    int getWorkTime()
    {
        return workTime;
    }

    int getBreakTime()
    {
        return breakTime;
    }
};

// Default mode

class DefaultMode : public TimerMode
{
public:

    void setTime() override
    {
        workTime = 25;
        breakTime = 5;
    }

    void showMode()
    {
        cout << "\nDefault mode selected." << endl;
        cout << "Work time: " << workTime << " minutes" << endl;
        cout << "Break time: " << breakTime << " minutes" << endl;
    }
};
// Custom mode

class CustomMode : public TimerMode
{
public:
    void setTime() override
    {
        cout << "\nEnter work time in minutes: ";
        cin >> workTime;
        cout << "Enter break time in minutes: ";
        cin >> breakTime;
    }

    void showMode()
    {
        cout << "\nCustom mode selected" << endl;
        cout << "Work time: " << workTime << " minutes" << endl;
        cout << "Break time: " << breakTime << " minutes" << endl;
    }
};

// Pomodoro timer class
class PomodoroTimer
{
    private:
    int seconds;
    public:
    PomodoroTimer(int time)
    {
        seconds = time;
    }

    void start()
    {
        for (int i = seconds; i > 0; i--)
        {
            cout << "\rTime left: " << i << " seconds" ;
            cout.flush();
            Sleep(1000);
        }

        cout << "\nTime is over" << endl;
        Beep(1000, 500);
    }

    void start (string message)
    {
        cout << "\n" << message << endl;
        for (int i = seconds; i > 0; i--)
        {
            cout << "\rTime left: " << i << " seconds" ;
            cout.flush();
            Sleep(1000);
        }

        cout << "\nTime is over" << endl;
        Beep(1000, 500);
    }
};

//session logger class
class SessionLogger
{
    public:
    void save(int work, int breakTime, int count)
    {
        mkdir("pomodoro_logs");
        ofstream file("pomodoro_logs/session_log.csv", ios::app);
        if (!file)
        {
            cout << "Error saving session" << endl;
            return;
        }
        time_t now = time(0);
        tm* currentTime = localtime(&now);
        file << currentTime->tm_year + 1900 << "-" << currentTime->tm_mon + 1 << "-" << currentTime->tm_mday << ","
             << currentTime->tm_hour << ":" << currentTime->tm_min << ":" << currentTime->tm_sec << ","
             << work << "," << breakTime << "," << count << endl;
        file.close();
        cout << "Session saved" << endl;
    }
};

int main()
{
    int choice;
    int continueChoice;
    int pomodoroCount = 0;
    cout << "*** Pomodoro Timer ***" << endl;

    cout << "\n1. Default Mode (25/5)" << endl;
    cout << "2. Custom Mode" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    // creating mode objects
    DefaultMode defaultMode;
    CustomMode customMode;

    // pointer to TimerMode
    TimerMode* mode;

    if (choice == 1)
    {
        mode = &defaultMode;
    }
    else if (choice == 2)
    {
        mode = &customMode;
    }
    else
    {
        cout << "Invalid choice" << endl;
        return 0;
    }
    mode->setTime();
    if (choice == 1)
    {
        defaultMode.showMode();
    }
    else
    {
        customMode.showMode();
    }

    while (true)
    {
        int workSeconds;
        workSeconds = mode->getWorkTime() * 60;
        PomodoroTimer workTimer(workSeconds);
        workTimer.start("Work time started");

        int breakSeconds;
        breakSeconds = mode->getBreakTime() * 60;
        PomodoroTimer breakTimer(breakSeconds);
        breakTimer.start("Break time started");

        pomodoroCount++;

        cout <<"\nContinue? "<< endl;
        cout << "1. Yes" << endl;
        cout << "0. No" << endl;

        cout << "Enter your choice: ";
        cin >> continueChoice;

        if (continueChoice == 0)
        {
            break;
        }
    }

    //save session log
    SessionLogger logger;
    logger.save(mode->getWorkTime(), mode->getBreakTime(), pomodoroCount);

    cout << "\nSession ended" << endl;
    cout << "Total Pomodoro sessions completed: " << pomodoroCount << endl;
    return 0;
}