
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int getOxygen(vector<string> &vec, int size, int pos) {
    if (pos == 11){
        string select = (vec[0][pos] == '1' ? vec[0] : vec[1]);
        return stoi(select, 0, 2);
    }     
    int c = 0;
    for (int a = 0; a < size; a++) {
        if (vec[a][pos] == '1') c++;
    }
    char selection = c >= size - c ? '1' : '0';
    for (auto i = vec.begin(); i != vec.end(); i++) {
        if ((*i)[pos] != selection) {
            vec.erase(i);
            i--;
        }
    }
    return getOxygen(vec, vec.size(), ++pos);
}
int getCo2(vector<string> &vec, int size, int pos) {
    if (pos == 11){
        string select = (vec[0][pos] == '1' ? vec[1] : vec[0]);
        return stoi(select, 0, 2);
    }     
    int c = 0;
    for (int a = 0; a < size; a++) {
        if (vec[a][pos] == '1') c++;
    }
    char selection = c >= size - c ? '0' : '1';
    for (auto i = vec.begin(); i != vec.end(); i++) {
        if ((*i)[pos] != selection) {
            vec.erase(i);
            i--;
        }
    }
    return getCo2(vec, vec.size(), ++pos);
}
int main() {
    ifstream fin("binary.in");

    vector<string> oxygen(1000);
    vector<string> co2(1000);

    for (int a = 0; a < 1000; a++) {
        fin >> oxygen[a];
        co2[a] = oxygen[a];
    }
    cout << (getOxygen(oxygen, 1000, 0))*(getCo2(co2, 1000, 0)) << endl;
    return 0;
}