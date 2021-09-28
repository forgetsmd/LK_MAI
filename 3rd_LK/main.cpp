#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const int SIZE = 10;

class Protocol
{
public:
	virtual void send(char* buf, int len) {};
};

class BinaryProtocol : public Protocol
{
public:
	void send(char* buf, int len) override
	{
		for (int i = 0; i < len && buf[i] != '\0'; i++)
		{
			for (int i = 7; i >= 0; i--)
			{
				cout << ((buf[i] >> i) & 0x01);
			}
			cout << " ";
		}
	}
};

class HexProtocol : public Protocol
{
public:
	void send(char* buf, int len) override
	{
		for (int i = 0; i < len && buf[i] != '\0'; i++)
		{
			cout << "0x" << hex << (int)(buf[i] & 0xff) << " ";
		}
	}
};


void sendAll(Protocol** p, int number_of_prorocols)
{
	char fromconsole[SIZE];
	cin >> fromconsole;

	for (int i = 0; i < number_of_prorocols; i++)
	{
		p[i]->send(fromconsole, SIZE);
		cout << endl;
	}
}

void readFromFile(string file_dir, Protocol** p)
{
	string line;
	ifstream in(file_dir);
	int count = 0;

	if (in.is_open())
	{
		while (getline(in, line))
		{
			count++;
		}

		in.seekg(0, ios::beg);
		p = new Protocol * [count];
		int i = 0;

		while (getline(in, line))
		{
			if ((const char*)line[0] == "H")
			{
				p[i] = new HexProtocol;
			}
			else
			{
				p[i] = new BinaryProtocol;
			}
			i++;
		}
		sendAll(p, count);
		delete[] p;
	}
	in.close();
}


int main(string arg)
{
	Protocol** protocol = nullptr;
	readFromFile(arg, protocol);
	return 0;
}