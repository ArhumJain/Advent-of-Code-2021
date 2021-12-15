#include <bits/stdc++.h>
using namespace std;
const int HEIGHT = 100;
const int WIDTH = 100;
const int directions[4][2] = {{0,1}, {1,0}, {-1, 0}, {0, -1}};
int main() {
    ifstream fin("chiton.in");
    int cave[HEIGHT][WIDTH];
    for (int a=0; a<HEIGHT; a++) {
        char n;
        for (int b=0; b<WIDTH; b++) {
            fin >> n;
            cave[a][b] = n-48;
        }
    }
    pair<int, int> curr = {0, 0};
    pair<int ,int> goal = {HEIGHT-1, WIDTH-1};
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
            if ((curr.second + dy > -1 && curr.second + dy < HEIGHT) && (curr.first + dx > -1 && curr.first + dx < WIDTH))
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