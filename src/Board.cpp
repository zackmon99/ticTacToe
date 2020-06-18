#include "Board.hpp"
#include <iostream>

typedef std::vector<std::vector<Square*>> vec2d;

Board::Board(int rows, int columns, Screen* screen): m_rows(rows), m_columns(columns), m_pScreen(screen) {

    this->init();
    
}

Board::~Board() {
    // free up squares 
    std::cout << "Board destructor called" << std::endl;
    this->freeBoard();

}

void Board::init() {
    this->freeBoard();
    while (!m_squares.empty())
    {
        m_squares.pop_back();
    }

    m_squares.resize(m_columns);
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_columns; j++)
        {
            m_squares[j].push_back(new Square(i, j));

        }
    }
}

void Board::setSquare(int x, int y, int state) {
    
}

Square * Board::getSquare(int x, int y) {
    return m_squares[x][y];
}

int Board::getSquareState(int x, int y) {
    return m_squares[x][y]->getState();
}

void Board::drawBoard(Screen *screen) {
    
}

void Board::freeBoard() {
    for (int i = 0; i < m_squares.size(); i++)
    {
        for (int j = 0; j < m_squares[i].size(); j++)
        {
           delete m_squares[j][i];
        }
    }
}

bool Board::checkWin() {
    return false;
}

bool Board::checkHorizontalWin() {
    
    for (int i = 0; i < m_rows; i++)
    {
        bool winFound = true;
        for (int j = 0; j < m_columns; j++)
        {
            if(this->getSquareState(j, i) != 1)
            {
                winFound = false;
            }
            if (winFound)
            {
                this->blinkRow(i);
                return true;
            }
            
        }
    }

    for (int i = 0; i < m_rows; i++)
    {
        bool winFound = true;
        for (int j = 0; j < m_columns; j++)
        {
            if(this->getSquareState(j, i) != 2)
            {
                winFound = false;
            }
            if (winFound)
            {
                this->blinkRow(i);
                return true;
            }
            
        }
    }
    
    return false;
}

bool Board::checkVerticalWin() {
for (int i = 0; i < m_columns; i++)
    {
        bool winFound = true;
        for (int j = 0; j < m_rows; j++)
        {
            if(this->getSquareState(i, j) != 1)
            {
                winFound = false;
            }
            if (winFound)
            {
                this->blinkRow(i);
                return true;
            }
            
        }
    }

    for (int i = 0; i < m_columns; i++)
    {
        bool winFound = true;
        for (int j = 0; j < m_rows; j++)
        {
            if(this->getSquareState(i, j) != 2)
            {
                winFound = false;
            }
            if (winFound)
            {
                this->blinkRow(i);
                return true;
            }
            
        }
    }
    return false;
}

bool Board::checkDiagonalWin() {

    int j = 0;
    bool winFound = true;
    for (int i = 0; i < 3; i++)
    {
        if (getSquareState(i, j) != 1)
        {
            winFound = false;
        }
        j++;
    }
    
    if( winFound )
    {
        this->blinkDiagonal(0);
        return true;
    }
    
    j = 0;
    for (int i = 2; i >= 0; i--)
    {
        if (getSquareState(i, j) != 1)
        {
            winFound = false;
        }
        j++;
    }

    if( winFound )
    {
        this->blinkDiagonal(1);
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (getSquareState(i, j) != 2)
        {
            winFound = false;
        }
        j++;
    }
    
    if( winFound )
    {
        this->blinkDiagonal(0);
        return true;
    }
    
    j = 0;
    for (int i = 2; i >= 0; i--)
    {
        if (getSquareState(i, j) != 2)
        {
            winFound = false;
        }
        j++;
    }

    if( winFound )
    {
        this->blinkDiagonal(1);
        return true;
    }
    return false;
}

void Board::blinkRow(int row) {

}

void Board::blinkColumn(int column) {

}

void Board::blinkDiagonal(int diag) {

}


