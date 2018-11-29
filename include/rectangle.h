#include <iostream>

class Square;

class Rectangle {
    int width, height;

public:
    Rectangle(int w = 1, int h = 1) : width(w),height(h) {} 
    void display() { std::cout << "Rectangle: " << width * height << std::endl; }
    void morph(const Square&);
};

class Square {
    int side;

public:
    Square(int s = 1) : side(s) {} 
    void display() { std::cout << "Square: " << side * side << std::endl; }
    friend class Rectangle;
};

void Rectangle::morph(const Square &s) {
    width = s.side;
    height = s.side;
}

