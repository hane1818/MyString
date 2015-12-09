#include "mystring.h"

String::String(const char * s, int size)
{
    if(size != -1)
        size_=size;
    else
        size_=strlen(s);
    capacity_=size_;
    str_=new char[size_+1];
    strcpy(str_, s);
}

void String::swap(String & other)
{
    using std::swap;
    swap(str_, other.str_);
    swap(size_, other.size_);
    swap(capacity_, other.capacity_);
}

String & String::operator = (String & s)
{
    if(this == &s) return (*this);
    this->swap(s);
    return (*this);
}

String & String::operator = (const char * s)
{
    std::size_t len=strlen(s);
    if(len>capacity_)
    {
        String tmp(s);
        this->swap(tmp);
    }
    else
    {
        strcpy(str_,s);
        size_=len;
    }

    return (*this);
}

std::ostream & operator << (std::ostream & os, const String & s)
{
    if(s.str_)
        os << s.str_;
    else
        os << "\0";
    return os;
}

std::istream & operator >> (std::istream & is, String & s)
{
    char tmp[]={'\0'};
    is >> tmp;
    s = tmp;
    /*if(s.capacity_>=strlen(tmp))
        strcpy(s.str_, tmp);
    else
    {
        delete [] s.str_;
        s.str_=new char [strlen(tmp)];
        strcpy(s.str_, tmp);
        //s.capacity_=strlen(tmp);
    }
    s.size_=strlen(tmp);*/
    return is;
}
