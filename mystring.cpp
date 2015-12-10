#include "mystring.h"

String::String(const char * s, int size)
{
    if(size == -1)
        size=strlen(s);
    str_=new char[size+1];
    if(str_)
    {
        size_=size;
        for(std::size_t i=0;i<size_;i++)
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
    if(str.size()>capacity_)
        this->swap(str);
    else
    {
        for(std::size_t i=0;i<=str.size();i++)
            str_[i]=str[i];
        size_=str.size();
    }
    return (*this);
}

String & String::operator = (char c)
{
    char tmp[]{c,'\0'};
    (*this)=tmp;

    return (*this);
}

String & String::operator += (const String & str)
{
    if(capacity_ >= (size_+str.size_))
    {
        strcat(str_, str.str_);
        size_+=str.size_;
    }
    else
    {
        char *tmp = new char[size_+str.size_+1];
        if(tmp)
        {
            for(std::size_t i=0;i<size_;i++)
            {
                tmp[i]=(*this)[i];
            }
            std::swap(tmp, this->str_);
            delete [] tmp;
            for(std::size_t i=size_; i<=size_+str.size_;i++)
            {
                (*this)[i]=str[i-size_];
            }
            this->size_+=str.size_;
            this->capacity_=size_;
        }
    }
    return (*this);
}

String & String::operator += (char c)
{
    char tmp[]{c,'\0'};
    std::cout << tmp << std::endl;
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
    return tmp+=rhs;
}

std::ostream & operator << (std::ostream & os, const String & s)
{
    for(std::size_t i=0;i<s.size();i++)
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
