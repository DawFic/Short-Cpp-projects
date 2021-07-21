#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>

class Timer
{
public:
	Timer() {};

	void start();
	void stop();
	void timeFormat();

	friend std::ostream& operator << (std::ostream& out, Timer obj)
	{
        if (obj.startFlag && !obj.stopFlag){
            out << "Measurement not ended";
        }
        else{
            obj.timeFormat();
        }
		return out;
	}

	void calculateLoopTime();


	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<int64_t , std::ratio<1, 1000000000>>> getStart() const
	{
		return this->startStp;
	}

	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<int64_t , std::ratio<1, 1000000000>>> getStop() const
	{
		return this->stopStp;
	}
protected:
    std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<int64_t , std::ratio<1, 1000000000>>> startStp, stopStp;
    bool startFlag = 0, stopFlag = 0;
	void setStart(std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<int64_t , std::ratio<1, 1000000000>>> time) {
		this->startStp = time;
	}

	void setStop(std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<int64_t , std::ratio<1, 1000000000>>> time) {
		this->stopStp = time;
	}

	void setStartFlag(bool flag)
	{
		this->startFlag = flag;
	}

	void setStopFlag(bool flag)
	{
		this->stopFlag = flag;
	}
};

#endif
