#include "jatekos.hpp"
using namespace std;

Jatekos::Jatekos(int jatekosid, string jatekosnev, string jatekoskarakter)
{
    _jatekosid = jatekosid;
    _jatekosnev = jatekosnev;
    _jatekoskarakter = jatekoskarakter;
}

int Jatekos::getid()
{
    return _jatekosid;
}

string Jatekos::getnev()
{
    return _jatekosnev;
}

string Jatekos::getkarakter()
{
    return _jatekoskarakter;
}

void Jatekos::lephet(bool b)
{
    _lephet = b;
}

bool Jatekos::lephet_e()
{
    return _lephet;
}

