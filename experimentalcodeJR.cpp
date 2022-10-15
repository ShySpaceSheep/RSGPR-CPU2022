#include <iostream> 

using namespace std; 

 

//REGISTERS: 

 

int nAX; 

int nBX; 

 

int* AX = &nAX; 

int* BX = &nBX; 

 

//ZERO FLAG: 

 

bool ZF = 0; 

 

//MEMORY: 

 

int nM1; 

int nM2; 

int nM3; 

 

int* M1 = &nM1; 

int* M2 = &nM2; 

int* M3 = &nM3; 

 

//INSTRUCTION INDEX: 

 

int instruction; 

 

//OPERATIONS: 

 

void ADD(int* A, int* B) { 

    *A += *B; 

} 

 

void SUB(int* A, int* B) { 

    *A -= *B; 

} 

 

void MOV(int* A, int* B) { 

    *A = *B; 

} 

 

void INC(int* A) { 

    *A++; 

} 

 

void JMP(int A) { 

    if (ZF) { 

        instruction = A - 1; 

    } 

} 

 

void CMP(int* A, int* B) { 

    if (*A == *B) { 

        ZF = 1; 

    } 

} 

 

int main() { 

    //DEFINE BYTES 

    *M1 = 0; 

    *M2 = 1; 

     

    //PROGRAM 

    for (instruction = 1; instruction <= 7; instruction++) { 

        cout << instruction << endl; 

        switch (instruction) { 

            case 1: 

                MOV(AX, M1); 

                break; 

            case 2: 

                MOV(BX, M2); 

                break; 

            case 3: 

                ADD(AX, BX); 

                break; 

            case 4: 

                CMP(AX, BX); 

                break; 

            case 5: 

                JMP(7); 

                break; 

            case 6: 

                INC(AX); 

                break; 

            case 7: 

                MOV(M3, AX); 

                break; 

        } 

         

    } 

    cout << "M3 = " << *M3 << endl; 

    cout << "Exiting..."; 

     

} 
