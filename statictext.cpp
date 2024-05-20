#include "graphics.hpp"
#include "statictext.hpp"
using namespace std;
using namespace genv;

StaticText::StaticText(int x, int y, std::string szoveg) : OsWidget(x, y, gout.twidth(szoveg), 15), _szoveg(szoveg) {}

StaticText::~StaticText() {}
void StaticText::rajzol()
{
    gout << move_to(_x, _y) << color(0, 0, 0) <<text(_szoveg);
}

void StaticText::kezel(event ev) {}

void StaticText::settext(string s)
{
    _szoveg = s;
}
