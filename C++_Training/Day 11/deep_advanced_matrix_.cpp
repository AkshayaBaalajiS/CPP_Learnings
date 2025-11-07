#include <iostream>
using namespace std;
#define ROW 4
#define COL 4

class A {
public:
    int m_arr[ROW][COL];
    A();
    ~A();

    class Helper {
    public:
        A* m_p;
        int rIndex;
        int cIndex;
        Helper(A* p, int ri) : m_p(p), rIndex(ri), cIndex(-1) {}

        Helper operator[](int col_index) {
            cout << "Helper operator [] (int col_index)   : " << col_index << "\n";
            this->cIndex = col_index;
            return *this;
        }

        void operator=(int rhs) {
            cout << "void operator = (int rhs) : \n";
            this->m_p->m_arr[this->rIndex][this->cIndex] = rhs;
        }

        operator int() const {
            return this->m_p->m_arr[this->rIndex][this->cIndex];
        }
    };

    Helper operator[](int row_index);
    friend ostream& operator<<(ostream& os, const Helper& rhs);
};

A::A() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            m_arr[i][j] = j + i * 5;
        }
        cout << "\n";
    }
}

A::Helper A::operator[](int row_index) {
    cout << "A::Helper A :: operator[] (int row_index) " << row_index << "\n";
    return Helper(this, row_index);
}

ostream& operator<<(ostream& os, const A::Helper& rhs) {
    os << rhs.m_p->m_arr[rhs.rIndex][rhs.cIndex];
    return os;
}

A::~A() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << "A[" << i << "][" << j << "] = " << m_arr[i][j] << "   ";
        }
        cout << "\n";
    }
}

int main() {
    A obj;

    cout << "++++++++++++++++++++++++++++++++++++++++++++\n";
    obj[0][1] = 1234; // write
    cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";

    cout << "----------------------------------\n";
    cout << obj[0][1];
    cout << "----------------------------------\n";
}