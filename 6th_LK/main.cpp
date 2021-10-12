#include <iostream>

using namespace std;

template <typename T>
class SP {
private:
    T* ptr;
public:
    SP()
    {
        ptr = nullptr;
    }
    SP(T *ptr)
    {
        this->ptr = ptr;
    }
    ~SP()
    {
        delete[] ptr;
    }

    T& operator[](int index)
	{
        if (index < 0)
        {
            throw - 1;
        }
        return ptr[index];
	}

    T& operator* ()
    {
        return *ptr;
    }

    T* operator-> ()
    {
        return ptr;
    }
};

template<typename T>
void rec(T& array, int len) 
{
    static int i = 0;
    try
    {
        cout << array[len - i - 1] << ' ';
        ++i;
        rec(array, len);
    }
    catch(...)
    {
        return;
    }
}

int main()
{
    int SIZE;
    cout << "Enter size" << endl;
    cin >> SIZE;
    SP<int> ptr = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        ptr[i] = rand() % 10;
    }
    rec(ptr, SIZE);
    return 0;
}