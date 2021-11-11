#include <iostream>
#include <future>
#include <string>
using namespace std::chrono_literals;
void printing()
{
	std::cout << "printing" << std::endl;
	std::this_thread::sleep_for(5s);
	std::cout << "printing runs on-" << std::this_thread::get_id() << std::endl;
	
}

int addition(int x, int y)
{
	std::cout << "addition" << std::endl;
	std::this_thread::sleep_for(5s);
	std::cout << "addition runs on-" << std::this_thread::get_id() << std::endl;
	
	return x + y;
}

int substract(int x, int y)
{
	std::cout << "substract" << std::endl;
	std::this_thread::sleep_for(5s);
	std::cout << "substract runs on-" << std::this_thread::get_id() << std::endl;
	
	return x - y;
}

int main()
{
	std::cout << "main thread id -" << std::this_thread::get_id() << std::endl;

	int x = 100;
	int y = 50;

	std::future<void> f1 = std::async(std::launch::async, printing);
	std::future<int> f2 = std::async(std::launch::deferred, addition, x, y);
	std::future<int> f3 = std::async(std::launch::deferred | std::launch::async,
		substract, x, y);

	f1.get();
	std::cout << "value recieved using f2 future -" << f2.get() << std::endl;
	std::cout << "value recieved using f2 future -" << f3.get() << std::endl;

}