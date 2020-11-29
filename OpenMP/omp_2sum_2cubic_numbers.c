# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <omp.h>

/* 
Inside loop operations to calculate the specified numbers.
No changhes from original code but moved to a function.
*/
void loop_operation (int a,int n) {
    int a3 = a*a*a;
    if (a3 > n) {}
    else {
        for (int b = a; b <= n; b++) {
            int b3 = b*b*b;  
            if (a3 + b3 > n) break;
  
            for (int c = a + 1; c <= n; c++) 
    	    {  
                int c3 = c*c*c;  
                if (c3 > a3 + b3) break;  
  
                for (int d = c; d <= n; d++) 
			    {  
                    int d3 = d*d*d;  
                    if (c3 + d3 > a3 + b3) break;  
  
                    if (c3 + d3 == a3 + b3) 
				    {  
                        printf(" %d = ",(a3+b3));  
                        printf("%d^3 + %d^3 = ",a,b);   
                        printf("%d^3 + %d^3",c,d);   
                        printf("\n"); 
                    }  
                }  
            }  
        }
    }
}

void main ()
{
    int n = 100000;
    printf("\n\n Find the numbers between a range that can be expressed as the sum of two cubes:\n");
	printf("------------------------------------------------------------------------------------\n");
	printf(" The numbers in the above range are: \n");

    omp_set_num_threads(8);     // Set number of threads
    #pragma omp parallel for    // Combine parallel and for pragma in one line
    for (int i = 1; i <= n; i++){
        loop_operation(i,n);
    }
}