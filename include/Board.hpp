#include "Square.hpp"
#include "Screen.hpp"
#include <vector>

using namespace zmgfx;
class Board
{
private:
    /* data */
    int m_rows;
    int m_columns;
    std::vector< std::vector<Square*> > m_squares;
    int m_turn;
    int m_squareWidth;
    int m_squareHeight;
    
    
public:
    Screen *m_pScreen;

    Board(int rows, int columns, Screen *screen);
    ~Board();
    void init();
    void setSquare(int x, int y, int state);
    Square * getSquare(int x, int y);
    int getSquareState(int x, int y);
    void drawBoard();
    void freeBoard();
    bool checkWin();
    bool checkHorizontalWin();
    bool checkVerticalWin();
    bool checkDiagonalWin();
    bool checkCatsGame();
    void blinkRow(int row);
    void blinkColumn(int column);
    void blinkDiagonal(int diagonal);
    int getRows();
    int getColumns();
    Screen* getScreen();
    int getTurn();
    void nextTurn();
    void colorSquare(int x, int y, int state);
    void newGame();
};


