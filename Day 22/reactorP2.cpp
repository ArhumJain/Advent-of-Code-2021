#include <bits/stdc++.h>
using namespace std;
struct Cuboid {
    int x1, x2, y1, y2, z1, z2;
    bool state;
};
int main() {
    ifstream fin("reactor.in");
    int minX, maxX, minY, maxY, minZ, maxZ;
    vector<Cuboid> cuboids;
    vector<int> X, Y, Z;
    for (int a=0; a<420; a++) {
        Cuboid cuboid;
        string instruction; fin >> instruction;
        int state = instruction == "on" ? true : false;
        fin.ignore(3); fin >> cuboid.x1; fin.ignore(2); fin >> cuboid.x2;
        fin.ignore(3); fin >> cuboid.y1; fin.ignore(2); fin >> cuboid.y2;
        fin.ignore(3); fin >> cuboid.z1; fin.ignore(2); fin >> cuboid.z2;
        cuboid.x2++; cuboid.y2++; cuboid.z2++;
        X.push_back(cuboid.x1); X.push_back(cuboid.x2);
        Y.push_back(cuboid.y1); Y.push_back(cuboid.y2);
        Z.push_back(cuboid.z1); Z.push_back(cuboid.z2);
        cuboid.state = state;
        cuboids.push_back(cuboid);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    int n = int(X.size());
    auto get_index = [&](vector<int> &C, int c) -> int {
        return int(lower_bound(C.begin(), C.end(), c) - C.begin());
    };
    vector<vector<vector<bool>>> grid(n, vector<vector<bool>>(n, vector<bool>(n, false)));
    for (Cuboid &c: cuboids) {
        int x1 = get_index(X, c.x1);
        int x2 = get_index(X, c.x2);
        int y1 = get_index(Y, c.y1);
        int y2 = get_index(Y, c.y2);
        int z1 = get_index(Z, c.z1);
        int z2 = get_index(Z, c.z2);
        for (int x=x1; x<x2; x++) {
            for (int y=y1; y<y2; y++) {
                for (int z=z1; z<z2; z++) {
                    grid[x][y][z] = c.state;
                }
            }
        }
    }
    unsigned long long sum = 0;
    for (int x=0; x<n-1; x++ ) {
        for (int y=0; y<n-1; y++) {
            for (int z=0; z<n-1; z++) {
                sum += int64_t(grid[x][y][z]) * (X[x+1] - X[x]) * (Y[y+1]-Y[y]) * (Z[z+1]-Z[z]);
            }
        }
    }
    cout << sum << endl;
}