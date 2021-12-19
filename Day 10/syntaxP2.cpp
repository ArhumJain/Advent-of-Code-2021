#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<char, int> score = {{'(', 1}, {'[', 2}, {'{', 3}, {'<', 4}};
int main() {
    ifstream fin("syntax.in");
    vector<unsigned long long> scores;
    unsigned long long sum = 0; int size = 0; bool incomplete = true; string subsys[102]; vector<char> s; 
    for (int a=0; a<102; a++) fin >> subsys[a];
    for (auto line: subsys) {
        size = line.size(); incomplete = true;
        for (int a=0; a<size; a++) {
            if (line[a]==40 || line[a]==60 || line[a]==91 || line[a]==123) s.push_back(line[a]);
            else if (line[a]-s.back()==1 || line[a]-s.back()==2) s.pop_back(); 
            else  { 
                incomplete = false; 
                s.clear();
                break; 
            }
        }
        if (incomplete) {
            size = s.size();
            for (int a=0; a<size; a++) {
                sum = 5*sum+score[s.back()];
                s.pop_back();
            }
            scores.push_back(sum); sum = 0;
        } else s.clear();
        sum = 0;
    }
    sort(scores.begin(), scores.end());
    cout << scores[scores.size()/2]<< endl;
}