#ifndef MYSTRING__
#define MYSTRING__
#include <iostream>
#include <cstring>
#include <cstdio>

class String
{
friend std::ostream & operator << (std::ostream & os, const String & s);
friend std::istream & operator >> (std::istream & is, String & s);

public:
    String()=default;
    String(const char * s);
    String(const String & s);
    ~String() { delete [] str_; };
    std::size_t size() { return size_; }
    const char * c_str() { return str_; }
    const char & operator [] (std::size_t i) const { return str_[i]; }
    char & operator [] (std::size_t i) {
        return const_cast<char &>(static_cast<const String &>(*this)[i]); }
    void operator += (const String & s);
    void clear() { size_=0; str_[0]='\0'; }
    void swap(String & other);
    String & operator = (const char * s);
    String & operator = (String s);
private:
    char *str_=nullptr;
    std::size_t size_=0, capacity_=0;
};

std::ostream & operator << (std::ostream & os, const String & s);
std::istream & operator >> (std::istream & is, String & s);

#endif // MYSTRING__
