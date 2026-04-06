#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Clase solicitada para la actividad [cite: 8]
class CalculadorRFC {
private:
    string nombre, apellidoPaterno, apellidoMaterno;
    string dia, mes, anio;

    // Función para encontrar la primera vocal interna del apellido paterno [cite: 18]
    char obtenerPrimeraVocal(string apellido) {
        for (size_t i = 1; i < apellido.length(); i++) {
            char c = toupper(apellido[i]);
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') return c;
        }
        return 'X';
    }

    // Validación de palabras inconvenientes según la regla de la actividad 
    bool esInconveniente(string combo) {
        vector<string> lista = {"PENE", "PUTA", "PUTO", "CACA", "COGE", "COJO", "BUEY", "KAKA"};
        for (string palabra : lista) {
            if (combo == palabra) return true;
        }
        return false;
    }

public:
    void capturarDatos() {
        cout << "Calculo de RFC" << endl;
        cout << "Introduce tu nombre: "; getline(cin, nombre);
        cout << "Introduce tu apellido paterno: "; getline(cin, apellidoPaterno);
        cout << "Introduce tu apellido materno: "; getline(cin, apellidoMaterno);
        cout << "Fecha de nacimiento (solo numeros)" << endl;
        cout << "Dia: "; cin >> dia;
        cout << "Mes: "; cin >> mes;
        cout << "Año: "; cin >> anio;
    }

    void mostrarRFC() {
        string rfc = "";
        
        // 1 y 2: Inicial y primera vocal del paterno [cite: 18]
        rfc += (char)toupper(apellidoPaterno[0]);
        rfc += obtenerPrimeraVocal(apellidoPaterno);
        
        // 3: Inicial materno o X si no existe 
        if (apellidoMaterno.empty()) rfc += 'X';
        else rfc += (char)toupper(apellidoMaterno[0]);

        // 4: Inicial del nombre o X si es palabra inconveniente 
        string cuatroLetras = rfc + (char)toupper(nombre[0]);
        if (esInconveniente(cuatroLetras)) {
            rfc += 'X';
        } else {
            rfc += (char)toupper(nombre[0]);
        }

        // 5-10: Fecha YYMMDD 
        if (dia.length() == 1) dia = "0" + dia;
        if (mes.length() == 1) mes = "0" + mes;
        rfc += anio.substr(2, 2);
        rfc += mes;
        rfc += dia;

        cout << "Tu RFC sin homoclave es: " << rfc << endl; // Sin homoclave [cite: 29]
    }
};

int main() {
    CalculadorRFC app;
    app.capturarDatos();
    app.mostrarRFC();
    return 0;
}