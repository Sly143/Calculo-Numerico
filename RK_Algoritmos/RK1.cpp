#include <stdio.h>
#include <stdlib.h>

float calcfuncao(float x, float y){
	//return (x-(y+2)); 	// A
	//return (y-((2*x)/y));	// B
	//return (1/x);	// C
	//return 1-(y/x);		// D
	return (0.04*y);		// E
}

int main(){
	
	int k,m;
	float a,b,h;
	
	a=0;
	b=1;
	//h=0.1;
	h=0.2; 
		
	m = (b-a)/h;
	printf("\nNumero de m = %d\n",m);
	float x[m]; float y[m];
	
			x[0]=0;
			y[0]=1000;
		
	for(k=0;k<=m-1;k++){
		
		x[k+1]= x[k]+h;
		y[k+1]= y[k]+(h*calcfuncao(x[k],y[k]));
		printf("calcf = %.4f\t",calcfuncao(x[k],y[k]));
		printf("x [%d] = %.4f\t\t",k+1,x[k+1]);
		printf("y [%d] = %.4f\n",k+1,y[k+1]);
		
	}
	system("pause");
}
	
