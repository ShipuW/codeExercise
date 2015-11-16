#include<stdio.h>
#include<math.h>

int T;
double L,W;
int i,j;

double gcd(double L,double W);

int main()
{
	scanf("%d",&T);
	for(i = 1;i<=T;i++)
	{
		scanf("%lf%lf",&L,&W);
		double g = gcd(L,W);
		printf("Case #%d: %.0lf\n",i,g);
	}
	return 1;
}
/*
double gcd(double L,double W)
{
	double div = L/W;
	div = floor(div);          //floor return type is float
	double mod = L-W*div;
	return W < 0.1 ? L:gcd(W,mod);   //L%W
}
*/
/*
double gcd(double L,double W)
{
    while(!(W<0.1))
    {
       double div = L/W;
       div = floor(div);          //floor return type is float
	   double mod = L-W*div;

       L=W;
       W=mod;
    }
    return L;
}
*/
double gcd(double L,double W)
{
    while(L!=W)
    {
       if(L>W)
           L-=W;
       else
           W-=L;
    }
    return L;
}