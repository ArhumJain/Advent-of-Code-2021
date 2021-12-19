#include <iostream>
#include <fstream>
#include <utility>
const int WIDTH = 10;
const int HEIGHT = 10;
int flash(std::pair<char, bool> (&octopuses)[WIDTH][HEIGHT], int y, int x) {
    octopuses[y][x].first = 48;
    octopuses[y][x].second = true;
    int flashCount = 1;
    for (int dy = (y > 0 ? -1 : 0); dy <= (y < HEIGHT-1 ? 1 : 0); ++dy) {
        for (int dx = (x > 0 ? -1 : 0); dx <= (x < WIDTH-1? 1 : 0); ++dx) {
            if (dx != 0 || dy != 0) {
                if (octopuses[y+dy][x+dx].first > 48) octopuses[y+dy][x+dx].first++;
                if (!octopuses[y+dy][x+dx].second && octopuses[y+dy][x+dx].first > 57) flashCount += flash(octopuses, y+dy, x+dx);
            } 
        }
    }
    return flashCount;
}
int main() {
    std::ifstream fin("octopus.in");
    int flashCount = 0;
    std::pair<char, bool> octopuses[HEIGHT][WIDTH];
    for (int a=0; a<HEIGHT; a++) {
        for (int b=0; b<WIDTH; b++) fin >> octopuses[a][b].first;
    }
    for (int step=0; step<100; step++) {
        for (int y=0; y<HEIGHT; y++) {
            for (int x=0; x<WIDTH; x++) octopuses[y][x].first++;
        }
        for (int y=0; y<HEIGHT; y++) {
            for (int x=0; x<WIDTH; x++) {
                if (!octopuses[y][x].second && octopuses[y][x].first > 57) flashCount += flash(octopuses, y, x);
            }
        }

        for (int y=0; y<HEIGHT; y++) {
            for (int x=0; x<WIDTH; x++) {
                octopuses[y][x].second = false;
            }
        }
    }
    std::cout << flashCount << std::endl;
    for (int a=0; a<HEIGHT; a++) {
        for (int b=0; b<WIDTH; b++ ) {
            std::cout << octopuses[a][b].first << " ";
        }
        std::cout << std::endl;
    }
}