# Task 0 - Hello CENG140 (10 Pts)
* In this task, you will be given some variables in the main function in integer format.
* You are going to print a text using these variables in the desired formats.

* Variables:
1- course_code (int)
2- lab_exam_count (int)
3- point1 (float)
4- point2 (float)

* Desired output:</br>
I got <point1> from the first and <point2> from the second lab exam of CENG<course_code>.</br>
There will be <lab_exam_count> lab exams in total.</br>
If I get two zero grades in the forthcoming lab exams, I'm going to get NA.</br>

* Important Note: </br>
This printed text will not be a single line text. It will be 3 lines. </br>
DO NOT forget to put newline characters to the required places. </br>
Floating points will be printed with 2-digit precision.</br>

* Example:</br>
Input: 242 2 50.13 80.123</br>
Output: </br>

# Task 1 - Square Integer Check (20 pts)
* In this task, you will implement a program that checks if a given integer is a square of an integer or not. 
* Your program should take an integer as input from the stdin, perform the check, and print the result accordingly.

* Variables:</br>
1- num (int): The input integer to be checked in range [1, 1000]</br>

* Desired output:</br>
If the given integer is a square of an integer, print "Square of x" where x is the square root of the given integer. </br>
If the given integer is not a square of any integer, print "Not a square".</br>

* Example input/output:</br>
Input: 25 </br>
Output: Square of 5</br>
Input: 49 </br>
Output: Square of 7</br>
Input: 37</br>
Output: Not a square</br>

* Important note: There will NOT be a newline character at the end.

# Task 2 - Narrowing Zig Zag Check (30 pts)
* In this task, you will implement a program that checks if a given list of integers is a narrowing zig zag or not. 
* Your program should take an integer N (3 ≤ N ≤ 100) as input, representing the size of the integer list, followed by N integers as input from the stdin. 
* It should then check if the given list of integers follows the criteria of a narrowing zig zag, where the list should increase at a point and then immediately decrease after that point and vice versa, and repeat it.

* Being zigzag rule:</br>
If a number in the list is greater than its predecessor, it should also be greater than its successor, and vice versa</br>
Examples: a > b < c and b < c > d</br>

* Being narrowing rule:
If the peaks in the list are getting smaller compared to their predecessors, and the valleys are getting larger compared to their predecessors, then the list is considered narrowing.</br>
Examples: a > c > e > g and b < d < f</br>
Series should start with a peak to be able to be a zigzag.</br>

* Variables:</br>
1- N (int): The size of the number series</br>
2 - N integers forming the series</br>

* Desired output:</br>
If the given list of integers is a narrowing zig zag, print "Narrowing zigzag". </br>
If the given list of integers is a zig zag but not narrowing, print "Zigzag but not narrowing". </br>
If the given list of integers is not a zig zag, print "Not a zigzag".</br>

* Example input/output (First integer in the input is representing the size of the series): </br>
Input: 7 10 1 8 3 6 4 5 Output: Narrowing zigzag</br>
Input: 6 10 8 15 12 17 14 Output: Zigzag but not narrowing</br>
Input: 5 3 6 9 12 15 Output: Not a zigzag</br>

* Important note: Series should start with a peak to be able to be a zigzag. There will not be a newline character at the end.

# Task 3 - Letter Grade Calculator (40 pts)
* You are given an integer, N (1 ≤ N ≤ 100), representing the number of grades. 
* This is followed by N floating point grades. Additionally, 3 more floating point grades are given. 
* Your task is to calculate the average grade of the class using these N+3 grades.
* After calculating the average, you need to assign letter grades for the last 3 grades separately, based on the following rules:</br>

If the difference between the calculated average and the grade is within the range [-5, 5), the student will receive a "CC" grade.</br>
If the difference between the calculated average and the grade is greater than or equal to +5 points, the student will receive a "CB" grade.</br> 
If the difference is greater than or equal to +10 points, the student will receive a "BB" grade, and so on, with increasing intervals of 5 points. </br>
Similarly, if the difference between the calculated average and the grade is less than -5 points, the student will receive a "DC" grade.</br> 
If the difference is less than -10 points, the student will receive a "DD" grade, and so on, with decreasing intervals of 5 points.</br>
You need to implement a program that takes the inputs as described above and calculates the average grade of the class, assigns letter grades for the last 3 grades based on the given rules, and prints the results.

* Input:</br>
An integer N, representing the number of grades.</br>
N floating point grades</br>
3 more floating point grades</br>
* Output:</br>
The calculated average grade of the class.</br>
Letter grades for the last 3 grades, based on the given rules.</br>

* Examples:</br>
Input: 3 60.1 70.2 50.3 40.1 50.2 60.3</br>
Output: Average: 55.20. Letter grades: FD CC CB</br>

Input: 10 10.11 20.22 30.33 40.44 50.55 45.54 79.79 29.29 23.23 66.66 22.23 60.51 91.5</br>
Output: Average: 43.88. Letter grades: FF BA AA</br>

* Important note: There will NOT be a whitespace or a newline character at the end.

## Specifications
* There will NOT be an extra whitespace character  and there will NOT be a newline character at the end in prints.
* Each floating point will be printed with 2 digit precision.
* You should not use any library other than “stdio.h”. You can use conditional clauses (switch/if/else if/else), loops (for/while). 
* You can NOT use any further elements beyond that. You can define your own helper functions.



