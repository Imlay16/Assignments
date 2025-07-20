
#include "DynamicArray.h"

int main()
{
	DynamicArray arr;

	cout << "capacity: " << arr.getCapacity() << endl;
	cout << "size: " << arr.getSize() << endl;	

	arr.add(1);
	arr.add(2);

	arr.printAllData();
}