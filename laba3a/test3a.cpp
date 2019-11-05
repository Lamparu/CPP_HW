#include "pch.h"
#include "../laba3_15/laba3_15.h"
#include "../laba3_15/queue.cpp"

using namespace Prog3_1;

TEST(ParamConstructor, DefaultConstructor) {
	Param p1;
	ASSERT_EQ(0, p1.n);
	ASSERT_STREQ("null", p1.name);

	Param *arrp = new Param[3];
	for (auto i = 0; i < 3; ++i)
	{
		ASSERT_EQ(0, arrp[i].n);
		ASSERT_STREQ("null", arrp[i].name);
	}
}

TEST(QueueConstructor, DefaultConstructor) {
	Queue q1;
	Param pcp;
	for (unsigned i = 0; i < q1.getMaxSize(); ++i)
	{
		ASSERT_ANY_THROW(q1.outQu(pcp));
		ASSERT_EQ(0, pcp.n);
		ASSERT_STREQ("null", pcp.name);
	}

	Param p(228, "name");
	Param p1;
	Queue q2(p);
	q2.outQu(p1);
	ASSERT_EQ(p1.n, 228);
	ASSERT_STREQ("name", p1.name);

	Queue *arrq = new Queue[3];
	for (auto i = 0; i < 3; ++i)
		for (unsigned j = 0; j < q1.getMaxSize(); ++j)
		{
			ASSERT_ANY_THROW(arrq[i].outQu(pcp));
			ASSERT_EQ(0, pcp.n);
			ASSERT_STREQ("null", pcp.name);
		}
}

TEST(ParamConstructor, InitConstructor) {
	Param p1("exolove", 29034);
	ASSERT_EQ(29034, p1.n);
	ASSERT_STREQ("exolove", p1.name);

	Param arrp[] = { Param(2, "array1"), Param(123456789), Param("emptynum"), Param(), Param(p1) };
	ASSERT_EQ(2, arrp[0].n);
	ASSERT_STREQ("array1", arrp[0].name);
	ASSERT_EQ(123456789, arrp[1].n);
	ASSERT_STREQ("null", arrp[1].name);
	ASSERT_EQ(0, arrp[2].n);
	ASSERT_STREQ("emptynum", arrp[2].name);
	ASSERT_EQ(0, arrp[3].n);
	ASSERT_STREQ("null", arrp[3].name);
	ASSERT_EQ(29034, arrp[4].n);
	ASSERT_STREQ("exolove", arrp[4].name);
}

TEST(QueueConstructor, InitConstructor){
	Param p1("exolove", 29034);
	Param arrp[] = { Param("my", 2), Param("sfs"), Param(2), Param(), Param(p1) };
	Queue q2(arrp, 5);
	q2.outQu(p1);
	ASSERT_EQ(2, p1.n);
	ASSERT_STREQ("my", p1.name);
	q2.outQu(p1);
	ASSERT_EQ(0, p1.n);
	ASSERT_STREQ("sfs", p1.name);
	q2.outQu(p1);
	ASSERT_EQ(2, p1.n);
	ASSERT_STREQ("null", p1.name);
	q2.outQu(p1);
	ASSERT_EQ(0, p1.n);
	ASSERT_STREQ("null", p1.name);
	q2.outQu(p1);
	ASSERT_EQ(29034, p1.n);
	ASSERT_STREQ("exolove", p1.name);
}

TEST(Methods, inQu) {
	Queue q3;
	Param p0;
	Param testp;

	q3.inQu(p0);
	q3.outQu(testp);
	ASSERT_EQ(0, testp.n);
	ASSERT_STREQ("null", testp.name);

	Param p1(999999, "mytest");
	q3.inQu(p1);
	q3.outQu(testp);
	ASSERT_EQ(999999, testp.n);
	ASSERT_STREQ("mytest", testp.name);

	const char *s = new char[szstr];
	for (unsigned i = 0; i < q3.getMaxSize(); ++i)
	{
			int n = 12 + i * 10;
			Param p;
			p.n = n;
			s = q3.getRandomStr(szstr - 1);
			strcpy_s(p.name, szstr, s);
			q3.inQu(p);
	}
	ASSERT_ANY_THROW(q3.inQu(p1));
}

TEST(Methods, inPar) {
	Param par1, par2;
	std::istringstream num("420");
	std::istringstream name("meme");
	std::cin.rdbuf(num.rdbuf());
	par1.inPar(name, num);
	ASSERT_STREQ("meme", par1.name);
	ASSERT_EQ(420, par1.n);

	//std::istringstream num1("420000000000000000000000000000000000");
	//std::istringstream name1("magdfgsrgsdfgresgf");
	//ASSERT_ANY_THROW(par2.inPar(name1, num));
	//ASSERT_ANY_THROW(par2.inPar(name, num1));
}

TEST(Methods, outQu) {
	Queue q4;
	Param testp;
	Param p("exo", 235);

	ASSERT_ANY_THROW(q4.outQu(testp));
	
	q4.inQu(p);
	ASSERT_EQ(q4.outQu(testp), 1);
	ASSERT_EQ(testp.n, 235);
	ASSERT_STREQ(testp.name, "exo");
}

TEST(Methods, State) {
	Queue q1;
	Param arrp[] = { Param("my", 2), Param("sfs"), Param(2), Param(), Param("user", 566), Param(45, "nut"), Param(), Param(335), Param(452332, "fgsfs"), Param(46536, "agstyty") };
	Queue q2(arrp, 10);
	Param p1("exolove", 29034);
	Param arrp1[] = { Param("my", 2), Param("sfs"), Param(2), Param(), Param(p1) };
	Queue q3(arrp1, 5);

	ASSERT_EQ(0, q1.stateQu());
	ASSERT_EQ(2, q2.stateQu());
	ASSERT_EQ(1, q3.stateQu());
}

TEST(Methods, GetSize) {
	Queue q1;
	Param arrp[] = { Param("my", 2), Param("sfs"), Param(2), Param(), Param("user", 566), Param(45, "nut"), Param(), Param(335), Param(452332, "fgsfs"), Param(46536, "agstyty") };
	Queue q2(arrp, 10);
	Param p1("exolove", 29034);
	Param arrp1[] = { Param("my", 2), Param("sfs"), Param(2), Param(), Param(p1) };
	Queue q3(arrp1, 5);

	ASSERT_EQ(q1.getMaxSize(), 10);
	ASSERT_EQ(q1.getSize(), 0);
	ASSERT_EQ(q2.getMaxSize(), 10);
	ASSERT_EQ(q2.getSize(), 10);
	ASSERT_EQ(q3.getMaxSize(), 10);
	ASSERT_EQ(q3.getSize(), 5);
}

TEST(UserInput, FromBuff) {
	int k;
	char *strt = new char[szstr];
	std::istringstream num1("228");
	std::cin.rdbuf(num1.rdbuf());
	std::istringstream str1("memes");
	std::cin.rdbuf(str1.rdbuf());

	ASSERT_EQ(getNum(num1, k), 1);
	ASSERT_EQ(getStr(str1, strt), 1);
}