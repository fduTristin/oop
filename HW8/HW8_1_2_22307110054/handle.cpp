#include "handle.h"


using std::istream;

Student_info::Student_info(const Student_info& s) : cp(0)
{
    if(s.cp) cp = s.cp->clone();
}


Student_info& Student_info::operator=(const Student_info& s)
{
    if(this != &s)
    {
        delete cp;
        if(s.cp) cp = s.cp->clone();
        else cp = 0;
    }

    return *this;
}

istream& Student_info::read(istream& is)
{
    delete cp;
    char ch;
    is>>ch;
    if(ch == 'U')
        cp = new Core(is);
    else 
        cp = new Grad(is);
    return is;
}
