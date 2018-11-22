#include <iostream>

int main(int argc, char* argv[])
{
	auto f = 1.23f; // 32 bits
	double d = 1.23; // 64 bits
	long double ld = 1.342349287492837492892873492347; // large

	int i = 0; // usually 32 bits
	short s = 32000; // usually 16 bits
	long l = 18000000000; // usually 64 bits
	long long ll = 1292309230983; // 128 bits
	char c = 0; // usually 8 bits 0-255

	auto b = false; // usually 8 bits, but check with sizeof(bool)

	std::cout << "Size of float and double: " << sizeof(float) 
		<< ", " << sizeof(double) << std::endl;
	
	// this is a "block"
	{
		int j = 1;
		int t = j;
	}
	
	if(b)
	{
		std::cout << "B is true!" << std::endl;
	}
	else if(!b)
	{
		std::cout << "B is false!" << std::endl;
	}
	else
	{
		std::cout << "B is false!" << std::endl;
	}

	switch(i)
	{
	case 0:
		std::cout << "switch 0" << std::endl;
		break;
	case 1:
		std::cout << "switch 1" << std::endl;
		break;
	case 2:
		std::cout << "switch 2" << std::endl;
		break;
	default:
		break;
	}

	// for loop
	for(unsigned int count = 0; count < 10; count++)
	{
		if (count == 5) continue;
		std::cout << "Count is: " << count << std::endl;
	}

	// range based for loop
	std::string str = "hello";
	for(char character : str)
	{
		std::cout << character << std::endl;
	}

	int while_count = 0;
	while(while_count < 10)
	{
		std::cout << "While count: " << while_count << std::endl;
		while_count++;
		// or...
		// if(while_cout >= 10) break;
	}

	getchar();

	return 0;
}
