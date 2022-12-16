#include "registers.h"

// Programmable Registers
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
Register* codeSeg = new Register("CS", 2, false);

Register* gpReg[4] = {accumulator, baseReg, counterReg, dataReg};
Register* specPurpReg[4] = {stackPtr, basePtr, srcIndReg, destIndReg};
Register* segReg[4] = {stackSeg, dataSeg, extraSeg, codeSeg};
