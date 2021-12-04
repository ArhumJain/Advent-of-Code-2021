#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;


int numbers[27];
int sums[3] = {0};
int check_board(vector<vector<pair<int, int>>> board) {
    for (int a = 0; a < 5; a++) {
        if (board[a][0].second == 1 && board[a][1].second == 1 && board[a][2].second == 1 && board[a][3].second == 1 && board[a][4].second == 1) return 1;
        if (board[0][a].second == 1 && board[1][a].second == 1 && board[2][a].second && board[3][a].second == 1 && board[4][a].second == 1) return 1;
    }
    return 0;
}
int main() {
    ifstream fin("squid.in");
    
    vector<vector<vector<pair<int, int>>>> boards;

    for (int i = 0; i < 27; i++) {
        fin >> numbers[i];
        fin.ignore(1, ',');
    }
    pair<int, int> cell;
    cell.second = 0;
    for (int a = 0; a < 3; a++) {
        boards.push_back(vector<vector<pair<int, int>>>());
        for (int b = 0; b < 5; b++) {
            boards[a].push_back(vector<pair<int,int>>());
            for (int c = 0; c < 5; c++) {
                fin >> cell.first;
                sums[a] += cell.first; 
                boards[a][b].push_back(cell);
            }
        }
    }

    for (int a = 0; a < 27; a++) {
        for (int board = 0; board < 3; board++) {
            for (int row = 0; row < 5; row++) {
                for (int col = 0; col < 5; col++) {
                    if (boards[board][row][col].first == numbers[a]) { 
                        boards[board][row][col].second = 1;
                        sums[board] -= boards[board][row][col].first;
                        if (check_board(boards[board])) {
                            cout << numbers[a] * sums[board] << endl;
                            return 0;
                        } else break;
                    } 
                }
            }
        }
    }
    cout << "hi" << endl;
}
