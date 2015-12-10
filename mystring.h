#ifndef MYSTRING__
#define MYSTRING__
#include <iostream>
#include <cstring>
#include <cstdio>

class String
{
friend bool operator < (const String & lhs, const String & rhs);
friend bool operator == (const String & lhs, const String & rhs);
friend std::ostream & operator << (std::ostream & os, const String & s);

public:
    String()=default;
    String(const char * s, int size=-1);
    String(const String & str):String(str.str_, str.size_) {};
    String(char c);
    ~String() { delete [] str_; };
    std::size_t size() { return size_; }
    std::size_t capacity() { return capacity_; }
    const char * c_str() { return str_; }
    void clear() { size_=0; str_[0]='\0'; }
    void swap(String & other);
    const char & operator [] (std::size_t i) const { return str_[i]; }
    char & operator [] (std::size_t i) {
        return const_cast<char &>(static_cast<const String &>(*this)[i]); }
    String & operator = (String & str);
    String & operator = (const char * s);
    String & operator = (char c);
    String & operator += (const String & str);
    String & operator += (const char * s);
    String & operator += (char c);
private:
    char *str_=nullptr;
    std::size_t size_=0, capacity_=0;
};
const String operator + (const String & lhs, const String & rhs);
const String operator + (const String & lhs, const char * rhs);
const String operator + (const String & lhs, char rhs);
inline bool operator < (const String & lhs, const String & rhs) { return (strcmp(lhs.str_, rhs.str_) < 0); }
inline bool operator > (const String & lhs, const String & rhs) { return rhs < lhs; }
inline bool operator <= (const String & lhs, const String & rhs) { return !(lhs > rhs); }
inline bool operator >= (const String & lhs, const String & rhs) { return !(lhs < rhs); }
inline bool operator == (const String & lhs, const String & rhs) { return (strcmp(lhs.str_, rhs.str_) == 0); }
inline bool operator != (const String & lhs, const String & rhs) { return !(lhs == rhs); }
std::ostream & operator << (std::ostream & os, const String & s);
std::istream & operator >> (std::istream & is, String & s);

#endif // MYSTRING__
