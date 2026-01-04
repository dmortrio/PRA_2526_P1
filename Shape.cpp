#include "Shape.h"
#include <stdexcept>

// Constructor por defecto(rojo)
Shape::Shape() {
    color = "red";
}

// Constructor con parámetro para validar el color
Shape::Shape(std::string color) {
    set_color(color);
}

// Getter
std::string Shape::get_color() const {
    return color;
}

// Setter con validación
void Shape::set_color(std::string c) {
    if (c == "red" || c == "green" || c == "blue") {
        color = c;
    } else {
        throw std::invalid_argument("Color no válido. Use 'red', 'green' o 'blue'.");
    }
}
