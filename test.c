#include <stdio.h>
#include <stdlib.h>
#include "arith.h"
#include "trans.h"
#include <x86intrin.h>

#define nb 3
#define ni 3
#define nc 3
#define N 3

typedef __attribute__((aligned(32))) int mat [N*N];

int main(void){
    
     int i,j;
    mat a = { 1,2,3, 1,2,3, 1,2,3};
    mat b = { 1,2,3, 1,2,3, 1,2,3};
    mat o;
    long long int c [2000];
    for (i=0; i<1000; i++) {
        c[i*2+0] = _rdtsc();
        matrix_mult((int *)o,(int *)a,(int *)b, nb, ni, nc);
        c[i*2+1] = _rdtsc();
    }
    int top= 0;
    double ort= 0.0;
    for (i=0; i<1000; i++)
    top += c[i*2+1]- c[i*2+0];
    ort = (double)top/100;
    
    printf ("%f", ort);
    
}
    
        
  
