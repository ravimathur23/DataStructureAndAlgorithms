#include<iostream>
#include<list>
#include<queue>
using namespace std;

void fillPaintUtil(int screen[8][8], int newR, int newC, int prev, int newVal){
    if((newR < 0) && (newR >= 8) && (newC < 0) && (newC >= 8))
        return;
    if(screen[newR][newC] != prev)
        return;
    
    
    screen[newR][newC] = newVal;
    
    fillPaintUtil(screen, newR+1, newC, prev, newVal);
    fillPaintUtil(screen, newR, newC+1, prev, newVal);
    fillPaintUtil(screen, newR-1, newC, prev, newVal);
    fillPaintUtil(screen, newR, newC-1, prev, newVal);
}
void fillPaint(int screen[8][8], int R, int C, int newVal){
    int prev = screen[R][C];
    fillPaintUtil(screen, R, C, prev, newVal);
}

int main(){

    int screen[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 1, 1, 0, 0},
                        {1, 0, 0, 1, 1, 0, 1, 1},
                        {1, 2, 2, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 0, 1, 0},
                        {1, 1, 1, 2, 2, 2, 2, 0},
                        {1, 1, 1, 1, 1, 2, 1, 1},
                        {1, 1, 1, 1, 1, 2, 2, 1}
                       };
    
    fillPaint(screen, 4, 4, 3);
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
