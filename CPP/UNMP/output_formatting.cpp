/**
 * Section 2-1. Output
 */

#include <iostream>
#include <iomanip>

using namespace std;


int main (void) {
    int number = 10;
    // Manipulator(조정자)
    // showbase : 진법 표기를 지시
    // hex : 다음에 오는 숫자를 16진수로 표기
    cout << showbase << hex << number << "\n";
    // showpos/noshowpos
    // showpos : 다음에 오는 숫자가 양수일 때 +기호를 표시
    cout << showpos << number;      // +10
    cout << noshowpos << number;    // 10
    // dec/hex/oct
    cout << dec << number << "\n";  // 10
    cout << hex << number << "\n";  // A
    cout << oct << number << "\n";  // 12
    // uppercase/nouppercase
    cout << uppercase << hex << number;     // A
    cout << nouppercase << hex << number;   // a
    // showbase/noshowbase
    cout << showbase << hex << number << "\n";  // 0xa
    cout << noshowbase << hex << number << "\n" // a
    // left/internal/right
    number = -123;
    cout << setw(6) << left << number;      // |-123  |
    cout << setw(6) << internal << number;  // |-  123|
    cout << setw(6) << right << number;     // |  -123|
    // showpoint/noshowpoint
    double decimal1 = 100.0;
    double decimal2 = 100.12;
    cout << noshowpoint << decimal1 << " " << decimal2;     // 100 100.12
    cout << showpoint << decimal1 << " " << decimal2;       // 100.000 100.120
    // fixed/scientific
    decimal1 = 123.456789;
    cout << fixed << decimal1;      // 123.456789
    cout << scientific << decimal1; // 1.234568E+02 : 유효한 값 하나를 정수형으로 두고 이하를 지수 형태로 표현
    // boolalpha/noboolalpha
    bool bReady = true;
    cout << boolalpha << bReady;    // true
    cout << noboolalpha << bReady;  // 1
    // #include <iomanip>에 포함된 조정자들
    // setw()
    number = 123;
    cout << setw(5) << number;                  // |  123|
    // setfill()
    cout << setfill('*') << setw(5) << number;  // |**123|
    // setprecision()
    cout << setprecision(7) << decimal1;        // 123.4567

    // appendix: cout member methods
    // cout << showpos << number;
    // ios_base includes these methods
    // setf(), unsetf(), width(), fill(), precision();
    // these methods are not so popular
    // setf(flag)/unsetf(flag)
    // flag: showpos, showbase, uppercase, boolalpha
    // setf(flag, flag)
    // setf(dec, basefield)
    // setf(fixed, floatfield)
    // setf(left, adjustfield)
    cout.setf(ios_base::showpos);
    cout << number;
    // cout << setw(5) << number;
    cout.width(5);
    cout << number;

    return 0;
}