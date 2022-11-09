//
// Created by Srutadeva das on 2022/9/28.
//

#ifndef HELLO_C_MY_LIB_H
#define HELLO_C_MY_LIB_H

#endif //HELLO_C_MY_LIB_H

#define LOWER 0
#define UPPER 300
#define STEP 20

#define IN  1
#define OUT 0

#define True 1
#define False 0

typedef enum Genders {
    MALE, FEMALE, OTHER
} Gender;


struct Student {
    char *name;
    int age;
    char *student_number;
    int is_validated;
};

typedef struct Persons {
    char *name;
    int age;
    char *tel;
    Gender gender;
} Person;

int hello_world();

int temperature();

int tryGetchar();

int countChar();

int wc();

long long power(int, int);

int mv_bit();

int arr_edge();

void try_array();

double avg_of_array(int array[]);

int try_struct();

int try_typedef();

int try_scanf();

int write_to_file();

int read_from_file();

int try_macros();
