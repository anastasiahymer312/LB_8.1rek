#include <iostream>
#include <cstring>

using namespace std;

int countOccurrences(const char* str, int index) {
    if (index > strlen(str) - 3) return 0;

    if (str[index] == 'a' && str[index + 1] == 'b' && str[index + 2] == 'c') {
        return 1 + countOccurrences(str, index + 1); 
    }

    return countOccurrences(str, index + 1);
}


void replaceOccurrences(const char* str, char* result, int index, int& resultIndex) {
    if (str[index] == '\0') {
        result[resultIndex] = '\0';
        return;
    }

 
    if (str[index] == 'a' && str[index + 1] == 'b' && str[index + 2] == 'c') {
        result[resultIndex++] = '*'; 
        result[resultIndex++] = '*'; // Додаємо другу зірочку
        replaceOccurrences(str, result, index + 3, resultIndex); 
    }
    else {
        result[resultIndex++] = str[index]; 
        replaceOccurrences(str, result, index + 1, resultIndex); 
    }
}

int main() {
    const int maxLength = 101;
    char str[maxLength];

    cout << "Enter string:" << endl;
    cin.getline(str, maxLength - 1);

    // Виклик рекурсивної функції для підрахунку груп "abc"
    int occurrences = countOccurrences(str, 0);
    cout << "Number of 'abc' occurrences: " << occurrences << endl;

    char* modifiedStr = new char[maxLength]; 
    int resultIndex = 0;

    
    replaceOccurrences(str, modifiedStr, 0, resultIndex);

    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr; 
    return 0;
}
