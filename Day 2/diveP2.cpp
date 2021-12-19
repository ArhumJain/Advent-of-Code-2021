#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream fin("dive.in");
    int hPos, depth, aim = 0;

    string direction;
    int d;

    while (!fin.eof()) {
        fin >> direction >> d;
        if (direction == "forward") {
            hPos += d;
            depth += aim * d;
        }
        else if (direction == "down") aim += d;
        else aim -= d;
    }
    
    cout << hPos * depth << endl;

}