#include <iostream>
#include <cstring>
#include <string>

class Register {
    std::string name;
    std::string displayHexVal;
    bool editableReg = false;
    bool splitableReg = false;
    int byteSize;

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
    bool setRegValue(int decimal) {
        if (decimal >= 65536) {return false;}
        this->displayHexVal = setHexadecimal(decimal);
        return true;
    }
    bool setRegHValue(int decimal) {
        if (decimal >= 256) {return false;}
        std::string currRegLVal = getLReg();
        setRegValue(decimal);
        std::string newRegLVal = getLReg();
        std::string newVal = newRegLVal + currRegLVal;
        setRegValue(readHexadecimal(newVal));
        return true;
    }
    bool setRegLValue(int decimal) {
        if (decimal >= 256) {return false;}
        std::string currRegLVal = getHReg();
        setRegValue(decimal);
        std::string newRegLVal = getLReg();
        std::string newVal = currRegLVal + newRegLVal;
        setRegValue(readHexadecimal(newVal));
        return true;
    }
    std::string getRegisterVal() {
        return displayHexVal;
    }
    std::string getHReg() {
        if (!splitableReg) {return NULL;}
        std::string highReg;
        for (int i = 0; i < ((byteSize*2) / 2); i++) {
            highReg += displayHexVal[i];
        }
        return highReg;
    }
    std::string getLReg() {
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