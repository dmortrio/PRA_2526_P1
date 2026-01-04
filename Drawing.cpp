#include "Drawing.h"
#include "ListLinked.h"
#include "Circle.h"
#include "Square.h"

// Constructor
Drawing::Drawing() {
    shapes = new ListLinked<Shape*>();
}

// Destructor: Liberamos la memoria de la lista
Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    std::cout << "Drawing contents:" << std::endl;
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
        std::cout << std::endl;
    }
}

double Drawing::get_area_all_circles() {
    double total_area = 0.0;
    
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        Circle* c = dynamic_cast<Circle*>(s);
        
        if (c != nullptr) {
            // Si c no es nulo es un círculo
            total_area += c->area();
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        Square* sq = dynamic_cast<Square*>(s);
        
        if (sq != nullptr) {
            // Si sq no es nulo lo movemos.
            sq->translate(incX, incY);
        }
    }
}
