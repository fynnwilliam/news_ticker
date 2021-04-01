#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void rotate(char * arr)
{
	char temp = arr[0];

	for(int i = 0; i < 39; i++)
	{
		arr[i] = arr[i + 1];
	}

	arr[39] = temp;
}

void display(char * arr)
{
	for(int i= 0; i < 40; i++)
	{
		std::cout << arr[i];
	}
	std::cout << '\n';
}

int main()
{
	std::system("clear");
	char banner[] = {" welcome to the good morning show...    "};

	for(int i = 0; i < 10000; i++)
	{
		rotate(banner);
		display(banner);
		std::this_thread::sleep_for(1000ms);
		std::system("clear");
	}

	return 0;
}
