# Movement of a Robot

* A robot is placed in a NxN grid. An example of 4x4 grid with axis indexes is given as following.


     0  1  2  3
  0  _  _  _  _
  1  _  _  _  _
  2  _  _  _  _
  3  _  _  _  _

- where each '_' character represents a cell.


* A position in the grid is relative to its upper left corner, that is, x value increases in East direction and y value increases in South direction. The position of the robot will be given as x and y coordinates. For example, if the robot is placed in x = 3, y = 2 in a 4x4 grid, its position can be shown as following.

     0  1  2  3
  0  _  _  _  _
  1  _  _  _  _
  2  _  _  _  _
  3  _  _  _  _
  
* The robot can only move in four directions as North, South, East and West where diagonal movements are forbidden. For example,

  - Movement from (3,2) to (3,3) is in the South direction.
  - Movement from (1,1) to (3,3) can be done as E,S,E,S .

* Write the code that updates the position of the robot according to the given movement direction. 
* If the robot's movement is blocked, the position of the robot will remain unchanged, that is the robot cannot move out of the grid. 
* The code should print the final position of the robot.



## SPECIFICATIONS:

* Your code should read 4 arguments as direction, the x coordinate of the robot, the y coordinate of the robot and N.
* Direction will be an uppercase character as 'N', 'S', 'W', 'E'.
* The given position of the robot will be a valid position in the grid.
* The size of the grid (N) will be given as a positive integer.
* The code should print the final position of the robot as x and y coordinates.
* You are not allowed to include a library except "stdio.h".
* Your code should read 4 arguments as direction, the x coordinate of the robot, the y coordinate of the robot and N.

## EXAMPLES:

./movement
E 4 5 7
5 5

./movement
E 6 5 7
6 5
