#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "doctest.h"

class DynamicArray
{
private:
	int* arr;
	size_t size;
	size_t cap;

	void free() // free the memory
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
		cap = 0;
	}

	void copy(const DynamicArray& other)
	{
		if (other.cap == 0)
		{
			*this = DynamicArray();

			return;
		}

		cap = other.cap;
		size = other.size;
		arr = new int[other.size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

public:
	// that is the first thing that initializes when we create an object
	// initial values
	DynamicArray()
	{
		size = 0;
		cap = 4;
		arr = new int[cap];
	}

	DynamicArray(const DynamicArray &other)
	{
		copy(other);
	}

	~DynamicArray()
	{
		free();
	}

	DynamicArray& operator = (const DynamicArray& other)
	{
		if (this != &other)
		{
			free();
			copy(other);
		}

		return *this;
	}

	// push_back, pop_back, reverse, clear, removemax and insertAfter

	void push_back(int element)
	{
		if (size >= cap)
		{
			growArray(cap * 2);
		}
		arr[size++] = element;
	}

	void pop_back()
	{
		if (size > 0)
		{
			size--;
			if (size < cap / 2)
			{
				shrinkArray(cap / 2);
			}
		}
	}

	void growArray(int newCap)
	{
		int* temp = new int[newCap];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		// deallocating array
		delete[] arr;

		// updating data members
		arr = temp;
		cap = newCap;
	}

	void shrinkArray(int newCap)
	{
		int* temp = new int[newCap];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		// deallocating the array
		delete[] arr;

		// updating data members
		arr = temp;
		cap = newCap;
	}

	void reverse1(int*& array) // & so we can store our values in array
	{
		int* reversedArray = new int[cap];
		for (int i = 0; i < size; i++)
		{
			reversedArray[i] = arr[size - i - 1]; // 3 2 1 0
		}

		// delete the memory previously allocated for 'array'
		delete[] array;

		// update the 'array' pointer to point to the reversed array
		array = reversedArray;
	}

	// removes all the elements from array
	void clear()
	{
		free();
	}

	void removeMax() // O (n)
	{
		int max = INT_MIN;

		for (int i = 0; i < getSize(); i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}

		int index = -1;
		for (int i = 0; i < getSize(); i++)
		{
			if (arr[i] == max)
			{
				index = i;
				break;
			}
		}

		for (int j = index; j < getSize(); j++)
		{
			arr[j] = arr[j + 1];
		}
		size--;
	}

	void insertAfter(int position, int element)
	{
		int* array = new int[cap];
		if (position < 0 || position > size)
		{
			throw std::exception("Invalid position");
		}

		if (size >= cap)
		{
			std::cout << "Array is full!" << std::endl;
			return;
		}

		// iterate from left to right, so we don't overwrite original values
		for (int i = size - 1; i >= position; i--) // 0 1 2
		{
			arr[i + 1] = arr[i]; // 2 = 1 -> 2, 1 = 0 -> 1,  0 1 10 2
		}

		arr[position + 1] = element;
		size++;
	}

	int getAt(int index)
	{
		return arr[index];
	}

	int getSize()
	{
		return size;
	}

	void print(int*& array)
	{
		for (int i = 0; i < getSize(); i++)
		{
			std::cout << array[i] << " ";
		}
	}

	void printArray()
	{
		for (int i = 0; i < getSize(); i++)
		{
			std::cout << arr[i] << " ";
		}
	}
};

TEST_CASE("test")
{
	DynamicArray d;

	for (int i = 0; i < 5; i++)
	{
		d.push_back(i);
	}

	CHECK(d.getSize() == 5);

	d.pop_back();

	CHECK(d.getSize() == 4);
	CHECK(d.getAt(1) == 1);
}

int main()
{
	doctest::Context().run();

	DynamicArray d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i);
	}

	d.pop_back();

	for (int i = 0; i < d.getSize(); i++)
	{
		std::cout << d.getAt(i) << " ";
	}

	std::cout << "\n";

	int* array = new int[50];
	d.reverse1(array);
	d.print(array);
	std::cout << "\n";

	delete[] array;

	// deleting all the elements inside of an array
	/*d.clear();
	
	std::cout << d.getSize() << std::endl;*/

	// adding elements
	
	// removing max element
	d.removeMax();
	d.printArray();
	std::cout << "\n";

	// inserting element after certain position
	d.insertAfter(1, 10);
	d.printArray();
	std::cout << "\n";

	return 0;
}