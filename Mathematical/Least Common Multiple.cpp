#include<iostream>
#include<stdio.h>
int fun (int, int);
int main()
{	int a,b,c;
    float x;
	std::cin>>a;
	std::cin>>b;
	if(b>a)
	{  	c=a;
		a=b;
		b=c;
	}
	else
	{	;
	}
	x=(float)a*b;
	x = x/fun(a,b);
	std::cout<<(int)x<<"\n";
	;
	return 0;
}
int fun(int a,int b)
{   int d;
	if(b==0)
	{	return a;
	}
	else
	{
		d = a%b;
		a=b;
		b=d;
		fun(a,b);
	}
}

