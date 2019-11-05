#include <iostream>
#include "laba3b.h"


using namespace Prog3_2;

int main()
{
	//1
	std::cout << "(2) Initializating empty queue: \n";
	Queue quser;
	std::cout << quser;
	//2
	std::cout << "(1) Initializating empty parametr: ";
	Param p;
	std::cout << p << std::endl;
	//3
	std::cout << "(3) Initializating array of parametrs: ";
	Param p1("exo", 101);
	Param p2("loving", 8);
	Param arrp[] = { Param("my", 2), Param("sfs"), Param(2), Param(), Param(p1) };
	int szarr = sizeof(arrp) / sizeof(arrp[0]);
	for (auto i = 0; i < szarr; ++i)
		std::cout << arrp[i] << " ";
	std::cout << std::endl;
	std::cout << "Initializating  queue with array: ";
	Queue q2(arrp, szarr);
	std::cout << q2;
	Queue q3(p1);
	std::cout << "Initializating queue with 1 parameter " << p1;
	std::cout << "The queue is: " << q3 << std::endl;
	//reload operators check
	std::cout << "RELOAD" << std::endl;
	std::cout << "q2 : " << q2;
	std::cout << "q3 : " << q3 << std::endl;
	std::cout << "qu1 = qu2 + qu3" << std::endl;
	Queue q1;
	q1 = q2 + q3;
	std::cout << q1;
	std::cout << "q2: " << q2;
	Param tp(777, "lucky");
	std::cout << std::endl;
	std::cout << "qu1 = qu1 + param (" << tp << ")" << std::endl;
	q1 = q1 + tp;
	std::cout << q1 << std::endl;
	std::cout << "qu1 += qu2 ";
	try { q1 += q2; }
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << q1 << std::endl;
	Queue q4;
	std::cout << "q4(empty) = tp + q2 + q3 + p2(" << p2 << ")" << std::endl;
	//std::cout << q2 << q3;
	try { q4 = Queue(tp) + q2 + q3 + p2; }
	catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << q4 << std::endl;
	Queue q5, q6;
	std::cout << "q5 = q4--" << std::endl;
	q5 = q4--;
	std::cout << "q4: " << q4 << "q5: " << q5;
	std::cout << "q5 = --q4" << std::endl;
	q5 = --q4;
	std::cout << "q4: " << q4 << "q5: " << q5;
	std::cout << std::endl;
	std::cout << "q5 = q4-- + " << tp << std::endl;
	q5 = q4-- + tp;
	std::cout << "q4: " << q4 << "q5: " << q5;


	//user input
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
			if (quser() == 2)
			{
				std::cout << "Queue is full" << std::endl;
				break;
			}
			try { quser.inQu(p1); }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "(7) Your queue is: " << quser;
			break;
		case 2: //4, 5, 6
			std::cout << "(5) Adding  parameter into queue..." << std::endl;
			if (quser() == 2)
			{
				std::cout << "Queue is full" << std::endl;
				break;
			}
			try {
				std::cin >> par;
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
				break;
			}
			std::cout << "The parameter is: " << par << std::endl;
			try { quser.inQu(par); }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "(6) Your queue is: " << quser << std::endl;
			break;
		case 3:
			std::cout << "(9) Getting  parameter from queue..." << std::endl;
			if (!quser())
			{
				std::cout << "Queue is empty" << std::endl;
				break;
			}
			try {quser--;}
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
			if (quser() == 2)
			{
				std::cout << "Queue is full" << std::endl;
				break;
			}
			try { quser.choose(q2); }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "Your queue is: ";
			std::cout << quser;
		}
		if (var != 0)
			//std::cout << std::endl;
			system("pause");
	} while (var != 0);

	std::cout << "THE END" << std::endl;
	system("pause");
	return 0;

}