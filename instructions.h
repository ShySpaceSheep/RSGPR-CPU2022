#include <iostream>
#include <string>
#include "registers.h"

// An 8086 instruction operand can be memory-memory, memory-register, register-register, memory-immediate, and register-immediate.
class Instruction {
    std::string mnemonic;
    std::string opcode;
    std::string dest;
    std::string operand;
    
  public:
    Instruction(std::string name, std::string opcode) {
        this->mnemonic = name;
        this->opcode = opcode;
    }

    void execIns(std::string register) {
        
}
