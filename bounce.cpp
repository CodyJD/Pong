//Author: Cody Davis
//description: we are testing out collission 
//and programming in this porgram

#include <iostream>
#include <unistd.h>
using namespace std;
const int W = 40;
const int H = 40;
void show_arr(char arr[][W], int H, int W);
class Ball {
    public:
        double pos[2];
        double vel[2];
        
        Ball () { pos[0]=W/2; pos[1]= H/2; vel[0]=vel[1]=0;}

};

int main(void) {
    char arr[H][W];
    Ball b;
    int direction = 0;
    b.vel[0]=2.0;
    do {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                arr[i][j] = '.';
            }
        }
        arr[(int)b.pos[1]][(int)b.pos[0]] = '#';
        show_arr(arr,H,W);
        usleep(100000);
        b.pos[0] += b.vel[0];
        b.pos[1] += b.vel[1];
        //b.vel[0] += 0.02;
        if (b.pos[0] >= W - 2) {
            b.vel[0] = -b.vel[0];
            b.pos[0] = W-1;
        }
        if (b.pos[0] < 0) {
            b.pos[0] = 0;            
            b.vel[0] = -b.vel[0];
        }
    }while (true);

    return 0;
}


void show_arr(char arr[][W], int H, int W) {

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << arr[i][j];
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
