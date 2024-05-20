#ifndef OSWIDGET_HPP_INCLUDED
#define OSWIDGET_HPP_INCLUDED
#include "graphics.hpp"

class OsWidget{
protected:
    int _x, _y;
    int _sx, _sy;
public:
    OsWidget(int x, int y, int sx, int sy);
    virtual void rajzol() = 0;
    virtual void kezel(genv::event ev) = 0;
    virtual bool focused(int ex, int ey);
};
#endif // OSWIDGET_HPP_INCLUDED
