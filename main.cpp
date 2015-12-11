#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "mystring.h"
#include <string>

using namespace std;

void PrintDb(String * db, size_t sz)
{
    cout << endl;
    for(size_t i=0; i<sz;++i)
    {
        cout << ' ' << i+1 << ". " << db[i] << endl;
    }
    cout << endl;
}

int main()
{
    const size_t ARR_SIZE=10;
    String arr[ARR_SIZE]{"NTNU", "CSIE", "CIC"};
    size_t now_arr=3;
    while(true){
        cout << "Our database can store " << ARR_SIZE << " data(s)." << endl
             << "Now, we already have " << now_arr << " data(s) in our database." << endl;
        PrintDb(arr, now_arr);
        cout << endl
             << "What do you want to do?" << endl
             << "(1) Input new data" << endl
             << "(2) Modify data" << endl
             << "(3) Remove data" << endl
             << "(4) Compare two data" << endl
             << "(5) Sort data" << endl
             << "(6) Exit" << endl << endl
             << "Please input your choice...>";
        int choice;
        cin >> choice;
        system("cls");
        switch(choice)
        {
        case 1:
            {
                if(now_arr<ARR_SIZE)
                {
                    cout << "Please input your data(no space)...>";
                    String s;
                    cin.get();
                    cin >> s;
                    arr[now_arr++]=s;
                    cout << endl << "New data is \"" << s << "\", data size is " << s.size() << endl;
                }
                else
                {
                    cout << "Database is full." << endl;
                }
                break;
            }
        case 2:
            {
                PrintDb(arr, now_arr);
                cout << "Please choose which data to modify(input data number, 0 to leave)...>";
                int ind;
                cin >> ind;
                if(ind==0) break;
                cout << "What do you want to do with this data?" << endl << endl
                     << " 1) replace by a new string(at most 100 characters)" << endl
                     << " 2) replace by a character" << endl
                     << " 3) append a new string(at most 100 characters)" << endl
                     << " 4) append a character" << endl << endl
                     << "Input your choice(0 to leave)...>";
                int opt;
                cin >> opt;
                char c, str[101],op;
                switch(opt)
                {
                case 0: break;
                case 1:
                    cout << endl << "Please input a string(at most 100 characters)...>";
                    cin >> str;
                    cout << endl << "\"" << arr[ind-1] << "\" will be replaced by \"" << str << "\"" << endl
                         << "Are you sure to modify data(y/N)...>";
                    cin >> op;
                    if(op=='y'||op=='Y')
                        arr[ind-1]=str;
                    break;
                case 2:
                    cout << endl << "Please input a character...>";
                    cin >> c;
                    cout << endl << "\"" << arr[ind-1] << "\" will be replaced by '" << c << "'" << endl
                         << "Are you sure to modify data(y/N)...>";
                    cin >> op;
                    if(op=='y'||op=='Y')
                        arr[ind-1]=c;
                    break;
                case 3:
                    cout << endl << "Please input a string(at most 100 characters)...>";
                    cin >> str;
                    cout << endl << "The result after appending is \"" << arr[ind-1]+str << "\"" << endl
                         << "Are you sure to modify data(y/N)...>";
                    cin >> op;
                    if(op=='y'||op=='Y')
                        arr[ind-1]+=str;
                    break;
                case 4:
                    cout << endl << "Please input a character...>";
                    cin >> c;
                    cout << endl << "The result after appending is \"" << arr[ind-1]+c << "\"" << endl
                         << "Are you sure to modify data(y/N)...>";
                    cin >> op;
                    if(op=='y'||op=='Y')
                        arr[ind-1]+=c;
                    break;
                default:
                    cout << "Invalid option." << endl;
                    break;
                }
                break;
            }
        case 3:
            {
                PrintDb(arr, now_arr);
                cout << "Please choose which data to remove(input data number, 0 to leave)...>";
                int opt;
                cin >> opt;
                if(opt==0) break;
                arr[opt-1].clear();
                for(size_t i=opt;i<now_arr;++i)
                    arr[i-1].swap(arr[i]);
                now_arr-=1;
                break;
            }
        case 4:
            {
                PrintDb(arr, now_arr);
                cout << "Please choose two data to compare(input two data number, 0 to leave)...>";
                int a, b;
                cin >> a;
                if(a==0) break;
                cin >> b;
                a-=1; b-=1;
                if(arr[a]>=arr[b])
                    cout << "\"" << arr[a] << "\"" << " is not less than " << "\"" << arr[b] << "\"" << endl;
                if(arr[a]>arr[b])
                    cout << "\"" << arr[a] << "\"" << " is greater than " << "\"" << arr[b] << "\"" << endl;
                if(arr[a]<=arr[b])
                    cout << "\"" << arr[a] << "\"" << " is not greater than " << "\"" << arr[b] << "\"" << endl;
                if(arr[a]<arr[b])
                    cout << "\"" << arr[a] << "\"" << " is less than " << "\"" << arr[b] << "\"" << endl;
                if(arr[a]==arr[b])
                    cout << "\"" << arr[a] << "\"" << " is equal to " << "\"" << arr[b] << "\"" << endl;
                if(arr[a]!=arr[b])
                    cout << "\"" << arr[a] << "\"" << " is not equal to " << "\"" << arr[b] << "\"" << endl;

                break;
            }
        case 5:
            sort(arr, arr+now_arr);
            cout << "After sorted: " << endl;
            PrintDb(arr, now_arr);
            break;
        case 6:
            cout << "Bye bye~" << endl;
            return 0;
        default:
            cout << "Invalid option" << endl;
            break;
        }
        system("pause");
        system("cls");
    }
}

