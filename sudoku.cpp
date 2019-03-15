#include <bits/stdc++.h>

using namespace std;

class Sudoku
{
    public:
    int x,y,num;
    bool invalid=0;
    int sudoku[9][9];

    void input(){
        cout<<"Enter Sudoku:"<<endl;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>sudoku[i][j];
            }
        }
        cout<<"Enter X: ";
        cin>>x;
        cout<<"Enter Y: ";
        cin>>y;
        cout<<"Enter number: ";
        cin>>num;

    }

    void check()
    {
        if(sudoku[x][y]!=0)
            cout<<"Invalid number";
        else{
            for(int i=0;i<9;i++){
                if(sudoku[i][y]==num){
                    invalid = 1;
                    break;
                }
                if(sudoku[x][i]==num){
                    invalid = 1;
                    break;
                }
        }

            int sbox_x = x - x%3;
            int sbox_y = y - y%3;

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(sudoku[i][j]==num){
                        invalid = 1;
                        break;
                    }
                }
                if(invalid){
                    break;
                }
            }
            if(invalid){
                cout<<"Invalid number";
            }
            else{
                cout<<"Valid number";
            }

        }
    }
};

int main() {

    Sudoku obj1;
    obj1.input();
    obj1.check();

    return 0;
}
