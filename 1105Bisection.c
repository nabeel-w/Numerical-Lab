#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// Let equation be x^3-4x-9=0

float interval(float i) { return pow(i,3) - (4 * i) - 9; }
void main() {
  int i, j;
  float x1, x2, y,t=0,d=0;
  float result = 0, result2 = 0;
  for (i = 0; i < 100; i++) {
    result2 = result;
    result = interval(i);
    if (result2 - result < 0) {
      x1 = i;
      x2 = x1 + 1;
      break;
    }
  }
  printf("x1=%f x2=%f", x1, x2);
  float x = (x1 + x2) / 2;
  printf("\n%f", x);
  y = interval(x);
  printf("\n------------------\n");
  int k;
  printf("\nEnter number of iterations: ");
  scanf("%d",&k);
  for (i = 1; i <=k; i++) {
    x = (x1 + x2) / 2;
    y = interval(x);
    printf("\nf(x) = %f", y);
    if (y < 0) {
      x1 = x;
      x2 = x2;
      t = y;
    } else {
      x2 = x;
      x1 = x1;
      d = y;
    }
    printf("\nRoot after iteration %d: %f\n",i,x);
    printf("\n------------------\n");
  }
}