# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main()
{
    int a,b,c,d,n;
	double result;
	printf("\n\n Find the numbers between a range that can be expressed as the sum of two cubes:\n");
	printf("------------------------------------------------------------------------------------\n");
	printf(" The numbers in the above range are: \n");
         n = 100000;  
        for (int a = 1; a <= n; a++) 
		{  
            int a3 = a*a*a;  
            if (a3 > n) break;  
  
            for (int b = a; b <= n; b++) 
			{  
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