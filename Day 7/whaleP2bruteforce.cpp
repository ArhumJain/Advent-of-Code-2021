#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin("whale.in");
    int positions[1000]; int min = 9999; int max = -9999;
    for (int i = 0; i  < 1000; i++) {
         fin >> positions[i]; fin.ignore(1); 
         if (positions[i] < min) min = positions[i];
         else if (positions[i] > max) max = positions[i];
    }
    int sum = 0; int minSum = std::numeric_limits<int>::max();
    for (int i = min; i < max+1; i++) {
        for (int j = 0; j < 1000; j++) {
            for (int k =  1; k < abs(positions[j]-i)+1; k++) sum += k;
        }
        if (sum < minSum) minSum = sum;
        else sum = 0;
    }
    cout << minSum << endl;
}