#pragma once
#include <iostream>

struct SinglyNode
{
	int data;
	SinglyNode* next = nullptr;
};

struct DoublyNode
{
	DoublyNode* prev = nullptr;
	int data;	
	DoublyNode* next = nullptr;
};