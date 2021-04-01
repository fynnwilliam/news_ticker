#include<vector>

void rotate(std::vector<char> &arr)
{
	arr.push_back(arr.front());
	arr.erase(arr.begin());
}

void display(std::vector<char> &arr)
{
	for(char elem : arr)
	{
		std::cout << elem;
	}
	std::cout << std::flush;
}