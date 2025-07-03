#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Clase base
class Publicacion {
protected:
    string titulo;
    string autor;
    int anioPublicacion;

public:
    Publicacion(string t, string a, int anio) : titulo(t), autor(a) {
        setAnioPublicacion(anio);
    }

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getAnio() const { return anioPublicacion; }

    void setAnioPublicacion(int nuevoAnio) {
        if (nuevoAnio >= 1500 && nuevoAnio <= 2025)
            anioPublicacion = nuevoAnio;
        else
            cout << "Anio no valido (1500-2025)." << endl;
    }
    
    class Libro : public Publicacion {
private:
    int numeroPaginas;

public:
    Libro(string t, string a, int anio, int numPaginas)
        : Publicacion(t, a, anio), numeroPaginas(numPaginas) {}
        
        // FUBCipn
void ingresarLibro() {
    string titulo, autor;
    int anio, paginas;

    cin.ignore();
    cout << "TItulo: ";
    getline(cin, titulo);
    cout << "Autor: ";
    getline(cin, autor);
    cout << "Aio: ";
    cin >> anio;
    cout << "Paginas: ";
    cin >> paginas;

    if (titulo.empty() || autor.empty() || paginas <= 0 || anio < 1500 || anio > 2025) {
        cout << "Datos invalidos" << endl;
        return;
    }

