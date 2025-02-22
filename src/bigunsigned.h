#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

// clase template que recibe un tipo de dato de base 2, 8, 10 o 16

template <unsigned char Base = 10> class BigUnsigned {
  public:
    BigUnsigned() {}; // constructor por defecto
    BigUnsigned(const std::string& num); // constructor que recibe un string
    BigUnsigned(const BigUnsigned& num); // constructor que recibe un objeto de la misma clase
    BigUnsigned(const std::vector<unsigned char>& num); // constructor que recibe un vector de digitos
    BigUnsigned(const long long& num); // constructor que recibe un digito
    // convertidor de cualquier base a Unsigned de base 10
    BigUnsigned<10> toBase10(const BigUnsigned<Base>& num); // convertidor de cualquier base a Unsigned de base 10
    BigUnsigned<Base> fromBase10(const BigUnsigned<10>& num); // convertidor de base 10 a cualquier base
    BigUnsigned<Base> operator+(const BigUnsigned<Base>& num); // sobrecarga del operador +
    friend std::ostream& operator<<(std::ostream& os, const BigUnsigned<Base>& num) { // sobrecarga del operador de salida
      for (int i = 0; i < num.digits_.size(); i++) {
        os << static_cast<int>(num.digits_[i]);
      }
      return os;
    }
    friend std::istream& operator>>(std::istream& is, BigUnsigned<Base>& num) { // sobrecarga del operador de entrada
      std::string str;
      is >> str;
      num = BigUnsigned<Base>(str);
      return is;
    }
    bool operator<(const BigUnsigned<Base>& num); // sobrecarga del operador <
    bool operator>(const BigUnsigned<Base>& num); // sobrecarga del operador >
    bool operator==(const BigUnsigned<Base>& num); // sobrecarga del operador ==
    bool operator>=(const BigUnsigned<Base>& num); // sobrecarga del operador >=
    BigUnsigned<Base> operator-(const BigUnsigned<Base>& num); // sobrecarga del operador -
    BigUnsigned<Base> operator*(const BigUnsigned<Base>& num); // sobrecarga del operador *
    BigUnsigned<Base> operator/(const BigUnsigned<Base>& num); // sobrecarga del operador /
    BigUnsigned<Base> operator%(const BigUnsigned<Base>& num); // sobrecarga del operador %

    BigUnsigned<Base> pow(const unsigned int& exp); // operador de potencia
    BigUnsigned<Base> operator=(const BigUnsigned<Base>& num); // sobrecarga del operador =

    unsigned char getDigit(size_t index) const { return digits_.at(index); } // obtener un digito
    void pushDigitFront(unsigned char digit) { digits_.insert(digits_.begin(), digit); } // insertar un digito al principio
    std::vector<unsigned char> getDigits() const { return digits_; } // obtener los digitos
  private:
    std::vector<unsigned char> digits_; // vector que almacena los dígitos
    unsigned char base_ = Base; // base del número
    
    
    
};

// constructor que recibe un string

template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const std::string& num) {
  // se recorre el string y se almacena en el vector de dígitos
  for (int i = 0; i < num.size(); i++) {
    if (num[i] >= '0' && num[i] <= '9') {
      digits_.push_back(num[i] - '0');
    } else if (num[i] >= 'A' && num[i] <= 'F') {
      digits_.push_back(num[i] - 'A' + 10);
    }
  }
  // imprimir el vector de dígitos
  // for (int i = 0; i < digits_.size(); i++) {
  //   std::cout << static_cast<int>(digits_[i]) << std::endl;
  // }
}

// constructor que recibe un objeto de la misma clase

template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const BigUnsigned& num) {
  // se copian los dígitos del objeto recibido al vector de dígitos
  digits_ = num.digits_;
}

// constructor que recibe un vector de digitos

template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const std::vector<unsigned char>& num) {
  // se copian los dígitos del vector recibido al vector de dígitos
  digits_ = num;
}

// constructor que recibe un digito

template <unsigned char Base> BigUnsigned<Base>::BigUnsigned(const long long& num) {
  // se convierte el número a string
  std::string str = std::to_string(num);
  // se recorre el string y se almacena en el vector de dígitos
  for (int i = 0; i < str.size(); i++) {
    digits_.push_back(str[i] - '0');
  }
}
// sobrecarga del operador =

