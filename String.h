#pragma once
#include "Vec.h"
using namespace std;

class String :
    public Vec<char>
{
private:
    int _make(const char& c)
    {
        switch (c)
        {
        case ' ': return 0;
        case '+': return 1;
        case '-': return 1;
        case '.': return 3;
        case 'e': return 4;
        default: return _number(c);
        }
    }//有限状态自动机辅助函数
    int _number(const char& c)
    {
        if (c >= '0' && c <= '9')
            return 2;
        else
            return 5;
    }//有限状态自动机辅助函数
public:
    String(const char* str = "") :Vec<char>(strlen(str), str) {};
    void output(ostream& out) const;
    void input(istream& in);
    String operator+(String& str);
    int size();
    bool isNumber();
    friend ostream& operator<<(ostream& out, String& str);
    friend istream& operator>>(istream& in, String& str);
    bool operator==(const String& s) const;
    bool operator==(const char* s) const;
    friend bool strCmp(String a, String b);
};
void ACauto();
void Manacher();

