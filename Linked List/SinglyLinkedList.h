#pragma once
#include "Define.h"
#include <iostream>

using namespace std;

class SinglyLinkedList
{
private:
	SinglyNode* pHead = nullptr;

public:
	SinglyLinkedList() { }

	~SinglyLinkedList()
	{
		delete pHead;
	}

	void Add(int data)
	{
		if (pHead == nullptr)
		{
			// 처음 노드일 때
			SinglyNode* pData = new SinglyNode{ data, nullptr };
			pHead = pData;
		}
		else
		{
			// 이미 다른 노드들이 있을 때,
			SinglyNode* pData = new SinglyNode{ data, nullptr };
			
			SinglyNode* temp = pHead;

			while (temp->next != nullptr)
			{
				temp = temp->next;				
			}

			temp->next = pData;			
		}
	}

	void Remove(int data)
	{
		SinglyNode* temp = pHead;

		while (temp != nullptr)
		{
			if (temp->data == data)
			{
				delete temp;
				temp = nullptr;

				// 뒷놈이랑 연결해줘야함!!!
			}
			temp = temp->next;
		}
	}

	SinglyNode* Find(int data)
	{
		SinglyNode* temp = pHead;

		while (temp != nullptr)
		{
			if (temp->data == data)
			{
				return temp;
			}
			temp = temp->next;
		}

		return nullptr;

		// 근데 이렇게 포인터를 반환하면, 밖에서 CONTROL 가능하지 않나?
	}

	void PrintAllData()
	{
		SinglyNode* temp = pHead;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	
	// 요소 뒤집기
	void Reverse()
	{
		
	}
};