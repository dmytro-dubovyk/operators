#include <iostream>

class Cell {
public:
    Cell(int a, int b, int c = 0) : x(a), y(b), value(c) {}
    Cell(int v) : x(10), y(10), value(v) {}
    Cell() = delete;
    ~Cell() = default;
/*
    const Cell operator+(const Cell& cell) const {
        Cell newCell(x + cell.x, y + cell.y);
        return newCell;
    }
*/
    friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
    friend const Cell operator+(const Cell& lhs, const Cell& rhs);

private:
    int x;
    int y;
    int value;
};

std::ostream& operator<<(std::ostream& out, const Cell& cell) {
    return out << "x = " << cell.x << ", y = " << cell.y << ", value = " << cell.value <<std::endl;
}

const Cell operator+(const Cell& lhs, const Cell& rhs) {
    Cell cell(lhs.x + rhs.x, lhs.y + rhs.y, lhs.value + rhs.value);
    return cell;
}
