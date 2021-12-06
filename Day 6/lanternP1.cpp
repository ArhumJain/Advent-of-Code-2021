// Initial bruteforce attempt, works fine for 80 day input but 256 days oh boyy, p2, map is so much better
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {{
    ifstream fin("lantern.in");
    vector<int> fish(300);
    for (int a = 0; a < 300; a++) {
        fin >> fish[a];
        fin.ignore(1);
    }
    for (int a = 0; a < 80; a++) {
        int size = fish.size();
        for (int b = 0; b < size; b++) {
            if (fish[b] == 0) {
                fish[b] = 6;
                fish.push_back(8);
                continue;
            }
            fish[b]--;
        }
    }
    cout << fish.size() << endl;
}}