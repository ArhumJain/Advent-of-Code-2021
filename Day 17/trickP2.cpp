#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("trick.in");
    int minX, maxX, minY, maxY;
    fin.ignore(15); fin >> minX; fin.ignore(2); fin >> maxX; fin.ignore(4); fin >> minY; fin.ignore(2); fin >> maxY;
    cout << "Boundary MinX: " << minX << " MaxX: " << maxX << " MinY: " << minY << " MaxY: " << maxY << endl;
    int xVel, yVel;
    int distinctCount = 0;
    for (int a=-1000; a<1000; a++) {
        for (int b=-1000; b<1000; b++) {
            int yVel = b; int xVel = a;
            int height = -999999999;
            int xPos = 0, yPos = 0;
            while (xPos <= maxX && yPos >= minY) {
                xPos += xVel; yPos += yVel;
                yVel--;
                if (xVel > 0) xVel--;
                if (yPos > height) height = yPos;
                if ((xPos >= minX && xPos <= maxX) && (yPos >= minY && yPos <= maxY)) {
                    distinctCount++;
                    break;
                }
            }

        }
    }
    std::cout << distinctCount << endl;
}