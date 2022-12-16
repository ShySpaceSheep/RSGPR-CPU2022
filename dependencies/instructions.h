#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "definitions.h"
#include "memory.h"

// An 8086 instruction operand can be memory-memory, memory-register, register-register, memory-immediate, and register-immediate.
class Instruction {
    std::string mnemonic;
    std::string opcode;   // This is in hex, so 00000100 will be 04.
    std::string opr1;
    std::string opr2;

    bool isStrNum(std::string str) {
        if(str.size() == 0) {return false;}
        for(int i = 0; i < str.size(); i++) {
            if((str[i] >= '0' && str[i] <= '9') == false) {
                return false;
            }
        }
        return true;
    }

    int readHexadecimal(std::string hexStr) {
        return stoi(hexStr, 0, 16);
    }
    std::string setHexadecimal(int decimal) {
        std::string resStr;
        int i = 3;
        int remainders[4] = {0, 0, 0, 0};
        while (decimal != 0) {
            remainders[i] = decimal % 16;
            decimal /= 16;
            i--;
        }

        for (int j = 0; j < 4; j++) {
            if (remainders[j] < 10) {
                resStr += (char) '0' + remainders[j];
            } else {
                int difference = remainders[j] - 10;
                resStr += (char) 65 + difference;
            }
        }
        return resStr;
    }
    int getOperandVal(std::string opr) {
      // Programmable Registers - you can see where this gets dirty.
      if (opr == "ax" || opr == "AX") {return readHexadecimal(accumulator->getRegisterVal());}
      if (opr == "bx" || opr == "BX") {return readHexadecimal(baseReg->getRegisterVal());}
      if (opr == "cx" || opr == "CX") {return readHexadecimal(counterReg->getRegisterVal());}
      if (opr == "dx" || opr == "DX") {return readHexadecimal(dataReg->getRegisterVal());}

      // The high and low part of the register...
      if (opr == "ah" || opr == "AH") {return readHexadecimal(accumulator->getHReg());}
      if (opr == "al" || opr == "AL") {return readHexadecimal(accumulator->getLReg());}
      if (opr == "bh" || opr == "BH") {return readHexadecimal(baseReg->getHReg());}
      if (opr == "bl" || opr == "BL") {return readHexadecimal(baseReg->getLReg());}
      if (opr == "ch" || opr == "CH") {return readHexadecimal(accumulator->getHReg());}
      if (opr == "cl" || opr == "CL") {return readHexadecimal(accumulator->getLReg());}
      if (opr == "dh" || opr == "DH") {return readHexadecimal(baseReg->getHReg());}
      if (opr == "dl" || opr == "DL") {return readHexadecimal(baseReg->getLReg());}

      // In case of memory retrieval:

      // In case of immediate values, just check if the string is a pure number:
      if (isStrNum(opr)) {return stoi(opr, 0, 10);}
      return -1;
    }
    int setOperandVal(std::string opr, int val) {
      if (opr == "ax" || opr == "AX") {return accumulator->setRegValue(val);}
      if (opr == "bx" || opr == "BX") {return baseReg->setRegValue(val);}
      if (opr == "cx" || opr == "CX") {return counterReg->setRegValue(val);}
      if (opr == "dx" || opr == "DX") {return dataReg->setRegValue(val);}

      if (opr == "ah" || opr == "AH") {return accumulator->setRegHValue(val);}
      if (opr == "al" || opr == "AL") {return accumulator->setRegLValue(val);}
      if (opr == "bh" || opr == "BH") {return baseReg->setRegHValue(val);}
      if (opr == "bl" || opr == "BL") {return baseReg->setRegLValue(val);}
      if (opr == "ch" || opr == "CH") {return counterReg->setRegHValue(val);}
      if (opr == "cl" || opr == "CL") {return counterReg->setRegLValue(val);}
      if (opr == "dh" || opr == "DH") {return dataReg->setRegHValue(val);}
      if (opr == "dl" || opr == "DL") {return dataReg->setRegLValue(val);}
      return 0;
    }
  public:
    Instruction(std::string type, std::string op1, std::string op2, std::string opcode) {
      this->mnemonic = type;
      this->opcode = opcode;
      this->opr1 = op1;
      this->opr2 = op2;
    }
    void execute() {
      int status;
      if (mnemonic == "ADD") {
        int res = getOperandVal(opr1) + getOperandVal(opr2);
        setOperandVal(opr1, res);
      } else if (mnemonic == "SUB") {
        int res = getOperandVal(opr1) - getOperandVal(opr2);
        setOperandVal(opr1, res);
      } else if (mnemonic == "MOV") {
        int res = getOperandVal(opr2);
        setOperandVal(opr1, res);
      } else if (mnemonic == "INC") {
        int res = getOperandVal(opr1) + 1;
        setOperandVal(opr1, res);
      } else if (mnemonic == "JMP") {
        
      }
    }

    std::string getInstMnemonic() {
      return this->mnemonic;
    }
    std::string getInstOpcode() {
      return this->opcode;
    }
};

class InstArray {
    Instruction** array;
    std::string varList[75];

    int capacity;
    int instCnter;
    int programCnter;
    void updateArrMin() {
        if (instCnter <= (capacity * 0.66) && capacity > 20) {
            capacity -= (int) floor(capacity * 0.34);
            Instruction** ptr_ar = (Instruction**) realloc(array, sizeof(Instruction) * capacity);
            array = ptr_ar;
        }
    }
    void updateArrMax() {
        if (instCnter >= capacity) {
            capacity = (int) ceil(capacity * 1.5);
            Instruction** ptr_ar = (Instruction**) realloc(array, sizeof(Instruction) * capacity);
            array = ptr_ar;
        }
    }
  public:
    InstArray() {
      capacity = 20;
      instCnter = 0;
      array = (Instruction**) malloc(capacity * sizeof(Instruction));
    }
    ~InstArray() {
      clearInstList();
    }
    void addInstruction(std::string mnemonic, std::string op1, std::string op2, std::string opc) {
      updateArrMax();
      array[instCnter] = new Instruction(mnemonic, op1, op2, opc);
      instCnter++;
    }
    bool checkValidity() {
      return true;
    }
    void startExecution() {
      for (programCnter = 0; programCnter < instCnter; programCnter++) {
        array[programCnter]->execute();
      }
    }
    void clearInstList() {

    }
};