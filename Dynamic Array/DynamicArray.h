#pragma 
#include <iostream>

using namespace std;

class DynamicArray
{
private:
	size_t size = 0;
	size_t capacity = 1;
	int* arr = nullptr;
	void reAllocate(); // ���� ���Ҵ� + ������ �̵�

public:
	DynamicArray();
	DynamicArray(int capacity);
	~DynamicArray();
	void resize(int capacity);
	size_t getSize() { return size; }
	size_t getCapacity() { return capacity; }

	void add(int value);
	void remove(int value);
	void insert(int findValue, int value);
	int find(int value);
	void printAllData();
};

