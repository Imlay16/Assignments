// BinaryTree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "BinaryTree.h"

int main()
{
    BinaryTree tree;


    tree.Add(5);
    tree.Add(4);
    tree.Add(6);
    tree.Add(3);

    tree.PreOrder();
    tree.InOrder();
    tree.PostOrder();

    if (tree.Contains(3))
    {
        cout << "Contained" << endl;
    }
    else
    {
        cout << "Not Contained" << endl;
    }
    
    if (tree.Contains(7))
    {
        cout << "Contained" << endl;
    }
    else
    {
        cout << "Not Contained" << endl;
    }
}
