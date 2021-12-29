// A very, very simple interpreter to help test 
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
int main(int argc, char *argv[]) {
    if (argc == 0) {
        std::cout << "Error: no input file" << std::endl;
        return -1;
    }
    else {
        std::ifstream fin("../alu3.in");
        std::string parseLine;
        std::stringstream ss;
        std::string currParse;
        std::unordered_map<char, long long*> vars; 
        while (getline(fin, parseLine)) {
            ss.clear();
            ss << parseLine; ss >> currParse;
            if (currParse == "out") {
                std::string inp; ss>>inp;
                if (vars[inp[0]] != nullptr) {
                    std::cout << *(vars[inp[0]]) << std::endl;
                } else std::cout << inp << std::endl;
            }
            else if (currParse == "inp") {
                char var; ss >> var;
                std::string val; 
                std::cin >> val;
                vars[var] = new long long(stol(val));
            }
            else if (currParse == "int") {
                char newVar; ss >> newVar;
                std::string val; ss >> val;
                vars[newVar] = new long long(stol(val));
            }
            else {
                char var; ss >> var;
                if (vars[var] == nullptr) {
                    std::cout << "Variable " << var << " not yet declared" << std::endl;
                    return -1;
                }
                else if (currParse == "add") {
                    std::string val; ss >> val;
                    if (vars[val[0]] != nullptr) *(vars[var]) += *(vars[val[0]]);
                    else *(vars[var]) += stol(val);
                }
                else if (currParse == "mul") {
                    std::string val; ss >> val;
                    if (vars[val[0]] != nullptr) *(vars[var]) *= *(vars[val[0]]);
                    else *(vars[var]) *= stol(val);
                }
                else if (currParse == "div") {
                    std::string val; ss >> val;
                    if (vars[val[0]] != nullptr) *(vars[var]) /= *(vars[val[0]]);
                    else *(vars[var]) /= stol(val);
                }
                else if (currParse == "mod") {
                    std::string val; ss >> val;
                    if (vars[val[0]] != nullptr) *(vars[var]) %= *(vars[val[0]]);
                    else *(vars[var]) %= stol(val);
                }
                else if (currParse == "eql") {
                    std::string val; ss >> val;
                    if (vars[val[0]] != nullptr) *(vars[var]) = *(vars[val[0]]) == *(vars[var]);
                    else *(vars[var]) = *(vars[var]) == stol(val);
                }
            }
        }
    }
    return 0;
}