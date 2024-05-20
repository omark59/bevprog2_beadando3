#include "graphics.hpp"
#include "cella.hpp"
using namespace std;
using namespace genv;

Cella::Cella(int x, int y, int sx, int sy) : OsWidget(x, y, sx, sy)
{
    _kattintva = false;
}

void Cella::rajzol()
{
    if(_kattintva)
    {
        gout << move_to(_x+1, _y+1) << color(255, 255, 255) << box(_sx-1, _sx-1);
        gout << move_to(_x + _sx/2 - gout.twidth(_text)/2, _y + _sy/2 - gout.cascent()/2 - gout .cdescent()/2) << color(0, 0, 0) << text(_text);
    }
    if(_kattintva == false)
    {
        gout << move_to(_x+1, _y+1) << color(255, 255, 255) << box(_sx-1, _sx-1);
    }
}

void Cella::kezel(event ev) {}

bool Cella::isfocused()
{
    return _kattintva;
}

string Cella::getkarakter()
{
    return _text;
}

void Cella::kattint(bool kattintva, string text)
{
    _kattintva = kattintva;
    _text = text;
}
