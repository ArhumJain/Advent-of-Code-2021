#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("polymer.in");
    string pTemplate; fin >> pTemplate;
    unordered_map<string, char> insertionRules;
    unordered_map<char, long long> counts;
    unordered_map<string, long long> pairCounts, prevPairCounts;
    string key;
    for (int i=0; i<100; i++) {
        fin >> key; fin.ignore(4);
        fin >> insertionRules[key];
    }
    for (auto c: pTemplate) counts[c] += 1;
    for (int i=0; i<pTemplate.size()-1; i++) {
        pairCounts[string(1, pTemplate[i])+pTemplate[i+1]]++;
    }
    for (int a=0; a<40; a++) {
        prevPairCounts = pairCounts;
        for (auto i: prevPairCounts) {
            char insert = insertionRules[i.first];
            pairCounts[string(1, i.first[0])+insert] += i.second;
            pairCounts[insert+string(1, i.first[1])] += i.second;
            counts[insert] += i.second;
            pairCounts[i.first] -= prevPairCounts[i.first];
        }
    }
    long long max = LONG_LONG_MIN, min = LONG_LONG_MAX;
    for (auto i: counts) {
        if (i.second < min) min = i.second;
        else if (i.second > max) max = i.second;
    }
    cout << max-min << endl;
}