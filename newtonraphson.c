#include <stdio.h>
#include <math.h>
#define ERR 0.001

float func(float x){
    //the function is x^2-2x+1=0;
    return pow(x,2)+2*x+1;
}

//
float derivfunc(float x){
    return 2*pow(x,1)+2;
}

//function to calculate the mod value
float modval(float h){
    if(h<0){
        return h*(-1);
    }
    return h;
}

int main(){
    float x0,result,z;
    printf("Enter the approx initial value of the root: ");
    scanf("%f", &x0);
    float h=func(x0)/derivfunc(x0);
    result=x0;
    while(modval(h)>=ERR){
        h=func(result)/derivfunc(result);
        result=result-h;
    }
    
    
    printf("The probable root of the equation is: %0.2f\n", result);
	return 0;
}
