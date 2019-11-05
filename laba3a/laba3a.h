//file laba3_15.h
#ifndef _QUEUE_3_H_
#define _QUEUE_3_H_

#include <iostream>
//#include "../laba3_15/queue.cpp"

namespace Prog3_1 {
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
		Param(int n0, const char* name0 = "null") { n = n0; strcpy_s(name, szstr, name0);};
		//methods
		std::ostream & print(std::ostream&, Param) const;//вывод значения параметра
		std::istream & inPar(std::istream &, std::istream &);
	};

	class Queue {
	private:
		static const int SZ = 10;
		int top, bot;
		Param ar[SZ];
		//Param p;
	public:
		//constructors
		Queue() :top(0), bot(0) {};
		Queue(const Param *, int);
		Queue(const Param);
		
		int checkQu();
		unsigned int stateQu();

		//other func
		int inQu(Param); //ввод параметра в очередь
		int outQu(Param &); //выборка параметра из очереди
		

		Queue & choose(Queue &);
		unsigned int getMaxSize() const { return SZ; }
		unsigned int getSize() const { return (bot - top)%(SZ+1); }
		
		std::ostream & print(std::ostream&) const; //вывод содержимого очреди

		char* getRandomStr(unsigned int len);
	};

	void print_menu();
	int get_var(int &);
	int getStr(std::istream &);
	int getStr(char *);
	int getNum(std::istream &, int&);
	int getNum(int &);
	int dialog(const char*[], int);

}

#endif  _QUEUE_3_H_
