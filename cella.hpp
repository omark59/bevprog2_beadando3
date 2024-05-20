#ifndef CELLA_HPP_INCLUDED
#define CELLA_HPP_INCLUDED
#include "oswidget.hpp"
#include "graphics.hpp"
class Cella : public OsWidget{
protected:
    bool _kattintva;
    std::string _text;
public:
    Cella(int x, int y, int sx, int sy);
    void rajzol();
    void kezel(genv::event ev);
    bool isfocused();
    virtual void kattint(bool kattintva, std::string text);
    virtual std::string getkarakter();
};

#endif // CELLA_HPP_INCLUDED

