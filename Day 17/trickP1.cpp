#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream fin("trick.in");
    int minX, maxX, minY, maxY;
    fin.ignore(15); fin >> minX; fin.ignore(2); fin >> maxX; fin.ignore(4); fin >> minY; fin.ignore(2); fin >> maxY;
    cout << "Boundary MinX: " << minX << " MaxX: " << maxX << " MinY: " << minY << " MaxY: " << maxY << endl;
    int maxHeight = -999999999;
    int xVel, yVel;
    for (int a=0; a<10000; a++) {
        for (int b=0; b<10000; b++) {
            // if (a==6 && b==9) {
            //     cout << "a: " << a << " b: " << b << endl;
            // }
            int yVel = b;
            int xVel = a;
            int height = -999999999;
            int xPos = 0, yPos = 0;
            while (xPos <= maxX && yPos >= minY) {
                xPos += xVel;
                yPos += yVel;
                yVel--;
                // cout << xPos << " " << yPos << endl;
                if (xVel > 0) xVel--;
                if (yPos > height) height = yPos;
                if ((xPos >= minX && xPos <= maxX) && (yPos >= minY && yPos <= maxY)) {
                    if (height > maxHeight) maxHeight = height;
                    break;
                }
            }
            // cout << "----------------------------------------" << endl;

        }
    }
    cout << maxHeight << endl;
}