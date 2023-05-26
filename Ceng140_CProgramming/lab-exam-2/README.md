
# Lab Exam 2:
In this lab exam, you will work with arrays. You will implement these 3 functions:</br>
```
void minMaxNorm(float Arr[], int size)
void cosineSimilarity(float Vecs[], int vecSize, float Comp[])
void eraseCollisions(int n, int m, int ObjA[], int ObjB[], int width, int height, int TranslateCommands[], int commandCount)
```
To test your functions, you can use the main.c that we have provided. You can hit run and test your outputs.</br>
You can declare your own arrays by using the preprocessor constant that is defined in lab_2.h -> MAX_ARRAY_SIZE.</br>
It is guaranteed that your arrays will not be larger than this value.</br>

## Task 1 - Min-Max Normalization  (35 Pts)

* You are given:</br>
A data 𝑑𝑎𝑡𝑎=(𝑑1,𝑑2,𝑑3⋯𝑑𝑛)</br>
* You will apply min-max normalization on the data and update the contents of data array with new normalized values:</br>
You will take the values and find min and max  values</br>
Transform every value 𝑣 as 𝑣𝑛𝑒𝑤=𝑣𝑜𝑙𝑑−𝑚𝑖𝑛𝑚𝑎𝑥−𝑚𝑖𝑛</br>
Update the contents of the data that is passed to the function as an argument</br>
* For this task, you will implement the function that is given blank in lab_2.c file:</br>
void minMaxNorm(float arr[], int size);</br>
arr: an array of floats, example [2.5, 3.5, 4.5]</br>
size: size of the array. For example the array above has size 3</br>
* It will be guaranteed that:</br>
𝑛 is the size of the array</br>
0<𝑛≤100</br>
components of the data are floating points</br>
values of data will not be greater than 200  and will not be less than 0. </br>
### Important Notes:
Your function should not return anything, it is a void function. You will just update the values of the array that is given as an argument.</br>
We will check the contents of the array while evaluating. All the inputs are provided just like in the preliminary tasks.</br>
So, you will just implement the blank function that is given to you in lab_2.c
### Sample Input Outputs:
Args1 :  </br>
arr: [1.0, 2.0, 3.0]</br>
size: 3</br>
UpdatedContent1 :</br>
arr becomes [0.00, 0.50, 1.00]</br>
Args2 : </br> 
arr: [2.0, 20.0, 15.0, 4.5, 1.25]</br>
size: 5</br>
UpdatedContent2 :</br>
arr becomes [0.04, 1.00, 0.73, 0.17, 0.00]</br>
Args3 :  </br>
arr: [5.0, 8.0, 11.0, 14.0]</br>
size: 4</br>
UpdatedContent3 :</br>
arr becomes  [0.0, 0.33, 0.67, 1.00]</br>
* Important Note Again: You will not return or print anything. You will just update arr.

## Task 2 - Cosine Similarity  (45 Pts)
* You are given</br>
Data of 3D vectors 𝐷=(𝑉1𝑥,𝑉1𝑦,𝑉1𝑧,𝑉2𝑥,𝑉2𝑦,𝑉2𝑧,⋯𝑉𝑛𝑥,𝑉𝑛𝑦,𝑉𝑛𝑧)</br>
A 3D vector 𝐵=(𝑏𝑥,𝑏𝑦,𝑏𝑧)</br>
* You will compare vector 𝐵 with every vector inside the data 𝐷 and calculate cosine similarity. Then your program will output(printf):</br>
index of the vector (indices start from 1) which has the highest cosine similarity.</br>
highest similarity score</br>

* The cosine similarity between two vectors 𝐾 and 𝐿 is found by:</br>
𝑐𝑜𝑠𝑖𝑛𝑒 𝑠𝑖𝑚𝑖𝑙𝑎𝑟𝑖𝑡𝑦=𝑆𝐶(𝐾,𝐿)=𝑐𝑜𝑠(𝜃)=(𝐾⋅𝐿)/|𝐾|∗|𝐿|=∑𝑖=...</br>
* So, you have to find the dot product between two vectors and divide it by the product of both vectors' lengths. You have calculated dot products and vector lengths in your preliminary question.
* The dot product of two vectors is found by:</br>
𝐾⋅𝐿=...</br>
* For this task, you will implement the function:</br>
void cosineSimilarity(float Vecs[], int vecSize, float Comp[])</br>
vecs: an array of 3D vectors, example, if Vecs array is [0.5, 3.4, 4.23, 1.1, 0.1, 0.44], than we have two vectors [0.5, 3.4, 4.23] and [1.1, 0.1, 0.44]</br>
size: the number of vectors present in Vecs array. For the example above, size is 2.</br>
Comp: the 3D array that is going to be compared with every vector in vecs</br>

* It will be guaranteed that:</br>
0<𝑛≤100 where n is the size</br>
The components of both vectors will be floats</br>
the size of Comp array will always be 3 since it has one 3D vector</br>
cosine similarity scores will always be greater than 0</br>
Output format</br>
V<vector-index-in-data> <cosine-similarity></br>
If there are multiple highest similarities, select the one with lower index</br>
Vector indices in data start from 1</br>
The similarity score will have four-digit precision ("%.4f")</br>

