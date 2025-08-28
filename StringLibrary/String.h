#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <stdexcept>

class String {
private:
    char* data;
    size_t length;

public:
    // Constructores y destructor
    String();
    String(const char* str);
    String(const String& other);
    ~String();

    // Métodos requeridos
    void concat(const char* str, int n);
    void replace(const char* str1, const char* str2);
    void load(const char* filename);
    void save(const char* filename, const char* mode);

    // Operadores
    String& operator=(const String& other);
    char& operator[](int index);

    // Iterador
    class Iterator {
    private:
        char* ptr;
    public:
        Iterator(char* p) : ptr(p) {}
        char& operator*() { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + length); }

    // Métodos auxiliares
    size_t size() const { return length; }
    const char* c_str() const { return data; }
};