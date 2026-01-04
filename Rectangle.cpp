#include "Rectangle.h"

// Valida que los lados opuestos tengan la misma longitud
bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);
    
    // Comparacion de lados opuestos
    return (d01 == d23 && d12 == d30);
}

// Constructor por defecto
Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

// Constructor con parámetros
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
    
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Constructor de copia
Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice de vértice fuera de rango.");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un rectángulo válido.");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) { 
        // Liberar memoria antigua
        delete[] vs; 
        
        //Copiar atributos básicos
        this->color = r.color;
        
        //Reservar nueva memoria y copiar
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

double Rectangle::area() const {
    // Base * Altura (distancia v0-v1 * distancia v1-v2)
    return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const {
    //calculo perimetro 2*base*altura
    return 2 * (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2]));
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.color;
    for (int i = 0; i < Rectangle::N_VERTICES; i++) {
        out << "; v" << i << " = " << r.vs[i];
    }
    out << "]";
    return out;
}
