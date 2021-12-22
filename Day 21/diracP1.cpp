#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<int, int>> players = {{8,0}, {4,0}};
    bool win = false;
    bool turn = false;
    int diceRolls = 1;
    int moveDistance;
    while (!win) {
        moveDistance = (diceRolls%100) + (diceRolls+1%100) + (diceRolls+2%100);
        players[turn].first = (players[turn].first + moveDistance) % 10 == 0 ? 10 : (players[turn].first + moveDistance) % 10; // (players[turn].first + moveDistance) % 10;
        players[turn].second += players[turn].first;
        diceRolls += 3;
        if (players[turn].second >= 1000) {
            cout << players[!turn].second * (diceRolls-1) << endl;
            return 0;
        }
        turn = !turn;
    }
}