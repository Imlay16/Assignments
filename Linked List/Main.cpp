// LinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

int main()
{

#pragma region SinglyLinkedList Test
	
	cout << "SinglyLinkedList Test" << endl;

	SinglyLinkedList list;

	// 끝 삽입
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);
	list.PrintAllData();

	// 뒤집기
	list.Reverse();
	list.PrintAllData();
	list.Reverse();

	// 끝 삭제
	list.Remove(5);
	list.PrintAllData();

	// 중간 삽입
	list.Insert(3, 6);
	list.PrintAllData();

	// 헤드 삭제
	list.Remove(1);
	list.PrintAllData();

	// 중간 삭제
	list.Remove(3);
	list.PrintAllData();

	// 끝 삭제
	list.Remove(5);
	list.PrintAllData();

	cout << endl;

#pragma endregion

#pragma region Doubly LinkedList Test

	cout << "DoublyLinkedList Test" << endl;

	DoublyLinkedList dList;

	// 끝 삽입
	dList.Add(1);
	dList.Add(2);
	dList.Add(3);
	dList.Add(4);
	dList.Add(5);
	dList.PrintAllData();

	// 뒤집기
	dList.Reverse();
	dList.PrintAllData();
	dList.Reverse();

	// 끝 삭제
	dList.Remove(5);
	dList.PrintAllData();

	// 중간 삽입
	dList.Insert(3, 6);
	dList.PrintAllData();

	// 헤드 삭제
	dList.Remove(1);
	dList.PrintAllData();

	// 중간 삭제
	dList.Remove(3);
	dList.PrintAllData();

	// 끝 삭제
	dList.Remove(5);
	dList.PrintAllData();

#pragma endregion

}
