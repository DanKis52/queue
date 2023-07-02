#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

bool newCustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	
	std::srand(std::time(0));
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);
	cout << "Enter a number of simulation hours: ";
	int hours;
	cin >> hours;
	long cycleLimit = MIN_PER_HR * hours;
	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust = MIN_PER_HR / perhour;

	Item temp;
	long turnaways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cycleLimit; cycle++)
	{
		if (newCustomer(min_per_cust))
		{
			if (line.isFull())
			{
				turnaways++;
			}
			else
			{
				customers++;
				temp.set(cycle);
				line.enQueue(temp);
			}
		}
		if (wait_time<=0 && !line.isEmpty())
		{
			line.deQueue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
		{
			wait_time--;
		}
		sum_line += line.queueCount();
	}
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << "customers served: " << served << endl;
		cout << "turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cycleLimit << endl;
		cout << "average wait time: " << (double)line_wait / served << endl;
	}
	else
	{
		cout << "No customers!\n";
	}
	cout << "Done!\n";
	return 0;
}

bool newCustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}