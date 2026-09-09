#include <iostream>
#include <vector>


void printPascalsTriangle(int n) {
    std::vector<int> row;
    for (int i = 0; i <= n; i++) {
        std::vector<int> nextRow(i + 1, 1);
        for (int j = 1; j < i; j++) {
            nextRow[j] = row[j - 1] + row[j];
        }
        row = nextRow;   
        std::cout << "Row " << i << ": {";
        for (int j = 0; j <= i; j++) {
            std::cout << row[j] << (j < i ? ", " : "");
        }
        std::cout << "}\n";
    }
    std::cout << "\n";
}
int main() {
      
    std::cout << "--- n = 0 ---\n";
    printPascalsTriangle(0);
    std::cout << "--- n = 1 ---\n";
    printPascalsTriangle(1);
    std::cout << "--- n = 5 ---\n";
    printPascalsTriangle(5);
    return 0;
}
