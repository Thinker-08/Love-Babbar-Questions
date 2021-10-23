#include<iostream>
#include<stdio.h>
#include<vector>
struct m
{
    double weight;
    double value;
    double per;
};
double gr(std::vector<m>,int,double);
int main()
{
    m e;
    int itm,maxwei;
    std::cin>>itm>>maxwei;
    std::vector<m> a(itm);
    for(int i=0;i<itm;i++)
    {
        std::cin>>a[i].value>>a[i].weight;
        a[i].value=(a[i].value)*1.000;
        a[i].weight=(a[i].weight*1.000);
        a[i].per =(a[i].value/a[i].weight);
    }
    for(int j= 0;j<itm;j++)
    {
        for(int k =0;k<itm-1;k++)
        {
            if(a[k].per<a[k+1].per)
            {
                e = a[k];
                a[k] = a[k+1];
                a[k+1]=e;
            }
            else
            {
                continue;
            }

        }
    }
    std::cout<<gr(a,maxwei,0.000);
    return 0;
}
double gr(std::vector<m> a,int maxwei,double val)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i].weight==maxwei)
        {
            val = val + (a[i].per*maxwei);
            return val;
        }
        else
        {
            if(a[i].weight<maxwei)
            {
                maxwei = maxwei - a[i].weight;
                val = val+a[i].value;
            }
            else
            {
                val  = val + maxwei*a[i].per;
                return val;
            }

        }

    }

}
