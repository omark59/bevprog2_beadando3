#include "gamemaster.hpp"
#include "graphics.hpp"
#include "palya.hpp"
#include "statictext.hpp"
#include "pushbutton.hpp"
#include "szambeallito.hpp"
#include "jatekos.hpp"
#include <string>
#include <vector>
using namespace genv;
using namespace std;

const int palya_x = 600;
const int palya_y = 600;
const int X = 1600;
const int Y = 900;

Jatekos * player1 = new Jatekos(1, "player1", "x");
Jatekos * player2 = new Jatekos(2, "player2", "o");

GameMaster::GameMaster()
{
}
void GameMaster::open()
{
    gout.open(X, Y);
    gout << font("LiberationSans-Bold.ttf", 20);
    vector<OsWidget*> ow;
    gout << move_to(0, 0) << color(220,220,220) << box(X, Y);
    Palya * p = new Palya(700, 150, palya_x, palya_y, player1, player2);
    StaticText * amoba = new StaticText(1000 - gout.twidth("Amoba 15x15")/2, 75, "Amoba 15x15");
    PushButton * start = new PushButton(200, 150, 100, 30, 0, 255, 0, "Restart");
    PushButton * exit = new PushButton(200, 200, 100, 30, 255, 0, 0, "Exit");
    amoba->rajzol();
    ow.push_back(p);
    ow.push_back(start);
    ow.push_back(exit);
    for(OsWidget * w : ow)
    {
        w->rajzol();
    }
    gout << refresh;
    eventloop(ow);
}

void GameMaster::eventloop(vector<OsWidget*> ow)
{
    event ev;
    OsWidget * widget_pointer = nullptr;
    bool kilep = false;
    while(gin>>ev && ev.keycode != key_escape && kilep != true)
    {
        for(OsWidget * w : ow)
        {
            if(w->focused(ev.pos_x, ev.pos_y))
            {
                widget_pointer = w;
            }
        }

        if(widget_pointer != nullptr)
        {
            widget_pointer->kezel(ev);
            widget_pointer->rajzol();
        }

        for(OsWidget * widget : ow)
        {
            PushButton * pb1 = dynamic_cast<PushButton*>(widget);
            if(pb1 && pb1->nev() == "Exit" && pb1->isfocused())
            {
                kilep = true;
            }
        }

        Palya * pholder = nullptr;
        for(OsWidget * widget : ow)
        {
            Palya * p = dynamic_cast<Palya*>(widget);
            if(p)
            {
                pholder = p;
            }
        }
        for(OsWidget * widget : ow)
        {
            PushButton * pbrestart = dynamic_cast<PushButton*>(widget);
            if(pbrestart && pbrestart->nev() == "Restart" && pbrestart->isfocused())
            {
                auto rst = [&pholder] () {pholder->restart();};
                pbrestart->game_restart(rst);
            }
        }
        gout << refresh;
    }
}