/*void ReadWrite(String &str) { str[2] = 'T'; }
void ReadOnly(const String &str) { char c = str[1]; }

int main()
{
    //Constructor
    String s1, t1("CSIE106"), u1(t1);
    cout << s1 << ' ' << t1 << ' ' << u1 << endl;
    //Copy assignment
    String s2("NTU"), t2("NTNU"), u2("NTUST");
    cout << "Before Copy: " << s2 << ' ' << t2 << ' ' << u2 << endl;
    s2=t2;
    t2="NCU";
    u2='U';
    cout << "After Copy: " << s2 << ' ' << t2 << ' ' << u2 << endl;
    //size()&c_str()
    String s3("NTNU");
    cout << s3 << ' ' << s3.size()  << ' ' << s3.capacity() << endl;
    const char *p=s3.c_str();
    cout << "Convert to C-String: " << p << endl;
    //operator[]
    String s4("NTNU");
    cout << "Origin String: " << s4 << endl;
    ReadWrite(s4);
    ReadOnly(s4);
    cout << "Change the third character: " << s4 << endl;
    //operator+=
    String s5("NT"), t5("NU"), u5("NTU");
    cout << s5 << ' ' << t5 << ' ' << u5 << endl;
    s5+=t5;
    t5+="UL";
    u5+='~';
    cout << "Add&assign: " << s5 << ' ' << t5 << ' ' << u5 << endl;
    //operator+
    String s6("NT"), t6("NU"), u6;
    cout << "Origin: " << s6 << ' ' << t6 << ' ' << u6 << endl;
    u6=s6+t6;
    cout << "After add: " << s6 << ' ' << t6 << ' ' << u6 << endl;
    //clear()
    String s7("NTNU");
    cout << "Origin: " << s7 << endl;
    s7.clear();
    cout << "Clear: " << s7 << endl;
    //swap()
    String s8("NTNU"), u8("NTU");
    cout << "Origin: " << s8 << ' ' << u8 << endl;
    s8.swap(u8);
    cout << "Swap: " << s8 << ' ' << u8 << endl;

    return 0;
}*/
//another
/*int main(){
    String s("tcchiang"); //check(s);
String t = s, u = s;

//check(s); check(t); check(u);
cout << (void *)s.c_str() << ' ' << (void *)t.c_str() << ' ' << (void *)u.c_str() << endl;
t = "new";
cout << (void *)s.c_str() << ' ' << (void *)t.c_str() << ' ' << (void *)u.c_str() << endl;
//check(s); check(t); check(u);
s = "kk1234";
cout << (void *)s.c_str() << ' ' << (void *)t.c_str() << ' ' << (void *)u.c_str() << endl;
//check(s); check(t); check(u);
return 0;*/
/*string s("bitch");
    //s+=s;
    s += 'c';
    s += "123";
    cout << s <<endl <<endl;
    const char *p = s.c_str();

    s = "pae";
    cout << s.size() << "***" << s.capacity() << endl;
    //const char *p = s.c_str();
cout << p << ':'<< &p <<endl;
const char * q = s.c_str();
cout << q << ':' << &q;
    cout << s;
    return 0;
    String s("tcchiang");
int a;
cout << &s << ' ' << &a << endl;
//cout << (void *)&s[0] << ' ' << (void *)s.c_str() << endl;
cout << sizeof(s) << endl;
cout << s.size() << ' ' << s.capacity() << endl;
s = "ntnu";
cout << s.size() << ' ' << s.capacity() << endl;
//check(s);
s = "iloventnu";
cout << s.size() << ' ' << s.capacity() << endl;

s = 'c';
cout << s.size() << ' ' << s.capacity() << endl;
//check(s);
return 0;*/
//}
