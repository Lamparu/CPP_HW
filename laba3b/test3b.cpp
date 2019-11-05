#include "pch.h"
#include "../laba3_15b/laba3b.h"
#include "../laba3_15b/queue_b.cpp"

using namespace Prog3_2;

TEST(ReloadOperators, Plus) {
	Queue q1; //empty
	Param p1("action", 101);
	Param arrp[] = { Param("my", 2), Param("sfs")};
	Queue q2(arrp, 2); //array
	Queue q3(p1); //1 parametr
	Param testp;
	q1 = q2 + q3;
	ASSERT_EQ(q1.getSize(), 3);
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 2);
	ASSERT_STREQ(testp.name, "my");
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 0);
	ASSERT_STREQ(testp.name, "sfs");
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 101);
	ASSERT_STREQ(testp.name, "action");
	q1 = q3 + p1;
	ASSERT_EQ(q1.getSize(), 2);
	for (int i = 0; i < 2; ++i)
	{
		q1.outQu(testp);
		ASSERT_EQ(testp.n, 101);
		ASSERT_STREQ(testp.name, "action");
	}
	q1 = Queue(p1) + q3;
	ASSERT_EQ(q1.getSize(), 2);
	for (int i = 0; i < 2; ++i)
	{
		q1.outQu(testp);
		ASSERT_EQ(testp.n, 101);
		ASSERT_STREQ(testp.name, "action");
	}
	q1 = Queue(p1) + q2 + p1;
	ASSERT_EQ(q1.getSize(), 4);
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 101);
	ASSERT_STREQ(testp.name, "action");
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 2);
	ASSERT_STREQ(testp.name, "my");
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 0);
	ASSERT_STREQ(testp.name, "sfs");
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 101);
	ASSERT_STREQ(testp.name, "action");
	ASSERT_ANY_THROW(q2 + q2 + q2 + q2 + q2 + q2);
}

TEST(ReloadOperators, PlusEqual) {
	Param p1("action", 101);
	Queue q1(p1); 
	Param arrp[] = { Param("my", 2), Param("sfs") };
	Queue q2(arrp, 2); 
	Param testp;

	q1 += q2;
	ASSERT_EQ(q1.getSize(), 3);
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 101);
	ASSERT_STREQ(testp.name, "action");
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 2);
	ASSERT_STREQ(testp.name, "my");
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 0);
	ASSERT_STREQ(testp.name, "sfs");

	ASSERT_ANY_THROW(q1 += q2 += q2 += q2 += q2 += q2);
}

TEST(ReloadOperators, DoubleMinusPrefix) {
	Param arrp[] = { Param("my", 2), Param("sfs", 77) };
	Queue q1(arrp, 2);
	Param testp;
	Queue q2;

	q2 = --q1;
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 77);
	ASSERT_STREQ(testp.name, "sfs");
	q2.outQu(testp);
	ASSERT_EQ(testp.n, 77);
	ASSERT_STREQ(testp.name, "sfs");
	ASSERT_ANY_THROW(--q1);
}

TEST(ReloadOperators, DoubleMinusPostfix) {
	Param arrp[] = { Param("my", 2), Param("sfs", 77) };
	Queue q1(arrp, 2);
	Param testp;
	Queue q2;

	q2 = q1--;
	q1.outQu(testp);
	ASSERT_EQ(testp.n, 77);
	ASSERT_STREQ(testp.name, "sfs");
	q2.outQu(testp);
	ASSERT_EQ(testp.n, 2);
	ASSERT_STREQ(testp.name, "my");
	ASSERT_ANY_THROW(q1--);
}

TEST(ReloadOperators, RoundBrackets) {
	Param p1("algol", 3);
	Queue q1;
	Queue q2(p1);
	Queue q3;
	char *str = new char[szstr - 2];
	for (int i = 0; i < q1.getMaxSize(); ++i)
	{
		str = getRandomStr(szstr - 2);
		int num = 12 + i * 10;
		Param p1(num, str);
		q1.inQu(p1);
	}
	delete[] str;

	ASSERT_EQ(q3(), 0);
	ASSERT_EQ(q2(), 1);
	ASSERT_EQ(q1(), 2);
}

TEST(ReloadOperators, Input) {
	Param par;

	std::istringstream inputqu("meme 228\n");
	std::cin.rdbuf(inputqu.rdbuf());
	std::cin >> par;

	std::ostringstream outputqu;
	outputqu << par;

	EXPECT_EQ("228 - meme", outputqu.str());
}

TEST(ReloadOperators, InputError) {
	Param par;

	std::istringstream inputqu("228 meme\n 228\n");
	std::cin.rdbuf(inputqu.rdbuf());
	std::cin >> par;

	std::ostringstream outputqu;
	outputqu << par;

	EXPECT_EQ("228 - 228", outputqu.str());
}

