// Notice improvement in way of thinking and slight difference in approach to this problem, using maps vs vectors speeds
// up greatly!
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAPLENGTH = 24;
unordered_map<string, vector<string>> caves;
unordered_map<string, int> seenSmall;
int explore(string cave, string seenTwice) {
    if (cave == "end") { return 1; }
    else if (!isupper(cave[0]) && seenSmall[cave] > 1 && cave != seenTwice) { return 0; }
    int pathCount = 0; string nextSeenTwice;
    for (auto i: caves[cave]) {
        nextSeenTwice = seenTwice;
        if (!isupper(i[0]) && i != "end")
        {
            if ((seenTwice == "" && seenSmall[i] == 1) || seenSmall[i] < 1) { seenSmall[i]++; }
            else { continue; }
            if (seenTwice == "" && seenSmall[i] == 2) { nextSeenTwice = i; } // comment this line and does same as part 1
        }
        pathCount += explore(i, nextSeenTwice);
        seenSmall[i]--;
    }
    return pathCount;
}
int main() {
    ifstream fin("passage.in");
    string read, c1, c2;
    for (int a=0; a<MAPLENGTH; a++) {
        fin >> read;
        c1 = read.substr(0, read.find('-')); c2 = read.substr(read.find('-')+1, read.size());
        if (c1 != "end" && c2 != "start") { caves[c1].push_back(c2); }
        if (c2 != "end" && c1 != "start") { caves[c2].push_back(c1); }
    }
    cout << explore("start", string()) << endl;
}
