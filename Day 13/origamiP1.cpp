#include <fstream>
#include <iostream>
#include <utility>
#include <set>
using namespace std;
int main() {
    ifstream fin("origami.in");
    set<pair<int, int>> coords;
    pair<int, int> coord;
    for (int i=0; i<881; i++) {
        fin >> coord.first; fin.ignore(1); fin >> coord.second;
        if (coord.first > 655) coord.first = 655 + (655 - coord.first);
        coords.insert(coord);
    }
    cout << coords.size() << endl;
}