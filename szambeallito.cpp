#include "graphics.hpp"
#include "szambeallito.hpp"
using namespace std;
using namespace genv;

SzamBeallito::SzamBeallito(int x, int y, int sx, int sy) : OsWidget(x, y, sx, sy) {
_focused = false;
_szam = 0;
bool timer = false;
}

void SzamBeallito::rajzol()
{
    gout << move_to(_x, _y) << color(255, 255, 255) << box(_sx, _sy);
    gout << move_to(_x, _y) << color(0, 0, 0) << line_to(_x + _sx, _y);
    gout << line_to(_x + _sx, _y + _sy);
    gout << line_to(_x, _y + _sy);
    gout << line_to(_x, _y);
    _szoveg = to_string(_szam);
    gout << move_to(_x + gout.twidth(_szoveg)/2, _y + _sy/2) << color(0, 0, 0) << text(_szoveg);
}

void SzamBeallito::kezel(event ev)
{
    if(focused(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        _szam++;
        rajzol();
    }
    if(focused(ev.pos_x, ev.pos_y) && ev.button == btn_right)
    {
        _szam--;
        rajzol();
    }
}

