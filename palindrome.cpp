#include <iostream>
using namespace std;

int palindrome_checker(int num)
{
    int temp = num;
    int temp_num = 0;
    int r;
    while(num)
    {
        temp_num *= 10;
        r = num %10;
        temp_num += r;
        num /= 10;
    }
    if(temp == temp_num)
    {
        return 1;
    }
    return 0;
    
}

int main()
{
    int num;
    cout<<"Enter the number here ";
    cin>>num;

    int a = palindrome_checker(num);

    if(a)
    {
        cout<<"Hola!! The given number "<<num<<" is a Palindrome number"<<endl;
    }

    else
    {
        cout<<"No the given number "<<num<<" is not a Palindrome number"<<endl;
    }

    return 0;
}