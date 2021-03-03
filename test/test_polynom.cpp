#include "polynom.h"

#include <gtest.h>

TEST (TMonom, can_create_empty_monom)
{
	ASSERT_NO_THROW(Monom a);
}

TEST(TMonom, can_create_initialized_monom)
{
	ASSERT_NO_THROW(Monom m(1.5, 123));
}

TEST(TMonom, throws_if_degree_is_not_correct)
{
	ASSERT_ANY_THROW(Monom m(20, 1000));
}

TEST (TMonom, can_create_copied_monom)
{
	Monom m1(2, 532);
	ASSERT_NO_THROW(Monom m2(m1));
}

TEST (TMonom, can_mult_two_monoms)
{
	Monom m1(2, 123);
	Monom m2(3, 333);
	ASSERT_NO_THROW( m1 * m2 );
}

TEST(TMonom, can_mult_two_monoms_correctly_1)
{
	Monom m1(2, 123);
	Monom m2(3, 333);
	EXPECT_EQ((m1 * m2).degree, 456);
}

TEST(TMonom, can_mult_two_monoms_correctly_2)
{
	Monom m1(2, 123);
	Monom m2(3, 333);
	EXPECT_EQ((m1 * m2).k, 6);
}

TEST(TMonom, throws_if_res_of_mult_has_uncorrect_degree)
{
	Monom m1(2, 129);
	Monom m2(3, 331);
	ASSERT_ANY_THROW( m1 * m2 );
}

TEST(TMonom, throws_if_res_of_add_is_not_a_monom)
{
	Monom m1(2, 123);
	Monom m2(3, 124);
	ASSERT_ANY_THROW( m1 + m2 );
}

TEST(TMonom, can_add_two_monoms)
{
	Monom m1(2, 123);
	Monom m2(3, 123);
	EXPECT_EQ( (m1 + m2).k, 5 );
}

TEST(TPolynom, can_create_polynom_with_head)
{
	Monom m;
	Node<Monom>* p = new Node<Monom>(m, nullptr);
	ASSERT_NO_THROW(Polynom pol(p));
}

TEST(TPolynom, can_create_copied_polynom)
{
	Monom m;
	Node<Monom>* p = new Node<Monom>(m, nullptr);
	Polynom p1(p);
	ASSERT_NO_THROW(Polynom p2(p1));
}

TEST(TPolynom, can_mult_monom_and_polynom)
{
	Monom m;
	Node<Monom>* p = new Node<Monom>(m, nullptr);
	Polynom pol(p);
	Polynom res(pol);

	Monom m1(3, 123), m2(5, 251), m3(6, 245), m4(10, 373);
	Monom m5(2, 122);
	pol.push_front(m2);
	pol.push_front(m1);
	res.push_front(m4);
	res.push_front(m3);

	EXPECT_EQ(m5*pol, res);
}

TEST(TPolynom, can_add_two_polynoms)
{
	Monom m;
	Node<Monom>* p = new Node<Monom>(m, nullptr);
	Polynom pol(p);
	Polynom pol2(pol);
	Polynom res(pol);

	Monom m1(3, 123), m2(5, 251), m3(3, 675);

	pol.push_front(m2);

	pol2.push_front(m3);
	pol2.push_front(m1);

	res.push_front(m3);
	res.push_front(m2);
	res.push_front(m1);
	EXPECT_EQ(pol + pol2, res);
}

TEST(TPolynom, can_add_polynoms_with_equal_degrees_of_monoms)
{
	Monom m;
	Node<Monom>* p = new Node<Monom>(m, nullptr);
	Polynom pol(p);
	Polynom pol2(pol);
	Polynom res(pol);

	Monom m1(4, 123), m2(2, 123), m3(6, 123);
	pol.push_front(m1);
	pol2.push_front(m2);
	res.push_front(m3);
	EXPECT_EQ(pol + pol2, res);
}

TEST(TPolynom, can_mult_two_polynoms)
{
	Monom m;
	Node<Monom>* p = new Node<Monom>(m, nullptr);
	Polynom pol(p);
	Polynom pol2(pol);
	Polynom res(pol);

	Monom m1(3, 123), m2(5, 251), m3(3, 645), m4(2, 253);
	Monom m5(15, 374), m6(6, 376), m7(15, 896), m8(6, 898); 

	pol.push_front(m4);
	pol.push_front(m2);
	pol2.push_front(m3);
	pol2.push_front(m1);

	res.push_front(m8);
	res.push_front(m7);
	res.push_front(m6);
	res.push_front(m5);

	EXPECT_EQ(pol*pol2, res);
}

