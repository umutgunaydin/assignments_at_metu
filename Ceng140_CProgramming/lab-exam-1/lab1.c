#include <stdio.h>

/*
    This function takes 4 inputs from stdin and prints 
    in the string given in description
*/
void hello_ceng(){
    
    int course_code;
    int lab_exam_count;
    float point1;
    float point2;
    
    scanf("%d %d %f %f",&course_code,&lab_exam_count,&point1,&point2);
    
    printf("I got %.2f from the first and %.2f from the second lab exam of CENG%d.\n"
    "There will be %d lab exams in total.\n"
    "If I get two zero grades in the forthcoming lab exams, I'm going to get NA.",point1,point2,course_code,lab_exam_count);


}

/* 
    This function takes an integer from stdin
    and checks if it is a square of an integer or not
*/
void square_check(){
    
    int number;
    int i;
    
    scanf("%d",&number);
   
   for(i=1;i<=number;i++){
       if(i*i==number){
           printf("Square of %d",i);
           return;
       }
   }
   printf("Not a square");
    
}

/*
    This function takes a number N and N integers after that. Checks if the
    given series is a zigzag and narrowing or not.
*/
void zigzag_check(){
    
    int n;
    int i;
    int peak;
    int numbers[100];
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        scanf(" %d",&numbers[i]);
    }
    
    peak=numbers[0];
    
    for(i=1;i<n-1;i++){
        if(i%2==1){
            if(numbers[i]<numbers[i-1]&&numbers[i]<numbers[i+1]){
                
            }else{
                printf("Not a zigzag");
                return;
            }
        }else if(i%2==0){
            if(numbers[i]>numbers[i-1]&&numbers[i]>numbers[i+1]){
                
            }else{
                printf("Not a zigzag");
                return;
            }
        }
    }
    
    for(i=1;i<n;i++){
        if(numbers[i]>peak){
            printf("Zigzag but not narrowing");
            return;
        }
    }
    
    printf("Narrowing zigzag");

}

/*
    This function takes a number N and N floating-points after that. Takes
    3 more floating points. Calculates the average grade using N+3 grades.
    Prints letter grades of the last 3 grades.
*/
void letter_grades(){
    
    int n;
    int i;
    float point;
    float sum;
    float avg;
    float point1;
    float point2;
    float point3;
    scanf("%d",&n);
    sum=0;
    
    for(i=0;i<n;i++){
        scanf(" %f",&point);
        sum+=point;    
    }
    scanf(" %f",&point1);
    scanf(" %f",&point2);
    scanf(" %f",&point3);
    sum+=point1+point2+point3;
    avg=sum/(n+3);
    
    printf("Average: %.2f. Letter grades:",avg);
        
        if (point1-avg<-20){
            printf(" FF");
        }else if (point1-avg>=-20 && point1-avg<-15){
            printf(" FD");
        }else if (point1-avg>=-15 && point1-avg<-10){
            printf(" DD");
        }else if (point1-avg>=-10 && point1-avg<-5){
            printf(" DC");
        }else if(point1-avg>=-5 && point1-avg<5){
            printf(" CC");
        }else if (point1-avg>=5 && point1-avg<10){
            printf(" CB");
        }else if (point1-avg>=10 && point1-avg<15){
            printf(" BB");
        }else if (point1-avg>=15 && point1-avg<20){
            printf(" BA");
        }else if (point1-avg>=20){
            printf(" AA");
        }
    
        if (point2-avg<-20){
            printf(" FF");
        }else if (point2-avg>=-20 && point2-avg<-15){
            printf(" FD");
        }else if (point2-avg>=-15 && point2-avg<-10){
            printf(" DD");
        }else if (point2-avg>=-10 && point2-avg<-5){
            printf(" DC");
        }else if(point2-avg>=-5 && point2-avg<5){
            printf(" CC");
        }else if (point2-avg>=5 && point2-avg<10){
            printf(" CB");
        }else if (point2-avg>=10 && point2-avg<15){
            printf(" BB");
        }else if (point2-avg>=15 && point2-avg<20){
            printf(" BA");
        }else if (point2-avg>=20){
            printf(" AA");
        }

        if (point3-avg<-20){
            printf(" FF");
        }else if (point3-avg>=-20 && point3-avg<-15){
            printf(" FD");
        }else if (point3-avg>=-15 && point3-avg<-10){
            printf(" DD");
        }else if (point3-avg>=-10 && point3-avg<-5){
            printf(" DC");
        }else if(point3-avg>=-5 && point3-avg<5){
            printf(" CC");
        }else if (point3-avg>=5 && point3-avg<10){
            printf(" CB");
        }else if (point3-avg>=10 && point3-avg<15){
            printf(" BB");
        }else if (point3-avg>=15 && point3-avg<20){
            printf(" BA");
        }else if (point3-avg>=20){
            printf(" AA");
        }


}