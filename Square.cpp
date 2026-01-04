#include "Square.h"
#include <stdexcept>

// Comprueba que los 4 lados tengan la misma longitud
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d12 && d12 == d23 && d23 == d30);
}

// Constructor por defecto
Square::Square() : Rectangle() {
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

// Constructor con parámetros
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    //comprobamos que sea específicamente un cuadrado.
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Los vértices no forman un cuadrado válido.");
    }
    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.color;
    for (int i = 0; i < Square::N_VERTICES; i++) {
        out << "; v" << i << " = " << square.vs[i];
    }
    out << "]";
    return out;
}
