#include "bigunsigned.h"

int main() {
  // vamos a probar el construtor y el operador de salida

  BigUnsigned<10> num1("925");
  std::cout << num1 << std::endl;
  BigUnsigned<10> num2("2134");
  std::cout << num2 << std::endl;
  // BigUnsigned<10> num3 = num1 + num2;
  // std::cout << num3 << std::endl;

  // BigUnsigned<10> num4 = num1.pow(3);
  // std::cout << num4 << std::endl;

  BigUnsigned<16> num5("4FA");
  BigUnsigned<10> num6 = num5.toBase10(num5);
  std::cout << "Numero6: " << num6 << std::endl;

  // BigUnsigned<2> num7("1010");
  // BigUnsigned<10> num8 = num7.toBase10(num7);
  // std::cout << "Numero8: " << num8 << std::endl;

  // BigUnsigned<8> num9("24525");
  // BigUnsigned<10> num10 = num9.toBase10(num9); // deberia ser 10293
  // std::cout << "Numero10: " << num10 << std::endl;

  BigUnsigned<16> num11;
  num11 = num11.fromBase10(num6);
  std::cout << "Num11 size: " << num11.getDigits().size() << std::endl;
  for (int i = 0; i < num11.getDigits().size(); i++) {
    std::cout << static_cast<int>(num11.getDigits()[i]) << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  BigUnsigned<2> num12("0111011010");
  BigUnsigned<10> num13 = num12.toBase10(num12);
  std::cout << "Numero13: " << num13 << std::endl;
  BigUnsigned<2> num14;
  num14 = num14.fromBase10(num13);
  std::cout << "Num14 size: " << num14.getDigits().size() << std::endl;
  for (int i = 0; i < num14.getDigits().size(); i++) {
    std::cout << static_cast<int>(num14.getDigits()[i]) << " ";
  }

  std::cout << std::endl;
  std::cout << std::endl;

  BigUnsigned<8> num15("2342776");
  BigUnsigned<10> num16 = num15.toBase10(num15); // deberia ser 10293
  std::cout << "Numero16: " << num16 << std::endl;
  BigUnsigned<8> num17;
  num17 = num17.fromBase10(num16);
  std::cout << "Num17 size: " << num17.getDigits().size() << std::endl;
  for (int i = 0; i < num17.getDigits().size(); i++) {
    std::cout << static_cast<int>(num17.getDigits()[i]) << " ";
  }






  // BigUnsigned num2(10);
  // std::cout << num2 << std::endl;

  // if (num1 == num2) {
  //   std::cout << "Son iguales" << std::endl;
  // } else {
  //   std::cout << "No son iguales" << std::endl;
  // }
  // if (num1 < num2) {
  //   std::cout << "num1 es menor que num2" << std::endl;
  // } else {
  //   std::cout << "num1 no es menor que num2" << std::endl;
  // }
  
  // prueba de pre-incremento
  // std::cout << "num1: " << num1 << std::endl;
  // ++num1;
  // std::cout << "num1: " << num1 << std::endl;
  // // prueba de post-incremento
  // std::cout << "num1: " << num1 << std::endl;
  // num1++;
  // std::cout << "num1: " << num1 << std::endl;
  //prueba de pre-decremento
  // std::cout << "num1: " << num1 << std::endl;
  // --num1;
  // std::cout << "num1: " << num1 << std::endl;
  // prueba de post-decremento
  // std::cout << "num1: " << num1 << std::endl;
  // num1--;
  // std::cout << "num1: " << num1 << std::endl;
  // prueba de suma
  
  // if (num1 == num2) {
  //   std::cout << "Son iguales" << std::endl;
  // } else {
  //   std::cout << "No son iguales" << std::endl;
  // }
  // if (num1 < num2) {
  //   std::cout << "num1 es menor que num2" << std::endl;
  // } else {
  //   std::cout << "num1 no es menor que num2" << std::endl;
  // }

  // BigUnsigned num3 = num1 + num2;
  // std::cout << "num3: " << num3 << std::endl;

  // //prueba de resta
  // BigUnsigned num4 = num1 - num2;
  // std::cout << "num4: " << num4 << std::endl;

  // // prueba de multiplicacion
  // // BigUnsigned num5 = num1 * num2;
  // // std::cout << "num5: " << num5 << std::endl;

  // // prueba de division
  // BigUnsigned<10> num6;
  // num6 = num2 % num1;
  // std::cout << "num6: " << num6 << std::endl;
  
  // // prueba de modulo
  // // std::cout << BigUnsigned(380)%BigUnsigned(23) << std::endl;
  // BigUnsigned num7 = num1 % num2;
  // std::cout << "num7: " << num7 << std::endl;

  // prueba salida BigIteger
  // BigInteger num8(5);
  // std::cout << "Numero con simbolo: "<<num8 << std::endl;
  // BigInteger num9(7);
  // std::cout << "Numero con simbolo2: "<<num9 << std::endl;
  // // prueba de suma
  // std::cout << "\n\n";
  // std::cout << "numeros con los que se va a trabajar: " << num8 << " y " << num9 << std::endl;
  // num8.eliminadorCeros();
  // num9.eliminadorCeros();
  // std::cout << "prueba:" << std::endl;
  // std::cout << "num8: " << num8.getDigits()[0] << std::endl;
  // std::cout << "num9: " << num9.getDigits()[0] << std::endl;


  // BigInteger num10 = num8 + num9;
  // std::cout << "num10(suma): " << num10 << std::endl;
  
  // prueba <
  // if (num8 < num9) {
  //   std::cout << "num8 es menor que num9" << std::endl;
  // } else {
  //   std::cout << "num8 no es menor que num9" << std::endl;
  // }

  // prueba ++
  // std::cout << "num8: " << num8 << std::endl;
  // ++num8;
  // std::cout << "num8: " << num8 << std::endl;

  // prueba --
  // std::cout << "num8: " << num8 << std::endl;
  // --num8;
  // std::cout << "num8: " << num8 << std::endl;

  // prueba de resta (no funciona)
  // BigInteger num11 = num8 - num9;
  // std::cout << "num11: " << num11 << std::endl;

  // prueba de multiplicacion
  // BigInteger num12 = num8 * num9;
  // std::cout << "num12(multiplicacion): " << num12 << std::endl;

  // prueba de division
  // BigInteger num13 = num8 / num9;
  // std::cout << "num13(division): " << num13 << std::endl;

  // prueba de modulo
  // BigInteger num14 = num8 % num9;
  // std::cout << "num14(modulo): " << num14 << std::endl;

  // prueba de mcd de bigunsigned
  // BigUnsigned num15 = num1.mcd(num1, num2);
  // std::cout << "num15(mcd): " << num15 << std::endl;

}