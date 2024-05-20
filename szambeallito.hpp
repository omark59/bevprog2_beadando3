#ifndef SZAMBEALLITO_HPP_INCLUDED
#define SZAMBEALLITO_HPP_INCLUDED
#include "oswidget.hpp"
#include "graphics.hpp"
class SzamBeallito : public OsWidget{
protected:
    std::string _szoveg;
    bool _focused;
    int _szam;
    bool timer;
public:
    SzamBeallito(int x, int y, int sx, int sy);
    virtual void rajzol();
    virtual void kezel(genv::event ev);
};
#endif // SZAMBEALLITO_HPP_INCLUDED
