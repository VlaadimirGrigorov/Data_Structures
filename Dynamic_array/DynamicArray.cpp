#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <vector> // std::vector
#include <cassert> 
#include "doctest.h"

class DynamicArray {
private:
    int* arr;
    int size;
    int cap;
public:
    DynamicArray() {
        size = 0;
        cap = 4;
        arr = new int[cap];
    }

    // this means that the class is not designed to support copying or assigment of dynamic arrays. If we try, it will give us compilation error.
    DynamicArray(const DynamicArray& other) = delete;
    DynamicArray& operator=(const DynamicArray& other) = delete;

    // destructor is responsible for deallocating the memory 
    ~DynamicArray() {
        delete[] arr;
        arr = nullptr; // prevent accesing the memory after it has been deallocated
    }

    // method
    int getAt(int index)
    {
        return arr[index];
    }

    // method
    void push_back(int newElement)
    {
        if (size >= cap)
        {
            growArray(cap * 2);
        }
        arr[size++] = newElement;
    }

    // method
    void pop()
    {
        if (size > 0)
        {
            size--;
            if (size < cap / 2)
            {
                shrinkArray(cap / 2);
            }
        }
        else
        {
            std::cout << "Array is empty!" << std::endl;
        }
    }

    // method
    // increasing the capacity of the dynamic array when it becomes full
    void growArray(int newCap) // we have to double capacity
    {
        int* temp = new int[newCap]; // newCap is the new size, which is doubled 
        for (int i = 0; i < size; ++i)
        {
            temp[i] = arr[i]; // copying to new array
        }

        // deallocating array
        delete[] arr;

        // updating data members
        arr = temp;
        cap = newCap;
    }

    // reducing the capacity of the dynamic array
    void shrinkArray(int newCap) // divide capacity with two
    {
        // set that capacity is equal to size
        newCap = cap / 2;
        int* temp = new int[newCap];

        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }

        // deallocating 
        delete[] arr;

        // updating data members
        arr = temp;
        cap = newCap;
    }

    // UNCLEAR yet!
    // insert at given position
    void insertAt(int index, int value)
    {
        if (size <= cap)
        {
            growArray(cap * 2);
        }

        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }

        arr[index] = value;
        size++;
    }

    // UNCLEAR yet!
    // delete at given position
    void deleteAt(int index)
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[size - 1] = 0;

        size--;

        shrinkArray(cap / 2);
    }

    // method
    int getSize()
    {
        return size;
    }

    // print values
    void print()
    {
        for (int i = 0; i < getSize(); i++)
        {
            std::cout << getAt(i) << " ";
        }
        std::cout << std::endl;
    }
};

void print(const std::vector<int>& vertices)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        std::cout << vertices[i] << " ";
    }
    std::cout << "\n";
}

TEST_CASE("test")
{
    DynamicArray d;
    for (int i = 0; i < 5; i++)
    {
        d.push_back(i);
    }

    CHECK(d.getAt(3) == 3);
    CHECK(d.getAt(1) == 1);
    CHECK(d.getSize() == 5);

    d.pop();

    CHECK(d.getAt(3) == 3);
    CHECK(d.getSize() == 4);

    d.pop();
    d.pop();

    CHECK(d.getSize() == 2);

    d.push_back(5);

    CHECK(d.getAt(2) == 5);

    d.pop();
    d.pop();
    d.pop();

    CHECK(d.getSize() == 0);
}

TEST_CASE("test1")
{
    std::vector<int> vertices;

    for (int i = 0; i < 5; i++)
    {
        vertices.push_back(i);
    }

    CHECK(vertices.at(3) == 3);

    vertices.erase(vertices.begin() + 1);

    CHECK(vertices.at(1) == 2);
}

int main()
{
    doctest::Context().run();

    DynamicArray d;

    for (int i = 0; i < 5; i++)
    {
        d.push_back(i);
    }

    d.pop();

    if (d.getSize() > 3)
    {
        std::cout << d.getAt(3) << std::endl;
    }
    std::cout << d.getSize() << std::endl;

    d.insertAt(2, 10);

    std::cout << d.getSize() << "\n";
    
    d.deleteAt(1);

    std::cout << d.getSize() << "\n";

    d.print();

    return 0;

    // std::vector (it's all done already, we don't have to do anything manually)

    /*std::vector<int> vertices;

    for (int i = 0; i < 5; i++)
    {
        vertices.push_back(i);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << vertices[i] << " ";
    }

    std::cout << std::endl;
    
    vertices.erase(vertices.begin() + 1);*/

	return 0;
}