#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    ifstream fin("polymer.in");
    string pTemplate; fin >> pTemplate;
    unordered_map<string, char> insertionRules;
    unordered_map<char, int> counts;
    string key;
    for (int i=0; i<100; i++) {
        fin >> key; fin.ignore(4);
        fin >> insertionRules[key];
    }
    for (auto c: pTemplate) counts[c] += 1;
    for (int a=0; a<40; a++) {
        for (int i=0; i<pTemplate.size()-1; i++) {
            char insert = insertionRules[string(1, pTemplate[i])+pTemplate[i+1]];
            pTemplate.insert(i+1, 1, insert); 
            counts[insert]++;
            i++;
        }

        cout << counts['B'] - counts['H'] << endl;
    }
    int max = -999999, min = 999999;
    for (auto i: counts) {
        if (i.second < min) min = i.second;
        else if (i.second > max) max = i.second;
    }
    cout << max-min << endl;

}