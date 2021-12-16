#include <bits/stdc++.h>
using namespace std;
int pos = 0;
long long packetEvaluate(string packet) {
    long long version;
    long long type;
    version = stol(packet.substr(pos, 3), 0, 2);
    type = stol(packet.substr(pos+3, 3), 0, 2);
    long long lengthID;
    string parse = "";
    if (type == 4)
    {
        for (long long i = 0;; i++)
        {
            parse += packet.substr(pos + 6 + (i * 5) + 1, 4);
            if (packet[pos + 6 + (i * 5)] == '0')
            {
                pos += 6 + (i * 5) + 1 + 4;
                break;
            }
        }
        return stol(parse, 0, 2);
    } else
    {
        lengthID = packet[pos+6] - 48;
        vector<long long> packetValues;
        if (lengthID == 0)
        {
            long long length;
            try {
                length = stol(packet.substr(pos+7, 15), 0, 2);
            } catch (const std::exception& e) {
                cout << "sus " << endl;
            }
            long long prevPos = pos+22; 
            pos += 22;
            while (pos - prevPos != length) {
                packetValues.push_back(packetEvaluate(packet));
            }
        } else
        {
            long long subCount;
            try {
                subCount = stol(packet.substr(pos+7, 11), 0, 2);
            } catch (const std::exception& e) {
                cout << "sus 2 " << endl;
            }
            long long currSubCount = 0;
            pos += 18;
            for (long long a=0; a<subCount; a++){
                packetValues.push_back(packetEvaluate(packet));
            }
        }
        if (type == 0) {
            long long sum = 0;
            for (auto i: packetValues) sum += i;
            return sum;
        } else if (type == 1) {
            long long product = 1;
            for (auto i: packetValues) product *= i;
            return product;
        } else if (type == 2) {
            long long min = 999999999;
            for (auto i: packetValues) if (i < min) min = i;
            return min;
        } else if (type == 3) {
            long long max = -999999999;
            for (auto i: packetValues) if (i > max) max = i;
            return max;
        } else if (type == 5) {
            return packetValues[0] > packetValues[1];
        } else if (type == 6) {
            return packetValues[0] < packetValues[1];
        } else if (type == 7) {
            return packetValues[0] == packetValues[1];
        }
    }
    return 0;
}
string getBinaryStringFromHexString (string sHex)
{
    string sReturn = "";
    for (long long i = 0; i < sHex.length (); ++i)
    {
        switch (sHex [i])
        {
            case '0': sReturn.append ("0000"); break;
            case '1': sReturn.append ("0001"); break;
            case '2': sReturn.append ("0010"); break;
            case '3': sReturn.append ("0011"); break;
            case '4': sReturn.append ("0100"); break;
            case '5': sReturn.append ("0101"); break;
            case '6': sReturn.append ("0110"); break;
            case '7': sReturn.append ("0111"); break;
            case '8': sReturn.append ("1000"); break;
            case '9': sReturn.append ("1001"); break;
            case 'A': sReturn.append ("1010"); break;
            case 'B': sReturn.append ("1011"); break;
            case 'C': sReturn.append ("1100"); break;
            case 'D': sReturn.append ("1101"); break;
            case 'E': sReturn.append ("1110"); break;
            case 'F': sReturn.append ("1111"); break;
        }
    }
    return sReturn;
}
int main() {
    ifstream fin("packet.in");
    stringstream ss;
    string packet; fin >> packet;
    packet = getBinaryStringFromHexString(packet);
    cout << packetEvaluate(packet) << endl;
    return 0;
}