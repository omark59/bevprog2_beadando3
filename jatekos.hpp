#ifndef JATEKOS_HPP_INCLUDED
#define JATEKOS_HPP_INCLUDED
#include <string>
class Jatekos{
protected:
    int _jatekosid;
    std::string _jatekosnev;
    std::string _jatekoskarakter;
    bool _lephet;
public:
    Jatekos(int jatekosid, std::string jatekosnev, std::string jatekoskarakter);
    virtual int getid();
    virtual std::string getnev();
    virtual std::string getkarakter();
    virtual void lephet(bool b);
    virtual bool lephet_e();
};
#endif // JATEKOS_HPP_INCLUDED
