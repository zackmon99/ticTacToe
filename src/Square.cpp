#include "Square.hpp"


Square::Square(int row, int column): m_row(row), m_column(column), m_state(0) {

}

int Square::getRow() {
    return m_row;
}

void Square::setRow(int row) {
    m_row = row;
}

int Square::getColumn() {
    return m_column;
}

void Square::setColumn(int column) {
    m_column = column;
}

void Square::setRowColumn(int row, int column) {
    m_row = row;
    m_column = column;
}

int Square::getState() {
    return m_state;
}
void Square::setState(int state) {
    m_state = state;
    
}

Square::~Square() {
    
}
