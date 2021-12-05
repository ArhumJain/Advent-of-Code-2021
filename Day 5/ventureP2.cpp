#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;
struct Segment {
    int x1, y1;
    int x2, y2;
    int minX, maxX;
    int minY, maxY;
    int slope;
    void construct() {
        minX = min(x1, x2); maxX = max(x1, x2);
        minY = min(y1, y2); maxY = max(y1, y2);
        slope = (x1 == x2) ? -2 : (y2-y1)/(x2-x1);
    }
};
int main() {
    ifstream fin("venture.in");
    int count = 0;
    unordered_map<unsigned int, int> points;
    Segment segment;
    for (int a = 0; a < 500; a++) {
        int x, y;
        fin >> segment.x1; fin.ignore(1);
        fin >> segment.y1; fin.ignore(4);
        fin >> segment.x2; fin.ignore(1);
        fin >> segment.y2;
        segment.construct();
        if (segment.x1 == segment.x2) {
            for (int y = segment.minY; y < segment.maxY+1; y++) {
                points[65536*segment.x1 + y] += 1; 
                if (points[65536*segment.x1 + y] == 2) count++; 
            }
        } else if (segment.y1 == segment.y2) {
            for (int x = segment.minX; x < segment.maxX+1; x++) { 
                points[65536*x + segment.y1] += 1;
                if (points[65536*x + segment.y1] == 2) count++;
            }
        } else if (segment.slope == 1 || segment.slope == -1) {
            int y = segment.slope == 1 ? segment.minY : segment.maxY;
            for (int x = segment.minX; x < segment.maxX+1; x++) {
                points[65536*x + ((y+((x-segment.minX)*segment.slope)))] += 1;
                if (points[65536*x + ((y+((x -segment.minX)*segment.slope)))] == 2) count++;
            }
        }
    }
    cout << count << endl;
}

