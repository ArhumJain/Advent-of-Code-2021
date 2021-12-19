// absoulte garbage, overthought this trash like never before, p2 was much better after i realized my never ending stupidity. p2
// still garbage just not as much considering i was tired of this puzzle by time time i pulled together a "working" solutoin 
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <utility>
using namespace std;
struct Segment {
    int x1, y1;
    int x2, y2;
    int minX, maxX;
    int minY, maxY;
    bool slope;
    void construct() {
        minX = min(x1, x2); maxX = max(x1, x2);
        minY = min(y1, y2); maxY = max(y1, y2);
        if (y1 == y2) slope = true;
        else slope = false;
    }
};
int overlap(int min1, int min2, int max1, int max2, int &p1, int &p2) { 
    int maxMin = max(min1, min2);
    int minMax = min(max1, max2);
    p1 = maxMin;
    p2 = minMax;
    return minMax - maxMin;
}
int main() {
    ifstream fin("venture.in");
    vector<Segment> segments;
    set<pair<int, int>> points;

    Segment segment;
    for (int a = 0; a < 500; a++) {
        fin >> segment.x1; fin.ignore(1);
        fin >> segment.y1; fin.ignore(4);
        fin >> segment.x2; fin.ignore(1);
        fin >> segment.y2;
        if (segment.x1 == segment.x2 || segment.y1 == segment.y2) { 
            segment.construct();
            segments.push_back(segment);
        }
    }
    for (int a = 0; a < segments.size(); a++) {
        Segment segmentA = segments[a];
        for (int b = a + 1; b < segments.size(); b++) {
            Segment segmentB = segments[b];
            int overlapCount;
            int p1;
            int p2;
            if (segmentA.x1 == segmentB.x1 && (!segmentA.slope && !segmentB.slope)) {
                // overlapCount = overlap(segmentA.maxY, segmentB.maxY, segmentA.minY, segmentB.minY, p1, p2);
                overlapCount = overlap(segmentA.minY, segmentB.minY, segmentA.maxY, segmentB.maxY, p1, p2);
                if (overlapCount > -1) {
                    for (int y = p1; y < p1 + overlapCount + 1; y++) points.insert(make_pair(segmentA.x1, y));
                }
                
            }
            else if (segmentA.y1 == segmentB.y1 && (segmentA.slope && segmentB.slope)) {
                overlapCount = overlap(segmentA.minX, segmentB.minX, segmentA.maxX, segmentB.maxX, p1, p2);
                if (overlapCount > -1) {
                    for (int x = p1; x < p1 + overlapCount + 1; x++) points.insert(make_pair(x, segmentA.y1));
                }
            }
            else if (segmentA.slope && !segmentB.slope) {
                // if (segmentA.maxX >= segmentB.x1 && segmentB.minY <= segmentA.y1) points.insert(make_pair(segmentB.x1, segmentA.y1));
                if ((segmentB.x1 <= segmentA.maxX && segmentB.x1 >= segmentA.minX) && (segmentA.y1 >= segmentB.minY && segmentA.y1 <= segmentB.maxY)) points.insert(make_pair(segmentB.x1, segmentA.y1));
            }
            else if (!segmentA.slope && segmentB.slope) {
                if ((segmentA.x1 <= segmentB.maxX && segmentA.x1 >= segmentB.minX) && (segmentB.y1 >= segmentA.minY && segmentB.y1 <= segmentA.maxY)) points.insert(make_pair(segmentA.x1, segmentB.y1));
            }

        }
    }
    std::cout << points.size() << std::endl;
}