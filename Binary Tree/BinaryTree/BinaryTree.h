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
		// Ż�� ����
		// �ڽ� ��尡 �ϳ��� ���� ��
		if (node->left == nullptr && node->right == nullptr) return;


	}

public:
	BinaryTree() { }
	~BinaryTree()
	{

	}
	
	// ��ͷ� ����
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
		// ������ ��,
		// 1. �ڽ��� ���� ���
		// 2. �ڽ��� �ϳ� �ִ� ���
		// 3. �ڽ��� ���� ���	
				
	}

	// ��ȸ
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