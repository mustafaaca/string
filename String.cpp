#include "String.h"

String::String ()
{
    length = 0;
    data   = new char[0];
}

String::String (const char * c)
{
    if (c)
    {
        int n = 0;
        while (c[n] != '\0')
        {
            n++;
        }
        length = n;
        data   = new char[n];
        for (int j = 0; j < n; j++)
        {
            data[j] = c[j];
        }
    }
    else
    {
        length = 0;
        data   = new char[0];
    }
}

String::String (const String & str)
{
    length = str.len();
    data   = new char[length];
    for (int j = 0; j < length; j++)
    {
        data[j] = str[j];
    }
}

String::~String ( )
{
    delete[] data;
}

int String::len ( ) const
{
    return length;
}

std::ostream & operator << (std::ostream& os, const String & str)
{
    if (str.len() > 0)
    {
        for (int j = 0; j < str.len(); j++)
            os << str[j];
    } else os << "";
    
    return os;
}

char String::operator[] (int j) const
{
    if (j >= length) throw 1;
    return data[j];
}

String & String::operator= (const String& str)
{
    if(this == & str)
    {
        return * this;
    }
    delete data;
    length = str.len();
    data   = new char[length];
    for (int j=0; j < length; j++)
    {
        data[j] = str[j];
    }
    return * this;
}

String& String::operator+= (const String& s)
{
    unsigned len = length + s.len();
    char* str = new char[len];
    
    for (unsigned j=0; j < length; j++)
        str[j] = data[j];
    
    for (unsigned i=0; i < s.len(); i++)
        str[length+i] = s[i];
    
    delete data;
    length = len;
    data   = str;
    return * this;
}

String operator + (const String& l, const String& r)
{
    return String(l) += r;
}
