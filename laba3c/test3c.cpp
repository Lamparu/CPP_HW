#include "pch.h"
#include "../laba3c/laba3c.h"
#include "../laba3c/queue_c.cpp"

using namespace Prog3_3;

TEST(Comstructors, Copy) {
	Queue q1;
	char *str = new char[szstr - 2];
	for (int i = 0; i < 5; ++i)
	{
		str = getRandomStr(szstr - 2);
		int num = 12 + i * 10;
		Param p1(num, str);
		q1.inQu(p1);
	}
	delete[] str;
	Queue q2(q1);
	Param p1, p2;

	q1.outQu(p1);
	q2.outQu(p2);
	ASSERT_EQ(p1.n, p2.n);
	ASSERT_STREQ(p1.name, p2.name);
}

TEST(Comstructors, CopyPlusEq) {
	Param arrp[] = { Param("one", 1), Param("two", 2), Param("three", 3) };
	Queue q1, q2;
	Param p;
	for (int i = 0; i < 3; ++i)
		q1.inQu(arrp[i]);
	ASSERT_ANY_THROW(q2 += q1);
	for (int i = 0; i < 3; ++i)
	{
		q2.outQu(p);
		ASSERT_EQ(p.n, arrp[i].n);
		ASSERT_STREQ(p.name, arrp[i].name);
	}
}

TEST(Methods, InputQueue) {
	Queue q1;
	Param p2("name", 345);

	q1.inQu(p2);
	ASSERT_EQ(q1.getMaxSize(), 3);
	ASSERT_EQ(q1.getSize(), 1);
	char *str = new char[szstr - 2];
	for (int i = 0; i < 3; ++i)
	{
		str = getRandomStr(szstr - 2);
		int num = 12 + i * 10;
		Param p1(num, str);
		q1.inQu(p1);
	}
	delete[] str;
	ASSERT_EQ(q1.getMaxSize(), 6);
	ASSERT_EQ(q1.getSize(), 4);
}

TEST(ReloadOperators, Prisvaivanie) {
	Queue q1, q2;
	Param testp;
	Param p1, p2;

	char *str = new char[szstr - 2];
	for (int i = 0; i < 3; ++i)
	{
		str = getRandomStr(szstr - 2);
		int num = 12 + i * 10;
		Param p(num, str);
		q1.inQu(p);
	}
	delete[] str;
	q2 = q1;
	for (int i = 0; i < 3; ++i)
	{
		q1.outQu(p1);
		q2.outQu(p2);
		ASSERT_EQ(p1.n, p2.n);
		ASSERT_STREQ(p1.name, p2.name);
	}
}

TEST(ReloadOperators, Move) {
	Queue q1, q2, q3;
	Param testp;
	Param p1, p2;

	char *str = new char[szstr - 2];
	for (int i = 0; i < 3; ++i)
	{
		str = getRandomStr(szstr - 2);
		int num = 12 + i * 10;
		Param p(num, str);
		q1.inQu(p);
	}
	delete[] str;
	q2 = q1;
	ASSERT_ANY_THROW(q3[q1]);
	ASSERT_ANY_THROW(q1.outQu(p1));
	for (int i = 0; i < 3; ++i)
	{
		q3.outQu(p1);
		q2.outQu(p2);
		ASSERT_EQ(p1.n, p2.n);
		ASSERT_STREQ(p1.name, p2.name);
	}
}

TEST(Funcs, swap) {
	Param p1("one", 1), p2("two", 2);

	swap(p1, p2);
	ASSERT_EQ(p1.n, 2);
	ASSERT_STREQ(p1.name, "two");
	ASSERT_EQ(p2.n, 1);
	ASSERT_STREQ(p2.name, "one");

	Queue q1;
	Param arrp[] = { Param("one", 1), Param("two", 2), Param("three", 3) };
	for (int i = 0; i < 3; ++i)
		q1.inQu(arrp[i]);
	Param p3("swap", 888);
	Queue q2(p3);
	
	swap(q1, q2);
	q1.outQu(p1);
	ASSERT_EQ(p1.n, 888);
	ASSERT_STREQ(p1.name, "swap");
	ASSERT_ANY_THROW(q1.outQu(p1));

	for (int i = 0; i < 3; ++i)
	{
		q2.outQu(p1);
		ASSERT_EQ(p1.n, arrp[i].n);
		ASSERT_STREQ(p1.name, arrp[i].name);
	}
	ASSERT_ANY_THROW(q2.outQu(p1));

}