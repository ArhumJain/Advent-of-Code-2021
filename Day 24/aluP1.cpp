#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
constexpr int varying[14][3] = {{1, 13, 6}, {1, 15, 7}, {1, 15, 10}, {1, 11, 2}, {26, -7, 15}, {1, 10, 8}, {1, 10, 1}, {26, -5, 10}, {1, 15, 5},  {26, -3, 3}, {26, 0, 5}, {26, -5, 11}, {26, -9, 12} , {26, 0, 10}};
ull maxValid = 0;
int zCount;
map<tuple<int, long long, long long>, bool> seenStates;
bool findMaxValid(int inpCount, long long x, long long y, long long z, ull curr) {
    if (z > pow(10, 7)) return false;
    if (inpCount == 14) {
        if (z==0) {
            cout << curr << endl;
            maxValid = curr;
        }
        return true;
    }
    for (int w=9; w>0; w--) {
        if (seenStates[make_tuple(inpCount, w, z)]) return true;
        else {
            int x = ((z%26)+varying[inpCount][1]) == w ? 0 : 1;
            int y = (w + varying[inpCount][2]) * x;
            long long zNew = ((25*x)+1) * (z/varying[inpCount][0]);
            if (zNew == 1) zCount++;
            if (x == 1) {
                findMaxValid(inpCount+1, x, y, zNew+w+varying[inpCount][2], curr+pow(10, 13-inpCount)*w);
            } else {
                findMaxValid(inpCount+1, x, y, zNew, curr+pow(10, 13-inpCount)*w);
            }
            seenStates[make_tuple(inpCount, w, z)] = true;
        }
    }
    return true;
}
int main() {
    findMaxValid(0, 0, 0, 0, 0);
}