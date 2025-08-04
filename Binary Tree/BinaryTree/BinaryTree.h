#pragma once

struct TreeNode 
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

class BinaryTree
{
private:
	TreeNode* root = nullptr;

	TreeNode* Find(int data)
	{

	}

	void AddRecursive(TreeNode* node, int data)
	{
		// 탈출 조건
		// 자식 노드가 하나도 없을 때
		if (node->left == nullptr && node->right == nullptr) return;


	}

public:
	BinaryTree() { }
	~BinaryTree()
	{

	}
	
	// 재귀로 구현
	void Add(int data)
	{
		if (root == nullptr)
		{
			root = new TreeNode{ data, nullptr, nullptr };
		}
		else
		{
			AddRecursive(root, data);
		}
	}

	void Remove(int data)
	{
		// 삭제될 때,
		// 1. 자식이 없는 경우
		// 2. 자식이 하나 있는 경우
		// 3. 자식이 둘인 경우	
				
	}

	// 순회
	void PreOrder()
	{

	}

	void InOrder()
	{

	}

	void PostOrder()
	{

	}
};