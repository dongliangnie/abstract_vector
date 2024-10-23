#pragma once 
#include "String.h"

void String::output(ostream& out) const
{
	//out << "num=" << num<<endl;
	for (int i = 0; i < num; i++) {
		out << this->elems[i];
	}
}

void String::input(istream& in)
{
	string s;
	in >> s;
	*this = s.c_str();
}

String String::operator+(String& str)
{
	int i, j;
	String add;
	add.__super::num = __super::num + str.__super::num;
	add.elems = new char[add.__super::num+10];
	for (i = 0; i < __super::num; i++)
	{
		add.elems[i] = elems[i];
	}
	for (j = 0; j < str.__super::num; j++)
	{
		add.elems[i + j] = str.elems[j];
	}
	add._size = add.num+2;
	return add;

}

int String::size()
{
	return this->num;
}

ostream& operator<<(ostream& out, String& str)
{
	str.output(out);
	return out;
}

istream& operator>>(istream& in, String& str)
{
	str.input(in);
	return in;
}
