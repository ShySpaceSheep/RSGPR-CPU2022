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