#include <iostream>
#include <string>
#include "mystring.h"

using namespace std;

int main()
{
    string ss = "\0";
    cout << ss << "?" << endl;
    String s1;
    String s2("HI");
    String tmp("bycopy");
    String s3(tmp);

    cout << "s1:" << s1.size() << s1 << endl;
    cout << "s2:" << s2.size() << s2 << endl;
    cout << "s3:" << s3.size() << s3 << endl;
    cin >> s1;
    cout << s1 << s1.size() << endl;
    s1 = "assign~";
    s1[2]='\0';
    cout << s1 << " " << s1.size() << endl;
    s2 = s3;
    cout << s2 << " copy from s3." << s2.size() << endl;

    return 0;
}
