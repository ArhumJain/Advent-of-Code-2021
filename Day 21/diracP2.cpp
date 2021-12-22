#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<pair<bool, vector<pair<int, int>>>, ull> p1ScoresToWins;
map<int, ull> p2ScoresToWins;
ull playerWins(pair<bool, vector<pair<int, int>>> &players) {
    if (p1ScoresToWins[players] != 0) return p1ScoresToWins[players];
    else if (players.second[1].second >= 21) return 0;  // make this second[1]
    else if (players.second[0].second>=21) return 1;    // and this second[0] to find the wincount for player 2
    ull winCount = 0;
    bool turn = players.first;
    int prevPos = players.second[turn].first, prevScore = players.second[turn].second;
    for (int a=1; a<4; a++) {
        for (int b=1; b<4; b++) {
            for (int c=1; c<4; c++) {
                int moveDistance = a+b+c;
                players.second[turn].first = (players.second[turn].first + moveDistance) % 10 == 0 ? 10 : (players.second[turn].first + moveDistance) % 10;
                players.second[turn].second += players.second[turn].first;
                players.first = !players.first;
                winCount += playerWins(players);
                players.second[turn].first = prevPos;
                players.second[turn].second = prevScore;
                players.first = !players.first;
                
            }
        }
    }
    p1ScoresToWins[players] = winCount;
    return winCount;
}

int main() {
    pair<bool, vector<pair<int, int>>> players = {false, {{8,0}, {4,0}}};
    bool win = false;
    bool turn = false;
    int diceRolls = 1;
    int moveDistance;
    ull wins;
    wins = playerWins(players);
    cout << wins << endl;
}