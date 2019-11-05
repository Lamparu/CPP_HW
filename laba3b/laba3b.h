//file laba3_15.h
#ifndef _QUEUE_3_H_
#define _QUEUE_3_H_

#include <iostream>
//#include "../laba3_15/queue.cpp"

namespace Prog3_2 {
	static const int szstr = 11;
	struct Param
	{
		int n;
		char name[szstr];
		Param(const char* name0 = "null", int n0 = 0)
		{
			n = n0;
			strcpy_s(name, szstr, name0);
		}
		Param(int n0, const char* name0 = "null") { n = n0; strcpy_s(name, szstr, name0); };
		//methods
		//std::istream & inPar(std::istream &, std::istream &);
		friend std::ostream & operator << (std::ostream &, const Param &);
		friend std::istream & operator >> (std::istream &, Param &);
	};

	class Queue {
	private:
		static const int SZ = 10;
		int top, bot;
		Param ar[SZ];
	public:
		//constructors
		Queue() :top(0), bot(0) {};
		Queue(const Param *, int);
		Queue(const Param);

		//other func
		int inQu(Param); //ввод параметра в очередь
		int outQu(Param &); //выборка параметра из очереди

		Queue & choose(Queue &);
		unsigned int getMaxSize() const { return SZ; }
		unsigned int getSize() const { return (bot - top) % (SZ + 1); }

		//reload operators
		Queue & operator +=(const Queue &);
		friend Queue operator +(const Queue, const Queue); //+
		friend Queue operator +(Queue , const Param &);
		friend std::ostream & operator << (std::ostream &, const Queue &);
		int operator ()();
		Queue & operator --(); //--qu; префиксный
		const Queue operator --(int); //qu--; постфиксный 
		
	};

	void print_menu();
	int get_var(int &);
	int getStr(std::istream &);
	int getStr(char *);
	int getNum(std::istream &, int&);
	int getNum(int &);
	int dialog(const char*[], int);
	char* getRandomStr(unsigned int len);

}

#endif  _QUEUE_3_H_
