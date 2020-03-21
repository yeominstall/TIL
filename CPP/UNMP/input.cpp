/**
 * Section 3-2. Input
 */
#include <iostream>
#include <iomanip>

int main (void) {
    // >> : extraction operation(추출 연산자, 입력 연산자, 뽑아오는 연산자, ...)
    // why scanf() is risky?
    // char firstName[4];
    // scanf("%s", firstName);
    // |P|O|P|E|\0 --> It needs 5 spaces
    // There's no edge detection in C language -- scanf() doesn't know the size of `firstName`
    // because it just has a starting address.
    // But, C++ (cin) also has the same problem.
    char firstName[4];
    cin >> setw(4) >> firstName;
    // + In C, we needs to use below: 
    // fgets(firstName, sizeof(firstName), stdin);

    // Stream states
    char line[512];
    // if(fgets(line, sizeof(line), stdin) != NULL)
    cin >> line;
    if (!cin.eof()) {
        // ...
    }
    // istream states (input_stream)
    // using namespace ios_base;
    // bitflag : goodbit, eofbit, failbit, badbit
    // method : good(), eof(), fail(), bad()
    int number;
    cin >> number;
    // if number is 456abc -- cin read 456, and bufferpointer is on a.
    //                        eofbit: unset     failbit: unset

    // get()
    // get characters without \n -- before the \n
    // ** \n is remained in input stream **
    get(firstName, 100);
    // or, before the specific character
    get(firstName, 100, '#');
    // \n can be ignored when we use getline()
    getline(firstName, 100);
    getline(firstName, 100, '#');

}