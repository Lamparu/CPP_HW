#include <iostream>
#include "laba3_15.h"


using namespace Prog3_1;

int main()
{
	//1
	std::cout << "(2) Initializating empty queue: ";
	Queue quser;
	quser.print(std::cout);
	//2
	std::cout << "(1) Initializating empty parametr: ";
	Param p;
	p.print(std::cout, p);
	//3
	std::cout << "(3) Initializating array of parametrs: \n";
	Param p1("exo", 101);
	Param arrp[] = { Param("my", 2), Param("sfs"), Param(2), Param(), Param(p1) };
	int szarr = sizeof(arrp) / sizeof(arrp[0]);
	for (auto i = 0; i < szarr; ++i)
		arrp[i].print(std::cout, arrp[i]);
	std::cout << "Initializating  queue with array: ";
	Queue q2(arrp, szarr);
	q2.print(std::cout);
	std::cout << "Initializating queue with 1 parameter ";
	Queue q3(p1);
	p1.print(std::cout, p1);
	std::cout << "The queue is: ";
	q3.print(std::cout);
	//user_input();
	
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
		//std::cout << "Your queue is: " << std::endl;
		quser.print(std::cout);
		std::cout << "-->";
		get_var(var);

		switch (var) {
		case 1://8
			std::cout << "Push parameter into your queue: ";
			p1.print(std::cout, p1);
			try { quser.inQu(p1); }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "(7) Your queue is: " << std::endl;
			quser.print(std::cout);
			break;
		case 2: //4, 5, 6
			std::cout << "(5) Adding  parameter into queue..." << std::endl;
			try { par.inPar(std::cin, std::cin);}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
				break;
			}
			std::cout << "The parameter is: ";
			par.print(std::cout, par);
			try { quser.inQu(par);}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			std::cout << "(6) ";
			std::cout << "Your queue is: " << std::endl;
			quser.print(std::cout);
			break;
		case 3:
			std::cout << "(9) Getting  parameter from queue..." << std::endl;
			try { fl = quser.outQu(delp); }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			if (fl != 0)
			{
				std::cout << "Deleted parametr is : ";
				delp.print(std::cout, delp);
				//quser.checkQu();
				std::cout << "Your queue is: ";
				quser.print(std::cout);
			}
			break;
		case 4: //10
			std::cout << "(10) State of your queue is: ";
			fl = quser.stateQu();
			if (fl == 0)
				std::cout << "empty" << std::endl;
			if (fl == 1)
				std::cout << "partly full" << std::endl;
			if (fl == 2)
				std::cout << "full" << std::endl;
			break;
		case 5:
			std::cout << "Copying queue through new unit...";
			try { quser.choose(q2); }
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			//quser.checkQu();
			//q2.checkQu();
			std::cout << "Your queue is: ";
			quser.print(std::cout);
		}
		if (var != 0)
			//std::cout << std::endl;
			system("pause");
	} while (var != 0);

	std::cout << "THE END" << std::endl;
	system("pause");
	return 0;

}