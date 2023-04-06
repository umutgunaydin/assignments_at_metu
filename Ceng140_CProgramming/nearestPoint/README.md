# FINDING NEAREST POINT

* In this question, you are required to calculate the nearest point in a 2 dimensional (2D) space where each point has x and y pair. 
You will prompt the user by asking x and y coordinate of a point P, then you will find the index of the nearest point in the stored arrays. 

## Specifications
1. Points are stored in two integer arrays which one array stores x coordinates and other stores y coordinates. 
2. The coordinates of the first point is stored in xcoors[0] and ycoors[0] in a corresponding manner and other points similarly. 
3. Euclidean distance will be used as distance metric. Remember that Euclidean distance between 2D points is that 
square root of ((qx - px)^2 + (qy - py)^2), where px and py are x and y coordinates of the point P respectively.

## Output
* In the output, first print point P, then nearest array index and distance between point P and this index. 

## Note: 

* All given point coordinates are integers, show distance as float with 1 precision point.
* There are 10 points in coordinate arrays.
* If two coordinates' distances are equal, use the one with the lower index.

### Sample Input:
  3 4 2 1 0 9 0 1 5 6 <br>
  3 3 1 6 2 9 8 9 3 7 <br>
  9 <br>
  8

### Sample Output:
P = (9,8), nearest point index = 5, distance = 1.0
