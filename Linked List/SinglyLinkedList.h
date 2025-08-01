#pragma once
#include "Define.h"

using namespace std;

class SinglyLinkedList
{
private:
	SinglyNode* pHead = nullptr;
	SinglyNode* pTail = nullptr;

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

		pHead = pTail = nullptr;
	}

	void Add(int data)
	{
		SinglyNode* newNode = new SinglyNode{ data, nullptr };

		// ��尡 ���� ��,
		if (pHead == nullptr)
		{
			pHead = newNode;
			pTail = newNode;
		}
		else
		{			
			pTail->next = newNode;
			pTail = newNode;
		}
	}

	// data�� ã�� �ڿ� ���ο� ��� ����, ������ �ƹ��͵� ����
	void Insert(int findData, int newData)
	{
		SinglyNode* findNode = Find(findData);

		if (findNode == nullptr) return;

		SinglyNode* newNode = new SinglyNode{ newData, nullptr };

		if (findNode == pTail) {  // ������ ��� �ڿ� ����
			findNode->next = newNode;
			pTail = newNode;
		}
		else {  // �߰��̳� head �ڿ� ���� 
			newNode->next = findNode->next;
			findNode->next = newNode;
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
				if (pHead == pTail) // ������ 1���� ���
				{
					delete pHead;
					pHead = pTail = nullptr;
				}
				else if (current == pHead) // ��� ����
				{
					pHead = current->next;
					delete current;
				}
				else if (current == pTail) // ���� ����
				{
					pTail = prev;
					prev->next = nullptr;
					delete current;
				}
				else // �߰� ����
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
	
	// ��� ������
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