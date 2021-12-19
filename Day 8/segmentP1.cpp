#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("segment.in");
    string output; int count = 0; 
    for (int a=0; a<200; a++) {
        fin.ignore(61);
        for (int b=0; b<4; b++) {
            fin >> output;
            if (output.size() == 2 || output.size() == 4 || output.size() == 3 || output.size() == 7) count++;
        }
    }
    std::cout << count << endl;
}