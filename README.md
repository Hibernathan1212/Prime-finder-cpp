## Prime finder using Sieve of Eratosthenes in C++

Gives list of all primes up to a certain value


***~1.5s for all primes under 100,000***
***~18s for all primes under 1,000,000***

Only keeps track of values of type 6n-1 (6n+5) and 6n+1 for integers n to minimize memory usage and reduce computation

Number of type 6n, 6n+2, and 6n+4 will be even, therefore not prime 
Numbers of type 6n+3 are divisible by 3 
