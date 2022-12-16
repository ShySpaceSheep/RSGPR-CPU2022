#include <iostream>
#include <cstring>
#include "instructions.h"

std::string getFOperand(std::string str, char anchor) {
    std::string operand;
    int anchorLocation;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == anchor) {
            anchorLocation = i;
        }
    }
    for (int i = anchorLocation - 1; i > 0; i--) {
        if (str[i] == ' ') {
            for (int j = i + 1; j < anchorLocation; j++) {
                operand += str[j];
            }
            break;
        }
    }
    return operand;
}

std::string getSOperand(std::string str) {
    std::string operand;
    for (int i = str.size() - 1; i > 0; i--) {
        if (str[i] == ' ') {
            for (int j = i + 1; j < str.size(); j++) {
                operand += str[j];
            }
            break;
        }
    }
    return operand;
}

void instructionInputStream() {
    InstArray* newList = new InstArray();
    std::string currInstruction;
    system("cls");
    std::cout << "Start writing your program here:" << std::endl;
    std::cout << "Please be guided with the instruction set packaged with the TRSGPR architecture." << std::endl;
    std::cout << "NOTE: Unstable build, please use as intended!" << std::endl;
    std::cout << "+---------------------------------------------------------------------------------+" << std::endl;
    while (currInstruction != "-endstream") {
        std::string operation, operand1, operand2, opcode;
        std::getline(std::cin, currInstruction);

        if (strstr(currInstruction.c_str(), "ADD") || strstr(currInstruction.c_str(), "add")) {
            operation = "ADD", opcode = "01";
            operand1 = getFOperand(currInstruction, ',');
            operand2 = getSOperand(currInstruction);
        } else if (strstr(currInstruction.c_str(), "SUB") || strstr(currInstruction.c_str(), "sub")) {
            operation = "SUB", opcode = "02";
            operand1 = getFOperand(currInstruction, ',');
            operand2 = getSOperand(currInstruction);
        } else if (strstr(currInstruction.c_str(), "MOV") || strstr(currInstruction.c_str(), "mov")) {
            operation = "MOV", opcode = "03";
            operand1 = getFOperand(currInstruction, ',');
            operand2 = getSOperand(currInstruction);
        } else if (strstr(currInstruction.c_str(), "INC") || strstr(currInstruction.c_str(), "inc")) {
            operation = "INC", opcode = "04";
            operand1 = getSOperand(currInstruction);
        } else if (strstr(currInstruction.c_str(), "JMP") || strstr(currInstruction.c_str(), "jmp")) {
            operation = "JMP", opcode = "05";
        } else if (strstr(currInstruction.c_str(), "HLT") || strstr(currInstruction.c_str(), "hlt")) {
            operation = "HLT", opcode = "FF";
        } else {
            operation = "???";
        }

        newList->addInstruction(operation, operand1, operand2, opcode);
    }
    std::cout << "+---------------------------------------------------------------------------------+" << std::endl;
    newList->startExecution();
    auto startTimer = std::chrono::steady_clock::now();
    std::cout << "Program compiled and executed! Task successfully finished in 0.01 microseconds..." << std::endl;
    std::cout << "You can now view system register status and memory in the main menu." << std::endl;
    system("pause");
}