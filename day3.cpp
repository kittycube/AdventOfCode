

#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

int main() {
    std::ifstream input("input\\day3_input.txt");
    if (!input.is_open()) {
        std::cerr << "Error while reading file" << std::endl;
    }
    else {
        int sum = 0;
        bool mulEnabled = true;
        char buffer[13]{};
        std::string line;
        while (std::getline(input, line, 'm')) {
            if (mulEnabled && line.substr(0,3) == "ul(") {
                line.erase(line.begin(), line.begin() + 3);
                int split = line.find(',');
                if (split!=std::string::npos) {
                    std::string num1 = line.substr(0, split);
                    std::string num2 = line.substr(split+1);
                    int cutoff = num2.find(')');
                    if (cutoff != std::string::npos) {

                        num2 = num2.substr(0, cutoff);

                        //convert to num
                        char* end1;
                        int int1 = strtol(num1.c_str(), &end1, 10);
                        char* end2;
                        int int2 = strtol(num2.c_str(), &end2, 10);

                        if (*end1 || *end2) {

                        }
                        else {
                            sum += int1 * int2;
                        }


                    }
                }
            }
            int hasD = line.find('d');
            if (hasD!=std::string::npos) {
                if (line.substr(hasD, 4) == "do()") {
                    mulEnabled = true;
                }
                if (line.substr(hasD, 7) == "don't()") {
                    mulEnabled = false;
                }
            }
        }
        std::cout << "total: " << sum << std::endl;
        delete buffer;

        input.close();
    }
    return 0;
}

