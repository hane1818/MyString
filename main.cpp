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
                    if(s.c_str())
                    {
                        arr[now_arr++]=s;
                        cout << endl << "New data is \"" << s << "\", data size is " << s.size() << endl;
                    }
                    else
                    {
                        cout << endl << "No data input." << endl;
                    }
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
                if(ind>now_arr) { cout << "Out of range" << endl; break; }
                cout << "What do you want to do with this data?" << endl << endl
                     << " 1) replace by a new string(at most 100 characters)" << endl
                     << " 2) replace by a character" << endl
                     << " 3) append a new string(at most 100 characters)" << endl
                     << " 4) append a character" << endl
                     << " 5) change one character of string" << endl
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
                case 5:
                    {
                        cout << endl << " ";
                        for(int i=0;i<arr[ind-1].size();i++) cout << i+1;
                        cout << " (index)" << endl
                             << "\"" << arr[ind-1] << "\"" << endl << endl
                             << "Please input the character index of the string to change(0 to leave)...>";
                        int i;
                        cin >> i;
                        if(i==0) break;
                        if(i>now_arr) { cout << "Out of range" << endl; break; }
                        cout << "Please input the new character to replace '" << arr[ind-1][i-1] << "' (no space)...>";
                        cin >> c;
                        arr[ind-1][i-1]=c;
                        cout << endl << "The result after changing is \"" << arr[ind-1] << "\"" << endl;
                        break;
                    }
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
                if(opt>now_arr) { cout << "Out of range" << endl; break; }
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
                if(a>now_arr||b>now_arr) { cout << "Out of range" << endl; break; }
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
        cout << endl;
        system("pause");
        system("cls");
    }
}
