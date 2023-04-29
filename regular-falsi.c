#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ERR 0.0001


float function(float x){
    float resultant;
    //The function is: x^2-2x+1=0
    return resultant=pow(x,2)-(2*x)+1;
}
float mod_value(float r){
    if(r<0){
	return r*-1;
	}
	return r;
}
void main(){
    float x1,x0,x2;
    printf("Enter the estimated starting values: ");
    printf("x0: ");
    scanf("%f", &x0);
    printf("x1: ");
    scanf("%f", &x1);
    do{
        x2=((x0*function(x1)-(x1*function(x0))))/(function(x1)-function(x0));
        if(function(x0)*function(x2)<0){
            x1=x2;
        }
        else if(function(x0)*function(x2)>0){
            x0=x2;
        }
        else if(function(x0)*function(x2)==0){
            break;
        }
    }while(mod_value(function(x2))>ERR);
    printf("The possible roots: %0.2f\n", x2);
}
