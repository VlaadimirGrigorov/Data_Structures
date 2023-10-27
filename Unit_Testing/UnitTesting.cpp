//#define DOCTEST_CONFIG_IMPLEMENT
//#include <iostream>
//#include <cmath>
//#include "doctest.h"
//
//int factorial(int n)
//{
//	int fact = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		fact *= i;
//	}
//
//	return fact;
//}
//
//unsigned int countDigits(unsigned int n)
//{
//	int counter = 0;
//
//	while (n != 0)
//	{
//		counter++;
//		n /= 10;
//	}
//
//	return counter;
//}
//
//unsigned int countOccurencesOfADigit(unsigned int n, unsigned int digit)
//{
//	int counter = 0;
//
//	while (n != 0)
//	{
//		if (n % 10 == digit)
//		{
//			counter++;
//		}
//		n /= 10;
//	}
//
//	return counter;
//}
//
//unsigned int reverse(unsigned int n)
//{
//	int reverse = 0;
//
//	while (n != 0)
//	{
//		reverse *= 10;
//		reverse += (n % 10);
//		n /= 10;
//	}
//
//	return reverse;
//}
//
//unsigned int power(unsigned int base, unsigned int exponent)
//{
//	int result = 1;
//
//	for (int i = 0; i < exponent; i++)
//	{
//		result *= base;
//	}
//
//	return result;
//}
//
//bool isPrime(unsigned int n)
//{
//	double temp = sqrt(n);
//	if (n <= 1)
//	{
//		return false;
//	}
//
//	for (int i = 2; i <= temp; i++)
//	{
//		if (n % i == 0)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//TEST_CASE("test1")
//{
//	CHECK(factorial(6) == 720);
//	CHECK(factorial(4) == 24);
//	CHECK(factorial(3) == 6);
//	CHECK(reverse(123) == 321);
//	CHECK(reverse(1513) == 3151);
//	CHECK(reverse(9157) == 7519);
//}
//
//TEST_CASE("test2")
//{
//	CHECK(countDigits(12345) == 5);
//	CHECK(countDigits(1234) == 4);
//	CHECK(countDigits(123) == 3);
//	CHECK(countOccurencesOfADigit(1232323, 2) == 3);
//	CHECK(countOccurencesOfADigit(123121, 1) == 3);
//}
//
//TEST_CASE("test3")
//{
//	CHECK(power(2, 5) == 32);
//	CHECK(power(5, 2) == 25);
//	CHECK(power(3,4) == 81);
//	CHECK(isPrime(7) == true);
//	CHECK(isPrime(19) == true);
//	CHECK(isPrime(77) == false);
//}
//
//int main()
//{
//	doctest::Context().run();
//
//	return 0;
//}