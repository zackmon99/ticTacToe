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
            std::cout << "Mouse click at " << x << ", " << y << std::endl;
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


void EventHandler::mousePress(SDL_MouseButtonEvent& b) {
    std::cout << "In Mouse button stuff" << std::endl;
    if(b.button == SDL_BUTTON_LEFT){
        std::cout << "left mouse click!" << std::endl;
    }
}
