#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;

void drawcircle(int x, int y, int val)
{
	putpixel(x,y,val);
	putpixel(y,x,val);
	putpixel(-x,y,val);
	putpixel(-y,x,val);
	putpixel(-x,-y,val);
	putpixel(-y,-x,val);
	putpixel(x,-y,val);
	putpixel(y,-x,val);
}
void circle(int r, int val)
{
	int x=100;
	int y=100+r;
	int d=1-r;
	drawcircle(x,y,val);
	while(y>x)
	{
		if (d<0)
		{
			
			x++;
			d+=2*x+3;
		}
		else
		{
			x++;
			y--;
			d+=2*(x-y)+5;
		}
	drawcircle(x,y,val);
	}
}

int main()
{
	int gd=DETECT,gm;
	int r;
	initgraph(&gd,&gm," ");
	cout<<"Enter the radius:";
	cin>>r;
	circle(r,3);
	getch(); 
	closegraph();
	return 0;
}