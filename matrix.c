#include <stdio.h>
int a[100][100],b[100][100],c[100][100],r1,r2,r3,c1,c2,c3,i,j,k;
int input()
{
	printf("Enter the number of rows for matrix a: ");
	scanf("%d", &r1);
	printf("Enter the number of columns for matrix a: ");
	scanf("%d", &c1);
	printf("Enter the number of rows for matrix b: ");
	scanf("%d", &r2);
	printf("Enter the number of columns for matrix b: ");
	scanf("%d", &c2);
	
	
	printf("\nEnter elements of 1st matrix:\n");
  	for (i = 0; i < r1; i++){
		for (j = 0; j < c1; j++) {
			a[i][j]=0;
			printf("Enter element a%d%d: ", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("\nEnter elements of 2nd matrix:\n");
  	for (i = 0; i < r2; i++){
		for (j = 0; j < c2; j++) {
			b[i][j]=0;
			printf("Enter element a %d %d: ", i + 1, j + 1);
			scanf("%d", &b[i][j]);
		}
	}
	
	printf("\nElements of 1st matrix:\n");
	for (i = 0; i < r1; i++){
		for (j = 0; j < c1; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\nElements of 2nd matrix:\n");
		for (i = 0; i < c2; i++){
			for (j = 0; j < r2; j++) {
				printf("%d ", b[i][j]);
		}
			printf("\n");
	}
	return 0;
}
int display(int x,int y)
{
	for (i = 0; i < x; i++){
		for (j = 0; j < y; j++) {
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int add()
{
	if(r1==r2 && c1==c2)
	{
		for (i = 0; i < r1; ++i){
			for (j = 0; j < c1; ++j) {
				c[i][j] = a[i][j] + b[i][j];
    		}
		}
	}
	else
		printf("Addition not possible");
	r3=r1;
	c3=c1;
	
	display(r3,c3);
	return 0;
}

int subtract()
{
	if(r1==r2 && c1==c2)
	{
		for (i = 0; i < r1; ++i){
			for (j = 0; j < c1; ++j) {
				c[i][j] = a[i][j] - b[i][j];
    		}
		}
	}
	else
		printf("Subtraction not possible");
	r3=r1;
	c3=c1;
	
	display(r3,c3);
	return 0;
}

int multiply()
{
	if (c1==r2)
	{
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c2; j++) {
				c[i][j] = 0;
				for (k = 0; k < r2; k++) {
                	c[i][j] += a[i][k] * b[k][j];
            	}
        	}
    	}
	}
	else
		printf("Multiplication not possible");
	r3=r1;
	c3=c2;
	
	display(r3,c3);
	return 0;
}

int transpose()
{
	printf("Enter 1 or 2 to find the transpose of matrix a or b respectively:");
	int ch;
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			for (i = 0;i < r1;i++)
    		{
        		for (j = 0; j < c1; j++)
        		{   
            		c[j][i] = a[i][j];
        		}
    		}
			c3=r1;
			r3=c1;
			break;	
		case 2:
			for (i = 0;i < r2;i++)
    		{
        		for (j = 0; j < c2; j++)
        		{   
            		c[j][i] = b[i][j];
        		}
    		}
			c3=r2;
			r3=c2;
			break;
		default:
			printf("Wrong choice:");	
	}
	
	display(r3,c3);
	return 0;
}
int main()
{
	input();
	
	int p;
	printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n5.Exit\nEnter your choice");
	do{
		scanf("%d",&p);
		switch (p)
		{
			case 1:
				add();
				break;
			case 2:
				subtract();
				break;
			case 3:
				multiply();
				break;
			case 4:
				transpose();
				break;
			case 5:
				printf("Exiting");
				break;
			default:
				printf("Wrong choice");
		}
	}
	while(p!=5);
}


