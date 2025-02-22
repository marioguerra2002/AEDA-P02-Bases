// #include "bigunsigned.h"




// // constructor que recibe un string

// template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const std::string& num) {
//   // se recorre el string y se almacena en el vector de dígitos
//   for (int i = 0; i < num.size(); i++) {
//     digits_.push_back(num[i] - '0');
//   }
// }

// // constructor que recibe un objeto de la misma clase

// template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const BigUnsigned& num) {
//   // se copian los dígitos del objeto recibido al vector de dígitos
//   digits_ = num.digits_;
// }

// // constructor que recibe un vector de digitos

// template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const std::vector<unsigned char>& num) {
//   // se copian los dígitos del vector recibido al vector de dígitos
//   digits_ = num;
// }

// // constructor que recibe un digito

// template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const long long& num) {
//   // se convierte el número a string
//   std::string str = std::to_string(num);
//   // se recorre el string y se almacena en el vector de dígitos
//   for (int i = 0; i < str.size(); i++) {
//     digits_.push_back(str[i] - '0');
//   }
// }

// // sobrecarga del operador +
// template<unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::operator+(const BigUnsigned<Base>& num) {
//   BigUnsigned<Base> result;
//   int carry = 0;

//   int i = digits_.size() - 1;
//   int j = num.digits_.size() - 1;
//   while (i >= 0 || j >= 0 || carry > 0) {
//     int sum = carry;
//     if (i >= 0) {
//       sum += digits_[i];
//       i--;
//     }
//     if (j >= 0) {
//       sum += num.digits_[j];
//       j--;
//     }
//     carry = sum / Base;
//     sum = sum % Base;
//     result.digits_.push_back(sum);
//   }
//   // dar la vuelta al vector de dígitos para que quede en el orden correcto
//   std::reverse(result.digits_.begin(), result.digits_.end());

//   return result;
// }

// // convertidor de cualquier base a Unsigned de base 10


// // template <unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::toBase10(const BigUnsigned& num) {
// //   // se crea un objeto de la clase BigUnsigned con base 10
// //   BigUnsigned<10> base10;
// //   int size = num.digits_.size();
// //   std::string result = "";

// //   // se recorre el vector de dígitos del objeto recibido
  
// //   // se retorna el objeto base10
// //   return base10;
// // }