template<unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::operator=(const BigUnsigned<Base>& num) {
  digits_ = num.digits_;
  return *this;
}
// sobrecarga del operador <
template<unsigned char Base> bool BigUnsigned<Base>::operator<(const BigUnsigned<Base>& num) {
  BigUnsigned<10> num1 = toBase10(*this);
  BigUnsigned<10> num2 = toBase10(num);
  if (num1.digits_.size() < num2.digits_.size()) {
    return true;
  } else if (num1.digits_.size() > num2.digits_.size()) {
    return false;
  } else {
    for (int i = 0; i < num1.digits_.size(); i++) {
      if (num1.digits_[i] < num2.digits_[i]) {
        return true;
      } else if (num1.digits_[i] > num2.digits_[i]) {
        return false;
      }
    }
  }
  return false;
}
// sobre carga del operador >
template<unsigned char Base> bool BigUnsigned<Base>::operator>(const BigUnsigned<Base>& num) {
  BigUnsigned<10> num1 = toBase10(*this);
  BigUnsigned<10> num2 = toBase10(num);
  if (num1.digits_.size() > num2.digits_.size()) {
    return true;
  } else if (num1.digits_.size() < num2.digits_.size()) {
    return false;
  } else {
    for (int i = 0; i < num1.digits_.size(); i++) {
      if (num1.digits_[i] > num2.digits_[i]) {
        return true;
      } else if (num1.digits_[i] < num2.digits_[i]) {
        return false;
      }
    }
  }
}
// sobrecarga del operador ==
template<unsigned char Base> bool BigUnsigned<Base>::operator==(const BigUnsigned<Base>& num) {
  if (digits_.size() != num.digits_.size()) {
    return false;
  } else {
    for (int i = 0; i < digits_.size(); i++) {
      if (digits_[i] != num.digits_[i]) {
        return false;
      }
    }
  }
  return true;
}
//sobrecarga del operador >=
template<unsigned char Base> bool BigUnsigned<Base>::operator>=(const BigUnsigned<Base>& num) {
  BigUnsigned<10> num1 = toBase10(*this);
  BigUnsigned<10> num2 = toBase10(num);
  if (num1.digits_.size() > num2.digits_.size()) {
    return true;
  } else if (num1.digits_.size() < num2.digits_.size()) {
    return false;
  } else {
    for (int i = 0; i < num1.digits_.size(); i++) {
      if (num1.digits_[i] > num2.digits_[i]) {
        return true;
      } else if (num1.digits_[i] < num2.digits_[i]) {
        return false;
      }
    }
  }
  return true;
}

// sobrecarga del operador +
template<unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::operator+(const BigUnsigned<Base>& num) {
  // convierte siempre a base 10 para hacer la suma. Si la base ya es 10, en el método toBase10 se devuelve el mismo número
  BigUnsigned<10> num1 = toBase10(*this);
  BigUnsigned<10> num2 = toBase10(num);
  // BigUnsigned<10> result = num1 + num2; no se si estoy funciona
  int carry = 0;
  BigUnsigned<10> result;

  int i = num1.digits_.size() - 1;
  int j = num2.digits_.size() - 1;
  while (i >= 0 || j >= 0 || carry > 0) {
    int sum = carry;
    if (i >= 0) {
      sum += num1.digits_[i];
      i--;
    }
    if (j >= 0) {
      sum += num2.digits_[j];
      j--;
    }
    carry = sum / 10;
    sum = sum % 10;
    result.digits_.push_back(sum);
  }
  // dar la vuelta al vector de dígitos para que quede en el orden correcto
  std::reverse(result.digits_.begin(), result.digits_.end());
  // falta convertir el resultado a la base original
  /////////////////////////////
  return result;

  
}
// sobrecarga del operador -
template <unsigned char Base>
BigUnsigned<Base> BigUnsigned<Base>::operator-(const BigUnsigned<Base>& num) {
  BigUnsigned<10> num1 = toBase10(*this);
  BigUnsigned<10> num2 = toBase10(num);

  // Si num2 es mayor que num1, la resta no es válida para números sin signo
  if (num1 < num2) {
    throw std::invalid_argument("No se puede restar un número mayor.");
  }

  BigUnsigned<10> result;
  int borrow = 0;

  // Asegurar que result tenga el mismo tamaño que num1
  result.digits_ = num1.digits_;

  int i = num1.digits_.size() - 1;
  int j = num2.digits_.size() - 1;

  while (i >= 0) {
    int diff = num1.digits_[i] - borrow;
    if (j >= 0) {
        diff -= num2.digits_[j];
        j--;
    }
    if (diff < 0) {
        diff += 10;
        borrow = 1;
    } else {
        borrow = 0;
    }
    result.digits_[i] = diff;
    i--;
  }

  // Eliminar ceros a la izquierda
  while (result.digits_.size() > 1 && result.digits_[0] == 0) {
      result.digits_.erase(result.digits_.begin());
  }

  return result;
}

