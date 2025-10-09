// CircularQueue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include "CircularQueue.h"

using namespace std;

int main()
{
    CircularQueue<int> intCq(5);
    CircularQueue<vector<char>> cq(10);

    intCq.Push(10);
    intCq.Push(11);
    intCq.Push(12);
    intCq.Push(13);
    intCq.Push(14);
    intCq.Push(15);



    while (!intCq.IsEmpty())
    {
        int value = intCq.Front();
        intCq.Pop();
        cout << value << endl;
    }
}

