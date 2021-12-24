#include <iostream>
#include <fstream>
using namespace std;
bool space[100][100][100];
int main() {
    ifstream fin("reactor.in");
    int onCount = 0;
    int minX, maxX, minY, maxY, minZ, maxZ;
    for (int a=0; a<420; a++) {
        string instruction; fin >> instruction;
        int state = instruction == "on" ? true : false;
        fin.ignore(3); fin >> minX; fin.ignore(2); fin >> maxX;
        fin.ignore(3); fin >> minY; fin.ignore(2); fin >> maxY;
        fin.ignore(3); fin >> minZ; fin.ignore(2); fin >> maxZ;
        for (int x=minX; x<maxX+1; x++) {
            if (x < -50 || x > 50) continue;
            for (int y=minY; y<maxY+1; y++) {
                if (y < -50 || y > 50) continue;
                for (int z=minZ; z<maxZ+1; z++) {
                    if (z < -50 || z > 50) continue;
                    space[x+50][y+50][z+50] = state;
                }
            }
        }
    }
    for (int x=0; x<100; x++) {
        for (int y=0; y<100; y++) {
            for (int z=0; z<100; z++) {
                if (space[x][y][z]) onCount++;
            }
        }
    }
    cout << onCount << endl;
}