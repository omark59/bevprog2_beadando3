#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED
#include "graphics.hpp"
#include "oswidget.hpp"
#include <vector>
class GameMaster{
public:
    GameMaster();
    void open();
    void eventloop(std::vector<OsWidget*> ow);
};
#endif // GAMEMASTER_HPP_INCLUDED