// operador de multiplicacion
template<unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::operator*(const BigUnsigned<Base>& num) {
  std::vector<unsigned char> result;
  result.resize(digits_.size() + num.digits_.size(), 0);
  if (digits_.size() > num.digits_.size()) {
    // multiplicamos digitos usando el algoritmo de la multiplicacion por columnas
    for (int i = digits_.size() - 1; i >= 0; i--) {
      for (int j = num.digits_.size() - 1; j >= 0; j--) {
        result[i + j + 1] += digits_[i] * num.digits_[j];
        result[i + j] += result[i + j + 1] / Base;
        result[i + j + 1] %= Base;
      }
    }
  } else if (digits_.size() < num.digits_.size()) {
    // multiplicamos digitos usando el algoritmo de la multiplicacion por columnas
    for (int i = num.digits_.size() - 1; i >= 0; i--) {
      for (int j = digits_.size() - 1; j >= 0; j--) {
        result[i + j + 1] += num.digits_[i] * digits_[j];
        result[i + j] += result[i + j + 1] / Base;
        result[i + j + 1] %= Base;
      }
    }
  } else {
    // multiplicamos digitos usando el algoritmo de la multiplicacion por columnas
    for (int i = digits_.size() - 1; i >= 0; i--) {
      for (int j = num.digits_.size() - 1; j >= 0; j--) {
        result[i + j + 1] += digits_[i] * num.digits_[j];
        result[i + j] += result[i + j + 1] / Base;
        result[i + j + 1] %= Base;
      }
    }

  }
  if (result[0] == 0) { // si el primer digito es 0, lo eliminamos
    result.erase(result.begin());
  }
  BigUnsigned<Base> res(result);
  return res;
}

// operador de potencia

template<unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::pow(const unsigned int& exp) {
    if (exp == 0) return BigUnsigned<Base>(1);  // a^0 = 1
    
    BigUnsigned<Base> base = *this;
    BigUnsigned<Base> result(1);  // Inicialmente en 1

    unsigned int e = exp;  // Para evitar modificar `exp`
    while (e > 0) {
        if (e % 2 == 1) {
            result = result * base;  // Si el exponente es impar, multiplicar base
        }
        base = base * base;  // Elevar la base al cuadrado
        e /= 2;  // Reducir el exponente a la mitad
    }
    return result;
}

// sobrecarga del operador /

template<unsigned char Base> 
BigUnsigned<Base> BigUnsigned<Base>::operator/(const BigUnsigned<Base>& num) {
  // Convertimos los números a base 10 para operar
  BigUnsigned<10> num1 = toBase10(*this);
  BigUnsigned<10> num2 = toBase10(num);

  // Verificación de división por cero
  if (num2.digits_[0] == 0 && num2.digits_.size() == 1) {
    throw std::runtime_error("Division by zero");
  }

  // Casos especiales
  if (num1.digits_[0] == 0 && num1.digits_.size() == 1) {
    return BigUnsigned<Base>(0);  // Si el dividendo es 0, resultado es 0
  }
  if (num2.digits_[0] == 1 && num2.digits_.size() == 1) {
    return *this;  // Si divisor es 1, el resultado es el mismo número
  }

  std::vector<unsigned char> cociente(num1.digits_.size(), 0); // Resultado de la división
  BigUnsigned<10> resto; // Resto de la división

  // Algoritmo de división larga
  for (size_t i = 0; i < num1.digits_.size(); i++) {
    // Desplazar el resto y agregar el nuevo dígito de num1
    resto.digits_.push_back(num1.digits_[i]);

    // Eliminar ceros a la izquierda en el resto
    while (resto.digits_.size() > 1 && resto.digits_.front() == 0) {
      resto.digits_.erase(resto.digits_.begin());
    }

    // Encontrar cuántas veces num2 cabe en resto
    unsigned char cociente_digit = 0;
    while (resto >= num2) {  // Aquí se usa el operador `>=` correctamente
      resto = resto - num2;
      cociente_digit++;
    }
    cociente[i] = cociente_digit;
  }

  // Crear el resultado en base `Base`
  BigUnsigned<Base> resultBig;
  for (size_t i = 0; i < cociente.size(); i++) {
    resultBig.digits_.push_back(cociente[i]);
  }

  // Eliminar ceros iniciales del cociente
  while (resultBig.digits_.size() > 1 && resultBig.digits_.front() == 0) {
    resultBig.digits_.erase(resultBig.digits_.begin());
  }

  return resultBig;
}

