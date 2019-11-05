#include <iostream>
#include "laba3b.h"

using namespace Prog3_2;

const char *msgs[] = { "0. Quit", "1. Add inited parameter", "2. Add parameter", "3. Get parameter and delete from the queue" , "4. State of queue", "5. Copy queue with parametrs into yours" };
const int Nmsgs = sizeof(msgs) / sizeof(msgs[0]);

namespace Prog3_2 {

	void print_menu() {
		system("cls");
		for (auto i = 0; i < Nmsgs; ++i)
			std::cout << msgs[i] << std::endl;
	}

	int get_var(int &var)
	{
		const char *pch = "";
		int fl;
		do
		{
			std::cout << pch << std::endl;
			fl = getNum(var);
			pch = "Incorrect input. Try again: ";
			if (fl == -1)
				var = 0;

		} while (!fl || ((var < 0) || (var >= Nmsgs)));
		return var;
	}

	int getNum(std::istream &s, int &k)
	{
		const char *pch = "";
		do {
			std::cout << pch << std::endl;
			s >> k;
			if (!(std::cin.good()))
			{
				pch = "Input error, try again";
				if (std::cin.eof())
					return -1;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			else
				return 1;
		} while (true);
	}

	int getNum(int &a)
	{
		const char *pch = "";
		do {
			std::cout << pch << std::endl;
			std::cin >> a;
			if (!(std::cin.good()))
			{
				pch = "Input error, try again";
				if (std::cin.eof())
					return -1;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			else return 1;

		} while (true);
	}



	int getStr(char *s)
	{
		const char *pch = "";
		do
		{
			std::cout << pch;
			std::cin >> s;
			if (!(std::cin.good()))
			{
				pch = "Input error, try again";
				if (std::cin.eof())
					return -1;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			else return 1;
		} while (true);
	}

	int getStr(std::istream &sin, char *str)
	{
		const char *pch = "";
		do
		{
			std::cout << pch;
			sin >> str;
			if (!(std::cin.good()))
			{
				pch = "Input error, try again";
				if (std::cin.eof())
					return -1;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			else return 1;
		} while (true);
	}

	int dialog(const char *msgs[], int N)
	{
		const char *errmsg = "";
		int i, n = 0;
		do {
			std::cout << errmsg << std::endl;
			errmsg = "U r wrong. Repeat, pls!";
			for (i = 0; i < N; ++i)
				std::cout << msgs[i] << std::endl;
			puts("Make ur choice: -->");
			getNum(n);
		} while (n < 0 || n >= N);
		return n;
	}

	Queue::Queue(const Param *arrp, int n)
	{
		top = 0;
		bot = 0;
		for (auto i = top; (i < n && i < SZ); ++i)
			inQu(arrp[i]);
	}

	Queue::Queue(const Param par)
	{
		top = 0;
		bot = 0;
		inQu(par);
	}

	int Queue::outQu(Param &p)
	{
		int rc = abs(top - bot);
		if (top != bot) //проверка, что очередь не пуста
			p = ar[(top++) % SZ];
		//else
			//throw std::exception("Queue is empty");
		return rc;
	}

	int Queue::inQu(Param p)
	{
		int rc = abs(bot - top);
		if (rc < SZ) //проверка, что очередь не полна
			ar[(bot++) % SZ] = p;
		else
			throw std::exception("Queue overflow");
		return rc;
	}

	Queue & Queue::choose(Queue &qu)
	{
		Param par;
		Queue qu1(qu);
		while (qu1.outQu(par) > 0)
			inQu(par);
		return *this;
	}

	char* getRandomStr(unsigned int len)
	{
		char *str = new char[len + 1];
		int x;
		char a;
		for (unsigned int i = 0; i < len; i++)
		{
			x = 65 + rand() % 25;
			a = x;
			str[i] = a;
		}
		str[len] = '\0';
		return str;
	}

	Queue & Queue::operator --() //--qu
	{
		int rc = abs(top - bot);
		if (top != bot) 
			ar[(top++) % SZ];
		else
			throw std::exception("Queue is empty");
		return *this;
	}

	const Queue Queue::operator --(int) //qu--
	{
		Queue qu(*this);
		int rc = abs(top - bot);
		if (top != bot) 
			ar[(top++) % SZ];
		else
			throw std::exception("Queue is empty");
		return qu;
	}

	int Queue::operator()()
	{
		if (top == bot)
			return 0; //empty
		else
			if (abs(bot - top) == SZ)
				return 2; //full
			else
				return 1; //partly full
	}

	Queue operator +(Queue qu1, Queue qu2)
	{
		Queue tmp(qu1);
		Param par;
		while (qu2.outQu(par) > 0)
			tmp.inQu(par);
		return tmp;
	}

	Queue operator +(Queue qu, const Param &p1)
	{
		qu.inQu(p1);
		return qu;
	}
	
	Queue & Queue::operator +=(const Queue &q1)
	{
		Param par;
		Queue tmp(q1);
		while (tmp.outQu(par) > 0)
			inQu(par);
		return *this;
	}

	std::ostream & operator << (std::ostream &s, const Queue &qu)
	{
		int n = 0, i = qu.top;
		if (qu.top - qu.bot == 0)
			s << "Queue is empty";
		else
			while ((n < qu.SZ) && (n < qu.bot - qu.top))
			{
				s << qu.ar[i].n << "-" << qu.ar[i].name << ' ';
				n++;
				i = (i + 1) % qu.SZ;
			}
		s << std::endl;
		return s;
	}

	std::ostream & operator << (std::ostream &s, const Param &par)
	{
		s << par.n << " - " << par.name;
		return s;
	}
	
	std::istream & operator >> (std::istream &s, Param &par)
	{
		std::cout << "(4) Enter parameter : name -->";
		int fl = 0, i = 0;
		char *flstr = new char[szstr];
		const char *pch = "";
		do {
			std::cout << pch;
			fl = getStr(s, flstr);
			pch = "Too long name, try again --> ";
			if (fl == -1)
				throw std::exception("");
		} while (strlen(flstr) >= szstr);
		strcpy_s(par.name, szstr, flstr);
		std::cout << "number -->";
		fl = getNum(s, i);
		if (fl == -1)
			throw std::exception("");
		par.n = i;
		delete[] flstr;
		return s;
	}
	
}
