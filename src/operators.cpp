#include <iostream>

#include "cell.h"
#include "rectangle.h"
#include "vector_op.h"

int main() {
    Cell cell1(1, 1);
    Cell cell2(2, 3);

    std::cout << cell1 + cell2;
    std::cout << cell1 + 2;
    std::cout << 2 + cell1;

    std::vector<int> vec{ 1, 2, 3, 4, 5, 6 };
    std::cout << vec;
    
    Rectangle rec(5,10);
    Square sq(5);
    std::cout << "Before:" << std::endl;
    rec.display();
    sq.display();

    rec.morph(sq);
    std::cout << "\nAfter:" << std::endl;
    rec.display();
    sq.display();
}
