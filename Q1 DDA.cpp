#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;
void DDA(int x1,int y1, int x2, int y2, int val)
{	
	int dx=x2-x1;
	int dy=y2-y1;
	float m=float( dy/dx);
	while(x1<=x2 && y1<=y2)
	{
		putpixel(x1,y1,val);
		dx=dy/m;
		dy=dx*m;
		if (abs(dx)>= abs(dy))
		{
			x1+=1;
			y1+=m;
		}
		else
		{
			x1+=(1/m);
			y1+=1;
		}
	}
	
	
}
main()
{
int gd=DETECT,gm;
int x1,x2,y1,y2;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cout<<"Enter the start point:";
cin>>x1>>y1;
cout<<"Enter the end point:";
cin>>x2>>y2;
DDA(x1,y1,x2,y2,4);
getch();
closegraph();
}