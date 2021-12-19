#include <bits/stdc++.h>
using namespace std;
string getBinaryStringFromHexString (string sHex)
{
    string sReturn = "";
    for (int i = 0; i < sHex.length (); ++i)
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
    int pos = 0;
    int sum = 0;
    cout << packet << endl;
    while (pos != packet.size())  {
        int version;
        int type;
        try {
            version = stoi(packet.substr(pos, 3), 0, 2);
            type = stoi(packet.substr(pos+3, 3), 0, 2);
        } catch (const std::exception& e) {
            break;
        }
        int lengthID;
        string parse = "";
        sum += version;
        if (type == 4)
        {
            for (int i = 0;; i++)
            {
                parse += packet.substr(pos + 6 + (i * 5) + 1, 4);
                if (packet[pos + 6 + (i * 5)] == '0')
                {
                    pos += 6 + (i * 5) + 1 + 4;
                    break;
                }
            }
            continue;
        } else
        {
            lengthID = packet[pos+6] - 48;
            if (lengthID == 0)
            {
                pos += 22;
            } else
            {
                pos += 18;
                continue;
            }
        }
    }
    cout << sum << endl;
    return 0;
}