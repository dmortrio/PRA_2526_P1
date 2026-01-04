#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
    protected:
        Point2D* vs; // Array de vértices
    
    public:
        static const int N_VERTICES = 4;

    private:
        // Método estático
        static bool check(Point2D* vertices);

    public:
        // Constructores y Destructor
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        Rectangle(const Rectangle &r); // Constructor de copia
        ~Rectangle(); // Destructor

        // Getters y Setters
        Point2D get_vertex(int ind) const;
        Point2D operator[](int ind) const;
        virtual void set_vertices(Point2D* vertices);

        // Operador de asignacion
        Rectangle& operator=(const Rectangle &r);

        // Sobrecarga global del operador de salida
        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

        // Métodos virtuales heredados
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        void print() override;
};

#endif
