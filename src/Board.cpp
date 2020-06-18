#include "Board.hpp"
#include <iostream>

typedef std::vector<std::vector<Square*>> vec2d;

Board::Board(int rows, int columns, Screen* screen): m_rows(rows), m_columns(columns), m_pScreen(screen) {

    this->init();
    m_squareWidth = m_pScreen->SCREEN_WIDTH / m_columns;
    m_squareHeight = m_pScreen->SCREEN_HEIGHT / m_rows;
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
    m_turn = 1;
    
}

void Board::setSquare(int x, int y, int state) {
    m_squares[x][y]->setState(state);
}

Square * Board::getSquare(int x, int y) {
    return m_squares[x][y];
}

int Board::getSquareState(int x, int y) {
    return m_squares[x][y]->getState();
}

void Board::drawBoard() {
    

    for (int i = 0; i < m_pScreen->SCREEN_WIDTH; i += m_squareWidth )
    {
        for (int j = 0; j < m_pScreen->SCREEN_HEIGHT ; j++)
        {
            m_pScreen->setPixel(i, j, 255, 255, 255);
        }
        
    }

    for (int i = 0; i < m_pScreen->SCREEN_WIDTH; i++)
    {
        for (int j = 0; j < m_pScreen->SCREEN_HEIGHT; j += m_squareHeight)
        {
            m_pScreen->setPixel(i, j, 255, 255, 255);
        }
    }
    

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
    bool win = false;
    if ( checkHorizontalWin() ) {
        win = true;
    }

    if ( checkVerticalWin() ) {
        win = true;
    }

    if ( checkDiagonalWin() ) {
        win = true;
    }
    return win;
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
        }
        if (winFound)
        {
            this->blinkRow(i);
            return true;
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
        }
        if (winFound)
        {
            this->blinkRow(i);
            return true;
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
                break;
            }
        }
        if (winFound)
        {
            this->blinkColumn(i);
            return true;
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
                break;
            }
        }
        if (winFound)
        {
            this->blinkColumn(i);
            return true;
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
            j++;
            break;
        }
        j++;
    }
    
    if( winFound )
    {
        this->blinkDiagonal(0);
        return true;
    }
    
    j = 0;
    winFound = true;
    for (int i = 2; i >= 0; i--)
    {
        if (getSquareState(i, j) != 1)
        {
            winFound = false;
            j++;
            break;
        }
        j++;
    }

    if( winFound )
    {
        this->blinkDiagonal(1);
        return true;
    }

    j = 0;
    winFound = true;
    for (int i = 0; i < 3; i++)
    {
        if (getSquareState(i, j) != 2)
        {
            winFound = false;
            j++;
            break;
        }
        j++;
    }
    
    if( winFound )
    {
        this->blinkDiagonal(0);
        return true;
    }
    
    j = 0;
    winFound = true;
    for (int i = 2; i >= 0; i--)
    {
        if (getSquareState(i, j) != 2)
        {
            winFound = false;
            j++;
            break;
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

bool Board::checkCatsGame() {
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_columns; j++)
        {
            if ( this->getSquareState(j, i) == 0 )
            {
                return false;
            }
        }
        
    }
    return true;
    
}

void Board::blinkRow(int row) {

}

void Board::blinkColumn(int column) {

}

void Board::blinkDiagonal(int diag) {

}

Screen* Board::getScreen() {
    return m_pScreen;
}

int Board::getRows() {
    return m_rows;
}

int Board::getColumns() {
    return m_columns;
}

int Board::getTurn() {
    return m_turn;
}

void Board::nextTurn() {
    if ( m_turn == 1 ) {
        m_turn = 2;
    }
    else {
        m_turn = 1;
    }
}

void Board::colorSquare(int x, int y, int state) {
    for (int i = x * m_squareWidth; i < x * m_squareWidth + m_squareWidth; i++)
    {
        for (int j = y * m_squareHeight; j < y * m_squareHeight + m_squareHeight ; j++)
        {
            if ( state == 1 )
            {
                m_pScreen->setPixel(i, j, 255, 0, 0);
            }
            else if (state == 2)
            {
                m_pScreen->setPixel(i, j, 0, 0, 255);
            }
        } 
    }
    m_pScreen->update();
    
}


