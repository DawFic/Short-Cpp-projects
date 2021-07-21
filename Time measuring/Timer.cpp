#include <iostream>
#include <thread>
#include "Timer.h"

using namespace std;
using namespace chrono;

void Timer::timeFormat() {
    auto start_time = Timer::getStart();
    auto stop_time = Timer::getStop();

    auto m = duration_cast<minutes>(stop_time - start_time);
    auto s = duration_cast<seconds>(stop_time - start_time);
    auto ms = duration_cast<microseconds>(stop_time - start_time);



    cout << "Time difference: ";
    if (m.count() >= 10)
        cout << m.count() << ":";
    else
        cout << "0" << m.count() << ":";
    if (s.count() >= 60)
        cout << "0" << s.count() % 60 << ".";
    else if (s.count() >= 10 && s.count() < 60)
        cout << s.count() << ".";
    else
        cout << "0" << s.count() << ".";
    if (ms.count() >=100)
        if(ms.count()%100 >=10)
            cout<<"0"<<ms.count()%100;
        else
            cout<<"00"<<ms.count()%100;
    else if (ms.count()>=10 && ms.count()<100)
        cout<<"0"<<ms.count();
    else
        cout<<"00"<<ms.count();

}

void Timer::start()
{
    Timer::setStart(steady_clock::now());
    Timer::setStartFlag(true);
}

void Timer::stop()
{
    Timer::setStop(steady_clock::now());
    Timer::setStopFlag(true);
}
