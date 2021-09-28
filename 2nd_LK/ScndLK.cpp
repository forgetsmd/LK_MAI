#include <iostream>

using namespace std;

class FooString {
	int size;
	char* buf;
public:
	FooString(char* tbuf)
	{
		size = strlen(tbuf)+1;
		buf = new char[size];
		for (size_t i = 0; i < size; i++)
		{
			buf[i] = tbuf[i];
		}
	}
	
	~FooString()
	{
		//delete[] buf;
	}

	void show()
	{
		cout << buf;
	}


	bool compare(FooString str)
	{
		if (size = str.size)
		{
			for (size_t i = 0; i < size-1; i++)
			{
				if (buf[i] != str.buf[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
};

int main()
{
	char fst[] = "TestString";
	char scnd[] = "TestString";
	FooString fstOb(fst);
	FooString scndOb(scnd);
	if (fstOb.compare(scndOb) == true)
	{
		cout << "test completed successfully";
	}
	else
	{
		cout << "test failed";
	}
	return 0;
}