#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
    private:
        static bool check(Point2D* vertices);

    public:
        // Constructores
        Square();
        Square(std::string color, Point2D* vertices);

        // Métodos sobrescritos
        void set_vertices(Point2D* vertices) override;
        void print() override;

        // Sobrecarga global del operador de salida
        friend std::ostream& operator<<(std::ostream &out, const Square &square);
};

#endif 
