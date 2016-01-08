#ifndef MYSTRING__
#define MYSTRING__
#include <iostream>
#include <cstring>

class String
{
friend bool operator < (const String & lhs, const String & rhs);
friend bool operator == (const String & lhs, const String & rhs);

public:
    String()=default;
    String(const char * s);
    String(const String & str);
    ~String() { delete [] str_; };
    std::size_t size() const { return size_; }
    std::size_t capacity() const { return capacity_; }
    const char * c_str() const { return str_; }
    void clear() { size_=0; str_[0]='\0'; }
    void swap(String & other);
    const char & operator [] (size_t i) const { return str_[i]; }
    char & operator [] (size_t i) {
        return const_cast<char &>(static_cast<const String &>(*this)[i]); }
    String & operator = (String str);
    String & operator = (char c);
    String & operator += (const String & str);
    String & operator += (char c);
private:
    void allocate_str_(const char * s);
    char *str_=nullptr;
    std::size_t size_=0, capacity_=0;
};
const String operator + (const String & lhs, const String & rhs);
//const String operator + (const String & lhs, char rhs);
//const String operator + (char lhs, const String & rhs);
inline bool operator < (const String & lhs, const String & rhs) { return (strcmp(lhs.str_, rhs.str_) < 0); }
inline bool operator > (const String & lhs, const String & rhs) { return rhs < lhs; }
inline bool operator <= (const String & lhs, const String & rhs) { return !(lhs > rhs); }
inline bool operator >= (const String & lhs, const String & rhs) { return !(lhs < rhs); }
inline bool operator == (const String & lhs, const String & rhs) { return (strcmp(lhs.str_, rhs.str_) == 0); }
inline bool operator != (const String & lhs, const String & rhs) { return !(lhs == rhs); }
std::ostream & operator << (std::ostream & os, const String & s);
std::istream & operator >> (std::istream & is, String & s);

#endif // MYSTRING__
