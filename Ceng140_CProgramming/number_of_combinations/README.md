
# TASK: Number of Combinations
In this task you will implement a function that returns the number k choices in a set of size n which is given as the combination formula below.
The function for this task is given as below, which takes two integers and return another one.

int combinations(int n, int k);

Hint & Warning: We are calculating combinations with recursion. It is expected that you should do minimum number of calls for combinations() function. 
There is a way of speeding up the calculation. For instance, C(20, 16) and C(20,4) are equal, if arguments are n=20 and k=16, you should call same function with n=20 and k=4, to get the same output.

Step by step calculation of "24 choose 20":

The 1st call is combinations (24, 20).
The 2nd call is combinations(24, 4) since it is faster to calculate C(24,4) than C(24,20).
The 3rd call is combinations (23, 3).
The 4th call is combinations (22, 2).
The 5th call is combinations (21, 1).
The 6th call is combinations (20, 0). This one is the base case, returns 1.
1 is multiplied with 21 from 5th step, 22, 23, 24 from other steps and final result is 10626.
An example call for combinations of 24 and 20

int n = combinations(24, 20);
This is the expected output:

> (24 20)
> (24 4)
> (23 3)
> (22 2)
> (21 1)
> (20 0) 
> combinations(24 20)=10626
