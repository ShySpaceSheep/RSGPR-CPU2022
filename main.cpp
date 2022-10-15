#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include "dependencies/registers.h"
using std::cout;
using std::cin;
using std::endl;

void actionSelector(), mainMenu(), viewRegState(), aboutText(), exitProgram();
bool RUNNING = true;

// I'm working with a lot of dangerous libraries I haven't got to know but it should be under control.
int main(void) {
    while (RUNNING) {
        system("cls");    // Very dangerous, only used for demonstration purposes.
        int actionID;
        mainMenu();
        actionSelector();
    }

    return 0;
}

void actionSelector() {
    int actionSelected = -1;
    bool isValidInput = false, retryPrompt = false;
    while (!isValidInput) {
        if (!retryPrompt) {
            cout << "Please select the number of the specific action you wish to perform: ";
            cin >> actionSelected;
        } else {
            cout << "Please choose from [1] to [6] as shown: ";
            cin >> actionSelected;
        }
        if (actionSelected >= 1 && actionSelected <= 6) {
            isValidInput = true;
        } else {
            retryPrompt = true;
        }
    }

    switch(actionSelected) {
        case 1:
            cout << "Not yet implemented" << endl;
            system("pause");
            break;
        case 2:
            cout << "Not yet implemented" << endl;
            system("pause");
            break;
        case 3:
            viewRegState();
            break;
        case 4:
            cout << "Documentation opened in external window!" << endl;
            cout << "If it didn't, copy and paste the GitHub link to your browser:" << endl;
            cout << "https://github.com/ShySpaceSheep/RSGPR-CPU2022" << endl;
            ShellExecuteW(0, 0, L"https://github.com/ShySpaceSheep/RSGPR-CPU2022", 0, 0, SW_SHOW);
            system("pause");
            break;
        case 5:
            aboutText();
            break;
        case 6:
            RUNNING = false;
            break;
        default:
            cout << "Unknown fatal error, please restart the program and try again." << endl;
            system("pause");
            exitProgram();
    }
}

void mainMenu() {
    int actionSelect;
    cout << "+-----------------------------------------------------------------+" << endl;
    cout << "|   The Relatively Simple General-Purpose Register Computer       |" << endl;
    cout << "+-----------------------------------------------------------------+" << endl;
    cout << "| 1. WRITE PROGRAM    | Write a simple program for the RSGPR.     |" << endl;
    cout << "| 2. VIEW MEMORY      | View the 1024kb total memory in pages.    |" << endl;
    cout << "| 3. VIEW REGISTERS   | View register status                      |" << endl;
    cout << "| 4. HELP             | Provides a brief documentation via GitHub |" << endl;
    cout << "| 5. ABOUT            | Project details and version               |" << endl;
    cout << "| 6. EXIT             | Exit the program.                         |" << endl;
    cout << "+-----------------------------------------------------------------+" << endl;
}

// RIP to people who will read this, this is not standard practice by the way.
void viewRegState() {
    system("cls");
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|  REGISTER  |   H   |   L   |     |  SEGMENTS  |  VALUE  |     |  POINTERS  |  VALUE  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     A      |  " << gpReg[0]->getHighReg() << "   |   " << gpReg[0]->getLowReg() << "  |     |     SS     |   " << segReg[0]->getRegisterVal() << "  |     |     SP     |   " << specPurpReg[0]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     B      |  " << gpReg[1]->getHighReg() << "   |   " << gpReg[1]->getLowReg() << "  |     |     DS     |   " << segReg[1]->getRegisterVal() << "  |     |     BP     |   " << specPurpReg[1]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     C      |  " << gpReg[2]->getHighReg() << "   |   " << gpReg[2]->getLowReg() << "  |     |     ES     |   " << segReg[2]->getRegisterVal() << "  |     |     SI     |   " << specPurpReg[2]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     D      |  " << gpReg[3]->getHighReg() << "   |   " << gpReg[3]->getLowReg() << "  |                                  |     DI     |   " << specPurpReg[3]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+                                  +------------+---------+" << endl;
    cout << "You will now be returned to the main menu..." << endl;
    system("pause");
}

void aboutText() {
    system("cls");
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "| The Relatively Simplified General-Purpose Computer                                            |" << endl;
    cout << "| Version 0.1.0 - build 10w3a (UI-Support Soon)                                                 |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "|                                                                                               |" << endl;
    cout << "| TRSGPC is our take on a theoretical simplified GPR-CPU architecture, more specifically, the   |" << endl;
    cout << "| 8086 architecture, used to demonstrate the capabilities of the 8086 and its features in       |" << endl;
    cout << "| in contrast to the other architecture such as the RSCPU and the Stack-based architecture.     |" << endl;
    cout << "|                                                                                               |" << endl;
    cout << "| The source code of this project is available in GitHub (currently private repository):        |" << endl;
    cout << "| https://github.com/ShySpaceSheep/RSGPR-CPU2022                                                |" << endl;
    cout << "|                                                                                               |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "| Contributors:                                                                                 |" << endl;
    cout << "| Jose Elijah Fernandez, Jedidiah Ramos, Jason Carlo Obiso, Carl Vincent Piramide,              |" << endl;
    cout << "| Christian Leo Martinez, Yureen Mae Flores, Kelly Tom Cu, Adrian De Leon, Bermar Villarazo Jr. |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "| Advisor: Mr. Ralph Pepe Laviste                                                               |" << endl;
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    system("pause");
}

void exitProgram() {
    RUNNING = false;
}
