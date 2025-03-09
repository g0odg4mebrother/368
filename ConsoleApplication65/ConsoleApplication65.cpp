#include <iostream>
using namespace std;

class GeometricFigure {
protected:
    double area_;

public:
    virtual ~GeometricFigure() {}

    virtual double getArea() const = 0;
};

class Rectangle : public GeometricFigure {
private:
    double width_;
    double height_;

public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double getArea() const override {
        return width_ * height_;
    }
};

class Circle : public GeometricFigure {
private:
    double radius_;

public:
    Circle(double radius) : radius_(radius) {}

    double getArea() const override {
        return 3.14 * pow(radius_, 2);
    }
};

class Triangle : public GeometricFigure {
private:
    double a_;
    double b_;
    double c_;

public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}

    double getArea() const override {
        double s = (a_ + b_ + c_) / 2;
        return sqrt(s * (s - a_) * (s - b_) * (s - c_));
    }
};

int main() {
    Rectangle rectangle(5, 3);       
    Circle circle(4);    
    Triangle triangle(3, 4, 5);    

    GeometricFigure* figures[] = { &rectangle, &circle, &triangle };

    for (auto figure : figures) {
        cout << "Площадь фигуры: " << figure->getArea() << endl;
    }

    return 0;
}
