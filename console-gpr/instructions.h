#include <iostream>
#include <string>

// An 8086 instruction operand can be memory-memory, memory-register, register-register, memory-immediate, and register-immediate.
class Instruction {
    auto operation;
    std::string opcode;
    std::string register;
    int memory, value;
    
  public:
    Instruction(std::string name, auto func()) {
        this->opcode = name;
        this->operation = func();
    }
}