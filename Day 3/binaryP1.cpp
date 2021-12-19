#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("binary.in");

    string report[1000];
    int counts[12] = {0};

    string gamma;
    string epsilon;

    for (int a = 0; a < 1000; a++) {
        fin >> report[a];
        for (int b = 0; b < 12; b++) {
            if (report[a][b] == '1') {
                counts[b] += 1;
            }
        }
    }
    for (auto i: counts) {
        if (i > 500) {
            gamma += "1";
            epsilon += "0";
        } else {
            gamma += "0";
            epsilon += "1";
        }
    }

    cout << stoi(gamma, 0, 2) * stoi(epsilon, 0, 2) << endl;
}