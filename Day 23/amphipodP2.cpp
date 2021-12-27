// Oh my lord, this was the worst puzzle so far this year. Runs ridiculously slow, ESPECIALLY in a language like C++, pure terrible, but I finally finished!
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> StateCost;

bool validHallwayIndex(int i);
bool roomContainsOthers(char roomType);
bool hallwayPathClear(int hallwayPos1, int hallwayPos2);
int anyOpenInRoom(char roomType);
int getEnergy(char roomType, int stepCount);
int hammingDist(string &str1, string &str2);


// Set up information needed to traverse state
string currState = "...DDDD..BCBA..CBAB..CACA..";
int currCost = 0;
map<char, int> roomTypePositions = {{'A', 3}, {'B', 9}, {'C', 15}, {'D', 21}};
map<int, char> hallwayEntrancePositions = {{2, 'A'}, {4, 'B'}, {6, 'C'}, {8, 'D'}};
map<int, int> hallwayPositions = {{0, 0}, {1, 1}, {2, 2}, {7, 3}, {8, 4}, {13, 5}, {14, 6}, {19, 7}, {20, 8}, {25, 9}, {26, 10}};

// Define open and closed sets for pathfinding
priority_queue<StateCost, vector<StateCost>, greater<StateCost>> open; // Min heap
map<string, bool> closed;
int main() {
    open.push(make_pair(0, currState)); // Energy cost for getting to initial state is 0
    while (currState != "...AAAA..BBBB..CCCC..DDDD..") { // <--- Destination state, when all rooms are filled with their corresponding type (A, B, C, D)
        int currRoomIndex = 0; // <-- should be 2, 4, 6, 8 because index of spaces above each room in terms of hallway only 
        char currRoom;
        int openRoomIndex;
        for (int c=0; c<27; c++) { // <--- Find where all movable fish can go to
            char curr = currState[c];
            currRoomIndex += (c == 3 || c==9 || c==15 || c==21) ? 2 : 0;
            currRoom = hallwayEntrancePositions[currRoomIndex];
            if (curr == '.') continue;
            openRoomIndex = anyOpenInRoom(curr);
            if (validHallwayIndex(c) && !roomContainsOthers(curr) && openRoomIndex != -1) { // need to add pathClear
                int pos1, pos2;
                if (c > roomTypePositions[curr]-1) {
                    pos1 = roomTypePositions[curr]-1; 
                    pos2 = c-1;
                }
                else {
                    pos1 = c+1;
                    pos2 = roomTypePositions[curr]-1;
                }
                if (hallwayPathClear(pos1, pos2)) {
                    string state = currState;
                    int cost = currCost;
                    state[openRoomIndex] = curr;
                    state[c] = '.'; // first is the string representation of the state
                    cost += getEnergy(curr, (openRoomIndex - roomTypePositions[curr] + 1) + // second is the cost of reaching this new state
                                    abs(hallwayPositions[c] - (hallwayPositions[roomTypePositions[curr]-1])));
                    open.push(make_pair(cost, state));
                }

                continue;
            }
            openRoomIndex = anyOpenInRoom(currRoom);
            if (roomContainsOthers(currRoom) && ((openRoomIndex==-1 && c == roomTypePositions[currRoom]) || openRoomIndex+1 == c)) { // <--- We only want to allow moving fish out of the room if they dont belong there
                for (pair<const int, int> hallwayPosition: hallwayPositions) {
                    int pos1, pos2;
                    if (hallwayPosition.first > roomTypePositions[currRoom]-1) { 
                        pos1 = roomTypePositions[currRoom]-1;
                        pos2 = hallwayPosition.first; 
                    }
                    else { 
                        pos1 = hallwayPosition.first; 
                        pos2 = roomTypePositions[currRoom]-1; 
                    }
                    if (validHallwayIndex(hallwayPosition.first) && hallwayPathClear(pos1, pos2)) {
                        string state = currState;
                        int cost = currCost;
                        state[hallwayPosition.first] = curr;
                        state[c] = '.';
                        cost += getEnergy(curr, ((openRoomIndex == -1 ? 0 : openRoomIndex - (roomTypePositions[currRoom]-1)) +
                                           abs(hallwayPosition.second-currRoomIndex)+1));
                        open.push(make_pair(cost, state));
                    }
                }
            }
        }
        // Done exploring this state, add it to the closed set
        do {
            closed[open.top().second] = true;
            open.pop();
            currState = open.top().second;
            currCost = open.top().first;
        } while (closed[currState]);
    }
    cout << currState << endl;
    cout << currCost << endl;
}

int hammingDist(string &str1, string &str2)
{
    int i = 0, count = 0;
    for (int i=0; i<str1.size(); i++) {
        if (str1[i] != str2[i])
            count++;
    }
    return count;
}

bool validHallwayIndex(int i) {
    return (i==0 || i==1 || i==7 || i==13 || i==19 || i==25 || i==26);
}

bool roomContainsOthers(char roomType) {
    for (int a=roomTypePositions[roomType]; a<roomTypePositions[roomType]+4; a++) {
        if (currState[a] != roomType && currState[a] != '.') {
            return true;
        }
    }
    return false;
}

bool hallwayPathClear(int hallwayPos1, int hallwayPos2) {
    for (int pos=hallwayPos1; pos<hallwayPos2+1; pos++) {
        if (validHallwayIndex(pos) && currState[pos] != '.') return false;
    }
    return true;
}

int anyOpenInRoom(char roomType) {
    for (int a=roomTypePositions[roomType]+3; a>roomTypePositions[roomType]-1; a--) {
        if (currState[a] == '.') return a;
    }
    return -1;
}

int getEnergy(char roomType, int stepCount) {
    return pow(10, roomType-65) * stepCount; // Subtracting 65 gives us a power, from 0-3, to raise 10 to for A, B, C, D - 1, 10, 100, 1000;
}