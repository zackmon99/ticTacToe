#include "Board.hpp"
#include <SDL.h>

class EventHandler
{
private:
    Board *m_pBoard;
    SDL_Event event;
public:
    EventHandler(Board *board);
    ~EventHandler();
    bool processEvents();
    void mousePress(int x, int y);
};

