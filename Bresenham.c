#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main(){
	int x1, y1, x2, y2;
	int dx, dy, p, x, y, s1, s2, temp, i, flag;
	int gd = DETECT, gm;

	printf("x1 y1 x2 y2: ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	initgraph(&gd, &gm, "C://TURBOC3PP/BIN");

	flag = 0;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);

	p = 2 * dy - dx;

	if (x2 - x1 < 0){
		s1 = -1;
	}
	else if (x2 - x1 > 0){
		s1 = 1;
	}
	else{
		s1 = 0;
	}

	if (y2 - y1 < 0){
		s2 = -1;
	}
	else if (y2 - y1 > 0){
		s2 = 1;
	}
	else{
		s2 = 0;
	}

	if (dy > dx){
		flag = 1;
		temp = dy;
		dy = dx;
		dx = temp;
	}

	x = x1;
	y = y1;

	for (i = 0; i < dx; i++){
		if (p >= 0){
		    if (i%5 == 0){
			putpixel(x,y,BLACK);
		    }
		    else{
			putpixel(x,y,WHITE);
		    }
			x = x + s1;
			y = y + s2;
			p = p + 2 * dy - 2 * dx;
		}
		else{
			 if (i%5 == 0){
			putpixel(x,y,BLACK);
		    }
		    else{
			putpixel(x,y,WHITE);
		    }
			if (flag == 0){
				x =  x + s1;
			}
			else{
				y = y + s2;
			}
			p = p + 2 * dy;
		}

	}
	getch();
	closegraph();

}

