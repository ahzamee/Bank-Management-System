#ifndef __String_class__
#define __String_class__
#include <iostream>
#include<cstdlib>
using namespace std;
class MyString
{
private:
    char *str;
    int  size;
public:
    MyString();
    MyString(char *s);
    void StrRev();
    void StrCat(char *s);
    int StrLen(char *s);
    char GetStr();
    int GetSize();
    bool StrCmp(char *s);
};

MyString::MyString()
{
    str=NULL;
    size=0;
}

char MyString::GetStr()
{
    return *str;
}

int MyString::GetSize()
{
    return size;
}


MyString::MyString(char s[])
{
    size=StrLen(s);
    str=new char[size+1];
    for(int i=0; i<=size; i++)
        *(str+i)=s[i];
}

void MyString::StrCat(char *s)
{
    int n,i;
    n=StrLen(s);
    i=size;
    size+=n;
    realloc(str,size);
    for(int j=0; i<=size; i++,j++)
    {
        *(str+i)=s[j];
    }
}

void MyString::StrRev()
{
    for(int i=0; i<size/2; i++)
    {
        char temp;
        temp=*(str+i);
        *(str+i)=*(str+size-1-i);
        *(str+size-1-i)=temp;
    }
}

bool MyString::StrCmp(char *s)
{
    bool flag=true;
    int n;
    n=StrLen(s);
    if(n!=size) flag=false;
    else
    {
        for(int i=0; s[i]!='\0'; i++)
        {
            if(s[i]!=*(str+i))
            {
                flag=false;
                break;
            }
        }
    }
    return flag;
}

int MyString::StrLen(char *s)
{
    int i;
    for(i=0; s[i]!='\0'; i++);
    return i;
}
#endif
