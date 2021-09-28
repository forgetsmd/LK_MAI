#include <iostream>
#include <string>
using namespace std;

int main()
{

    string name;
    cout << "Enter your name" << endl;
    cin >> name;
    cout << "Your variant is: " << name.length() % 1;

    return 0;
}