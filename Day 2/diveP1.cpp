#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ifstream fin("dive.in");
    int hPos, depth = 0;

    string direction;
    int d;

    while (!fin.eof()) {
        fin >> direction >> d;
        if (direction == "forward") hPos += d;
        else if (direction == "down") depth += d;
        else depth -= d;
    }
    
    cout << hPos * depth << endl;

}