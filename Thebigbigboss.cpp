#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// si este commit funciona, deberia mostrarse
// commit subido arrastrando el archivo desde mi carpeta xd


using namespace std;

class Publicacion {
private:
    string titulo;
    string autor;
    int anioPublicacion;

public:
    Publicacion(string t, string a, int anio) {
        setTitulo(t);
        setAutor(a);
        setAnioPublicacion(anio);
    }

    virtual ~Publicacion() {}

    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getAnio() const { return anioPublicacion; }

    void setTitulo(const string& t) {
        if (!t.empty()) titulo = t;
    }

    void setAutor(const string& a) {
        if (!a.empty()) autor = a;
    }

    void setAnioPublicacion(int a) {
        if (a >= 1500 && a <= 2025) anioPublicacion = a;
    }

    virtual void mostrarInformacion() const {
        cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nAnio: " << anioPublicacion << endl;
    }

    virtual string tipo() const = 0;
};

class Libro : public Publicacion {
private:
    int numPaginas;

public:
    Libro(string t, string a, int anio, int p) : Publicacion(t, a, anio) {
        setPaginas(p);
    }

    void setPaginas(int p) {
        if (p > 0) numPaginas = p;
    }

    void mostrarInformacion() const override {
        Publicacion::mostrarInformacion();
        cout << "Paginas: " << numPaginas << endl;
    }

    string tipo() const override { return "Libro"; }
};

class Revista : public Publicacion {
private:
    int numeroEdicion;

public:
    Revista(string t, string a, int anio, int ed) : Publicacion(t, a, anio) {
        setEdicion(ed);
    }

    void setEdicion(int ed) {
        if (ed > 0) numeroEdicion = ed;
    }

    void mostrarInformacion() const override {
        Publicacion::mostrarInformacion();
        cout << "Edicion: " << numeroEdicion << endl;
    }

    string tipo() const override { return "Revista"; }
};

class Periodico : public Publicacion {
private:
    string fechaPublicacion;
    string ciudad;

public:
    Periodico(string t, string a, int anio, string f, string c) : Publicacion(t, a, anio) {
        setFecha(f);
        setCiudad(c);
    }

    void setFecha(const string& f) {
        if (!f.empty()) fechaPublicacion = f;
    }

    void setCiudad(const string& c) {
        if (!c.empty()) ciudad = c;
    }

    void mostrarInformacion() const override {
        Publicacion::mostrarInformacion();
        cout << "Fecha de publicacion: " << fechaPublicacion << endl;
        cout << "Ciudad: " << ciudad << endl;
    }

    string tipo() const override { return "Periodico"; }
};

vector<Publicacion*> publicaciones;

string aMinusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);
    return texto;
}

bool existeDuplicado(const string& titulo, const string& autor) {
    string t = aMinusculas(titulo);
    string a = aMinusculas(autor);
    for (auto* p : publicaciones)
        if (aMinusculas(p->getTitulo()) == t && aMinusculas(p->getAutor()) == a)
            return true;
    return false;
}

void ingresarLibro() {
    string titulo, autor;
    int anio, paginas;

    cin.ignore();
    cout << "Titulo: "; getline(cin, titulo);
    cout << "Autor: "; getline(cin, autor);
    cout << "Anio: "; cin >> anio;
    cout << "Paginas: "; cin >> paginas;

    if (titulo.empty() || autor.empty() || paginas <= 0 || anio < 1500 || anio > 2025) {
        cout << "Datos invalidos." << endl;
        return;
    }

    if (existeDuplicado(titulo, autor)) {
        cout << "Ya existe esta publicacion." << endl;
        return;
    }

    publicaciones.push_back(new Libro(titulo, autor, anio, paginas));
    cout << "Libro agregado." << endl;
}

void ingresarRevista() {
    string titulo, autor;
    int anio, ed;

    cin.ignore();
    cout << "Titulo: "; getline(cin, titulo);
    cout << "Autor: "; getline(cin, autor);
    cout << "Anio: "; cin >> anio;
    cout << "Edicion: "; cin >> ed;

    if (titulo.empty() || autor.empty() || ed <= 0 || anio < 1500 || anio > 2025) {
        cout << "Datos invalidos." << endl;
        return;
    }

    if (existeDuplicado(titulo, autor)) {
        cout << "Ya existe esta publicacion." << endl;
        return;
    }

    publicaciones.push_back(new Revista(titulo, autor, anio, ed));
    cout << "Revista agregada." << endl;
}