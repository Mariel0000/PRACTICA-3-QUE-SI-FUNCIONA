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

    virtual void mostrarInformacion() const {
        cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nAnio: " << anioPublicacion << endl;
    }

    virtual string tipo() const = 0;
    virtual ~Publicacion() {}
};

// Clase derivada Libro
class Libro : public Publicacion {
    int numeroPaginas;
public:
    Libro(string t, string a, int anio, int paginas)
        : Publicacion(t, a, anio), numeroPaginas(paginas) {}

    void mostrarInformacion() const override {
        Publicacion::mostrarInformacion();
        cout << "Paginas: " << numeroPaginas << endl;
    }

    string tipo() const override { return "Libro"; }
};

// Clase derivada Revista
class Revista : public Publicacion {
    int numeroEdicion;
public:
    Revista(string t, string a, int anio, int edicion)
        : Publicacion(t, a, anio), numeroEdicion(edicion) {}

    void mostrarInformacion() const override {
        Publicacion::mostrarInformacion();
        cout << "Edicion: " << numeroEdicion << endl;
    }

    string tipo() const override { return "Revista"; }
};

// Vector dinámico de publicaciones
vector<Publicacion*> publicaciones;

// Utilidad para convertir a minúsculas
string aMinusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    return texto;
}

// Verifica si ya existe una publicación con mismo título y autor
bool existeDuplicado(const string& titulo, const string& autor) {
    string tMin = aMinusculas(titulo);
    string aMin = aMinusculas(autor);
    for (auto* pub : publicaciones) {
        if (aMinusculas(pub->getTitulo()) == tMin &&
            aMinusculas(pub->getAutor()) == aMin)
            return true;
    }
    return false;
}

// Funciones del sistema
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

    if (existeDuplicado(titulo, autor)) {
        cout << "Ya eXiste esa publicacion" << endl;
        return;
    }

    publicaciones.push_back(new Libro(titulo, autor, anio, paginas));
    cout << "Libro agregado." << endl;
}

void ingresarRevista() {
    string titulo, autor;
    int anio, edicion;

    cin.ignore();
    cout << "Tuitulo: ";
    getline(cin, titulo);
    cout << "Autor: ";
    getline(cin, autor);
    cout << "Anioo: ";
    cin >> anio;
    cout << "Edicion: ";
    cin >> edicion;

    if (titulo.empty() || autor.empty() || edicion <= 0 || anio < 1500 || anio > 2025) {
        cout << "Datos invalidos." << endl;
        return;
    }

    if (existeDuplicado(titulo, autor)) {
        cout << "Ya existe esa publicacion." << endl;
        return;
    }

    publicaciones.push_back(new Revista(titulo, autor, anio, edicion));
    cout << "Revista agregada." << endl;
}

