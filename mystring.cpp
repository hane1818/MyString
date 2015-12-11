#include "mystring.h"
#include <algorithm>
#include <limits>

String::String(const char * s):size_(strlen(s)), capacity_(size_)
{
    this->allocate_str_(s);
}

String::String(const String & str):size_(str.size_),capacity_(str.capacity_)
{
    this->allocate_str_(str.str_);
}

void String::swap(String & other)
{
    using std::swap;
    swap(this->str_, other.str_);
    swap(this->size_, other.size_);
    swap(this->capacity_, other.capacity_);
}

String & String::operator = (String str)
{
    if(str.size()>this->capacity_)
        this->swap(str);
    else
    {
        for(std::size_t i=0;i<=str.size();i++)
            this->str_[i]=str[i];
        this->size_=str.size();
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
    if(this->capacity_ >= (this->size_+str.size_))
    {
        for(std::size_t i=this->size_; i<=this->size_+str.size_;i++)
        {
            this->str_[i]=str[i-(this->size_)];
        }
        this->size_+=str.size_;
    }
    else
    {
        char *tmp = new (std::nothrow) char[this->size_+str.size_+1];
        if(tmp)
        {
            for(std::size_t i=0;i<this->size_;i++)
            {
                tmp[i]=this->str_[i];
            }
            std::swap(tmp, this->str_);
            delete [] tmp;
            for(std::size_t i=this->size_; i<=this->size_+str.size_;i++)
            {
                this->str_[i]=str[i-this->size_];
            }
            this->size_+=str.size_;
            this->capacity_=this->size_;
        }
    }
    return (*this);
}

String & String::operator += (char c)
{
    char tmp[]{c,'\0'};
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

const String operator + (char lhs, const String & rhs)
{
    char tmp[]{lhs, '\0'};
    return tmp+rhs;
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
    if(c!='\n') is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return is;
}

//Private Function
void String::allocate_str_(const char * s)
{
    this->str_=new (std::nothrow) char[(this->size_)+1];
    if(this->str_)
    {
        for(std::size_t i=0;i<this->size_;i++)
        {
            this->str_[i]=s[i];
        }
    }
    else
    {
        this->size_=0;
        this->capacity_=0;
    }
}
