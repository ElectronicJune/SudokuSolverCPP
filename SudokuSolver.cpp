#include <iostream>
#include <cmath>
using namespace std;
char grid[9][9];

void input(){
    for (int i =0;i<9;i++){
        string str;
        cin >> str;
        for (int j =0;j<9;j++){
            grid[i][j] = str[j];
        }
        
    }
}
void output(){
    for (int a=0;a<3;a++){
        for(int b =0;b<3;b++){
            for(int c=0;c<3;c++){
                for (int d=0;d<3;d++){
                    cout << grid[(a*3)+b][(c*3)+d] << " ";
                }
                cout << "  ";
            }
            cout << endl ;
        }
        cout << endl ;
    }
}
bool possible(int y,int x,char n){
    for (int i =0;i<9;i++){
        if (grid[y][i]== n){return false;}
    }
    for (int i =0;i<9;i++){
        if (grid[i][x]==n){return false;}
    }
    int x0 = (int)(floor(x/3))*3;
    int y0 = (int)(floor(y/3))*3;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (grid[y0+i][x0+j]==n){
                return false;
            }
        }
    }
    return true;
}
char intToChar(int n){
    char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
    return nums[n];
}
void solve(){
    for(int y=0;y<9;y++){
        for(int x=0;x<9;x++){
            if (grid[y][x]=='0'){
                for (int n=1;n<10;n++){
                    if (possible(y,x,intToChar(n))){
                        grid[y][x]=intToChar(n);
                        solve();
                        
                    }
                }
                grid[y][x]='0';
                return;
            }
        }
    }
    output();
}

int main(){
    cout << "enter sudoku puzzle:"<< endl;
    input();
    cout << "\nanswer is:\n"<< endl;
    solve();
    while(true){}
}