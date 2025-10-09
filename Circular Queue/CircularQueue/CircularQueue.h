#pragma once

template <typename T>
class CircularQueue
{
public:
	CircularQueue()
		: capacity(2)
		, head(0)
		, tail(0)
	{
		arr = new T[capacity];
	}

	CircularQueue(int size)
		: capacity(size + 1)
		, head(0)
		, tail(0)
	{
		arr = new T[capacity];
	}

	~CircularQueue()
	{
		if (arr != nullptr)
		{
			delete[] arr;
		}
	}

	bool IsEmpty()
	{
		return head == tail;
	}

	bool IsFull()
	{
		return ((tail + 1) % capacity == head);
	}

	void Push(const T& value)
	{
		if (!IsFull())
		{
			arr[tail] = value;
			tail = (tail + 1) % capacity;
		}
	}

	void Pop()
	{
		if (!IsEmpty())
		{			
			head = (head + 1) % capacity;			
		}
	}

	const T& Front() const
	{
		return arr[head];
	}

private:
	T* arr;

	int capacity;
	int head;
	int tail;
};