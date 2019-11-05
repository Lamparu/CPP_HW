#include <iostream>
#include "laba3c.h"
#include <stdlib.h>

using namespace Prog3_3;

int main()
{
	
	//1
	Queue q1;
	std::cout << "Push into queue: initializated max size = " << q1.getMaxSize() << std::endl;
	char *str = new char[szstr-2];
	for (int i = 0; i < 5; ++i)
	{
		str = getRandomStr(szstr-2);
		int num = 12 + i * 10;
		Param p1(num, str);
		q1.inQu(p1);
	}
	delete[] str;
	std::cout << "Current size = " << q1.getSize() << std::endl;
	std::cout << "The queue 1: " << q1;

	std::cout << "\n";
	Queue q2;
	std::cout << "Move from queue 1 to queue 2: " << std::endl;
	try { q2[q1]; }
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "queue 1: " << q1 << "queue 2: " << q2;

	std::cout << "\n";
	std::cout << "Copy from queue 2 to queue 1: ";
	try { q1 += q2; }
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << "queue 1: " << q1 << "queue 2: " << q2;

	std::cout << "\n";
	std::wcout << "Queue 1: max size = " << q1.getMaxSize() << ", current size = " << q1.getSize() << std::endl;
	std::cout << "Remove 2 parameters from queue 1: " << std::endl;
	for (int i = 0; i < 2; i++)
	{
		//try { --q1; }
		try { q1--; }
		catch (std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	std::cout << "In queue 1: " << q1;
	
	std::cout << "\n";
	std::cout << "Swapping queues:" << std::endl;
	swap(q1, q2);
	std::cout << "queue 1: " << q1 << "queue 2: " << q2;

	Param p1("agent", 7);
	Queue quser;
	int fl;
	int var;
	Param delp;
	Param par;
	system("pause");
	do
	{
		print_menu();
		std::cout << "Your queue : max size = " << quser.getMaxSize() << std::endl;
		std::cout << "Current size = " << quser.getSize() << "; In queue: \n";

		std::cout << quser;
		std::cout << "-->";
		get_var(var);

		switch (var) {
		case 1://8
			std::cout << "Push parameter into your queue: " << p1 << std::endl;
			quser.inQu(p1);
			std::cout << "(7) Your queue is: " << quser;
			break;
		case 2: //4, 5, 6
			std::cout << "(5) Adding  parameter into queue..." << std::endl;
			try {
				std::cin >> par;
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
				break;
			}
			std::cout << "The parameter is: " << par << std::endl;
			quser.inQu(par);
			std::cout << "(6) Your queue is: " << quser << std::endl;
			break;
		case 3:
			std::cout << "(9) Getting  parameter from queue..." << std::endl;
			if (!quser())
			{
				std::cout << "Queue is empty" << std::endl;
				break;
			}
			try { --quser; }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your queue is: " << quser;
			break;
		case 4: //10
			std::cout << "(10) State of your queue is: ";
			fl = quser();
			if (fl == 0)
				std::cout << "empty" << std::endl;
			if (fl == 1)
				std::cout << "partly full" << std::endl;
			if (fl == 2)
				std::cout << "full" << std::endl;
			break;
		case 5:
			std::cout << "Copying queue through new unit...";
			try { quser += q2; }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your queue is: " << quser;
			break;
		}
		if (var != 0)
			//std::cout << std::endl;
			system("pause");
	} while (var != 0);

	std::cout << "THE END" << std::endl;
	system("pause");
	return 0;

}