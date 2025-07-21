
#include "DynamicArray.h"

class Person
{
private:
	string name;
	int id;

public:
	Person() = default; 
	Person(string name, int id) : name(name), id(id) { }

	string toString() const {
		return "Name: " + name;
	}
};

int main()
{
	Person p1("John", 4);
	Person p2("Alice", 2);
	Person p3("Doom", 1);

	DynamicArray<Person> p;

	p.add(p1);
	p.add(p2);
	p.add(p3);

	cout << "size: " << p.getSize() << endl;
	cout << "capacity: " << p.getCapacity() << endl;

	p.printAllData();

	return 0;
}