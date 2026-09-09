#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findMode(std::vector<int> arr) {
    if (arr.empty()) {
        return {};
    }
    std::unordered_map<int, int> counts;
    for (int num : arr) {
        counts[num]++;
    }  
    int maxCount = 0;
    for (auto pair : counts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
        }
    } 
    std::vector<int> modes;
    for (auto pair : counts) {
        if (pair.second == maxCount) {
            modes.push_back(pair.first);
        }
    }
    return modes;
}
int main() {
    std::vector<int> arr1 = {1, 3, 3, 2, 3, 4, 3};
    std::vector<int> result1 = findMode(arr1);
    std::cout << "1. Unique Mode: " << result1[0] << "\n";
    std::vector<int> arr2 = {2, 5, 2, 8, 5, 1};
    std::vector<int> result2 = findMode(arr2);
    std::cout << "2. Multiple Modes: ";
    for (int num : result2) {
        std::cout << num << " ";    }
    std::cout << "\n";
    std::vector<int> arr3 = {};
    std::vector<int> result3 = findMode(arr3);
    std::cout << "3. Empty Array Size: " << result3.size() << "\n";
    return 0;
}