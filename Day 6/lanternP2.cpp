#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;
int main() {
    ifstream fin("lantern.in");
    unordered_map<int, long long> timerCounts {{8,0}, {7,0}, {6,0}, {5,0}, {4,0}, {3,0}, {2,0}, {1,0}, {0,0}};
    int timer;
    for (int a = 0; a < 300; a++) {
        fin >> timer;
        timerCounts[timer] += 1;
        fin.ignore(1);
    }
    long long spawns = 0; long long sum = 300;
    for (int a = 0; a < 256; a++) {
        spawns = timerCounts[0]; sum += spawns;
        for (int timer = 0; timer < 8; timer++) {
            timerCounts[timer] = timerCounts[timer+1];
        }
        timerCounts[8] = spawns;
        timerCounts[6] += spawns;
    }
    cout << sum << endl;
}