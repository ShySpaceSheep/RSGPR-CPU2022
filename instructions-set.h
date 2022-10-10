#include <instructions.h>

// Add the list of instructions using our "Instructions" template.
const Instruction* NOP = new Instruction("NOP", "00000000");
const Instruction* ADD = new Instruction("ADD", "00000001");
const Instruction* SUB = new Instruction("SUB", "00000010");
const Instruction* MOV = new Instruction("MOV", "00000011");
const Instruction* INC = new Instruction("INC", "00000100");
const Instruction* JMP = new Instruction("JMP", "00000101");
