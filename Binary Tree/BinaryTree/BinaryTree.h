#pragma once
#include <iostream>

using namespace std;

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

	TreeNode* Find(TreeNode* node, int data)
	{
		if (node == nullptr) return nullptr;

		if (node->data == data)
			return node;

		if (node->data > data)
		{
			return Find(node->left, data);
		}
		else
		{
			return Find(node->right, data);
		}
	}

	TreeNode* FindMin(TreeNode* node)
	{
		if (node == nullptr) return nullptr;

		if (node->left == nullptr) return node;

		return FindMin(node->left);
	}

	TreeNode* AddRecursive(TreeNode* node, int data)
	{
		if (node == nullptr) return new TreeNode{ data, nullptr, nullptr };

		if (node->data > data)
		{
			node->left = AddRecursive(node->left, data);
		}

		if (node->data < data)
		{
			node->right = AddRecursive(node->right, data);
		}
		
		return node;
	}	

	TreeNode* RemoveRecursive(TreeNode* node, int data)
	{
		if (node == nullptr) return nullptr;

		if (node->data == data)
		{
			// 삭제 로직 + 서브 트리 로직 
			
			// 자식이 없는 경우
			if (node->left == nullptr && node->right == nullptr)
			{
				// 그냥 삭제
				delete node;
				return nullptr;
			}
			// 자식이 하나인 경우
			else if ((node->left == nullptr) != (node->right == nullptr))
			{
				// 부모와 자식을 바꿔야함.
				TreeNode* child;
				if (node->left != nullptr)
				{
					child = node->left;
				}
				else
				{
					child = node->right;
				}

				delete node;
				return child;
			}			

			// 자식이 둘인 경우
			else if (node->left != nullptr && node->right != nullptr)
			{
				// 왼쪽 서브 트리의 최댓값 OR 오른쪽 서브 트리의 최솟값.
				// 어떤 값을 리턴할지 정해야함.
				
				// 오른쪽 서브 트리의 최솟값 찾기
				TreeNode* successor = FindMin(node->right);
				node->data = successor->data;

				node->right = RemoveRecursive(node->right, successor->data);
				return node;
			}
		}

		if (node->data > data)
		{
			// 리턴값? = RemoveRecursive(node->left, data);
			// 리턴이 되면 둘 중 하나. nullptr or 삭제할 node가 리턴
			node->left = RemoveRecursive(node->left, data);
		}
		else
		{
			// 리턴값? = RemoveRecursive(node->right, data);
			// 리턴이 되면 둘 중 하나. nullptr or 삭제할 node가 리턴
			node->right = RemoveRecursive(node->right, data);			
		}

		return node;
	}

	void PreOrderRecursive(TreeNode* node)
	{
		if (node == nullptr) return;

		cout << node->data << " ";
		PreOrderRecursive(node->left);
		PreOrderRecursive(node->right);
	}

	void InOrderRecursive(TreeNode* node)
	{
		if (node == nullptr) return;

		InOrderRecursive(node->left);
		cout << node->data << " ";
		InOrderRecursive(node->right);
	}

	void PostOrderRecursive(TreeNode* node)
	{
		if (node == nullptr) return;

		PostOrderRecursive(node->left);
		PostOrderRecursive(node->right);
		cout << node->data << " ";
	}

	void ClearNode(TreeNode* node)
	{
		if (node == nullptr) return;

		ClearNode(node->left);
		ClearNode(node->right);

		delete node;
	}

public:
	BinaryTree() { }
	~BinaryTree()
	{
		// 순회하면서 삭제
		// Left - Right - Root 순서로 delete 해야함. PostOrder.
		ClearNode(root);
		root = nullptr;
	}
	
	// 재귀로 구현
	void Add(int data)
	{
		root = AddRecursive(root, data);
	}

	void Remove(int data)
	{
		root = RemoveRecursive(root, data);
	}

	bool Contains(int data)
	{
		if (Find(root, data) != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// 순회
	void PreOrder()
	{
		PreOrderRecursive(root);
		cout << endl;
	}

	void InOrder()
	{
		InOrderRecursive(root);
		cout << endl;
	}

	void PostOrder()
	{
		PostOrderRecursive(root);
		cout << endl;
	}
};