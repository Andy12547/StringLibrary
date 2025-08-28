#include "String.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

// Constructor por defecto
String::String() : data(nullptr), length(0) {
    data = new char[1];
    data[0] = '\0';
}

// Constructor desde cadena C
String::String(const char* str) {
    if (str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    } else {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }
}

// Constructor de copia
String::String(const String& other) {
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
}

// Destructor
String::~String() {
    delete[] data;
}

// Operador de asignación
String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    return *this;
}

// Operador de índice
char& String::operator[](int index) {
    if (index < 0) index = length + index;
    if (index < 0 || index >= length) {
        throw out_of_range("Index out of bounds");
    }
    return data[index];
}

// Concatenación
void String::concat(const char* str, int n) {
    if (!str || n == 0) return;
    
    size_t strLen = strlen(str);
    if (n < 0) n = strLen + n;
    if (n <= 0) return;
    
    n = min(n, (int)strLen);
    size_t newLength = length + n;
    char* newData = new char[newLength + 1];
    
    strcpy(newData, data);
    strncat(newData, str, n);
    
    delete[] data;
    data = newData;
    length = newLength;
}

// Método replace CORREGIDO
void String::replace(const char* str1, const char* str2) {
    if (str1 == nullptr || str2 == nullptr || data == nullptr) return;
    
    size_t str1Len = strlen(str1);
    if (str1Len == 0) return; // No buscar cadena vacía
    
    // Buscar la primera ocurrencia
    char* found = strstr(data, str1);
    if (found == nullptr) return; // No se encontró
    
    // Calcular nuevas longitudes
    size_t str2Len = strlen(str2);
    size_t newLength = length - str1Len + str2Len;
    
    // Crear nuevo buffer
    char* newData = new char[newLength + 1];
    
    // Copiar parte anterior
    size_t prefixLen = found - data;
    strncpy(newData, data, prefixLen);
    newData[prefixLen] = '\0';
    
    // Agregar reemplazo
    strcat(newData, str2);
    
    // Agregar parte posterior
    strcat(newData, found + str1Len);
    
    // Actualizar objeto
    delete[] data;
    data = newData;
    length = newLength;
}

// Método load CORREGIDO
void String::load(const char* filename) {
    ifstream file(filename, ios::binary | ios::ate); // Abrir al final
    if (!file.is_open()) return; // Si no existe, no hacer nada
    
    // Obtener tamaño del archivo
    streamsize size = file.tellg();
    file.seekg(0, ios::beg);
    
    // Leer contenido
    char* buffer = new char[size + 1];
    file.read(buffer, size);
    buffer[size] = '\0';
    
    file.close();
    
    // Reemplazar contenido actual
    delete[] data;
    data = buffer;
    length = size;
}

// Método save CORREGIDO
void String::save(const char* filename, const char* mode) {
    if (data == nullptr) return;
    
    ios_base::openmode openMode;
    
    if (strcmp(mode, "w") == 0) {
        openMode = ios::out; // Sobrescribir
    } else if (strcmp(mode, "a") == 0) {
        openMode = ios::app; // Append
    } else {
        return; // Modo inválido
    }
    
    ofstream file(filename, openMode);
    if (file.is_open()) {
        file.write(data, length);
        file.close();
    }
}