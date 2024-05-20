#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include "oswidget.hpp"
#include "graphics.hpp"
class StaticText : public OsWidget{
protected:
    std::string _szoveg;
public:
    StaticText(int x, int y, std::string szoveg);
    virtual void rajzol();
    virtual void kezel(genv::event ev);
    virtual void settext(std::string s);
    ~StaticText();
};
#endif // STATICTEXT_HPP_INCLUDED
