#include <iostream>
#include <windows.h>
#include <shellapi.h>
#include <chrono>
#include "dependencies/interpreter.h"
using std::cout;
using std::cin;
using std::endl;

void actionSelector(), mainMenu(), instructionInputStream(), viewRegState(), aboutText(), exitProgram();
bool RUNNING = true;

// I'm working with a lot of dangerous libraries I haven't got to know but it should be under control.
int main(void) {
    dataSeg->setRegValue(0);
    extraSeg->setRegValue(256);
    codeSeg->setRegValue(512);
    stackSeg->setRegValue(1024);
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
        if (actionSelected >= 1 && actionSelected <= 7) {
            isValidInput = true;
        } else {
            retryPrompt = true;
        }
    }

    char writeProgImport, writeProgMode;
    switch(actionSelected) {
        case 1:
            instructionInputStream();
            break;
        case 2:
            viewDefaultMemory();
            break;
        case 3:
            viewRegState();
            break;
        case 4:
            cout << "Feature not yet implemented or supported" << endl;
            system("pause");
            break;
        case 5:
            cout << "Documentation opened in external window!" << endl;
            cout << "If it didn't open a browser tab, please copy and paste the GitHub link to your browser:" << endl;
            cout << "https://github.com/ShySpaceSheep/RSGPR-CPU2022" << endl;
            ShellExecuteW(0, 0, L"https://github.com/ShySpaceSheep/RSGPR-CPU2022", 0, 0, SW_SHOW);
            system("pause");
            break;
        case 6:
            aboutText();
            break;
        case 7:
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
    cout << "| 4. RESET STATE      | Reset registers and memory to default.    |" << endl;
    cout << "| 5. HELP             | Provides a brief documentation via GitHub |" << endl;
    cout << "| 6. ABOUT            | Project details and version               |" << endl;
    cout << "| 7. EXIT             | Exit the program.                         |" << endl;
    cout << "+-----------------------------------------------------------------+" << endl;
}
 
// RIP to people who will read this, this is not standard practice by the way.
void viewRegState() {
    system("cls");
    cout << "+------------------------+   TRSGPR REGISTER STATUS   +--------------------------------+" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|  REGISTER  |   H   |   L   |     |  SEGMENTS  |  VALUE  |     |  POINTERS  |  VALUE  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     A      |  " << gpReg[0]->getHReg() << "   |   " << gpReg[0]->getLReg() << "  |     |     SS     |   " << segReg[0]->getRegisterVal() << "  |     |     SP     |   " << specPurpReg[0]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     B      |  " << gpReg[1]->getHReg() << "   |   " << gpReg[1]->getLReg() << "  |     |     DS     |   " << segReg[1]->getRegisterVal() << "  |     |     BP     |   " << specPurpReg[1]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     C      |  " << gpReg[2]->getHReg() << "   |   " << gpReg[2]->getLReg() << "  |     |     ES     |   " << segReg[2]->getRegisterVal() << "  |     |     SI     |   " << specPurpReg[2]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "|     D      |  " << gpReg[3]->getHReg() << "   |   " << gpReg[3]->getLReg() << "  |     |     CS     |   " << segReg[3]->getRegisterVal() << "  |     |     DI     |   " << specPurpReg[3]->getRegisterVal() << "  |" << endl;
    cout << "+------------+-------+-------+     +------------+---------+     +------------+---------+" << endl;
    cout << "+--------------------------------------------------------------------------------------+" << endl;
    cout << "See anything wrong with the register status? Feel free to open an issue ticket so we can get to solving it." << endl;
    system("pause");
}

void aboutText() {
    system("cls");
    cout << "+-----------------------------------------------------------------------------------------------+" << endl;
    cout << "| The Relatively Simplified General-Purpose Computer                                            |" << endl;
    cout << "| Version 0.2.0 - build 10w4a (UI-Support Soon)                                                 |" << endl;
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
    system("pause");
}

void exitProgram() {
    RUNNING = false;
}
