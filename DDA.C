#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
int sign(float);
void main()
{       float x1,x2,y1,y2,x,y,xi,yi,dx,dy,len;
	int gd=DETECT,gm,i=0;
	initgraph(&gd,&gm,"C:/TURBOC3/BGI");
	printf("Enter starting point coords X1 & Y1\n");
	scanf("%f%f",&x1,&y1);
	printf("Enter ending point coords X2 and Y2\n");
	scanf("%f%f",&x2,&y2);
	putpixel(x1,y1,RED);//Starting point marked in red
	putpixel(x2,y2,RED);//Ending point marked in red
	dx=x2-x1;dy=y2-y1;
	x=x1;y=y1;
	if(abs(dx)>=abs(dy))
		len=abs(dx);
	else
		len=abs(dy);
	xi=dx/len;
	yi=dy/len;
	//THE FIX FOR GETTING THE CORRECT LINE
	x= x1 + 0.5*sign(xi);
	y= y1 + 0.5*sign(yi);
	/*for(i=1;i<=len;i++) will only show start point
	in red we remove = to make the end point also visible in red */
	for(i=1;i<len;i++)
	{
		x=x + xi;
		y=y + yi;
		putpixel((int)x,(int)y,GREEN);
	}
	getch();
	closegraph();
}
int sign(float n)
{
	if(n>0)
	return 1;
	else if(n<0)
	return -1;
	else
	return 0;
}
