#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED
#include "graphics.hpp"
#include "oswidget.hpp"
#include <functional>
class PushButton : public OsWidget{
protected:
    std::string _szoveg;
    bool _focused;
    int _r, _g, _b;
public:
    PushButton(int x, int y, int sx, int sy, int r, int g, int b, std::string szoveg);
    virtual void rajzol();
    virtual void kezel(genv::event ev);
    virtual bool isfocused();
    virtual std::string nev();
    virtual void game_restart(std::function<void()> f);
};
#endif // PUSHBUTTON_HPP_INCLUDED
