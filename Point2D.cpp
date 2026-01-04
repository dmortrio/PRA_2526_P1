#include "Point2D.h"
#include <cmath>

// Constructor
Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}


double Point2D::distance(const Point2D &a, const Point2D &b) {
    return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}

// Operador de igualdad ==
bool operator==(const Point2D &a, const Point2D &b) {
    return (a.x == b.x && a.y == b.y);
}

bool operator!=(const Point2D &a, const Point2D &b) {
    return !(a == b); // Reutilizamos ==
}

// Operador de impresión <<
std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
