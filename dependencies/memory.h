#include <iostream>
#include <string>

void viewDefaultMemory() {
    system("cls");
    std::string memory[1024];
    int newLineTracker = 0;
    std::cout << "+------------------- TRSGPR MEMORY -------------------+" << std::endl;
    for (int i = 0; i <= 255; i++) {
        if (i % 16 == 0) {std::cout << std::endl;}
        std::cout << "00 ";
    }
    std::cout << "\n+----- Showing the first 255 bytes of memory -------+" << std::endl;
    system("pause");
}

