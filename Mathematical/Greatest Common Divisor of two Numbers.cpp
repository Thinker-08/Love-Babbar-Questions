#include<iostream>
#include<stdio.h>
void fun (int,int);
int main()
{	int a,b,c;
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
	fun(a,b);
	return 0;
}
void fun(int a,int b)
{       int d;
	if(b==0)
	{	std::cout<<a;
	}
	else
	{   
		d = a%b;
		a=b;
		b=d;
		fun(a,b);
	}
}

