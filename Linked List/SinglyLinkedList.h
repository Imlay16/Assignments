#pragma once
#include "Define.h"
#include <iostream>

using namespace std;

class SinglyLinkedList
{
private:
	SinglyNode* pHead = nullptr;
	SinglyNode* pTail = nullptr;

public:
	SinglyLinkedList() { }

	~SinglyLinkedList()
	{
		SinglyNode* current = pHead;
		SinglyNode* prev = nullptr;

		while (current != nullptr)
		{
			prev = current;
			current = current->next;			
			delete prev;
		}
	}

	void Add(int data)
	{
		// 노드가 없을 때,
		if (pHead == nullptr)
		{
			SinglyNode* newNode = new SinglyNode{ data, nullptr };
			pHead = newNode;
			pTail = newNode;
		}
		else
		{			
			SinglyNode* newNode = new SinglyNode{ data, nullptr };

			if (pTail != nullptr)
			{
				pTail->next = newNode;
			}
			pTail = newNode;
		}
	}

	// data를 찾고 뒤에 새로운 노드 삽입, 없으면 아무것도 안함
	void Insert(int findData, int newData)
	{
		SinglyNode* current = pHead;

		while (current != nullptr)
		{
			if (current->data == findData)
			{
				SinglyNode* newNode = new SinglyNode{ newData, nullptr };

				if (current == pTail) {  // 마지막 노드 뒤에 삽입
					current->next = newNode;
					pTail = newNode;
				}
				else {  // 중간이나 head 뒤에 삽입 
					newNode->next = current->next;
					current->next = newNode;
				}

				return;
			}
			current = current->next;
		}
	}

	void Remove(int data)
	{
		SinglyNode* current = pHead;
		SinglyNode* prev = nullptr;

		while (current != nullptr)
		{
			if (current->data == data)
			{
				if (pHead == pTail) // 개수가 1개인 경우
				{
					delete pHead;
					pHead = pTail = nullptr;
				}
				else if (current == pHead) // 헤드 삭제
				{
					pHead = current->next;
					delete current;
				}
				else if (current == pTail) // 테일 삭제
				{
					pTail = prev;
					prev->next = nullptr;
					delete current;
				}
				else // 중간 삭제
				{
					prev->next = current->next;
					delete current;
				}
				return;
			}

			prev = current;
			current = current->next;
		}
	}

	SinglyNode* Find(int data)
	{
		SinglyNode* current = pHead;

		while (current != nullptr)
		{
			if (current->data == data)
			{
				return current;
			}
			current = current->next;
		}

		return nullptr;
	}

	bool IsEmpty()
	{
		return pHead == nullptr;
	}

	void PrintAllData()
	{	
		SinglyNode* current = pHead;

		//if (IsEmpty())
		//{
		//	cout << "Empty!" << endl;
		//	return;
		//}

		if (current == nullptr)
		{
			cout << "Empty!" << endl;
			return;
		}

		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	
	// 요소 뒤집기
	void Reverse()
	{
		SinglyNode* prev = nullptr;
		SinglyNode* current = pHead;
		SinglyNode* next = nullptr;
		pTail = current;

		while (current != nullptr)
		{
			next = current->next;
			current->next = prev;

			prev = current;
			current = next;	
		}		

		pHead = prev;
	}
};