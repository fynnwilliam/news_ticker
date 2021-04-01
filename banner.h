#include<vector>

void display(std::vector<char> &arr)
{
	for(char elem : arr)
	{
		std::cout << elem;
	}
	std::cout << std::flush;
}
