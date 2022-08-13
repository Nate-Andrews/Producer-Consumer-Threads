/*
*  Nathan Andrews
*  Programming Problem 1
*  10/9/20
*/

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

class ProCon {
public:
	std::vector<int> v; // buffer

	void Producer()
	{
		int i = 0;
		do
		{
			switch (v.size())
			{
			case 0:
				v.push_back(i); // stores i in v
				std::cout << "\nProducer writes " << i << std::endl; // prints it out
				i++;
				break;
			case 1: // if buffer is full waits 3 seconds
				std::this_thread::sleep_for(std::chrono::seconds(3)); // waits three seconds
				break;
			}
		} while (i < 4);
	};
	void Consumer()
	{
		do
		{
			switch (v.size())
			{
			case 0: // if buffer is empty waits 3.6
				std::this_thread::sleep_for(std::chrono::nanoseconds(3600000000));// waits 3.6 seconds
				break;
			case 1:
				std::cout << "Consumer recieves " << v.back() << std::endl; //writes whats in v
				v.clear();// clears v
				break;
			}
		} while (v.size() <= 1);
	};
private:
};


int main()
{
	ProCon* ProducerConsumer = new ProCon(); // new version of class
	std::thread th1(&ProCon::Producer, ProducerConsumer); //thread 1
	std::this_thread::sleep_for(std::chrono::nanoseconds(3100000000));// waits 3.1 seconds
	std::thread th2(&ProCon::Consumer, ProducerConsumer); //thread 2

	th1.join();
	th2.join();

	system("pause");
	return 0;
};