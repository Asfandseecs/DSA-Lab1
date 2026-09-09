#include <iostream>
#include <vector>

std::vector<std::vector<int>> combine(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B, char op) {
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = (op == '+') ? A[i][j] + B[i][j] : A[i][j] - B[i][j];
    return C;
}

std::vector<std::vector<int>> standardMultiply(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    int n = A.size();
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

std::vector<std::vector<int>> strassenMultiply(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    int n = A.size();
    if (n == 1) return {{A[0][0] * B[0][0]}};

    int k = n / 2;
    std::vector<std::vector<int>> A11(k, std::vector<int>(k)), A12(k, std::vector<int>(k)), A21(k, std::vector<int>(k)), A22(k, std::vector<int>(k));
    std::vector<std::vector<int>> B11(k, std::vector<int>(k)), B12(k, std::vector<int>(k)), B21(k, std::vector<int>(k)), B22(k, std::vector<int>(k));

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];         A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];     A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];         B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];     B22[i][j] = B[i + k][j + k];
        }
    }

    std::vector<std::vector<int>> M1 = strassenMultiply(combine(A11, A22, '+'), combine(B11, B22, '+'));
    std::vector<std::vector<int>> M2 = strassenMultiply(combine(A21, A22, '+'), B11);
    std::vector<std::vector<int>> M3 = strassenMultiply(A11, combine(B12, B22, '-'));
    std::vector<std::vector<int>> M4 = strassenMultiply(A22, combine(B21, B11, '-'));
    std::vector<std::vector<int>> M5 = strassenMultiply(combine(A11, A12, '+'), B22);
    std::vector<std::vector<int>> M6 = strassenMultiply(combine(A21, A11, '-'), combine(B11, B12, '+'));
    std::vector<std::vector<int>> M7 = strassenMultiply(combine(A12, A22, '-'), combine(B21, B22, '+'));

    std::vector<std::vector<int>> C11 = combine(combine(combine(M1, M4, '+'), M5, '-'), M7, '+');
    std::vector<std::vector<int>> C12 = combine(M3, M5, '+');
    std::vector<std::vector<int>> C21 = combine(M2, M4, '+');
    std::vector<std::vector<int>> C22 = combine(combine(combine(M1, M3, '+'), M2, '-'), M6, '+');

    std::vector<std::vector<int>> C(n, std::vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j]         = C11[i][j]; C[i][j + k]     = C12[i][j];
            C[i + k][j]     = C21[i][j]; C[i + k][j + k] = C22[i][j];
        }
    }
    return C;
}

void printMatrix(std::vector<std::vector<int>> M) {
    for (int i = 0; i < M.size(); i++) {
        std::cout << "[ ";
        for (int j = 0; j < M[i].size(); j++) std::cout << M[i][j] << " ";
        std::cout << "]\n";
    }
}

int main() {
    std::vector<std::vector<int>> A2 = {{1, 2}, {3, 4}}, B2 = {{5, 6}, {7, 8}};
    std::cout << "--- 2x2 Test ---\nStandard:\n";
    printMatrix(standardMultiply(A2, B2));
    std::cout << "Strassen:\n";
    printMatrix(strassenMultiply(A2, B2));

    std::vector<std::vector<int>> A4 = {{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}};
    std::vector<std::vector<int>> B4 = {{8,7,6,5},{4,3,2,1},{9,8,7,6},{5,4,3,2}};
    std::cout << "\n--- 4x4 Test ---\nStandard:\n";
    printMatrix(standardMultiply(A4, B4));
    std::cout << "Strassen:\n";
    printMatrix(strassenMultiply(A4, B4));

    std::vector<std::vector<int>> A_simple = {{2,0,0,0},{0,2,0,0},{0,0,2,0},{0,0,0,2}};
    std::vector<std::vector<int>> B_simple = {{1,1,1,1},{2,2,2,2},{3,3,3,3},{4,4,4,4}};
    std::cout << "\n--- Simple 4x4 Comparison ---\nStandard:\n";
    printMatrix(standardMultiply(A_simple, B_simple));
    std::cout << "Strassen:\n";
    printMatrix(strassenMultiply(A_simple, B_simple));

    return 0;
}