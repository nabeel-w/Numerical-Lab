#include <stdio.h>
#include <stdlib.h>
int factorial(int n){
    int result=1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    return result;
}
float forward_coefficient(float p,int n){
    float result=p;
    for(int i=1;i<n;i++){
        result*=(p-i);
    }
    result/=factorial(n);
    return result;
}
float backward_coefficient(float p,int n){
    float result=p;
    for(int i=1;i<n;i++){
        result*=(p+i);
    }
    result/=factorial(n);
    return result;
}
float forward_interpolation(int *x,int *y,int n){
    float determine;
    float p,h,result;
    printf("The forward difference table for the given data is=>\n");
    printf("The  values of x: \n");
    for(int i=0;i<n;i++){
        printf("%d ", *(x+i));
    }
    printf("\nThe values of f(x):\n");
    for(int i=0;i<n;i++){
        printf("%d\t", *(y+i));
    }
    printf("\n");
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            *(y+i*n+j)=*(y+(i-1)*n+j+1)-*(y+(i-1)*n+j);
            printf("%d\t", *(y+i*n+j));
        }
        printf("\n");
    }
    printf("Give the value of x to determine through interpolation: ");
    scanf("%f", &determine);
    h=*(x+1)-*(x);
    p=(determine-*(x))/h;
    printf("\nThe values of u and h are: %f %f\n", p,h);
    result=*(y);
    for(int i=1;i<n;i++){
        result+=forward_coefficient(p,i)*(*(y+i*n));
    }
    return result;
}
float backward_intepolation(int *x,int *y,int n){
    float determine,result,p,h;
    printf("The backward difference table for the given data is=>\n");
    printf("The  values of x: \n");
    for(int i=0;i<n;i++){
        printf("%d ", *(x+i));
    }
    printf("\nThe values of f(x):\n");
    for(int i=0;i<n;i++){
        printf("%d\t", *(y+i));
    }
    printf("\n");
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            *(y+i*n+j)=*(y+(i-1)*n+j+1)-*(y+(i-1)*n+j);
            printf("%d\t", *(y+i*n+j));
        }
        printf("\n");
    }
    printf("Give the value of x to determine through interpolation: ");
    scanf("%f", &determine);
    h=*(x+1)-*(x);
    p=(determine-*(x+n-1))/h;
    printf("\nThe values of u and h are: %f %f\n", p,h);
    result=*(y+n-1);
    for(int i=1;i<n;i++){
        result+=backward_coefficient(p,i)*(*(y+(i*n)+n-1-i));
    }
    return result;
}
void main(){
    int i,j,*x,*y,n;
    printf("The number of values for x that you want to input: ");
    scanf("%d", &n);
    x=(int *)calloc(n,sizeof(int));
    y=(int *)calloc(n*n,sizeof(int));
    printf("Give the values of the values for the x in the table: ");
    for(i=0;i<n;i++){
        scanf("%d", (x+i));
    }
    printf("Give the values of the f(x) values for the corresponding x values: ");
    for(i=0;i<n;i++){
        scanf("%d", (y+i));
    }
    float resultant=forward_interpolation(x,y,n);
    // float resultant=backward_intepolation(x,y,n);
    printf("The resultant value for the given x value from the table is: %f\n", resultant);
}