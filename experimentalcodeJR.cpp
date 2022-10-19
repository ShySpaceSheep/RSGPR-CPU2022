#include <iostream>

using namespace std;

//REGISTERS:

int nAX, nBX, nCX;

int* AX = &nAX;

int* BX = &nBX;

int* CX = &nCX;

//ZERO FLAG:

bool ZF = 0;

//MEMORY:

int nM;

int* M = &nM;

//INSTRUCTION INDEX:

int instruction = 0;

bool running = true;

//OPERATIONS:

void SUB(int* A, int B) {

*A = *A - B;

}

void MOV(int* A, int B) {

*A = B;

}

void INC(int* A) {

*A = *A + 1;

}

void JMP(int A) {

//ALWAYS JUMP

instruction = A - 1;

}

void JE(int A) {

if (ZF == 1) {

instruction = A - 1;

}

}

void JNE(int A) {

if (ZF == 0) {

instruction = A - 1;

}

}

void CMP(int* A, int B) {

if (*A == B) {

ZF = 1;

} else {

ZF = 0;

}

}

void IFNEG(int* A) {

//CHECK IF NEGATIVE NUMBER

if (*A < 0) {

ZF = 1;

} else {

ZF = 0;

}

}

void END() {

running = false;

}

void DISPLAY() {

cout << "AX = " << *AX << endl;

cout << "BX = " << *BX << endl;

cout << "CX = " << *CX << endl;

cout << "ZF = " << ZF << endl;

cout << "M = " << *M << endl;

}

int main() {

//DEFINE BYTES

*M = 1000;

// (BALANCE)

//PROGRAM

DISPLAY();

while (running) {

instruction++;

switch (instruction) {

case 1:

//ATTEMPT COUNTER

MOV(CX, 0);

break;

case 2:

//LOAD CORRECT PIN

MOV(BX, 1234);

break;

case 3:

//ENTER PIN

cout << "ENTER PIN: ";

cin >> nAX;

break;

case 4:

//VERIFY PIN

CMP(AX, *BX);

break;

case 5:

//JUMP TO WITHDRAW?

JE(10);

break;

case 6:

//COUNT ATTEMPTS

INC(CX);

break;

case 7:

//CHECK ATTEMPTS

CMP(CX, 3);

break;

case 8:

//JUMP TO EXIT

JE(30);

break;

case 9:

//JUMP TO ENTER PIN

JNE(3);

break;

case 10:

//WITHDRAW?

cout << "WITHDRAW? (1-YES, 0-NO): ";

cin >> nAX;

break;

case 11:

//CHECK WITHDRAW OPTION

CMP(AX, 1);

break;

case 12:

//JUMP TO WITHDRAW

JE(23);

break;

case 13:

//SELECT OPTION

cout << "SELECT OPTION (1-BALANCE INQUIRY, 2-WITHDRAW, 3-EXIT): ";

cin >> nAX;

break;

case 14:

//CHECK FOR OPTION 1

CMP(AX, 1);

break;

case 15:

//JUMP TO BALANCE INQUIRY

JE(20);

break;

case 16:

//CHECK FOR OPTION 2

CMP(AX, 2);

break;

case 17:

//JUMP TO WITHDRAW

JE(23);

break;

case 18:

//CHECK FOR OPTION 3

CMP(AX, 3);

break;

case 19:

//JUMP TO EXIT

JE(30);

break;

case 20:

//BALANCE INQUIRY

MOV(AX, *M);

break;

case 21:

//DISPLAY BALANCE

cout << "BALANCE: P" << *M << endl;

break;

case 22:

//JUMP TO SELECT OPTION

JMP(13);

break;

case 23:

//WITHDRAW

cout << "ENTER AMOUNT: ";

cin >> nAX;

break;

case 24:

//LOAD BALANCE

MOV(BX, *M);

break;

case 25:

//SUBTRACT AMOUNT

SUB(BX, *AX);

break;

case 26:

//CHECK IF NEGATIVE

IFNEG(BX);

break;

case 27:

//JUMP TO WITHDRAW

JE(23);

break;

case 28:

//UPDATE BALANCE

MOV(M, *BX);

break;

case 29:

//RECEIPT

cout << "RECEIPT" << endl;

cout << "ACCOUNT BALANCE: P" << *BX << endl;

cout << "CASH WITHDRAWN: P" << *AX << endl;

break;

case 30:

//EXIT

END();

cout << "EXITING..." << endl;

break;

}

}

DISPLAY();

}
