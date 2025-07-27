#pragma once

template<typename T>
struct SignlyNode
{
	T data;
	SinglyNode* next = nullptr;
};

template<typename T>
struct DoublyNode
{
	T data;
	DoublyNode* prev = nullptr;
	DoublyNode* next = nullptr;
};