#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
int check_board(vector<vector<pair<int, int>>> board) {
    for (int a = 0; a < 5; a++) {
        if (board[a][0].second == 1 && board[a][1].second == 1 && board[a][2].second == 1 && board[a][3].second == 1 && board[a][4].second == 1) return 1;
        if (board[0][a].second == 1 && board[1][a].second == 1 && board[2][a].second && board[3][a].second == 1 && board[4][a].second == 1) return 1;
    }
    return 0;
}
int main() {
    ifstream fin("squid.in");
    vector<pair<int, vector<vector<pair<int, int>>>>> boards;
    vector<int> sums;
    int numbers[100];
    for (int a = 0; a < 100; a++) {
        fin >> numbers[a];
        fin.ignore(1, ',');
    }
    pair<int, int> cell;
    int count = 0;
    cell.second = 0;
    while (!fin.eof()) {
        boards.push_back(make_pair(0, vector<vector<pair<int, int>>>()));
        sums.push_back(0);
        for (int b = 0; b < 5; b++) {
            boards[count].second.push_back(vector<pair<int,int>>());
            for (int c = 0; c < 5; c++) {
                fin >> cell.first;
                sums[count] += cell.first;
                boards[count].second[b].push_back(cell);
            }
        }
        count++;
    }
    for (int a = 0; a < 100; a++) {
        for (int board = 0; board < boards.size(); board++) {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    if (boards[board].second[row][col].first == numbers[a]) { 
                        boards[board].second[row][col].second = 1;
                        sums[board] -= boards[board].second[row][col].first;
                        if (boards[board].first == 0 && check_board(boards[board].second)) {
                            cout << numbers[a] * sums[board] << endl;
                            boards[board].first = 1;
                        } else break;
                    } 
                }
            }
        }
    }
}
