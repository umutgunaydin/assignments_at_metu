#ifndef QUESTION_H
#define QUESTION_H

/* Do not modify this file. */
struct Person {
    char initial;
    int age;
};

void set_age(struct Person* p, int new_age);
void print_info(struct Person* p);
struct Person* create_person(char initial, int age);
void print_age(struct Person* p);
void my_print(struct Person* p);

#endif
