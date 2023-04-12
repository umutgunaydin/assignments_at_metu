# Lab Exam 1 - Preliminary Question

## Task 0 - Hello CENG140 (10 Pts)
* In this task, you will be given some variables in the main function in integer format. 
* You are going to print a text using these variables in the desired formats.

### Variables:
1 course_code (int)<br>
2 lab_exam_count (int)<br>
3 point1 (int)<br>
4 point2 (int)<br>

### Desired output:
I got <point1> from the first and <point2> from the second lab exam of CENG<course_code>.<br>
There will be <lab_exam_count> lab exams in total.<br>
If I get two zero grades in the forthcoming lab exams, I'm going to get NA.<br>

## Task 1 - Calculator (40 pts)
* In this task, you will develop a simple calculator program that can perform basic arithmetic operations.
* The program should take two numbers and an operator as input from the user, perform the operation, and print the result.

The valid operators are:<br>

'+' for addition<br>
'-' for subtraction<br>
'*' for multiplication<br>
'/' for division<br>
* Your program should be able to handle division by zero and invalid operators.


### Example input/output: 
10 5 +<br>
Enter first number: 10<br>
Enter second number: 5<br>
Enter operator: +<br>
Result: 15.00<br>

* IMPORTANT NOTE: Division by zero will not be tested. Results will be printed with 2-digit precision. No newline will be printed at the end.

## Task 2: Character Processing (50 pts)
* In this task, you will implement a program that processes a given string of characters. Your program should be able to do the following:

1- Print each vowel in the string. <br>
2- Count the number of vowels in the string whose ASCII value is divisible by 3. <br>
3- Print the count of such vowels.<br>

### Example input/output:<br>
Input:<br>
10 openaliscool<br>
Output (oioo chars are divisible by 3):<br>
oeaioo 4<br>

### Specifications:
The result will be a floating point number with 2 digit precision.
You do not have to worry about upper limits of numbers. They are all trivial.
The output does not contain a new line character.
Please obey the print format for getting points in lab exam.
