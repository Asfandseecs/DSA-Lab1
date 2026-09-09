#include <iostream>
#include <string>

int PatternDetection(std::string text, std::string pattern) {
  
    if (pattern.empty()) {
        return 0;
    }

    int n = text.length();
    int m = pattern.length();

  
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

       
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

       
        if (j == m) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    std::string text = "hello world";

   
    std::cout << "Beginning: " << PatternDetection(text, "hello") << "\n";  

    
    std::cout << "End: " << PatternDetection(text, "world") << "\n";       

    std::cout << "Not present: " << PatternDetection(text, "c++") << "\n";   


    std::cout << "Empty pattern: " << PatternDetection(text, "") << "\n";   

    return 0;
}