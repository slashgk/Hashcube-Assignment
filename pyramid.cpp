#include <bits/stdc++.h>

using namespace std;

class Pyramid
{
    public:
    int rows;

    void input(){
        cout<<"Enter no. of rows: "<<endl;
        cin>>rows;
    }

    void print() {
        for (int i=0; i<rows; i++) {
            for (int j=rows-i; j>1; j--){
                cout<<" ";
            }
            for (int j=0; j<=i; j++){
                cout<<("* ");
            }
            cout<<endl;
        }
    }
};

int main() {
    Pyramid p1;
    p1.input();
    p1.print();

    return 0;
}
