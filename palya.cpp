#include "graphics.hpp"
#include "palya.hpp"
#include "cella.hpp"
#include "jatekos.hpp"
#include "statictext.hpp"
using namespace std;
using namespace genv;

Palya::Palya(int x, int y, const int sx, const int sy, Jatekos * player1, Jatekos * player2) : OsWidget(x, y, sx, sy)
{
    _gameover = false;
    _player1 = player1;
    _player1->lephet("true");
    _player2 = player2;
    _player2->lephet("false");
    const int egyseg_width = _sx/15;
    const int egyseg_height = _sy/15;
    for(int i = 0; i < 15; i++)
    {
        vector<Cella*> sor;
        for(int j = 0; j < 15; j++)
        {
            Cella * c = new Cella(_x+i*egyseg_width, _y+j*egyseg_height, egyseg_width, egyseg_height);
            sor.push_back(c);
        }
        _elemek.push_back(sor);
    }
}


void Palya::rajzol()
{
    gout << move_to(_x-1, _y-1) << color(0, 0, 0) << line_to(_x + _sx + 1, _y-1);
    gout << line_to(_x + _sx + 1, _y + _sy + 1);
    gout << line_to(_x-1, _y + _sy + 1);
    gout << line_to(_x-1, _y-1);
    gout << move_to(_x-2, _y-2) << color(0, 0, 0) << line_to(_x + _sx + 2, _y-2);
    gout << line_to(_x + _sx + 2, _y + _sy + 2);
    gout << line_to(_x-2, _y + _sy + 2);
    gout << line_to(_x-2, _y-2);
    gout << move_to(_x, _y) << color(238,232,170) << box(_sx, _sy);
    for(size_t i = 0; i < _elemek.size(); i++)
    {
        for(size_t j = 0; j < _elemek[i].size(); j++)
        {
            _elemek[i][j]->rajzol();
        }
    }
    StaticText * gameover = new StaticText(1000 - gout.twidth("Jatek vege!")/2, 825, "Jatek vege!");
    if(_gameover)
    {
        gameover->rajzol();
    }
}

void Palya::kezel(event ev)
{
    Jatekos * current_player = nullptr;
    Jatekos * other_player = nullptr;
    if(_player1->lephet_e())
    {
        current_player = _player1;
        other_player = _player2;
    }
    else if(_player2->lephet_e())
    {
        current_player = _player2;
        other_player = _player1;
    }
    for(size_t i = 0; i < _elemek.size(); i++)
    {
        for(size_t j = 0; j < _elemek[i].size(); j++)
        {
            if(_elemek[i][j]->focused(ev.pos_x, ev.pos_y) && ev.button == btn_left && ev.type == ev_mouse && !checkwin() && !betelt())
            {
                _elemek[i][j]->kattint(true, current_player->getkarakter());
                current_player->lephet(false);
                other_player->lephet(true);
            }
        }
    }
    if(checkwin() || betelt())
    {
        _gameover = true;
    }
}

Jatekos* Palya::switchplayer(Jatekos* currentplayer)
{
    if(currentplayer == _player1)
    {
        return _player2;
    }
    else
    {
        return _player1;
    }
}

bool Palya::checkwin()
{
    const int win_length = 5;
    const int size = 15;
    Jatekos * winner = nullptr;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= size - win_length; ++j) {
            string firstChar = _elemek[i][j]->getkarakter();
            if (firstChar == _player1->getkarakter() || firstChar == _player2->getkarakter()) {
                bool win = true;
                for (int k = 1; k < win_length; ++k) {
                    if (_elemek[i][j + k]->getkarakter() != firstChar) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }
    }

    for (int i = 0; i <= size - win_length; ++i) {
        for (int j = 0; j < size; ++j) {
            string firstChar = _elemek[i][j]->getkarakter();
            if (firstChar == _player1->getkarakter() || firstChar == _player2->getkarakter()) {
                bool win = true;
                for (int k = 1; k < win_length; ++k) {
                    if (_elemek[i + k][j]->getkarakter() != firstChar) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }
    }

    for (int i = 0; i <= size - win_length; ++i) {
        for (int j = 0; j <= size - win_length; ++j) {
            string firstChar = _elemek[i][j]->getkarakter();
            if (firstChar == _player1->getkarakter() || firstChar == _player2->getkarakter()) {
                bool win = true;
                for (int k = 1; k < win_length; ++k) {
                    if (_elemek[i + k][j + k]->getkarakter() != firstChar) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }
    }

    for (int i = win_length - 1; i < size; ++i) {
        for (int j = 0; j <= size - win_length; ++j) {
            string firstChar = _elemek[i][j]->getkarakter();
            if (firstChar == _player1->getkarakter() || firstChar == _player2->getkarakter()) {
                bool win = true;
                for (int k = 1; k < win_length; ++k) {
                    if (_elemek[i - k][j + k]->getkarakter() != firstChar) {
                        win = false;
                        break;
                    }
                }
                if (win) return true;
            }
        }
    }

    return false;
}


bool Palya::betelt()
{
    vector<Cella*> cella_vektor;
    for(size_t i = 0; i < _elemek.size(); i++)
    {
        for(size_t j = 0; j < _elemek[i].size(); j++)
        {
            if(_elemek[i][j]->getkarakter() == "x" || _elemek[i][j]->getkarakter() == "o")
            {
                cella_vektor.push_back(_elemek[i][j]);
            }
        }
    }

    if(cella_vektor.size() == 225)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Palya::restart()
{
    for(size_t i = 0; i < _elemek.size(); i++)
    {
        for(size_t j = 0; j < _elemek[i].size(); j++)
        {
            _elemek[i][j]->kattint(false, "");
        }
    }
    _player1->lephet("true");
    _player2->lephet("false");
    _gameover = false;
    rajzol();
}

bool Palya::jatek_vege()
{
    return _gameover;
}
