#pragma once
#include "Vec.h"
using namespace std;

class String :
    public Vec<char>
{
public:
    String(const char* str = "") :Vec<char>(strlen(str), str) {};
    void output(ostream& out) const;
    void input(istream& in);
    String operator+(String& str);
    int size();
    friend ostream& operator<<(ostream& out, String& str);
    friend istream& operator>>(istream& in, String& str);
    bool operator==(const String& s) const;
    bool operator==(const char* s) const;
};
void ACauto();
void Manacher();

