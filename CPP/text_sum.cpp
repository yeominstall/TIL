#include <iostream>
#include <string>

int main(void) {
  std::string str1, str2;
  std::cin >> str1 >> str2;
  const char *cstr1, *cstr2;
  char res[100];
  cstr1 = str1.c_str();
  cstr2 = str2.c_str();
  int p1, p2;
  p1 = str1.size() - 1;
  p2 = str2.size() - 1;

  // std::cout << "STR1: " << cstr1 << " (" << p1 << ")\n";
  // std::cout << "STR2: " << cstr2 << " (" << p2 << ")\n";

  int range = (p1 > p2) ? p1 : p2;
  char sum, carry = 0;
  for (int it = 0; it <= range; it++) {
    if (p1 > -1 && p2 > -1) {
      sum = cstr1[p1] + cstr2[p2] + carry;
      sum -= '0';
    }
    if (sum > '9') {
      carry = 1;
      sum -= 10;
    } else {
      carry = 0;
    }
    res[range + 1 - it] = sum;
    p1--;
    p2--;
  }

  std::cout << res << "\n";

  return 0;
}
