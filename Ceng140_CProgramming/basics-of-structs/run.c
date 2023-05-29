#include <stdlib.h>
#include <stdio.h>
#include "question.h"

/* Do not modify this file.*/
int main(){
    struct Person *p1, *p2;

    p1 = create_person('A', 35);
    p2 = create_person('K', 13);
    set_age(p1, 27);
    print_info(p1);
    print_info(p2);
    
    return 0;
}
