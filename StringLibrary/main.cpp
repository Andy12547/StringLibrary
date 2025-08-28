#include "String.h"
#include <iostream>
#include <cstdio>   // Para remove 

using namespace std;

// Función para crear archivo de prueba
void createTestFile() {
    FILE* file = fopen("test.txt", "w");
    if (file) {
        fputs("Este es un archivo de prueba\n", file);
        fputs("Contenido inicial para testing\n", file);
        fclose(file);
    }
}

// Función para limpiar archivos de prueba
void cleanupTestFiles() {
    remove("test.txt");
    remove("output.txt");
    remove("append_test.txt");
}

int main() {
    cout << "=== TEST COMPLETO DE STRING LIBRARY ===" << endl;
    
    // Limpiar archivos anteriores
    cleanupTestFiles();
    createTestFile();

    // 1. TEST CONSTRUCTORES
    cout << "\n1. TEST CONSTRUCTORES:" << endl;
    String s1; // Constructor por defecto
    String s2("Hola Mundo"); // Constructor desde const char*
    String s3(s2); // Constructor de copia
    
    cout << "s1 (default): '" << s1.c_str() << "' length: " << s1.size() << endl;
    cout << "s2 (from char*): '" << s2.c_str() << "' length: " << s2.size() << endl;
    cout << "s3 (copia de s2): '" << s3.c_str() << "' length: " << s3.size() << endl;

    // 2. TEST OPERADOR ASIGNACIÓN
    cout << "\n2. TEST OPERADOR ASIGNACIÓN:" << endl;
    s1 = s2;
    cout << "s1 después de s1 = s2: '" << s1.c_str() << "'" << endl;

    // 3. TEST OPERADOR ÍNDICE
    cout << "\n3. TEST OPERADOR ÍNDICE:" << endl;
    String s4("ABCDE");
    cout << "s4: '" << s4.c_str() << "'" << endl;
    cout << "s4[0]: '" << s4[0] << "'" << endl;
    cout << "s4[2]: '" << s4[2] << "'" << endl;
    cout << "s4[-1]: '" << s4[-1] << "'" << endl;
    cout << "s4[-2]: '" << s4[-2] << "'" << endl;

    // 4. TEST CONCAT
    cout << "\n4. TEST CONCAT:" << endl;
    String s5("Hello");
    cout << "s5 antes: '" << s5.c_str() << "'" << endl;
    s5.concat(" World", 6); // Concat positivo
    cout << "s5 después concat(6): '" << s5.c_str() << "'" << endl;
    
    String s6("Hello");
    s6.concat(" World", -3); // Concat negativo (debe tomar " Wo")
    cout << "s6 después concat(-3): '" << s6.c_str() << "'" << endl;

    // 5. TEST REPLACE
    cout << "\n5. TEST REPLACE:" << endl;
    String s7("El perro corre rápido");
    cout << "s7 antes: '" << s7.c_str() << "'" << endl;
    s7.replace("perro", "gato");
    cout << "s7 después replace: '" << s7.c_str() << "'" << endl;

    // 6. TEST ITERADOR
    cout << "\n6. TEST ITERADOR:" << endl;
    String s8("ABC");
    cout << "Iterando s8 '" << s8.c_str() << "': ";
    for (auto it = s8.begin(); it != s8.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 7. TEST LOAD Y SAVE
    cout << "\n7. TEST LOAD Y SAVE:" << endl;
    
    // Test LOAD
    String s9;
    s9.load("test.txt");
    cout << "s9 después de load('test.txt'): '" << s9.c_str() << "'" << endl;
    
    // Test SAVE (overwrite)
    String s10("Nuevo contenido");
    s10.save("output.txt", "w");
    cout << "Contenido guardado en output.txt (modo w)" << endl;
    
    // Test SAVE (append)
    String s11("\nTexto añadido");
    s11.save("append_test.txt", "a");
    cout << "Contenido añadido en append_test.txt (modo a)" << endl;

    // 8. TEST MANEJO DE ERRORES
    cout << "\n8. TEST MANEJO DE ERRORES:" << endl;
    
    // Test índice fuera de rango
    try {
        cout << "Intentando acceder a s4[10]: ";
        cout << s4[10] << endl; // Debe lanzar excepción
    } catch (const exception& e) {
        cout << "Error capturado: " << e.what() << endl;
    }
    
    // Test archivo no existente
    String s12;
    s12.load("archivo_que_no_existe.txt");
    cout << "s12 después de load archivo inexistente: '" << s12.c_str() << "'" << endl;

    // 9. TEST CADENAS VACÍAS
    cout << "\n9. TEST CADENAS VACÍAS:" << endl;
    String s13("");
    cout << "s13 (vacío): '" << s13.c_str() << "' length: " << s13.size() << endl;
    s13.concat("", 5);
    cout << "s13 después concat vacío: '" << s13.c_str() << "'" << endl;

    cout << "\n=== TODAS LAS PRUEBAS COMPLETADAS ===" << endl;
    cout << "=== REVISA LOS ARCHIVOS CREADOS ===" << endl;
    cout << "- test.txt (original)" << endl;
    cout << "- output.txt (modo w)" << endl;
    cout << "- append_test.txt (modo a)" << endl;

    return 0;
}