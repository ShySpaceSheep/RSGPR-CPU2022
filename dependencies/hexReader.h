#include <iostream>
#include <string>
int* returnHexRemainders(int);
std::string convertToHex(int*);

// TODO: Complete 
int* returnHexRemainders(int decimal) {
    int *remainders;
    int i = 0;
    while (decimal != 0) {
        remainders[i] = decimal % 16;
        decimal /= 16;
        i++;
    }
    return remainders;
}

std::string convertToHex(int* numArr) {
    int size = 0;
    std::string retStr;
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        if (numArr[i] < 10) {
            retStr += (char) '0' + numArr[i];
        } else {
            int difference = numArr[i] - 10;
            retStr += (char) 65 + difference;
        }
    }
    return retStr;
}
