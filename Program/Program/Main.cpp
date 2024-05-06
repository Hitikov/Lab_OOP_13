#include "Tasks.h"

#include <iostream>

int main() {
	int i;
	std::cout << "Enter task number: " << std::endl;
	std::cin >> i;

	switch (i)
	{
	case 1:
		funk_task1();
		break;
	case 2:
		funk_task2();
		break;
	case 3:
		funk_task3();
		break;
	default:
		break;
	}
}