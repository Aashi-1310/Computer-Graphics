#include<stdio.h>
#include<graphics.h>
#include<iostream>
using namespace std;
void bresenham(int x1,int y1, int x2, int y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	float m= float(dy/dx);
	int p=2*dy-dx;
		if(dx>=0 & dy>=0) 	
		{
			while(x1<=x2 & y1<=y2)
			{
				if(dy>=dx) 		
				{
					if(dx==0)
					{
						putpixel(x1,y1,GREEN);
						y1++;
						if(p<0)	p=p+2*dy;
						else	p=p+2*dy-2*dx;
					}
					else
					{
						putpixel(x1,y1,GREEN);
						x1++;
						if(p<0)	p=p+2*dx;
						else
						{
							p=p+2*(dx-dy);
							y1++;	
						}
					}
				}
				else if(dx>dy) 			
				{
						if(p<0)
						{
							x1++;
							p=p+2*dy;	
						}	
						else
						{
							p=p+2*dy-2*dx;
							y1++;
							x1++;
						}
				}
			}
		}
		else if(dy<0 || dx<0) 		
	{
		if(x1<x2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		while(x1>x2)
		{
			putpixel(x1,y1,GREEN);
				x1--;
					if(p<0){
						p=p-2*dy;
					}
					else{
							p=p-2*dy-2*dx;
							y1++;
						}
		}
	}

	
}
int main()
{
	int gd=DETECT,gm;
	int x1,x2,y1,y2;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	cout<<"Enter the start point:";
	cin>>x1>>y1;
	cout<<"Enter the end point:";
	cin>>x2>>y2;
	bresenham( x1,y1,x2,y2);
	getch(); 
	closegraph();
	return 0;
}