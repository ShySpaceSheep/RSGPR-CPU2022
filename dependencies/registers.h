#include <iostream>
#include <cstring>
#include <string>

class Register {
    std::string name;
    std::string displayHexVal;
    bool editableReg = false;
    bool splitableReg = false;
    int byteSize;
  public:
    Register(std::string name, int byteSize, bool isSplittable) {
        this->name = name;
        this->byteSize = byteSize;
        this->splitableReg = isSplittable;
        char container[byteSize * 2];
        for (int i = 0; i < (byteSize * 2); i++) {
            this->displayHexVal += '0';
        }
    }

    // Placeholder for now.
    bool setRegValue(std::string value) {
        this->displayHexVal = value;
        return true;
    }

    std::string getRegisterVal() {
        return displayHexVal;
    }

    std::string getHighReg() {
        if (!splitableReg) {return NULL;}
        std::string highReg;
        for (int i = 0; i < ((byteSize*2) / 2); i++) {
            highReg += displayHexVal[i];
        }
        return highReg;
    }

    std::string getLowReg() {
        if (!splitableReg) {return NULL;}
        std::string lowReg;
        for (int i = ((byteSize*2) / 2); i < (byteSize * 2); i++) {
            lowReg += displayHexVal[i];
        }
        return lowReg;
    }

    void printReg() {
        std::cout << name << " = " << displayHexVal;
    }
};

// NOTE: PLEASE DO NOT DO THIS, I DON'T KNOW IF THIS IS STANDARD BUT I KNOW THIS IS THE WRONG PROCEDURE.
// Pre-defined Registers for use:
Register* accumulator = new Register("AX", 2, true);
Register* baseReg = new Register("BX", 2, true);
Register* counterReg = new Register("CX", 2, true);
Register* dataReg = new Register("DX", 2, true);
// Special Purpose Registers
Register* stackPtr = new Register("SP", 2, false);
Register* basePtr = new Register("BP", 2, false);
Register* srcIndReg = new Register("SI", 2, false);
Register* destIndReg = new Register("DI", 2, false);
// Segment Registers - define them but abandon support
Register* stackSeg = new Register("SS", 2, false);
Register* dataSeg = new Register("DS", 2, false);
Register* extraSeg = new Register("ES", 2, false);

Register* gpReg[4] = {accumulator, baseReg, counterReg, dataReg};
Register* specPurpReg[4] = {stackPtr, basePtr, srcIndReg, destIndReg};
Register* segReg[3] = {stackSeg, dataSeg, extraSeg};