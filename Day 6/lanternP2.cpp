#include <iostream>
#include <fstream>
int main() {
    std::ifstream fin("lantern.in");
    long long timerCounts[9] = {0};
    int timer;
    for (int a = 0; a < 300; a++) {
        fin >> timer; timerCounts[timer] += 1; fin.ignore(1);
    }
    long long spawns = 0; long long sum = 300;
    for (int a = 0; a < 256; a++) {
        spawns = timerCounts[0]; sum += spawns;
        for (int timer = 0; timer < 8; timer++) timerCounts[timer] = timerCounts[timer+1];
        timerCounts[8] = spawns; timerCounts[6] += spawns;
    }
    std::cout << sum << std::endl;
}