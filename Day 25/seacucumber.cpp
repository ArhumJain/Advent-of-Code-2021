#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int simulate(vector<vector<char>> &curr, vector<vector<char>> &prev, int stepCount) {
    if (curr == prev) return stepCount;
    prev = curr;
    for (int a=0; a<137; a++) {
        for (int b=0; b<139; b++) {
            if (prev[a][b] == '>') {
                int destination = (b+1)%139;
                if (prev[a][destination] == '.') {
                    curr[a][b] = '.';
                    curr[a][destination] = '>';
                }
            }
        }
    }
    prev = curr;
    for (int a=0; a<137; a++) {
        for (int b=0; b<139; b++) {
            if (prev[a][b] == 'v') {
                int destination = (a+1)%137;
                if (prev[destination][b] == '.') {
                    curr[a][b] = '.';
                    curr[destination][b] = 'v';
                }
            }
        }
    }
    return simulate(curr, prev, stepCount+1);
}
int main() {
    ifstream fin("seacucumber.in");
    vector<vector<char>> curr;
    vector<vector<char>> prev;
    for (int a=0; a<137; a++) {
        curr.push_back(vector<char>());
        for (int b=0; b<139; b++) {
            char read; fin >> read;
            curr[a].push_back(read);
        }
    }
    cout << simulate(curr, prev, 0);
}