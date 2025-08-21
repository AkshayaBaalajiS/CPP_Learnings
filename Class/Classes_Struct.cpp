#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
    add code for struct here.
*/

struct Student 
{
    public :
        int age;
        string fname;
        string lname;
        int std;        
};

int main() {
    Student st;
    
    cin >> st.age >> st.fname >> st.lname >> st.std;
    cout << st.age << " " << st.fname << " " << st.lname << " " << st.std;
    
    return 0;
}
