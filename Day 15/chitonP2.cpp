#include <bits/stdc++.h>
using namespace std;
const int HEIGHT = 100;
const int WIDTH = 100;
const int directions[4][2] = {{0,1}, {1,0}, {-1, 0}, {0, -1}};
int main() {
    ifstream fin("chiton.in");
    int cave[HEIGHT*5][WIDTH*5];
    for (int a=0; a<HEIGHT; a++) {
        char n;
        for (int b=0; b<WIDTH; b++) {
            fin >> n;
            cave[a][b] = n-48;
            for (int c=0; c<5; c++) {
                for (int d=0; d<5; d++) {
                    if (c != 0 || d != 0) {
                        int x = b + (WIDTH * d);
                        int y = a + (HEIGHT * c);
                        if (cave[a][b] + d + c > 9) cave[y][x] = (cave[a][b]+d+c)%9;
                        else cave[y][x] = cave[a][b]+d+c;
                        
                    }
                }
            }
        }
    }
    pair<int, int> curr = {0, 0};
    pair<int ,int> goal = {HEIGHT*5-1, WIDTH*5-1};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> open;
    map<pair<int, int>, int> cellScores;
    open.push(make_pair(0, curr));
    while (curr != goal) {
        int dx, dy;
        pair<int, int> adjacentCoord;
        int cumScore;
        for (auto direction : directions)
        {
            dx = direction[0]; dy = direction[1];
            if ((curr.second + dy > -1 && curr.second + dy < HEIGHT*5) && (curr.first + dx > -1 && curr.first + dx < WIDTH*5))
            {
                adjacentCoord.first = curr.first+dx;
                adjacentCoord.second = curr.second+dy;
                cumScore = open.top().first + cave[curr.second+dy][curr.first+dx];
                if (cellScores[adjacentCoord] == 0) { 
                    open.push(make_pair(cumScore, adjacentCoord));
                    cellScores[adjacentCoord] = cumScore;
                }
                else if (cellScores[adjacentCoord] != 0 && cumScore < cellScores[adjacentCoord]) {
                    cellScores[adjacentCoord] = cumScore;
                }
            }
        }
        open.pop();
        curr = open.top().second;
    }
    cout << open.top().first << endl;
}