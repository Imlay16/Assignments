#pragma 
#include <iostream>

using namespace std;

template <typename T>
class DynamicArray
{
private:
	size_t size = 0;
	size_t capacity = 1;
	T* arr = nullptr;

	// 내부 재할당 + 데이터 이동
	void reAllocate()
	{
		capacity *= 2;
		T* newArr = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
	}

public:
	DynamicArray()
	{
		arr = new T[capacity];
	}

	DynamicArray(int capacity)
	{
		this->capacity = capacity;
		arr = new T[capacity];
	}

	~DynamicArray()
	{
		if (arr != nullptr)
		{
			delete[] arr;
		}
	}

	size_t getSize() const { return size; }
	size_t getCapacity() const { return capacity; }

	void add(const T& value)
	{
		if (size == capacity)
		{
			reAllocate();
		}

		arr[size++] = value;
	}

	void remove(const T& value)
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

	template<typename Compare>
	void remove(const T& value, Compare comp)
	{
		for (int i = 0; i < size; i++)
		{
			if (comp(arr[i], value))
			{
				while (i < size - 1)
				{
					arr[i] = arr[i + 1];
					i++;
				}
				size--;
			}
		}
	}

	void insert(const T& findValue, const T& value)
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

	template<typename Compare>
	void insert(const T& findValue, const T& value, Compare comp)
	{
		for (int i = 0; i < size; i++)
		{
			if (comp(arr[i], findValue))
			{
				if (size == capacity)
				{
					reAllocate();
				}
				arr[size++] = value;
			}
		}
	}

	int find(const T& value)
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

	template<typename Compare>
	int find(const T& value, Compare comp) {
		for (int i = 0; i < size; i++) {
			if (comp(arr[i], value)) {
				return i;
			}
		}
		return -1;
	}

	void printAllData()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "data [" << i << "]: " << arr[i].toString() << endl;
		}
		cout << endl;
	}
};

template<>
class DynamicArray<bool>
{
private:
	size_t size = 0;
	size_t boolSize = 0;
	size_t capacity = 1;

	unsigned char* boolArr;

	void reAllocate()
	{
		capacity++;
		unsigned char* newArr = new unsigned char[capacity];

		for (int i = 0; i < size; i++)
		{
			newArr[i] = boolArr[i];
		}

		delete[] boolArr;
		boolArr = newArr;
	}

public:
	DynamicArray()
	{
		boolArr = new unsigned char[capacity];
	}

	~DynamicArray()
	{
		if (boolArr != nullptr)
		{
			delete[] boolArr;
		}
	}

	size_t getSize() const { return boolSize; }
	size_t getCapacity() const { return capacity; }

	void add(const bool& value)
	{
		if (size == capacity)
		{
			reAllocate();
		}

		if (boolSize == 0) {
			*(boolArr + size) = 0;
		}

		*(boolArr + size) |= (static_cast<unsigned char>(value) << boolSize);

		++boolSize;
		if (boolSize == 8)
		{
			size++;
			boolSize = 0;
		}
	}

	bool getIndex(int index)
	{

	}

	void set(int index, const bool& value)
	{

	}

	void remove(const bool& value)
	{
		// 이건 그냥 맨 뒤에 있는 놈들 삭제..?
	}

	void printAllData()
	{
		for (int i = 0; i < size * 8; i++)
		{
			// 한 비트 씩 가져와서 1이면 true 출력, 0이면 false 출력하기

		}
	}
};

