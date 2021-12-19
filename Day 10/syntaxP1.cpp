#include <iostream>
#include <fstream>
#include <stack>
#include <unordered_map>
using namespace std;
int sum = 0;
unordered_map<char, int> score = {{')', 3}, {']', 57}, {'}', 1197}, {'>', 25137}};
int main() {
    ifstream fin("syntax.in");
    string subsys[102];
    for (int a=0; a<102; a++) fin >> subsys[a];
    int pos = 0; stack<char> s; int size;
    for (auto line: subsys) {
        size = line.size();
        for (int a=0; a<size; a++) {
            if (line[a]==40 || line[a]==60 || line[a]==91 || line[a]==123) s.push(line[a]);
            else if (line[a]-s.top()==1 || line[a]-s.top()==2) s.pop(); 
            else {
                sum += score[line[a]];
                break;
            }
        }
        s.empty();
    }
    cout << sum << endl;
}