def pattern_search(P,I):

    P_0=[]
    P_90=[]
    P_180=[]
    P_270=[]

    for i in range(len(P)):
        temp=""
        for j in range(len(P[0])):
            temp+=(P[i][j])
        P_0.append(temp)

    for i in range(len(P[0])):
        temp=""
        for j in range(len(P)):
            temp+=(P[len(P)-j-1][i])
        P_90.append(temp)

    for i in range(len(P)):
        temp=""
        for j in range(len(P[0])):
            temp+=(P[len(P)-i-1][len(P[0])-j-1])
        P_180.append(temp)

    for i in range(len(P_180[0])):
        temp=""
        for j in range(len(P_180)):
            temp+=(P_180[len(P_180)-j-1][i])
        P_270.append(temp)

    result=False

    for i in range(len(I)):

        if len(P_0)<=len(I) and len(P_0[0])<=len(I[0]):
            if(I[i].count(P_0[0])>0 and result==False):
                for y in [index for index, char in enumerate(I[i]) if I[i][index:index + len(P_0[0])] == P_0[0]]:
                    if result!=False:
                        break
                    x=i
                    k=i
                    result=(x,y,0)
                    for j in range(1,len(P_0)):
                        if k+1>len(I)-1:
                            result=False
                            break
                        if [index for index, char in enumerate(I[k+1]) if I[k+1][index:index + len(P_0[j])] == P_0[j]].count(y)>0:
                            k=k+1
                        else:
                            result=False
                            break

        if len(P_90)<=len(I) and len(P_90[0])<=len(I[0]):
            if(I[i].count(P_90[0])>0 and result==False):
                for y in [index for index, char in enumerate(I[i]) if I[i][index:index + len(P_90[0])] == P_90[0]]:
                    if result!=False:
                        break
                    x=i
                    k=i
                    result=(x,y,90)
                    for j in range(1,len(P_90)):
                        if k+1>len(I)-1:
                            result=False
                            break
                        if [index for index, char in enumerate(I[k+1]) if I[k+1][index:index + len(P_90[j])] == P_90[j]].count(y)>0:
                            k=k+1
                        else:
                            result=False
                            break
        if len(P_180)<=len(I) and len(P_180[0])<=len(I[0]):
            if(I[i].count(P_180[0])>0 and result==False):
                for y in [index for index, char in enumerate(I[i]) if I[i][index:index + len(P_180[0])] == P_180[0]]:
                    if result!=False:
                        break
                    x=i
                    k=i
                    result=(x,y,180)
                    for j in range(1,len(P_180)):
                        if k+1>len(I)-1:
                            result=False
                            break
                        if [index for index, char in enumerate(I[k+1]) if I[k+1][index:index + len(P_180[j])] == P_180[j]].count(y)>0:
                            k=k+1
                        else:
                            result=False
                            break
        if len(P_270)<=len(I) and len(P_270[0])<=len(I[0]):
            if(I[i].count(P_270[0])>0 and result==False):
                for y in [index for index, char in enumerate(I[i]) if I[i][index:index + len(P_270[0])] == P_270[0]]:
                    if result!=False:
                        break
                    x=i
                    k=i
                    result=(x,y,270)
                    for j in range(1,len(P_270)):
                        if k+1>len(I)-1:
                            result=False
                            break
                        if [index for index, char in enumerate(I[k+1]) if I[k+1][index:index + len(P_270[j])] == P_270[j]].count(y)>0:
                            k=k+1
                        else:
                            result=False
                            break
        
    return result