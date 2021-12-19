#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("whale.in");
    int positions[1000]; int mean = 0;
    for (int i = 0; i  < 1000; i++) { fin >> positions[i]; fin.ignore(1); mean += positions[i];}
    mean /= 1000;
    cout << (mean-1)/2 << endl;
    int sum = 0;
    for (auto i: positions) sum += (abs(i-mean)+1) * abs(i-mean) / 2;
    cout << sum << endl;
}