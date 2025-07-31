// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "SinglyLinkedList.h"

int main()
{

#pragma region SinglyLinkedList Test

	SinglyLinkedList list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);
	list.PrintAllData();

	list.Reverse();
	list.PrintAllData();

	list.Add(6);
	list.PrintAllData();

	list.Remove(3);
	list.PrintAllData();

	list.Remove(1);
	list.PrintAllData();

	list.Remove(5);
	list.PrintAllData();

	SinglyNode* findNode = list.Find(2);
	if (findNode != nullptr)
	{
		cout << "Find Node: " << findNode->data << endl;
	}

	list.Remove(2);
	list.Remove(4);
	list.PrintAllData();

#pragma endregion

#pragma region Doubly LinkedList Test



#pragma endregion

}
