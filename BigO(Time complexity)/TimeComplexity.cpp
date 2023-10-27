//#include <iostream>
//
//int main()
//{
//	// O (1) -> most efficient
//
//	int a = 5;
//	std::cout << a << std::endl;
//
//	// O (n) -> linear time algorithm (worst case runtime)
//
//	int n = 10, m = 10;
//
//	for (int i = 0; i < n; i++)
//	{
//		std::cout << i << " ";
//	}
//
//	// O (n^2)
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			std::cout << i << " * " << j << " = " << i * j << " ";
//		}
//		std::cout << std::endl;
//	}
//
//	// O (n * m)
//	
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			std::cout << i << " * " << j << " = " << i * j << " ";
//		}
//		std::cout << std::endl;
//	}
//
//	// O (n^3) -> it's usually the highest that we get to
//
//	// O (logn) -> ex. binary search, pushing and poping elements, it grows really slowly (practically a flat line, difference between logn and n in massive)
//
//	// O (nlogn) -> less efficient than O (n)
//
//	// O (2^n) -> recursion 
//
//	// O (sqrt(n)) -> getting all the factors of some value
//
//	// O (n!) -> permutations, very inefficient 
//
//	// If our solution is O (1), O (logn), O (sqrt(n)), O (n), O (nlogn), O (n^2) than is efficient
//
//	return 0;
//}