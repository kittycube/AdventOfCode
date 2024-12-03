#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//part 1 only

bool isSafe(std::string line) {
    bool saveUsed = false;
    int lvl = 0;
    std::istringstream iss(line);
    int currNum, nextNum, prevNum;
    iss >> currNum;
    while (iss >> nextNum) {
        if (lvl == 0) {
            if (currNum < nextNum) lvl = 1;
            else if (currNum > nextNum) lvl = -1;
            else {
                return false;
            }
        }

        if (currNum < nextNum && lvl == -1) {
            return false;
        }
        if (currNum > nextNum && lvl == 1) {
            return false;
        }
        if (currNum == nextNum) {
            return false;
        }

        if (abs(currNum-nextNum) > 3) {
            return false;
        }

        //prevNum = currNum;
        currNum = nextNum;
    }
    return true;
}
int main() {
    std::ifstream input("input\\day2_example.txt");
    if (!input.is_open()) {
        std::cerr << "Error while reading file" << std::endl;
    }
    else {
        int safeReports = 0;
        std::string line;
        while (std::getline(input, line)) {
            if (isSafe(line)) {
                std::cout << line << " is safe\n";
                safeReports++;
            }
            else {
                std::cout << line << " is not safe\n";

            }

        }
        std::cout << "safe reports: " << safeReports << std::endl;
        input.close();
    }
    return 0;
}