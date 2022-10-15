#include <iostream>
#include <string>
int* returnHexRemainders(int);
std::string convertToHex(int*);

int main(void) {
    int decNum, size;
    int* size_ptr = &size;
    std::cout << "Enter a decimal number: ";
    std::cin >> decNum;

    int *remainderArr = returnHexRemainders(decNum);
    //std::cout << sizeof(remainderArr) / sizeof(int);
    //std::cout << "The hex of " << decNum << " is " << convertToHex();
    return 0;
}

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