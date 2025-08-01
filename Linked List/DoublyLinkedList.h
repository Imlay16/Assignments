#pragma once
#include "Define.h"

class DoublyLinkedList
{

private:
	DoublyNode* pHead = nullptr;
	DoublyNode* pTail = nullptr;

	DoublyNode* Find(int data)
	{
		DoublyNode* current = pHead;

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
	DoublyLinkedList() {}
	~DoublyLinkedList()
	{
		DoublyNode* current = pHead;
		DoublyNode* temp = nullptr;

		while (current != nullptr)
		{
			temp = current;
			current = current->next;
			delete temp;
		}

		pHead = pTail = nullptr;
	}

	// �ǳ��� Add
	void Add(int data)
	{
		DoublyNode* newNode = new DoublyNode{ nullptr, data, nullptr };

		if (pHead == nullptr)
		{
			pHead = newNode;
			pTail = pHead;
		}
		else
		{
			newNode->prev = pTail;
			pTail->next = newNode;
			pTail = newNode;
		}
	}

	// finData Node �ڿ�, Add
	void Insert(int findData, int newData)
	{
		DoublyNode* findNode = Find(findData);

		if (findNode == nullptr) return;

		DoublyNode* newNode = new DoublyNode{ nullptr, newData, nullptr };

		if (findNode == pTail)
		{
			findNode->next = newNode;
			newNode->prev = findNode;
			pTail = newNode;
		}
		else // �߰� ����
		{
			findNode->next->prev = newNode;
			newNode->next = findNode->next;
			findNode->next = newNode;
			newNode->prev = findNode;
		}	
	}

	// ����
	void Remove(int data)
	{
		DoublyNode* findNode = Find(data);

		if (findNode == nullptr) return;

		if (pHead == pTail)
		{
			pHead = pTail = nullptr;
		}
		else if (findNode == pHead)
		{
			pHead = findNode->next;
			pHead->prev = nullptr;
		}
		else if (findNode == pTail)
		{
			pTail = findNode->prev;
			pTail->next = nullptr;
		}
		else // �߰� ����
		{
			findNode->prev->next = findNode->next;
			findNode->next->prev = findNode->prev;
		}

		delete findNode;	
	}

	bool IsEmpty()
	{
		return pHead == nullptr;
	}

	// ��ȸ�ϸ� ���
	void PrintAllData()
	{
		DoublyNode* current = pHead;

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

	// ������
	void Reverse()
	{
		DoublyNode* current = pTail;
		DoublyNode* temp = nullptr;

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;

			current = current->next;
		}
		
		temp = pTail;
		pTail = pHead;
		pHead = temp;
	}
};