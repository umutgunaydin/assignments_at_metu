# SPLITTING STRINGS
In this question, you will implement the split function that partitions a given string by the given delimeter. </br>
For example, the string "Hello World" can be splitted by the delimeter of space (' ') and the result would be two strings "Hello" and "World".</br>
Write a function named as split that partitions the given string by the delimeter and returns the partitions.</br>

## SPECIFICATIONS:
* The function should take two arguments where the first one is a char pointer containing the string and the second one is a char representing the delimeter. 
* The char pointer representing the string will NOT be given as NULL, the given string will contain at least one character and it is guaranteed to end with a null character ('\0') .
* The given delimeter will NOT be empty.
* In the given string, the delimeter will NOT occur consecutively. For example, a string like "Hello,,World" will not be given when the delimeter is ','.
* The function should return a double char pointer, representing a 2D array of characters where each row is a partition. Each part should end with a null character ('\0').
* The returned parts should not contain the delimeter.
* If the given string does not contain the given delimeter, the function should return only one partition. 
* If the delimeter occurs at the beginning or the end of the string, the beginning or the end of the string should also be considered as partitions. </br>
For example, "Hello " string (ending with a white space) is splitted by the delimeter ' ' (white space) and the result contains two parts "Hello" and an empty string.
* After you splitted the string, make sure that last part is NULL. Testing function will print parts of the string until NULL value is reached.</br>
For example, if input string is "winter-has-come" and delimeter is '-', then your double char pointer (char**) should contain 4 char pointers (char*). </br>
1st char* points to string "winter", 2nd char* points to "has", 3rd char* points to "come" and 4th char* is NULL.
* You are NOT allowed to use "string.h" functions.
* You are NOT allowed to include a library except "stdio.h" and "stdlib.h"
