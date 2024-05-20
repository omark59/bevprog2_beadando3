#include "graphics.hpp"
#include "oswidget.hpp"

using namespace genv;

OsWidget::OsWidget(int x, int y, int sx, int sy) : _x(x), _y(y), _sx(sx), _sy(sy) {}

bool OsWidget::focused(int ex, int ey)
{
    if(ex> _x && ex < _x + _sx && ey > _y && ey < _y + _sy)
    {
        return true;
    }
    else
    {
        return false;
    }
}
