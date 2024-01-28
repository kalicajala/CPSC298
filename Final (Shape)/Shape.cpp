/// @file Shape.cpp
/// @brief will be able to show properites and calculate different things about shapes
/// @author Kali Cajala

#include <iostream>
#include <cmath>

class Shape {
    public: 
        Shape(double dHeight, double dWidth);
        virtual ~Shape();
        virtual void scale(double dScaleFactor) = 0;
        virtual double area() = 0;
        virtual double perimeter() = 0;
        virtual void displayProperties();
    
    protected:
        double m_dHeight;
        double m_dWidth;
        std::string m_strType;
};

class Rectangle : public Shape {
    public:
        Rectangle(double dHeight, double dWidth);
        virtual ~Rectangle();
        void scale(double dScaleFactor);
        double area();
        double perimeter();
};

class Circle : public Shape {
    public:
        Circle(double dHeight, double dWidth);
        virtual ~Circle();
        void scale(double dScaleFactor);
        double area();
        double perimeter();
};

// SHAPE constructor, destructor, and other functions
Shape::Shape(double dHeight, double dWidth) : m_dHeight(dHeight), m_dWidth(dWidth) {
    m_strType = "Shape";
}

Shape::~Shape() {
}

void Shape::displayProperties() {
    std::cout << "Shape Type: " << m_strType << ", height: " << m_dHeight << ", height: " << m_dHeight << std::endl;
}

// RECTANGLE constructor, destructor, and other functions
Rectangle::Rectangle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
    m_strType = "Rectangle";
}

Rectangle::~Rectangle() {
}

void Rectangle::scale(double dScaleFactor) {
    m_dWidth *= dScaleFactor;
    m_dHeight *= dScaleFactor;
}

double Rectangle::area() {
    return m_dWidth * m_dHeight;
}

double Rectangle::perimeter() {
    return 2 * (m_dWidth + m_dHeight);
}

// CIRCLE contructor, destructor, and other functions
Circle::Circle(double dHeight, double dWidth) : Shape(dHeight, dWidth) {
    m_strType = "Circle";
}

Circle::~Circle() {
}

void Circle::scale(double dScaleFactor) {
    m_dWidth *= dScaleFactor;
    m_dHeight *= dScaleFactor;
}

double Circle::area() {
    return 0.25 * M_PI * m_dWidth * m_dWidth;
}

double Circle::perimeter() {
    return M_PI * m_dWidth;
}

int main() {
    Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* p_shapeCircle = new Circle(2.0, 2.0);

    Shape* p_shapes[2];

    p_shapes[0] = p_shapeCircle;
    p_shapes[1] = p_shapeRectangle;

    for (int i = 0; i < 2; ++i) {
        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;

        // Scale by a factor of 2
        p_shapes[i]->scale(2);

        p_shapes[i]->displayProperties();
        std::cout << "Area: " << p_shapes[i]->area() << ", Perimeter: " << p_shapes[i]->perimeter() << std::endl;
    }

    delete p_shapeRectangle;
    delete p_shapeCircle;

    return 0;
}