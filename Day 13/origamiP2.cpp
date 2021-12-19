#include <fstream>
#include <iostream>
#include <utility>
#include <set>
using namespace std;
int main() {
    ifstream fin("origami.in");
    set<pair<int, int>> coords;
    pair<int, int> coord;
    pair<char, int> folds[12];
    for (int i=0; i<881; i++) {
        fin >> coord.first; fin.ignore(1); fin >> coord.second;
        coords.insert(coord);
    }
    pair<char, int> fold;
    for (int i=0; i<12; i++) {
        fin.ignore(12); fin >> fold.first; fin.ignore(1); fin >> fold.second;
        folds[i] = fold;
    }
    set<pair<int, int>> tempCoords;
    for (pair<char, int> f: folds) {
        tempCoords = coords; coords.clear();
        for (pair<int, int> coord: tempCoords) {
            if (f.first=='x' && coord.first > f.second)  { coords.insert(make_pair(f.second+(f.second-coord.first), coord.second)); }
            else if (f.first=='y' && coord.second > f.second)  { coords.insert(make_pair(coord.first, f.second+(f.second-coord.second))); }
            else coords.insert(coord);
        }
    }
    for (int x=0; x<6; x++){
        cout << endl;
        for (int y=0; y<39; y++) {
            if (coords.find(make_pair(y, x)) != coords.end()) {
                cout << "# ";
            } else cout << ". ";
        }
    }
    cout << coords.size() << endl;
}
