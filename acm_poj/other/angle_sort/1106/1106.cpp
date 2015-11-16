#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double const PI = 3.1415926;

typedef struct point
{
	int x;
	int y;
	double angle;
}point;

point p[200];

int i,j;
int coor_x,coor_y;
double radius;
int num;

int compare(const void* a,const void* b);

int main()
{
	while(scanf("%d %d %lf",&coor_x,&coor_y,&radius)!=EOF)
	{
		if(radius<=0)      //??????????
		{
			break;
		}
		scanf("%d",&num);
		for(i = 0;i<num;)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			x -= coor_x;
			y -= coor_y;
			p[i].x = x;
			p[i].y = y;
			p[i].angle = atan2((double)(p[i].y),(double)(p[i].x))/PI*180;
			if(p[i].angle<0)
			{
				p[i].angle += 360;
			}
			i++;
		}
		qsort(p,num,sizeof(point),compare);
		int max = 0;
		for(i = 0;i<num;i++)
		{
			if(p[i].x*p[i].x+p[i].y*p[i].y>radius*radius)
			{
				continue;
			}
			int count = 1;
			j = i+1;
			if(j == num)
			{
				j = 0;
			}
			while((p[j].angle - p[i].angle >=0 && p[j].angle - p[i].angle <= 180) || (p[j].angle - p[i].angle <= -180))
			{
				if(i == j)
				{
					break;
				}
				if(p[j].x*p[j].x+p[j].y*p[j].y<=radius*radius)
				{
					count++;
				}
				j++;
				if(j == num)
				{
					j = 0;
				}
			}
			if(max<count)
			{
				max = count;
			}
		}
		printf("%d\n",max);
	}
	/*
	double x,y;
	while(scanf("%lf %lf",&x,&y)!=EOF)
	{
		printf("%lf %lf\n",atan2(y,x),atan2(y,x)/3.14*180);
	}
	*/
	return 0;
}

int compare(const void* a,const void* b)
{
	return (*(point*)a).angle > (*(point*)b).angle ? 1:-1;
}