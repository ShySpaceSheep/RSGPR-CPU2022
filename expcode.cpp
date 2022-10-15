#include <iostream> 
using namespace std; 

//REGISTERS: 
int nAX; 
int nBX; 
int nCX;
int* AX = &nAX; 
int* BX = &nBX; 
int* CX = &nCX; // added CX for more display options

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

char operation[255][3]; 
char operandA[255][2]; 
char operandB[255][2]; 

//READ INSTRUCTION: 
bool READ(char A, char B, char C) { 
    bool X = operation[instruction][0] == A; 
    bool Y = operation[instruction][1] == B; 
    bool Z = operation[instruction][2] == C; 
    return (X && Y && Z); 
} 
int* OP1() { 
    char A = operandA[instruction][0]; 
    char B = operandA[instruction][1]; 
    int* C; 
    //REGISTER 

    if (A == 'A' && B == 'X') { 

        C = AX; 

    } else 

    if (A == 'B' && B == 'X') { 

        C = BX; 

    } else 

    if (A == 'C' && B == 'X') {  // added CX for more display options

        C = CX; 

    } else 

    //MEMORY 

    if (A == 'M') { 

        if (B == '1') { 

            C = M1; 

        } else 

        if (B == '2') { 

            C = M2; 

        } else 

        if (B == '3') { 

            C = M3; 

        } 

    } 

    return C; 

} 

 

int* OP2() { 

    char A = operandB[instruction][0]; 

    char B = operandB[instruction][1]; 

    int* C; 

    //REGISTER 

    if (A == 'A' && B == 'X') { 

        C = AX; 

    } else 

    if (A == 'B' && B == 'X') { 

        C = BX; 

    } else 

    if (A == 'C' && B == 'X') { // added CX for more display options

        C = CX; 

    } else 

    //MEMORY 

    if (A == 'M') { 

        if (B == '1') { 

            C = M1; 

        } else 

        if (B == '2') { 

            C = M2; 

        } else 

        if (B == '3') { 

            C = M3; 

        } 

    } 

    return C; 

} 

int* OP3 () {
	int* C;
	return C;
}

//OPERATIONS: 

 

void ADD(int* A, int* B) { 

    *A = *A + *B; 

} 

 

void SUB(int* A, int* B) { 

    *A = *A - *B; 

} 

 

void MOV(int* A, int* B) { 

    *A = *B; 

} 

 

void INC(int* A) { 

    *A = *A + 1; 

} 

 

int jumpTO[100]; 

 

void JMP() { 

    if (ZF) { 

        instruction = jumpTO[instruction] - 1; 

    } 

} 

 

void DEC(int* A) { 

    *A = *A - 1; 

} 

 

void CMP(int* A, int* B) { 

    if (*A == *B) { 

        ZF = 1; 

    } else { 

        ZF = 0; 

    } 

} 

 

void JNC() { 

    if (!ZF) { 

        instruction = jumpTO[instruction] - 1; 

    } 

} 

// Elijah

//void DFB(int* A, int* B) { // Define Byte
	
    //*A = *B;
//} 

bool END; 

 

void DISPLAY() { 

    cout << "AX = " << nAX << endl; 

    cout << "BX = " << nBX << endl; 
    
    cout << "CX = " << nCX << endl; 

    cout << "M1 = " << nM1 << endl; 

    cout << "M2 = " << nM2 << endl; 

    cout << "M3 = " << nM3 << endl; 

} 

 

int main() { 

    //DEFINE BYTES 

    nM1 = 0; 

    nM2 = 0; 

    nM3 = 0;

    DISPLAY(); 

    //ENTER INSTRUCTIONS 

    cout << "Enter code:" << endl; 

    END = false; 

    instruction = 0; 

    while (!END) { 

        cout << instruction << ": "; 

        cin >> operation[instruction]; 

        if (READ('E','N','D')) { 

            END = true; 

        } else 

        //FIST OPERAND 

        if (READ('J','M','P') || READ('J','N','C')) { 

            cin >> jumpTO[instruction]; 

        } else { 

            cin >> operandA[instruction]; 

            if ( !(READ('I','N','C') || READ('J','M','P') || READ('D','E','C')) ) { 

                //SECOND OPERAND 

                cin >> operandB[instruction]; 

            } 

        } 

        instruction++; 

    } 

    //EXECUTE INSTRUCTIONS 

    cout << "Executing..." << endl; 

    END = false; 

    instruction = 0; 

    while (!END) { 

        cout << "INSTRUCTION " << instruction << endl; 

        if (READ('E','N','D')) { 

            END = true; 

        } else { 

            //READ INSTRUCTION 

            if (READ('A','D','D')) { 

                ADD(OP1(),OP2()); 

            } else 

            if (READ('S','U','B')) { 

                SUB(OP1(),OP2()); 

            } else 

            if (READ('M','O','V')) { 

                MOV(OP1(),OP2()); 
				
            } else 

            if (READ('I','N','C')) { 

                INC(OP1()); 

            } else 

            if (READ('J','M','P')) { 

                JMP(); 

            } else 

            if (READ('D','E','C')) { 

                DEC(OP1()); 

            } else 

            if (READ('C','M','P')) { 

                CMP(OP1(),OP2()); 

            } else 

            if (READ('J','N','C')) { 

                JNC(); 

            } /*else 

            if (READ('D','F','B')) { 
				
                DFB(OP1(),OP3());

            } */

        } 

        instruction++; 

    } 

    DISPLAY(); 

    cout << "Exiting..."; 

}
