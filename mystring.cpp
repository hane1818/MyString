#include "mystring.h"

String::String(const char * s, int size)
{
    if(size == -1)
        size=strlen(s);
    str_=new char[size+1];
    if(str_)
    {
        size_=size;
        for(int i=0;i<size_;i++)
        {
            str_[i]=s[i];
        }
        capacity_=size_;
    }
    else
        size_=0;
}

void String::swap(String & other)
{
    using std::swap;
    swap(str_, other.str_);
    swap(size_, other.size_);
    swap(capacity_, other.capacity_);
}

String & String::operator = (String str)
{
    this->swap(str);
    return (*this);
}

String & String::operator = (char c)
{
    char tmp[]={c,'\0'};
    (*this)=tmp;

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
            for(int i=0;i<size_;i++)
            {
                tmp[i]=str_[i];
            }
            std::swap(tmp, str_);
            delete [] tmp;
            strcat(str_, str.str_);
            size_+=str.size_;
            capacity_=size_;
        }
    }
    return (*this);
}

String & String::operator += (char c)
{
    char tmp[]={c,'\0'};
    (*this)+=tmp;
    return (*this);
}

const String operator + (const String & lhs, const String & rhs)
{
    String tmp(lhs);
    return tmp+=rhs;
}

const String operator + (const String & lhs, char rhs)
{
    String tmp(lhs);
    tmp+=rhs;
    return tmp;
}

std::ostream & operator << (std::ostream & os, const String & s)
{
    for(int i=0;i<s.size();i++)
    {
        os << s[i];
    }

    return os;
}

std::istream & operator >> (std::istream & is, String & s)
{
    char c;
    while(!(isspace(c=is.get())||is.eof()))
        s+=c;

    return is;
}
