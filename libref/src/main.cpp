#include "LibRef.h"

class Person : LibRef::Object
{
public:
	Person();
	~Person();

private:
	LibRef::Reference father;
};

int main()
{
}