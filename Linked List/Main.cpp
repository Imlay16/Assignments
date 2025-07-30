// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "SinglyLinkedList.h"

int main()
{
	SinglyLinkedList list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);

	list.PrintAllData();

	list.Remove(3);
}
