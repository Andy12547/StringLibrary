# String Library - Librería de Manejo de Cadenas en C++

Una librería completa e implementada desde cero para el manejo avanzado de cadenas de caracteres en C++. Desarrollada como proyecto académico que demuestra el dominio de memoria dinámica, algoritmos de cadenas y manejo de archivos.

## 🚀 Características

### Funcionalidades Principales
-  **Constructores**: Desde cadenas C, copia y por defecto
-  **Destructor**: Liberación automática de memoria
-  **Concatenación inteligente**: Soporta índices positivos y negativos
-  **Reemplazo de subcadenas**: Búsqueda y reemplazo eficiente
-  **Manejo de archivos**: Carga y guardado en diferentes modos
-  **Iteradores personalizados**: Compatible con range-based for loops
-  **Índices negativos**: Acceso tipo Python con índices negativos

### Métodos Implementados
- `String(char* str)` - Constructor desde cadena C
- `~String()` - Destructor
- `void concat(char* str, int n)` - Concatenación con índice
- `void replace(char* str1, char* str2)` - Reemplazo de subcadenas
- `void load(char* filename)` - Carga desde archivo
- `void save(char* filename, char* mode)` - Guardado en archivo
- `Iterator begin()/end()` - Iteradores personalizados

## 📦 Instalación y Uso

### Prerrequisitos
- Compilador C++ (g++, clang, o MSVC)
- Sistema Linux, Windows o macOS
- Git (opcional)

### Compilación y Ejecución

```bash
# 1. Clonar el repositorio (o descargar archivos)
git clone https://github.com/Andy12547/StringLibrary.git
cd stringLibrary

# 2. Compilar el programa
g++ -o program main.cpp String.cpp

# 3. Ejecutar las pruebas
./program

# 4. (Opcional) Compilar con más advertencias
g++ -Wall -Wextra -o program main.cpp String.cpp
