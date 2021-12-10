#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
bool adjacentMin(string (&lines)[100], int x, int y) {
    int minVal = lines[x][y]-48;
    for (int dx = (x > 0 ? -1 : 0); dx <= (x < 99 ? 1 : 0); ++dx) {
        for (int dy = (y > 0 ? -1 : 0); dy <= (y < 99? 1 : 0); ++dy) {
            if (dx != 0 || dy != 0) {
                if (lines[x+dx][y+dy] < lines[x][y]) return false;
            } 
        }
    }
    return true;
}
int main() {
    ifstream fin("smoke.in");
    string lines[100]; int risk = 0;
    for (int a=0; a<100; a++) fin >> lines[a];
    for (int a=0; a<100; a++) {
        for (int b=0; b<100; b++) {
            if (adjacentMin(lines, a, b)) risk += lines[a][b]-47;
        }
    }
    cout << risk << endl;
}