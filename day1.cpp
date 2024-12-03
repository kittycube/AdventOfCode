#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void sortedInsert(std::vector<int>& vector, const int value) {
    const auto it = std::lower_bound(vector.begin(), vector.end(), value);
    vector.insert(it, value);
}

bool processInput(std::string filename, std::vector<int>& listOne, std::vector<int>& listTwo) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        return false;
    }
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        int numOne, numTwo;
        iss >> numOne >> numTwo;
        sortedInsert(listOne, numOne);
        sortedInsert(listTwo, numTwo);
    }
    return true;
}

int main() {
    std::vector<int> listOne, listTwo;
    if (processInput("input\\day1_z.txt", listOne, listTwo)) {
        if (listOne.size() == listTwo.size()) {
            int distance = 0;
            int similarity = 0;

            for (int i=0; i<listOne.size(); i++) {
                distance += abs(listOne[i]-listTwo[i]);
                const int n = std::ranges::count(listTwo, listOne[i]);
                similarity += listOne[i] * n;
            }
            std::cout << "distance between lists: "  << distance << std::endl;
            std::cout << "similarity: " << similarity << std::endl;
        }
    }
    else {
        std::cerr << "Error while reading file" << std::endl;
    }
    return 0;
}

