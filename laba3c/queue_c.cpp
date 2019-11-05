#include <iostream>
#include "laba3c.h"

using namespace Prog3_3;

const char *msgs[] = { "0. Quit", "1. Add inited parameter", "2. Add parameter", "3. Get parameter and delete from the queue" , 
						"4. State of queue", "5. Copy queue with parametrs into yours", "6. My application" };
const int Nmsgs = sizeof(msgs) / sizeof(msgs[0]);

const char *appmsgs[] = { "0. Quit", "1. Add inited parameter", "2. Add parameter", "3. Get parameter and delete from the queue" ,
						"4. State of queue", "5. Show queue", "6. Copy queue with parametrs into yours" };
const int Nappmsgs = sizeof(appmsgs) / sizeof(appmsgs[0]);

namespace Prog3_3 {

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

	Queue::Queue(const Param par) :SZ(QUOTA),top(0), bot(1), ar(new Param[QUOTA])
	{
		ar[0] = par;
	}

	int Queue::outQu(Param &p)
	{
		int rc = abs(top - bot);
		if (top != bot) //проверка, что очередь не пуста
			p = ar[(top++) % SZ];
		else
			throw std::exception("empty");
		return rc;
	}

	int Queue::inQu(Param p)
	{
		int n = 0, i = top % SZ;
		if (bot - top >= SZ)
		{
			SZ += QUOTA;
			Param *old = ar;
			ar = new Param[SZ];
			while ((n < SZ) && (n < bot - top))
			{
				ar[i] = old[i%(SZ-QUOTA)];
				n++;
				i = (i + 1) % SZ;
			}
			delete[] old;
		}
		ar[(bot++) % SZ] = p;
		return bot - top;
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

	Queue::Queue(const Queue &qu) : top(qu.top), bot(qu.bot), SZ(qu.SZ) //copy
	{
		int n = 0, i = top % SZ;
		ar = new Param[SZ];
		while ((n < SZ) && (n < bot - top))
		{
			ar[i] = qu.ar[i];
			n++;
			i = (i + 1) % SZ;
		}
		std::cout << "*** COPY CONSTRUCTOR ***" << std::endl;
	}

	Queue::Queue(Queue &&qu) : top(qu.top), bot(qu.bot), SZ(qu.SZ), ar(qu.ar) //move
	{
		std::cout << "*** MOVE CONSTRUCTOR ***" << std::endl;
		qu.ar = nullptr;
	}

	Queue & Queue::operator =(const Queue &qu)
	{
		int n = 0, 
			i = qu.top % qu.SZ;
		if (this != &qu)
		{
			top = qu.top;
			bot = qu.bot;
			SZ = qu.SZ;
			delete[] ar;
			ar = new Param[SZ];
			while ((n < qu.SZ) && (n < qu.bot - qu.top))
			{
				ar[i] = qu.ar[i];
				n++;
				i = (i + 1) % qu.SZ;
			}
		}
		return *this;
	}

	Queue & Queue::operator [](Queue &qu)
	{
		Param par;
		while (qu.outQu(par) > 0)
			inQu(par);
		return *this;
	}

	Queue & Queue::operator =(Queue &&qu)
	{
		swap(top, qu.top);
		swap(bot, qu.bot);
		swap(ar, qu.ar);
		return *this;
	}

	Queue & Queue::operator --() //--qu
	{
		int rc = bot - top;
		if (top != bot)
			ar[(top++) % SZ];
		else
			throw std::exception("empty");
		return *this;
	}

	const Queue Queue::operator --(int) //qu--
	{
		Queue qu(*this);
		int rc = bot - top;
		if (top != bot)
			ar[(top++) % SZ];
		else
			throw std::exception("empty");
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
		int n = 0, 
			i = qu.top%qu.SZ;
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
