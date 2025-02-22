#include <iostream>
#include <math.h>

int main() {

  // // convertir de exadecimal a decimal
  // int aux = 0;
  // int acum = 0;
  // std::string num = "4FA";
  // for (int i = 0; i < num.size(); i++) {
  //   if (num[i] >= '0' && num[i] <= '9') {
  //     aux = num[i] - '0';
  //   } else if (num[i] >= 'A' && num[i] <= 'F') {
  //     aux = num[i] - 'A' + 10;
  //   }
  //   // elevar el numero a la base 16 elevado a la posicion
  //   acum += aux * pow(16, num.size() - 1 - i);
  // }
  // std::cout << "Numero en decimal: " << acum << std::endl;
  int a = 925;
  int b = 2134;
  int c = b % a;
  std::cout << c << std::endl;
}