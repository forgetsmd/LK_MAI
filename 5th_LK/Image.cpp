#include <iostream>

using namespace std;

template<typename T, size_t mx, size_t my>
class Image {
    size_t s_mx = mx;
    size_t s_my = my;
    T* img;
public:
    Image() {
        img = new T[s_mx*s_my]();
    }
    virtual ~Image() {
        delete[] img;
    }

    T get(T x, T y) {
        if (x >= s_mx || y >= s_my || x < 0 || y < 0) {
            throw 1;
        }
        return img[y * s_my + x];
    }

    T set(T x, T y, T color) {
        if (x >= s_mx || y >= s_my || x < 0 || y < 0) {
            throw 1;
        }
        img[y * s_my + x] = color;
    }
    Image<T,mx,my>& operator=(const Image<T,mx,my>& v) {
        delete[] this->img;
        this->s_mx = v.s_mx;
        this->s_my = v.s_my;
        img = new T[s_mx * s_my];

        for (size_t i = 0; i < s_mx * s_my; i++) {
            this->img[i] = v.img[i];
        }
        return *this;
    }
};
int main() {
    try
    {
        Image<int,2,2> frst;
        frst.set(0, 0, 1);
        frst.set(1, 0, 2);
        frst.set(0, 1, 3);
        frst.set(1, 1, 4);

        Image<short,2,2> scnd;
        scnd = frst;

        cout << scnd.get(0, 0) << endl;
        cout << scnd.get(1, 0) << endl;
        cout << scnd.get(0, 1) << endl;
        cout << scnd.get(1, 1) << endl;

        scnd.set(3, 3, 1);
    }
    catch (int)
    {
        cout << "Out of range" << endl;
    }
}