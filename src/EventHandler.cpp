#include "EventHandler.hpp"
#include <iostream>


EventHandler::EventHandler(Board *board): m_pBoard(board) {

}

EventHandler::~EventHandler() {
    
}

bool EventHandler::processEvents() {
    SDL_WaitEvent(&event);
    
    switch (event.type)
    {
        case SDL_MOUSEBUTTONDOWN:
            int x;
            int y;
            SDL_GetMouseState(&x, &y);
            mousePress(x, y);
            return true;
            break;

        case SDL_QUIT:
            return false;
            break;

        default:
            return true;
            break;
    }

}

void EventHandler::mousePress(int x, int y) {
    
    int screenWidth = m_pBoard->m_pScreen->SCREEN_WIDTH;
    int screenHeight = m_pBoard->m_pScreen->SCREEN_HEIGHT;

    int squareWidth = screenWidth / m_pBoard->getRows();
    int squareHeight = screenHeight / m_pBoard->getColumns();

    int xSquare = x / squareWidth;
    int ySquare = y / squareHeight;
    std::cout << "Mouse click at " << xSquare << ", " << ySquare << std::endl;
    if ( m_pBoard->getSquareState(xSquare, ySquare) == 0 )
    {
        m_pBoard->setSquare(xSquare, ySquare, m_pBoard->getTurn());
        m_pBoard->colorSquare(xSquare, ySquare, m_pBoard->getTurn());
        m_pBoard->nextTurn();
        if(m_pBoard->checkWin())
        {
            std::cout << "WIN DETECTED" << std::endl;
            m_pBoard->m_pScreen->clear();
            m_pBoard->init();
            m_pBoard->drawBoard();
            m_pBoard->m_pScreen->update();
            return;
        }
    }

    if ( m_pBoard->checkCatsGame() )
    {
        std::cout << "CAT'S GAME DETECTED" << std::endl;
        m_pBoard->m_pScreen->clear();
        m_pBoard->init();
        m_pBoard->drawBoard();
        m_pBoard->m_pScreen->update();
        return;
    }
}
