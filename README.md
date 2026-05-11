# C++ Modules 00–04 · 42 Madrid
> **Standard:** C++98 · **Compilador:** `c++ -Wall -Wextra -Werror -std=c++98`

---

## Índice

1. [Reglas generales](#reglas-generales)
2. [CPP00 · Introducción a OOP](#cpp00--introducción-a-oop)
3. [CPP01 · Memoria, referencias y punteros](#cpp01--memoria-referencias-y-punteros)
4. [CPP02 · Forma Canónica Ortodoxa y sobrecarga](#cpp02--forma-canónica-ortodoxa-y-sobrecarga)
5. [CPP03 · Herencia](#cpp03--herencia)
6. [CPP04 · Polimorfismo, clases abstractas e interfaces](#cpp04--polimorfismo-clases-abstractas-e-interfaces)
7. [Makefile de referencia](#makefile-de-referencia)
8. [Errores comunes](#errores-comunes)

---

## Reglas generales

- Prohibido: `malloc`, `free`, `printf`, funciones de C no aprobadas, STL en CPP00–CPP02 (salvo indicación contraria).
- Cada clase en su propio par de archivos: `Foo.hpp` / `Foo.cpp`.
- Sin memory leaks: todo `new` debe tener su `delete`.
- Norma del subject: sin `friend` salvo que se pida explícitamente.
- Los destructores deben ser `virtual` en jerarquías de herencia.

---

## CPP00 · Introducción a OOP

### Namespaces

Evitan colisiones de nombres. Agrupan símbolos bajo un identificador.

```cpp
namespace MyLib {
    void foo();
}
MyLib::foo();
```

`std::` es el namespace de la librería estándar.

---

### Clases y objetos

Una **clase** es un tipo que agrupa datos (atributos) y comportamiento (métodos).  
Un **objeto** es una instancia de una clase.

```
┌─────────────────────────┐
│         Clase           │
│  ─ ─ ─ ─ ─ ─ ─ ─ ─ ─  │
│  Atributos (datos)      │
│  Métodos (funciones)    │
└─────────────────────────┘
         │
         │ instancia
         ▼
      Objeto
```

**Encapsulación:** los atributos son `private`; el acceso se controla con métodos `public`.

---

### Modificadores de acceso

| Modificador | Accesible desde              |
|-------------|------------------------------|
| `public`    | Cualquier lugar              |
| `private`   | Solo la propia clase         |
| `protected` | La clase y sus derivadas     |

---

### Constructores y destructor

```
Constructor por defecto   →  sin parámetros
Constructor parametrizado →  con parámetros
Constructor de copia      →  recibe const ref de la misma clase
Destructor                →  libera recursos, prefijo ~
```

**Orden de ejecución:**
```
Constructor base → Constructor miembro → Cuerpo constructor
Cuerpo destructor → Destructor miembro → Destructor base
```

---

### Lista de inicialización

Inicializa atributos **antes** de ejecutar el cuerpo del constructor.  
**Obligatoria** para: referencias, `const`, objetos sin constructor por defecto.

```cpp
MyClass::MyClass(int x) : _x(x), _y(0) {
    // cuerpo
}
```

---

### Miembros estáticos (`static`)

Pertenecen a la **clase**, no a la instancia. Compartidos entre todos los objetos.

```
Clase::metodoEstatico()   // acceso sin objeto
Clase::_atributoEstatico  // debe definirse en .cpp
```

---

### Flujos de E/S (`iostream`)

| Objeto    | Uso                     |
|-----------|-------------------------|
| `std::cout` | Salida estándar        |
| `std::cin`  | Entrada estándar       |
| `std::cerr` | Errores (no bufferizado)|
| `std::endl` | Flush + salto de línea |

---

## CPP01 · Memoria, referencias y punteros

### Asignación dinámica de memoria

```
stack  →  vida ligada al scope, gestión automática
heap   →  vida manual, new / delete
```

```cpp
// objeto en heap
Foo *ptr = new Foo();
delete ptr;

// array en heap
int *arr = new int[10];
delete[] arr;
```

**Regla:** cada `new` → un `delete`; cada `new[]` → un `delete[]`.

---

### Punteros vs Referencias

| Característica       | Puntero (`*`)        | Referencia (`&`)       |
|----------------------|----------------------|------------------------|
| Puede ser nulo       | Sí                   | No                     |
| Reasignable          | Sí                   | No (ligada al init)    |
| Sintaxis de acceso   | `ptr->` / `*ptr`     | Directa (como alias)   |
| Uso típico           | Arrays, heap, nullptr | Parámetros, alias      |

---

### Punteros a miembros

Apuntan a un método o atributo de una clase (no a una instancia concreta).

```cpp
void (Foo::*fptr)() = &Foo::bar;
(obj.*fptr)();
```

---

### `switch` / `if` – cuándo usar cada uno

- `switch`: para comparar un valor entero/enum contra múltiples constantes.
- `if-else`: para condiciones booleanas o rangos.

---

### Archivos y streams (`fstream`)

```cpp
std::ifstream in("file.txt");
std::ofstream out("out.txt");
std::string line;
std::getline(in, line);
```

---

## CPP02 · Forma Canónica Ortodoxa y sobrecarga

### Forma Canónica Ortodoxa (OCF)

Toda clase con gestión de recursos **debe** implementar estos cuatro:

```
1. Constructor por defecto
2. Constructor de copia
3. Operador de asignación (operator=)
4. Destructor
```

**Por qué:** evita copias superficiales (shallow copy) que provocan doble `delete`.

```
Shallow copy  →  dos punteros apuntan al mismo heap  →  UB al destruir
Deep copy     →  cada objeto tiene su propia copia de los datos
```

El operador de asignación debe:
1. Comprobar autoasignación (`if (this == &rhs)`)
2. Liberar recursos propios
3. Copiar los datos de `rhs`
4. Retornar `*this`

---

### Sobrecarga de operadores (Ad-hoc polymorphism)

Permite usar operadores estándar con tipos propios.

| Operador         | Ejemplo de uso         |
|------------------|------------------------|
| Aritméticos      | `a + b`, `a - b`       |
| Comparación      | `a == b`, `a < b`      |
| Incremento       | `++a` (pre), `a++` (post) |
| Inserción stream | `std::cout << obj`     |
| Asignación       | `a = b`                |

El operador `<<` para streams suele declararse como función libre (`friend` o no miembro).

---

### Números en punto fijo

Representación de reales con un número fijo de bits para la parte fraccionaria.

```
valor_real = valor_entero / 2^fracBits
```

Permite aritmética de reales sin `float` hardware, con precisión controlada.

```
Conversión float → fixed:  roundf(f * (1 << _frac))
Conversión fixed → float:  (float)_raw / (1 << _frac)
```

---

## CPP03 · Herencia

### Concepto

Una clase **derivada** hereda atributos y métodos de una clase **base**, y puede extenderlos o modificarlos.

```
         Base
          │
    ┌─────┴─────┐
  Derived1   Derived2
```

```cpp
class Derived : public Base { ... };
```

**Tipo de herencia:**

| Especificador | public de Base pasa a | protected de Base pasa a |
|---------------|-----------------------|--------------------------|
| `public`      | public                | protected                |
| `protected`   | protected             | protected                |
| `private`     | private               | private                  |

---

### Constructores en herencia

El constructor de la derivada **debe** llamar explícitamente al de la base en la lista de inicialización:

```cpp
Derived::Derived(int x) : Base(x) { ... }
```

---

### Herencia múltiple y problema del diamante

```
      Base
     /    \
  Mid1    Mid2
     \    /
      Final
```

`Final` heredaría **dos copias** de `Base`. Solución: herencia virtual.

```cpp
class Mid1 : virtual public Base { ... };
class Mid2 : virtual public Base { ... };
class Final : public Mid1, public Mid2 { ... };
```

Con herencia virtual, `Base` se construye **una sola vez**, en el constructor más derivado.

---

### Ocultamiento vs sobrescritura

- **Ocultamiento:** método con el mismo nombre en la derivada oculta el de la base (sin `virtual`).
- **Sobrescritura (override):** método `virtual` en la base redefinido en la derivada → comportamiento polimórfico.

---

## CPP04 · Polimorfismo, clases abstractas e interfaces

### Funciones virtuales

Permiten que una llamada a través de un puntero/referencia a **Base** ejecute el método de la clase **real** del objeto (dispatch dinámico).

```
sin virtual → se llama el método del tipo del puntero  (estático)
con virtual → se llama el método del tipo del objeto   (dinámico)
```

Implementación interna: **vtable** (tabla de punteros a funciones virtuales por clase).

```
Objeto en memoria:
┌──────────┬──────────────┐
│ vptr     │  datos...    │
└──────────┴──────────────┘
     │
     ▼
  vtable de la clase real
  [ &Derived::metodo, ... ]
```

---

### Destructor virtual

**Regla:** si una clase tiene métodos virtuales, su destructor **debe** ser virtual.

Sin destructor virtual:
```
delete ptr_base;  →  solo llama ~Base()  →  leak de recursos de Derived
```
Con destructor virtual:
```
delete ptr_base;  →  llama ~Derived() y luego ~Base()  →  correcto
```

---

### Clases abstractas

Una clase con al menos una **función virtual pura** no puede instanciarse directamente.

```cpp
virtual void sound() = 0;  // función virtual pura
```

Sirve como **contrato**: toda clase derivada debe implementar esos métodos.

```
Clase abstracta (Animal)
        │
   ┌────┴────┐
  Dog       Cat
sound()   sound()   ← implementación obligatoria
```

---

### Interfaces (en C++98)

C++ no tiene palabra clave `interface`. Se simula con una clase que:
- Solo tiene funciones virtuales puras.
- No tiene atributos.
- Tiene destructor virtual público.

```cpp
class IShape {
public:
    virtual ~IShape() {}
    virtual float area() const = 0;
    virtual void draw() const = 0;
};
```

Una clase puede "implementar" múltiples interfaces mediante herencia múltiple de clases abstractas puras.

---

### Polimorfismo: resumen visual

```
Animal *a = new Dog();
a->sound();
     │
     └──▶ vtable de Dog ──▶ Dog::sound()   ✓

Animal *b = new Cat();
b->sound();
     │
     └──▶ vtable de Cat ──▶ Cat::sound()   ✓
```

Mismo código, comportamiento diferente según el tipo real del objeto.

---

### Copia profunda con jerarquías

Al copiar objetos polimórficos se necesita el **idiom clone**:

```cpp
virtual Animal *clone() const = 0;
// en Derived:
Animal *clone() const { return new Dog(*this); }
```

Evita el object slicing (pérdida de la parte derivada al copiar por valor a un objeto base).

---

## Makefile de referencia

```makefile
NAME    = program
CXX     = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS    = main.cpp Foo.cpp
OBJS    = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

---

## Errores comunes

| Error                                      | Causa                                          | Solución                                      |
|--------------------------------------------|------------------------------------------------|-----------------------------------------------|
| Double free / crash al destruir            | Shallow copy sin OCF                           | Implementar constructor de copia y `operator=`|
| Método de Base llamado en lugar de Derived | Método no marcado `virtual`                    | Añadir `virtual` en la Base                   |
| Leak con herencia                          | Destructor de Base no es `virtual`             | `virtual ~Base()`                             |
| Object slicing                             | Asignar Derived a objeto Base por valor        | Usar punteros/referencias; idiom `clone()`    |
| Atributo `static` sin definición en .cpp  | Declarado en .hpp pero no definido             | Añadir `Type Class::_attr = val;` en .cpp     |
| Herencia diamante sin `virtual`            | Dos copias de la Base en el objeto final       | `virtual public Base` en las intermedias      |
| `new[]` con `delete`                       | UB: mismatch de operadores                     | Usar `delete[]` para arrays                   |

---

> **Consejo general:** ante cualquier duda sobre un objeto, pregúntate:
> *¿quién lo crea? ¿quién lo posee? ¿quién lo destruye?*  
> Responder esas tres preguntas resuelve el 80% de los bugs de memoria.
