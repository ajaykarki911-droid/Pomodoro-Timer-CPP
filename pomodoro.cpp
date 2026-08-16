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

int main()
{
    cout << "*** Pomodoro Timer ***" << endl;

    return 0;
}