#include "mystring.h"

String::String(const char * s, int size)
{
    if(size == -1)
        size=strlen(s);
    str_=new char[size+1];
    if(str_)
    {
        size_=size;
        strcpy(str_, s);
        capacity_=size_;
    }
    else
        size_=0;
}

String::String(char c)
{
    if(c!='\0')
    {
        str_=new char[2];
        if(str_)
        {
            str_[size_++]=c;
            str_[size_]='\0';
            capacity_=size_;
        }
    }
}

void String::swap(String & other)
{
    using std::swap;
    swap(str_, other.str_);
    swap(size_, other.size_);
    swap(capacity_, other.capacity_);
}

String & String::operator = (String & str)
{
    if(this == &str) return (*this);
    this->swap(str);
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

String & String::operator += (const String & str)
{
    if(capacity_ > (size_+str.size_+1))
    {
        strcat(str_, str.str_);
        size_+=str.size_;
    }
    else
    {
        char *tmp = new char[size_+str.size_+1];
        if(tmp)
        {
            strcpy(tmp, str_);
            std::swap(tmp, str_);
            delete tmp;
            strcat(str_, str.str_);
            size_+=str.size_;
            capacity_=size_;
        }
    }
    return (*this);
}

String & String::operator += (const char * s)
{
    String tmp(s);
    (*this)+=tmp;
    return (*this);
}

String & String::operator += (char c)
{
    String tmp(c);
    (*this)+=tmp;
    return (*this);
}

const String operator + (const String & lhs, const String & rhs)
{
    String tmp(lhs);
    tmp+=rhs;
    return tmp;
}

const String operator + (const String & lhs, const char * rhs)
{
    String tmp(lhs);
    tmp+=rhs;
    return tmp;
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
