#pragma once

struct SinglyNode
{
	int data;
	SinglyNode* next = nullptr;
};

struct DoublyNode
{
	int data;
	DoublyNode* prev = nullptr;
	DoublyNode* next = nullptr;
};