// operador de modulo

template<unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::operator%(const BigUnsigned<Base>& num) {
  // Convertimos a base 10 para operar
  BigUnsigned<10> num1 = toBase10(*this);
  BigUnsigned<10> num2 = toBase10(num);
  if (num2.digits_[0] == 0 && num2.digits_.size() == 1) {
    throw std::runtime_error("Division by zero");
  } else if (num1.digits_[0] == 0 && num1.digits_.size() == 1) {
    return BigUnsigned<Base>(0);
  }
  // es lo mismo que el operador / pero devolviendo el resto
  std::vector<unsigned char> cociente(num1.digits_.size(), 0);
  BigUnsigned<10> resto;
  for (size_t i = 0; i < num1.digits_.size(); i++) {
    resto.digits_.push_back(num1.digits_[i]);
    while (resto.digits_.size() > 1 && resto.digits_.front() == 0) {
      resto.digits_.erase(resto.digits_.begin());
    }
    unsigned char cociente_digit = 0;
    while (resto >= num2) {
      resto = resto - num2;
      cociente_digit++;
    }
    cociente[i] = cociente_digit;
  }
  BigUnsigned<Base> resultBig;
  for (size_t i = 0; i < resto.digits_.size(); i++) {
    resultBig.digits_.push_back(resto.digits_[i]);
  }
  while (resultBig.digits_.size() > 1 && resultBig.digits_.front() == 0) {
    resultBig.digits_.erase(resultBig.digits_.begin());
  }
  return resultBig;

}

// convertidor de cualquier base a Unsigned de base 10

template<unsigned char Base> BigUnsigned<10> BigUnsigned<Base>::toBase10(const BigUnsigned<Base>& num) {
  if (Base == 10) {
    std::vector<unsigned char> digits = num.digits_;
    BigUnsigned<10> result(digits);
    return result;
  }
  BigUnsigned<10> result(0); // Inicializamos en 0
  BigUnsigned<10> acum; // Acumulador
  int aux;

  for (int i = num.digits_.size() - 1; i >= 0; i--) {
    // Convertimos el dígito a base 10.
    // el numero ya esta en formato numerico (por ejemplo, las letras A, B, C, D, E, F ya estan convertidas a 10, 11, 12, 13, 14, 15)
    aux = num.digits_[i];

    // Multiplicamos el dígito por la base elevada a la posición
    acum = BigUnsigned<10>(aux) * BigUnsigned<10>(static_cast<int>(Base)).pow(num.digits_.size() - 1 - i);

    // Sumamos al resultado total
    result = result + acum;
  }

  return result;
}


template<unsigned char Base> BigUnsigned<Base> BigUnsigned<Base>::fromBase10(const BigUnsigned<10>& num) {
  BigUnsigned<Base> result;
  std::vector<unsigned char> digits;
  BigUnsigned<10> num1 = num;
  BigUnsigned<10> cociente;
  BigUnsigned<10> resto;
  BigUnsigned<10> base(Base); // base en la que se va a convertir
  while (num1 >= base) {
    cociente = num1 / base;
    resto = num1 % base;
    unsigned char digit;
    if (resto.getDigits().size() == 1) {
      digit = resto.getDigit(0);
      // std::cout << "digit when resto size 1: " << static_cast<int>(digit) << std::endl;
    } else if (resto.getDigits().size() == 2) {
      // convertir resto a numero entero para poder convertirlo a char, ya que el resto va a tener dos digitos (por ejemplo, 10, 11, 12, 13, 14, 15)
      digit = resto.getDigit(0) * 10 + resto.getDigit(1);
      // std::cout << "digit when resto size 2: " << static_cast<int>(digit) << std::endl;
    }
    digits.push_back(digit);

    num1 = cociente;
  }
  unsigned char digit;
  if (num1.getDigits().size() == 1) {
    digit = num1.getDigit(0);
    // std::cout << "digit when num1 size 1: " << static_cast<int>(digit) << std::endl;
  } else if (num1.getDigits().size() == 2) {
    digit = num1.getDigit(0) * 10 + num1.getDigit(1);
    // std::cout << "digit when num1 size 2: " << static_cast<int>(digit) << std::endl;
  }
  digits.push_back(digit);
  // dar la vuelta al vector de digitos
  std::reverse(digits.begin(), digits.end());

  // imprimir el vector de digitos
  result = BigUnsigned<Base>(digits);
  return result;
   
}


