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
			// ó�� ����� ��
			SinglyNode* pData = new SinglyNode{ data, nullptr };
			pHead = pData;
		}
		else
		{
			// �̹� �ٸ� ������ ���� ��,
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

				// �޳��̶� �����������!!!
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

		// �ٵ� �̷��� �����͸� ��ȯ�ϸ�, �ۿ��� CONTROL �������� �ʳ�?
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
	
	// ��� ������
	void Reverse()
	{
		
	}
};