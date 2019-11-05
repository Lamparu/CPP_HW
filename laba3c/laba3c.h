#pragma once
#ifndef _QUEUE_3_H_
#define _QUEUE_3_H_

#include <iostream>

namespace Prog3_3 {
	static const int szstr = 6;
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
		friend std::ostream & operator << (std::ostream &, const Param &);
		friend std::istream & operator >> (std::istream &, Param &);
	};

	class Queue {
	private:
		static const int QUOTA = 3;
		int SZ;
		int top, bot;
		Param *ar;
	public:
		//constructors
		Queue() :SZ(QUOTA), top(0), bot(0), ar(new Param[QUOTA]) {};
		Queue(const Param);
		Queue(const Queue&); //copy
		Queue(Queue&&); //move

		//destructor
		~Queue() { delete[] ar; std::cout << "*** DESTRUCTOR ***" << std::endl; }

		//other func
		int inQu(Param); //ввод параметра в очередь
		int outQu(Param &); //выборка параметра из очереди

		unsigned int getSize() const { return (bot - top) % (SZ + 1); }
		unsigned int getMaxSize() const { return SZ; }

		//reload operators
		Queue & operator +=(const Queue &);
		friend Queue operator +(const Queue, const Queue); //+
		friend Queue operator +(Queue, const Param &);
		friend std::ostream & operator << (std::ostream &, const Queue &);
		int operator ()();
		Queue & operator --(); //--qu; префиксный
		const Queue operator --(int); //qu--; постфиксный 

		Queue & operator = (const Queue &); //reload operator присваивания
		Queue & operator = (Queue&&); //reload перемещающий operator присваивания
		Queue & operator [](Queue &); //move from queue to queue
	};

	void print_menu();
	int get_var(int &);
	int getStr(std::istream &);
	int getStr(char *);
	int getNum(std::istream &, int&);
	int getNum(int &);
	int dialog(const char*[], int);
	char* getRandomStr(unsigned int len);
	template <class AnySwap>
	void swap(AnySwap &a, AnySwap &b)
	{
		AnySwap tmp = a;
		a = b;
		b = tmp;
	}
}

#endif  _QUEUE_3_H_
