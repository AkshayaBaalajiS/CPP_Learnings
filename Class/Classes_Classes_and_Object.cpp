#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Write your Student class here

class Student
{
    public :
        int score[5];
        Student()
        {
            
        }
        
        ~Student()
        {
            
        }
        
        void input()
        {
            int m1,m2,m3,m4,m5;
            cin>>m1>>m2>>m3>>m4>>m5;
            
            score[0]=m1;
            score[1]=m2;
            score[2]=m3;
            score[3]=m4;
            score[4]=m5;        
        }
        
        int calculateTotalScore()
        {
            return score[0] + score[1] + score[2] + score[3] + score[4] ;
        }
};


int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
