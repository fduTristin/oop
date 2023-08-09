#ifndef HANDLE_H
#define HANDLE_H

#include "core.h"

class Student_info
{
private:
    Core *cp;

public:
    Student_info() : cp(0) {}
    Student_info(std::istream &is) : cp(0) { read(is); }
    Student_info(const Student_info &);
    Student_info &operator=(const Student_info &);
    ~Student_info() { delete cp; }

    std::istream &read(std::istream &);

    std::string name() const
    {
        if (cp)
            return cp->name();
        else
            throw std::runtime_error("uninitialized Student");
    }

    double grade() const
    {
        if (cp)
            return cp->grade();
        else
            throw std::runtime_error("uninitialized Student");
    }
    
    static bool compare(const Student_info &s1, const Student_info &s2)
    {
        return s1.name() < s2.name();
    }
};

#endif