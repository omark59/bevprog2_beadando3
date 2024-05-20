#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED
#include "oswidget.hpp"
#include "graphics.hpp"
#include "cella.hpp"
#include "jatekos.hpp"
#include <vector>
#include <array>
class Palya : public OsWidget{
protected:
    std::vector<std::vector<Cella*>> _elemek;
    Jatekos * _player1;
    Jatekos * _player2;
    bool _gameover;
public:
    Palya(int x, int y, int sx, int sy, Jatekos * player1, Jatekos * player2);
    virtual void rajzol();
    virtual void kezel(genv::event ev);
    virtual Jatekos* switchplayer(Jatekos * currentplayer);
    virtual bool checkwin();
    virtual bool betelt();
    virtual void restart();
    virtual bool jatek_vege();
};
#endif // PALYA_HPP_INCLUDED
