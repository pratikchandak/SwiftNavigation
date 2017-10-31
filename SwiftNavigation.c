#include <stdio.h>

void product(int F[2][2], int P[2][2]);
void power(int F[2][2], int n);
int prime(int n);

/* function that returns nth Fibonacci number */
int fibo(int n)
{
	int F[2][2] = {{1,1},{1,0}};
	if (n == 0)
		return 0;
	power(F, n-1);
	return F[0][0];
}

/* Optimized version of power() in method 4 */
void power(int F[2][2], int n)
{
	if( n == 0 || n == 1)
		return;
	int P[2][2] = {{1,1},{1,0}};

	power(F, n/2);
	product(F, F);

	if (n%2 != 0)
		product(F, P);
}

void product(int F[2][2], int P[2][2])
{
	int x = F[0][0]*P[0][0] + F[0][1]*P[1][0];
	int y = F[0][0]*P[0][1] + F[0][1]*P[1][1];
	int z = F[1][0]*P[0][0] + F[1][1]*P[1][0];
	int w = F[1][0]*P[0][1] + F[1][1]*P[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

int prime (int n){
    int i;
    if(n == 1)
        return 1;
    for(i=2; i<=n/2; ++i)
    {
        // condition for nonprime number
        if(n%i==0)
        {
            return 1;
        }
    }
    return 0;
}

/* Driver program to test above function */
int main()
{
	int i, n, fib;
	printf("Enter the value of n: \n");
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		fib = fibo(i);
		// number divisible by 3 and 5 will
		// always be divisible by 15, print 
		// 'FizzBuzz' in place of the number
		if (fib%15 == 0)        
			printf ("FizzBuzz\n");    
		 
		// number divisible by 3? print 'Buzzz'
		// in place of the number
		else if ((fib%3) == 0)    
			printf("Buzz\n");                 
		
		// number divisible by 5, print 'Fizz'  
		// in place of the number
		else if ((fib%5) == 0)                       
			printf("Fizz\n");                 
		
		// number is prime, print 'BuzzFizz'  
		// in place of the number
		else if(prime(fib) == 0) // print the number            
			printf("BuzzFizz\n"); 
			
		else //print the number
			printf("%d\n",fib);
	}
	getchar();
	return 0;
}
