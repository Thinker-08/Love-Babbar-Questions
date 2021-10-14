#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<vector>
void fun(std::vector <int> ,int,int);
int main()
{
    int i,b,d;
    char c;
    std::cout<<"Enter The maximum distance";
    std::cin>>d;
    std::vector <int> a;
    while(1)
    {
        std::cout<<"\n Enter the distance from starting point : ";
        std::cin>>b;
        a.push_back(b);
        std::cout<<"Want to Enter More? ";
        std::cin>>c;
        if(c=='n'||c=='N')
        {
            break;
        }
        else
        {
            continue;
        }
    }
    fun(a,a.size(),d);
    getch();
    return 0;
}
void fun(std::vector<int> a,int siz,int maxdis)
{
    int startpos=0,curpos,f=0;
    for(int i=0;i<siz;i++)
    {
        curpos=i;
        if((a[curpos]-a[startpos])<maxdis)
        {
            if(i==siz-1)
            {
                std::cout<<f;
            }
            else
            {
                continue;
            }
        }
        else
        {
            i=i-1;
            startpos=i;
            f++;
        }
    }
}
