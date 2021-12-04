#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("sonar.in");
    vector<int> depths;
    int count = 0;

    while (!fin.eof()) {
        int depth;
        fin >> depth;
        depths.push_back(depth);
    }

    for (int i = 1; i < depths.size(); i++) {
        if (i <= depths.size()-3) {
            if (depths[i] + depths[i+1] + depths[i+2] > depths[i-1] + depths[i] + depths[i+1]) {
                count++;
            }
        }
    }
    cout << count << endl;
}