#include "graphics.hpp"
#include "pushbutton.hpp"
#include <functional>
using namespace std;
using namespace genv;

PushButton::PushButton(int x, int y, int sx, int sy, int r, int g, int b, string szoveg) : OsWidget(x, y, sx, sy), _szoveg(szoveg), _r(r), _g(g), _b(b) {
_focused = false;
}

void PushButton::rajzol()
{
    if(_focused == false)
    {
        gout << move_to(_x, _y) << color(_r, _g, _b) << box(_sx, _sy);
        gout << move_to(_x, _y) << color(0, 0, 0) << line_to(_x + _sx, _y);
        gout << line_to(_x + _sx, _y + _sy);
        gout << line_to(_x, _y + _sy);
        gout << line_to(_x, _y);
        gout << move_to(_x + _sx/2 - gout.twidth(_szoveg)/2, _y + _sy/2 -gout.cascent()/2 - gout.cdescent()/2) << text(_szoveg);
    }
    if(_focused == true)
    {
        gout << move_to(_x+1, _y+1) << color(0, 0, 0) << line_to(_x + _sx-1, _y+1);
        gout << line_to(_x + _sx-1, _y + _sy-1);
        gout << line_to(_x + 1, _y + _sy-1);
        gout << line_to(_x+1, _y+1);
    }
}

void PushButton::kezel(event ev)
{
    if(focused(ev.pos_x, ev.pos_y) && ev.button == btn_left)
    {
        _focused = true;
    }
    if(focused(ev.pos_x, ev.pos_y) && ev.button == -btn_left)
    {
        _focused = false;
    }
    if(!focused(ev.pos_x, ev.pos_y))
    {
        _focused = false;
    }
}

bool PushButton::isfocused()
{
    return _focused;
}
string PushButton::nev()
{
    return _szoveg;
}

void PushButton::game_restart(function<void()> f)
{
    f();
}
