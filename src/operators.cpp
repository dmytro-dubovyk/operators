#include <iostream>
#include <vector>

#include "cell.h"
#include "constructor.h"
#include "rectangle.h"
#include "vector_op.h"

class enclose {
    struct nested { // private member
        void g() {
            std::cout << __PRETTY_FUNCTION__ << std::endl;
        }
    };
 public:
    static nested f() { return nested{}; }
};

int main() {
    Cell cell1(1, 1, 10);
    Cell cell2(2, 3);

    std::cout << cell1 + cell2;
    std::cout << cell1 + 2;

    std::cout << 2 + cell1; // won't work without global operator+(Cell, Cell)
    std::cout << "Cell as int: " << static_cast<int>(cell1) + 2 << std::endl; // explicit cast to int

    const std::type_info& typeInfo = typeid(&cell1);
    std::cout<< "type info: " << typeInfo.name() << std::endl;

    std::vector<int> vec{ 1, 2, 3, 4, 5, 6 };
    using VecT = int[];
    const VecT vec2{1, 2, 3, 4, 5};
    std::cout << "VecT is array: " << std::is_array<VecT>() << std::endl;
    std::cout << vec; // overloaded <<
    
    Rectangle rec(5,10);
    Square sq(5);
    std::cout << "Before:" << std::endl;
    rec.display();
    sq.display();

    rec.morph(sq);
    std::cout << "\nAfter:" << std::endl;
    rec.display();
    sq.display();

   try {
     X* p1 = new(false) X;
   } catch(const std::exception&) { }


    // nested namespaces trick
    enclose::f().g(); // OK: does not name 'nested'
    //enclose::nested n1 = enclose::f(); // error: 'nested' is private
    auto n2 = enclose::f(); // OK: does not name 'nested'
    n2.g();
}
