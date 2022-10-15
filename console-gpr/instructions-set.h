#include <instructions.h>
int addFunc(int x, int y) {
    return x + y;
}


// Add the list of instructions using our "Instructions" template.
const auto ADD = new Instruction("ADD", addFunc(x, y));

