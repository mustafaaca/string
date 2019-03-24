#ifndef STRING_H
#define STRING_H

#include <iostream>


class String
{
private:
    char * data;
    int length;
    
public:
    
    String ( );
    
    String (const char * c);
    
    String (const String & str);
    
    ~String ( );
    
    int len ( ) const;
    
    friend std::ostream& operator<< (std::ostream & so, const String & str);
    
    char operator[] (int j) const;
    
    String & operator = (const String & str);
    
    String & operator += (const String & str);
    
    friend String operator + (const String & l, const String & r);
    
};

#endif
