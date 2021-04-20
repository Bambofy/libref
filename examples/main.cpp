#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

#include <array>
#include <functional>
#include <map>
#include <memory>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <set>

#include "Reference.h"

class Person
{
public:
	Person(const char * name, int age, Reference<Person> father)
		: name(name), age(age), father(father) {
	}
	
	~Person() {
	
	}
	
	Reference<Person> Father() {
		return father;
	}
	
	const char * Name() {
		return name;
	}
private:
	const char * name;
	int age;
	Reference<Person> father;
};

int main()
{
    Reference<Person> john(new Person("John", 25, Reference<Person>::Null()));
    Reference<Person> other;
    
    other = john;
    
    other.Destroy();
    
    if (!john.Nulled())
    {
        std::cout << "Name: " << john->Name() << std::endl;
    }
}