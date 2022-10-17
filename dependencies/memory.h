#include <iostream>
#include <string>

void viewDefaultMemory() {
    system("cls");
    int newLineTracker = 0;
    std::cout << "+------------------- MEMORY -------------------+" << std::endl;
    for (int i = 0; i <= 255; i++) {
        if (newLineTracker == 16) {
            std::cout << std::endl;
            newLineTracker = 0;
        }
        std::cout << "00 ";
        newLineTracker++;
    }
    std::cout << "\n+--- Showing the first 255 bytes of memory ----+" << std::endl;
    system("pause");
}

