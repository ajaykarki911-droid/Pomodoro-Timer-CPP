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

int main()
{
    int choice;
    cout << "*** Pomodoro Timer ***" << endl;

    cout << "\n1. Default Mode (25/5)" << endl;
    cout << "2. Custom Mode" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    DefaultMode defaultMode;
    CustomMode customMode;
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
    return 0;
}