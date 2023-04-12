#include <stdio.h>
#include "lab_1.h"

void hello_ceng(){
    int point1,point2,course_code,lab_exam_count;

    scanf("%d %d %d %d",&course_code,&lab_exam_count,&point1,&point2);

    printf("I got %d from the first and %d from the second lab exam of CENG%d.\n"
           "There will be %d lab exams in total.\n"
           "If I get two zero grades in the forthcoming lab exams, I\'m going to get NA.", point1, point2, course_code, lab_exam_count);
    
}

void calculator(){

    float number1;
    float number2;
    float result;
    char op;

    scanf("%f %f %c",&number1,&number2,&op);

    switch (op) {
        case '/':
            result=number1/number2;
            break;
        case '*':
            result=number1*number2;
            break;
        case '+':
            result=number2+number1;
            break;
        case '-':
            result=number1-number2;
            break;
    }
    printf("Enter first number: %f\n",number1);
    printf("Enter second number: %f\n",number2);
    printf("Enter operator: %c\n",op);
    printf("Result: %.2f",result);

}

void character_processing(){

    int i;
    int j;
    int count;
    char ch;
    scanf("%d ",&i);

    count=0;
    for (j = 0; j < i; ++j) {
        scanf("%c",&ch);
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
            printf("%c",ch);
            if(ch%3==0){
                count++;
            }
        }
    }
    printf(" %d",count);

}