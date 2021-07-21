#include <cmath>
#include <vector>
#include <iostream>

template<typename T>
class dataVector : public std::vector<T> {
public:
	dataVector() : sum(0), mean(0), variance(0), std::vector<T>() {}

	void push_back(T&& data)
	{
		this->insert(this->end(), data);

		this->calcSum();
		this->mean = this->calcMean();
		this->variance = this->calcVariance();
	}

	double getVariance() const {
		return this->variance;
	};

	double getMean()const {
		return this->mean;
	};

	double getStdDev() const {
		return sqrt(this->variance);
	}
	friend std::ostream& operator << (std::ostream& out, dataVector<T> obj)
		{
			int vector_size = obj.size();
			for (int i = 0; i < vector_size; i++)
			{
				out << "dataVector[" << i << "] = " << obj[i] << std::endl;
			}
	
			return out;
		}

private:
	double calcMean() {
		return this->sum / this->size();
	};

	double calcVariance()
	{
		T tmp = 0;

		for (T item : *this)
			tmp += item * item;

		return (tmp / this->size()) - (this->mean * this->mean);
	};

	void calcSum() {
		T return_sum = 0;

		for (T item : *this)
			return_sum += item;

		this->sum = return_sum;
	};

	T sum;
	double mean;
	double variance;
};
