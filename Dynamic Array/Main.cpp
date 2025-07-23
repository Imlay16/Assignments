
#include "DynamicArray.h"

class Person
{
private:
	string name;
	int id;

public:
	Person() = default; 
	Person(string name, int id) : name(name), id(id) { }

	int getId() { return id; }

	string toString() const {
		return "Name: " + name;
	}
};

int main()
{
	Person p1("John", 4);
	Person p2("Alice", 2);
	Person p3("Doom", 1);
	Person p4("Bradley", 5);

	DynamicArray<Person> p;

	p.add(p1);
	p.add(p2);
	p.add(p3);

	cout << "size: " << p.getSize() << endl;
	cout << "capacity: " << p.getCapacity() << endl;

	int result = p.find(p4, [](auto val, auto findVal) { return val.getId() == findVal.getId(); });

	cout << result << endl;

	return 0;
}