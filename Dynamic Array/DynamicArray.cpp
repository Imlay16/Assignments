// DynamicArray.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
	arr = new int[capacity];
}

DynamicArray::DynamicArray(int capacity)
{
	this->capacity = capacity;
	arr = new int[capacity];
}

DynamicArray::~DynamicArray()
{
	if (arr != nullptr)
	{
		delete[] arr;
	}
}

void DynamicArray::reAllocate()
{
	capacity *= 2;
	int *newArr = new int[capacity];

	memcpy_s(newArr, capacity * sizeof(int), arr, size * sizeof(int));

	delete[] arr;
	arr = newArr;
}


void DynamicArray::resize(int capacity)
{
	// 사용자가 직접 capacity를 할당
	// 
}

void DynamicArray::add(int value)
{
	if (size == capacity)
	{
		reAllocate();
	}
	arr[size++] = value;
}

void DynamicArray::remove(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			// 데이터 앞으로 한 칸씩 당기고, size--;
			while (i < size - 1)
			{
				arr[i] = arr[i + 1];
				i++;
			}
			size--;
		}
	}
}

void DynamicArray::insert(int findValue, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == findValue)
		{
			if (size == capacity)
			{
				reAllocate();
			}
			arr[size++] = value;
		}
	}
}

int DynamicArray::find(int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void DynamicArray::printAllData()
{
	for (int i = 0; i < size; i++)
	{
		cout << "data [" << i << "]: " << arr[i] << endl;
	}
}


