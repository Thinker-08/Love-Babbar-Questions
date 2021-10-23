#include<iostream>
#include<stdio.h>
int cha(int,int);
int main()
{
    int m, b ;
    std::cin>>m;
    b=cha(m,0);
    std::cout<<b;
    return 0;

}
int cha(int m,int a)
{
    int d;
    if(m>10)
    {
        d=m/10;
        a = a+d;
        m = m - (d*10);
        cha(m,a);
    }
    else
    {
        if((m<10)&&(m>=5))
        {
            d = m/5;
            a = a+d;
            m = m - (d*5);
            cha(m,a);
        }
        else
        {
            if((m<5)&&(m!=0))
            {
                d = m/1;
                a = a + d;
                m = m - (d*1);
                cha(m,a);
            }
            else
            {
                return(a);
            }

        }

    }

}
