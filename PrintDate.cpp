/*给出年份m和一年中的第n天，算出第n天是几月几号。*/

#include<iostream>
#include<stdio.h>
using namespace std;

int monthdays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapyear(int year)
{
     if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
     {
         return true;
     }
    return false;
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        if(isLeapyear(m))
        {
            monthdays[2] = 29;
        }
        
        for(int i = 0; i <= 12; ++i)
        {
            if(n <= monthdays[i])
            {
                printf("%04d-%02d-%02d\n", m, i, n);
                break;
            }
            else
            {
                n -= monthdays[i];
            }
        }
    }
}
