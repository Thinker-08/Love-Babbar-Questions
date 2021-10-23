#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<vector>
void sor(std::vector <float> a,int);
void grp(std::vector <float> a,int,int);
int main()
{
    float b;
    char c;
    int d;
    std::cout<<"Enter The max difference between ages of children  : ";
    std::cin>>d;
    std::vector<float> a;
    while(1)
    {
        std::cout<<"\n Enter The Age of child  :";
        std::cin>>b;
        a.push_back(b);
        std::cout<<"\n Wnat to enter more  :";
        std::cin>>c;
        if((c=='n')||(c=='N'))
        {
            break;
        }
        else
        {
            continue;
        }
    }
    sor(a,a.size());
    for(int i=0;i<a.size();i++)
    {
        std::cout<<a[i]<<" ";
    }
    grp(a,a.size(),d);
    getch();
    return 0;
}
void sor(std::vector<float> a,int siz)
{
    for(int i=0;i<(siz-1);i++)
    {
        for(int j=0;j<(siz-1);j++)
        {
            if(a[j]>a[j+1])
            {
                float b;
                b=a[j];
                a[j]=a[j+1];
                a[j+1]=b;
            }
            else
            {
                continue;
            }

        }
    }
}
void grp(std::vector<float> a,int b,int d)
{
    int g=0,curpos=0;
    for(int i=0;i<b;i++)
    {
        if(((a[i+1])-(a[curpos]))>d)
        {
            i=i-1;
            curpos=i;
            g++;
        }
        else
        {
            continue;
        }

    }
    std::cout<<"\n The Number of groups are"<<g;
}

