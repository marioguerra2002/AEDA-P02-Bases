# Práctica 2: Notación Posicional para Números Grandes

## 1. Objetivo
El objetivo es repasar la implementación en lenguaje C++ de las plantillas y la especialización de plantillas como mecanismo para expresar situaciones particulares.

## 2. Entrega
La práctica se desarrolla en dos sesiones de laboratorio:
- **Sesión tutorada:** del 17 al 20 de febrero.
- **Sesión de entrega:** del 24 al 27 de febrero.

## 3. Enunciado
En la práctica anterior se han implementado tipos de datos definidos por el usuario para representar y operar con valores numéricos que sobrepasan el rango de representación de los tipos básicos del lenguaje C++. 

Para representar estos valores numéricos se ha utilizado el sistema de numeración decimal (Base=10), que es un caso particular de la notación posicional. En notación posicional, el valor de cada dígito depende de su posición relativa y de una base que determina la cantidad de dígitos necesarios para escribir cualquier número. 

Algunos ejemplos:

- **Base 10:**  \(314_{10} = 3 \times 10^2 + 1 \times 10^1 + 4 \times 10^0 = 314_{10}\)
- **Base 2:**  \(1010_{2} = 1 \times 2^3 + 0 \times 2^2 + 1 \times 2^1 + 0 \times 2^0 = 10_{10}\)
- **Base 8:**  \(75_{8} = 7 \times 8^1 + 5 \times 8^0 = 61_{10}\)
- **Base 16:**  \(1F_{16} = 1 \times 16^1 + 15 \times 16^0 = 31_{10}\)

### Plantillas a Implementar

Se definirán plantillas de clases en C++ para representar números grandes en distintas bases:

- `BigUnsigned<unsigned char Base>`: Representa números grandes no negativos en la base especificada.
- `BigInteger<unsigned char Base>`: Representa números grandes enteros en la base especificada.
- `BigRational<unsigned char Base>`: Representa números racionales mediante una pareja `(BigInteger<Base>, BigUnsigned<Base>)`.

#### Características de `BigRational<Base>`
- Se añade el constructor:
  ```cpp
  BigRational(const BigInteger<Base>& numerador=0, const BigNatural<Base>& denominador=1);
  ```
- Se eliminan:
  - Constructor a partir de `unsigned`
  - Operaciones de incremento/decremento
  - Operación de módulo de división
- Los números racionales se representarán en **fracción irreducible**.

## 4. Notas de Implementación

### Especialización para Base 2 (Complemento a Dos)
La representación de números enteros en binario **complemento a dos** optimiza el almacenamiento y la implementación de operaciones.

- **Rango de valores:** \(-2^{n-1} \leq N \leq 2^{n-1} - 1\)
- **Cálculo del complemento a dos:** \(C2(N) = 2^n - N\)
- **Resta de números:** \(N - M = N + C2(M)\)

La especialización de la plantilla para Base=2 se define así:
```cpp
template<>
class BigInteger<2> {
  // Implementación para Base=2 (complemento a dos)
};
```

### Almacenamiento Optimizado
Para Base=2, los dígitos del número se almacenarán en un `std::vector<bool>` en lugar de un `std::vector<char>` para optimizar espacio.

### Representación de Dígitos en Bases 10 a 26
Para visualizar un dígito en bases 10 a 26:

- Si \(d < 10\), se convierte a `ASCII('0') + d`.
- Si \(10 \leq d < 26\), se convierte a `ASCII('A') + d - 10`.
- Si \(d \geq 26\), no se visualizará.

## 5. Formato de Entrada y Salida

### Fichero de Entrada
El programa principal leerá desde un fichero dos números racionales grandes, representados en la base indicada en el propio fichero. 

Ejemplo:
```
Base = 10
N1 = -442142117615672 / 46651367647546
N2 = 46651367647546 / 442142117615672
```

### Fichero de Salida
El fichero de salida contendrá los mismos datos de entrada y las operaciones calculadas:
```
Base = 10
N1 = -442142117615672 / 46651367647546
N2 = 46651367647546 / 442142117615672
N1 == N2: false
N1 < N2: true
N1 + N2: …
```

## 6. Referencias

- [Práctica 1 - Números Grandes](https://campusingenieriaytecnologia2425.ull.es/mod/resource/view.php?id=19814)
- [Rangos en C++](https://en.cppreference.com/w/cpp/language/types)
- [Notación Posicional](https://es.wikipedia.org/wiki/Notaci%C3%B3n_posicional)
- [Número Racional](https://es.wikipedia.org/wiki/N%C3%BAmero_racional)
- [Complemento a Dos](https://es.wikipedia.org/wiki/Complemento_a_dos)
- [std::vector<bool>](https://cplusplus.com/reference/vector/vector-bool/)
