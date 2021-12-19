#include <iostream>
#include <fstream>
#include <math.h>
#include <unordered_map>
using namespace std;
inline unordered_map<char, int> decode(string (&patterns)[10]) {
    unordered_map<char, int> key = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}};
    for (auto pattern: patterns) {
        for (char i: pattern) key[i]++;
    } 
    return key;
}
int main() {
    ifstream fin("segment.in");
    string output; int t, d, sum = 0;
    string patterns[10];
    unordered_map<int, int> convertDigit = {{42, 0}, {17, 1}, {34, 2}, {39, 3}, {30, 4}, {37, 5}, {41, 6}, {25, 7}, {49, 8}, {45, 9}};
    for (int a=0; a<200; a++) {
        for (int b=0; b<10; b++) fin >> patterns[b];
        fin.ignore(3);
        unordered_map<char, int> key = decode(patterns);
        for (int b=1; b<5; b++) {
            fin >> output;
            for (auto i: output) t += key[i];
            sum += convertDigit[t] * pow(10, (4-b)); t = 0;
        }
    }
    cout << sum << endl;
}