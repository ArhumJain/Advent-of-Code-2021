#include <bits/stdc++.h>
using namespace std;
const int yBound = 200;
const int xBound = 200;
void display(vector<vector<bool>> pixels) {
    for (auto a: pixels) {
        for (auto b: a) {
            cout << (b == true ? "#" : ".");
        }
        cout << endl;
    }
}
int main() {
    ifstream fin("trench.in");
    string algorithm; fin >> algorithm;
    vector<vector<bool>> pixels(yBound, vector<bool>(xBound));
    char c;
    for (int a=50; a<150; a++) {
        for (int b=50; b<150; b++) {
            fin >> c;
            pixels[a][b] = c == '#' ? 1 : 0;
        }
    }
    vector<vector<bool>> temp;
    for (int i=0; i<50; i++) {
        temp = pixels;
        for (int y=0; y<yBound; y++) {
            for (int x=0; x<xBound; x++) {
                string input;
                for (int c=-1; c<2; c++) {
                    int cY = y+c;
                    for (int d=-1; d<2; d++) {
                        int cX = x+d;
                        if (cY < 0 || cY > yBound-1 || cX < 0 || cX > xBound-1) {
                            input += i%2 == 0 ? '0' : '1';
                        } else input += temp[cY][cX] == 1 ? '1' : '0';
                    }
                }
                pixels[y][x] = algorithm[stoi(input, 0, 2)] == '#' ? 1 : 0;
            }
        }
    }
    int count = 0;
    for (auto a: pixels) {
        for (auto b: a) {
            if (b) count++;
        }
    }
    cout << count << endl;
}