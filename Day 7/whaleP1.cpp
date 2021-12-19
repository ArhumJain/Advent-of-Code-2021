#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std;
int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ifstream fin("whale.in");
    int positions[1000];
    for (int i = 0; i  < 1000; i++) { fin >> positions[i]; fin.ignore(1); }
    std::sort(positions, positions+1000);
    int sum = 0; int center = positions[500];
    for (auto i: positions) sum += abs(i-center);
    cout << sum << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    cout << elapsed.count() << endl;
}