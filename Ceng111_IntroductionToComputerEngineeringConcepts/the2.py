
vertices=eval(input())

x1y1=vertices[0]
x2y2=vertices[1]
x3y3=vertices[2]
x4y4=vertices[3]

x1=vertices[0][0]
x2=vertices[1][0]
x3=vertices[2][0]
x4=vertices[3][0]

y1=abs(vertices[0][1])
y2=abs(vertices[1][1])
y3=abs(vertices[2][1])
y4=abs(vertices[3][1])

areaOfGivenQuadriliteral = (x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1)  #this is the formula of finding the area of given quadriliteral
areaOfGivenQuadriliteral = abs(areaOfGivenQuadriliteral * 0.5) # at the previous step there is subtraction so we need to use abs() just in case

listOf_xCoordinates=[x1,x2,x3,x4]
listOf_yCoordinates=[y1,y2,y3,y4]

sorted_xCoordinates=sorted(listOf_xCoordinates)
sorted_yCoordinates=sorted(listOf_yCoordinates)

xMax=max(x1,x2,x3,x4)
xMin=min(x1,x2,x3,x4)

# finding the y axisses of xMax and XMin  -----   if yAxisOf_xMax and yAxisOf_xMin are the lowest y coordinates we can calculate the are in this way
# if there are the x numbers which are equals we will check by this way
if(xMin==sorted_xCoordinates[0] and xMin==sorted_xCoordinates[1]):
    yAxissesOfMinX=[]
    if xMin in x1y1:
        yAxissesOfMinX.append(y1)
    if xMin in x2y2:
        yAxissesOfMinX.append(y2)
    if xMin in x3y3:
        yAxissesOfMinX.append(y3)
    if xMin in x4y4:
        yAxissesOfMinX.append(y4)
    
    sorted_yAxissesOfXMin=sorted(yAxissesOfMinX)
    yAxisOf_xMin=sorted_yAxissesOfXMin[0]

else:
    if xMin in x1y1:
        yAxisOf_xMin=y1
    elif xMin in x2y2:
        yAxisOf_xMin=y2
    elif xMin in x3y3:
        yAxisOf_xMin=y3
    elif xMin in x4y4:
        yAxisOf_xMin=y4


if(xMax==sorted_xCoordinates[2] and xMax==sorted_xCoordinates[3]):
    yAxissesOfMaxX=[]
    if xMax in x1y1:
        yAxissesOfMaxX.append(y1)
    if xMax in x2y2:
        yAxissesOfMaxX.append(y2)
    if xMax in x3y3:
        yAxissesOfMaxX.append(y3)
    if xMax in x4y4:
        yAxissesOfMaxX.append(y4)
    
    sorted_yAxissesOfXMax=sorted(yAxissesOfMaxX)
    yAxisOf_xMax=sorted_yAxissesOfXMax[0]
else:
    if xMax in x1y1:
        yAxisOf_xMax=y1
    elif xMax in x2y2:
        yAxisOf_xMax=y2
    elif xMax in x3y3:
        yAxisOf_xMax=y3
    elif xMax in x4y4:
        yAxisOf_xMax=y4


#print(xMax)
#print(xMin)

yMax=max(y1,y2,y3,y4)
yMin=min(y1,y2,y3,y4)

#these are the coordinates of y=0 coordinates, we will use them while calculating the area between quadriliteral and x axis
xMax_yZero=(xMax,0)
xMin_yZero=(xMin,0)


if (yAxisOf_xMin==sorted_yCoordinates[0] or yAxisOf_xMin==sorted_yCoordinates[1]) and (yAxisOf_xMax==sorted_yCoordinates[0] or yAxisOf_xMax==sorted_yCoordinates[1]):
    # değişecek ---->>>   (x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1)
    wantedArea=(xMin*yAxisOf_xMin + xMin*yAxisOf_xMax + xMax*0 + xMax*0) - (0*xMin + yAxisOf_xMin*xMax + yAxisOf_xMax*xMax + 0*xMin)
    wantedArea=abs(wantedArea*0.5)
    print("%.2f"%wantedArea)
elif(yAxisOf_xMin==sorted_yCoordinates[3] or yAxisOf_xMin==sorted_yCoordinates[2]) and (yAxisOf_xMax==sorted_yCoordinates[3] or yAxisOf_xMax==sorted_yCoordinates[2]):
    wantedArea=(xMin*yAxisOf_xMin + xMin*yAxisOf_xMax + xMax*0 + xMax*0) - (0*xMin + yAxisOf_xMin*xMax + yAxisOf_xMax*xMax + 0*xMin)
    wantedArea=abs(wantedArea*0.5)-areaOfGivenQuadriliteral
    print("%.2f"%wantedArea)
else:
    wantedArea=(xMin*yAxisOf_xMin + xMin*yAxisOf_xMax + xMax*0 + xMax*0) - (0*xMin + yAxisOf_xMin*xMax + yAxisOf_xMax*xMax + 0*xMin)
    wantedArea=abs(wantedArea*0.5)
    print("%.2f"%wantedArea)
