* Sample Input Outputs:</br>
Args1 :  </br>
vecs: [1.2, 1.0, 1.1, 0.2, 0.4, 0.5]</br>
size: 2</br>
Comp: [1.0, 1.0, 1.0]</br>
Output1 :</br>
V1 0.9973</br>
Args2 :  </br>
vecs: [0.54, 0.25, 0.70, 1.45, 1.51, 1.53, 2.0, 2.5, 3.0]</br>
size: 3</br>
Comp: [1.5, 1.45, 1.5]</br>
Output2 :</br>
V2 0.9995</br>

## Task 3 - Erase Collisions (20 Pts)
In this task, you will use your experience in solving Task 3 and Task 4 of the preliminary.</br>
* You are given:</br>
Frame width and height</br>
Object A's vertex array (𝑎1𝑥,𝑎1𝑦,𝑎2𝑥,𝑎2𝑦⋯𝑎𝑛𝑥,𝑎𝑛𝑦). This represents object A's vertices on a 2D plane</br>
Object B's vertex array (𝑏1𝑥,𝑏1𝑦,𝑏2𝑥,𝑏2𝑦⋯𝑏𝑚𝑥,𝑏𝑚𝑦). This represents object B's vertices on a 2D plane</br>
* For example, if the vertex array is [1, 1, 2, 2, 3, 3], this means that the vertices of the object are:</br>
v1 = (1, 1)</br>
v2 = (2, 2)</br>
v3 = (3, 3)</br>
A list of commands</br>
Translate (x,y): Translate the camera by x and y:</br>
This time, unlike the tasks in your preliminary work, our 2D Grid will be unlimited.</br>
However, we still provide you with a frame width and height and you will use them to display the object parts which fall into the frame.</br>

* For this task, you will implement the function:</br>
void eraseCollisions(int n, int m, int ObjA[], int ObjB[], int width, int height, int TranslateCommands[], int commandCount)</br>
n: vertex count of ObjA. If ObjA is [1, 5, 2, 4], then it has 2 vertices [1,5] and [2,4]</br>
m: vertex count of ObjB. Same rule applies as n</br>
ObjA: Array that contains 2D vertices of ObjA</br>
ObjB: Array that contains 2D vertices of ObjB</br>
width: Width of the frame</br>
height: Height of the frame</br>
TranslateCommands: An array with 2D vectors for translating the camera. For example, if TranslateCommands is [1, 1, 2, 2], then it has two translation commands [1,1] and [2,2] that you have to apply</br>
commandCount: how many commands does TranslateCommands array have. For the example above, it is 2.</br>

* Initially, you have to assume that there is a camera looking directly at the center of the frame. For example, let's visually demonstrate what happens if arguments are:</br>
n:  3 </br>
m: 2</br>
ObjA: [1, 1, 2, 2, 3, 2]</br>
ObjB: [3, 2, 4, 3]</br>
width: 6</br>
height: 6</br>
TranslateCommands: [-1, -1, -1, -1, 3, 0]</br>
commandCount: 3</br>

* These arguments mean that;</br>
Object A has three vertices at (1,1), (2,2), and (3,2)</br>
Object B has two vertices at (3,2), and (4,3)</br>
Frame width is 6 and frame height is 6</br>
There are three translation commands</br>
c1 = (-1, -1)</br>
c2 = (-1, -1)</br>
c3 = (3, 0)</br>
The initial grid without translating the camera looks like the following. Notice that there is a collision at (3,2). While giving the output, we will treat this collision as blank.</br>

* Sample Input/Outputs:</br>
Args1:</br>
n = 3, m = 3</br>
ObjA = [1, 1, 2, 2, 3, 3], ObjB = [1, 2, 2, 2, 2, 3]</br>
width = 5, height = 5</br>
commandCount = 3, TranslateCommands = [0, 1, 1, 0, 0, -2]</br>
Output1:</br>
```
-  -  -  -  -
-  -  -  -  -
a  -  -  -  -
b  -  -  -  -
-  b  a  -  -
```
Args2:</br>
n = 4, m = 3</br>
ObjA = [1, 1, 1, 2, 1, 3, 1, 4], ObjB = [1, 3, 1, 4, 1, 5]</br>
width = 3, height = 6</br>
commandCount = 1, TranslateCommands = [0, 1]</br>
Output2:</br>
```
-  a  -
-  a  -
-  -  -
-  -  -
-  b  -
-  -  -
```
### Specifications:
Just like in the preliminary work, there will be two spaces "  " between elements in the same row</br>
Spaces are only between inner elements of the row (There is no space before the first element of a row or after the last element of a row)</br>
If vertices of both objects collide, we will treat that vertex as it is blank. So we will erase the collisions</br>
Vertex coordinates can be any integer value. If it is out of the bounds of the frame, then it will not be displayed.</br>
Notice that we are translating the camera here, not the objects. (So you have to move the objects' vertices to the opposite direction)</br>
It is guaranteed that 1≤𝑐𝑜𝑚𝑚𝑎𝑛𝑑𝐶𝑜𝑢𝑛𝑡<5. So there is at least one translation command</br>
It is guaranteed that frame width and height 2≤𝑤,ℎ≤10</br>
It is guaranteed that each object has at least one vertex and at most 5 vertices. 1≤𝑛≤5</br>

