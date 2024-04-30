#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;
# define left 0x1
# define rt 0x2
# define btm 0x4
# define top 0x8

#define INSIDE(a) (!a)   // a point is inside the clip window if its 0000 
#define REJECT(a,b) (a&b) //points are rejected if anding doesn't give 0000 (condition of triviual rejection)
#define ACCEPT(a,b)  (!(a|b)) //if both pts are 0000 thier OR will be 0000 (cindition of trivial acceptence)

int getcode(int x, int y, int ymin, int ymax, int xmin, int xmax)
{
	char code=0x00;
	if(y > ymax) code |= top;
	if(y < ymin) code |= btm;
	if(x < xmin) code |= left;
	if(x > xmax) code |= rt;
	return code;
}
void clip (int x1, int y1,int x2, int y2, int ymin, int ymax, int xmin, int xmax)
{
	char code1 , code2;
	int done= false, draw=false;
	float m;
	while(!done)
	{
		code1=getcode(x1,y1,ymin,ymax,xmin,xmax);
		code2=getcode(x2,y2,ymin,ymax,xmin,xmax);
		if (ACCEPT(code1,code2))
		{
			done=true;
			draw=true;
		}
		else
		{
			if (REJECT(code1,code2)) done=true;
			else
			{
				if(INSIDE(code1)) //checks if first point is inside the window
				{
					swap(x1,x2);
					swap(y1,y2);
					swap(code1,code2);    //we swap the values to second point
				}
				if(x2!=x1) m= (y2-y1)/(x2-x1);
				if (code1 & left)
				{
					y1+=(xmin-x1)*m;
					x1=xmin;
				}
				else if (code1 & rt)
				{
					y1+=(xmax-x1)*m;
					x1=xmax;
				}
				else if(code1 & top)
				{
					if(x2!=x1)
					{
						x1+=(ymax-y1)/m;
						y1=ymax;
					}
				}
				else if(code1 & btm)
				{
					if(x2!=x1)
					{
						x1+=(ymin-y1)/m;
						y1=ymin;
					}
				}
				
			}
		}
	}
	if(draw)
	{
		setcolor(RED);
		line(x1,y1,x2,y2);
	}
}
int main() 
{
    int ymin, ymax, xmin, xmax, x1,x2,y1,y2;
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    //setcolor(WHITE);
    cout<<"Enter the coordinate of the clip window:";
    cin>>xmin>>xmax>>ymin>>ymax;
    rectangle(xmin,ymin,xmax,ymax);
    cout<<"Enter the coordinates of the starting point:";
    cin>>x1>>y1;
    cout<<"Enter the coordinates of the ending point:";
    cin>>x2>>y2;
    
    line(x1,y1,x2,y2);
    clip(x1,y1,x2,y2,ymin,ymax,xmin,xmax);
    getch();
    closegraph();
    return 0;
}