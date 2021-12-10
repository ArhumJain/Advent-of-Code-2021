#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int explore(char (&lines)[100][100], int x, int y) {
    int count = 1;
    lines[x][y] = '9';
    for (int dx = (x > 0 ? -1 : 0); dx <= (x < 99 ? 1 : 0); ++dx) {
        for (int dy = (y > 0 ? -1 : 0); dy <= (y < 99 ? 1 : 0); ++dy) {
            if (dx != 0 ^ dy != 0) {
                if (lines[x+dx][y+dy] != '9') {
                    lines[x+dx][y+dy] = '9';
                    count += explore(lines, x+dx, y+dy);
                }
            } 
        }
    }
    return count;
}
int main() {
    ifstream fin("smoke.in");
    vector<int> sizes;
    char lines[100][100];
    for (int a=0; a<100; a++) {
        for (int b=0; b<100; b++) fin >> lines[a][b];
    }
    for (int a=0; a<100; a++) {
        for (int b=0; b<100; b++) {
            if (lines[a][b] < '9') sizes.push_back(explore(lines, a, b));
        }
    }
    sort(sizes.begin(), sizes.end(), greater<int>());
    cout << sizes[0] * sizes[1] * sizes[2] << endl;
}
