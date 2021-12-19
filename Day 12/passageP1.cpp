#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAPLENGTH = 24;
unordered_map<string, vector<string>> caves;
int explore(string cave, vector<string> seenSmall) {
    if (cave == "end") return 1;
    else if (!isupper(cave[0]) && find(seenSmall.begin(), seenSmall.end(), cave) != seenSmall.end()) return 0;
    if (!isupper(cave[0]) && cave != "start") seenSmall.push_back(cave);
    int pathCount = 0;
    for (auto c: caves[cave]) {
        pathCount += explore(c, seenSmall);
    }
    return pathCount;
}
int main() {
    ifstream fin("passage.in");
    string read, c1, c2;
    for (int a=0; a<MAPLENGTH; a++) {
        fin >> read;
        c1 = read.substr(0, read.find('-')); c2 = read.substr(read.find('-')+1, read.size());
        if (c1 != "end" && c2 != "start") caves[c1].push_back(c2);
        if (c2 != "end" && c1 != "start") caves[c2].push_back(c1);
    }
    cout << explore("start", vector<string>()) << endl;
}
