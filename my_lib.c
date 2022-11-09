//
// Created by Srutadeva das on 2022/9/28.
//

#include <stdio.h>
#include "my_lib.h"


int hello_world() {
    printf("Hello World!\n");

    return 0;
}


void try_array() {
    int a[3][4] = {
            {0, 1, 2,  3},
            {4, 5, 6,  7},
            {8, 9, 10, 11}
    };

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);

    printf("The size of array a is %lu\n", sizeof a);

    printf("%d", a[2][4]);  // 数组越界

}


int mv_bit() {
    int n = 1;
    for (int i = 1; i <= 32; ++i)
        printf("1 << %d = %d\n", i, n << i);

    return 0;
}


int arr_edge() {
    int a[2] = {2, 3};
    for (int i = 0; i < 20; i++)  // 打印走出数组边界的元素
        printf("%d\n", a[i]);

    return 0;
}


/* 求幂 */
long long power(int base, int n) {
    long p = 1;

    for (int i = 1; i <= n; ++i)
        p = p * base;

    return p;
}

/* 统计输入的行数、单词数 */
int wc() {
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);

    return 0;
}


int countChar() {
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%0ld\n", nc);

    return 0;
}


int tryGetchar() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}

int temperature() {
    int fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 31));

    return 0;
}

int say_hello(struct Student *student) {
    printf("Hello, everyone! My name is %s. I am %d years old. ", student->name, student->age);
    printf("My student number is %s. ", student->student_number);
    if (student->is_validated)
        printf("I am in school. \n");
    else
        printf("I am not in school. \n");

    return 0;
}

int try_struct() {

    struct Student student;
    student.name = "Zhipeng";
    student.age = 29;
    student.student_number = "2011302660011";
    student.is_validated = True;

    say_hello(&student);

    struct Student *p;
    p = &student;

    p->is_validated = False;

    say_hello(&student);

    return 0;
}


int try_typedef() {
    Person person;
    person.name = "Sruta";
    person.age = 29;
    person.tel = "15120001810";
    person.gender = MALE;

    printf("%s, %d years old, the tel is %s. ", person.name, person.age, person.tel);
    switch (person.gender) {
        case MALE:
            printf("He is a guy. \n");
            break;
        case FEMALE:
            printf("She is a girl. \n");
            break;
        case OTHER:
            printf("other. \n");
            break;
    }

    return 0;
}

int try_scanf() {
    char name[50];
    int age;

    printf("Please input your name: ");
    scanf("%s", name);

    printf("And now please input your age: ");
    scanf("%d", &age);

    printf("Hello %s, you are %d years old. \n", name, age);

    return 0;
}

int write_to_file() {
    FILE *fp = NULL;

    // write into file
    fp = fopen("/tmp/test.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);

    return 0;
}

int read_from_file() {
    FILE *fp = NULL;
    char buff[255];

    fp = fopen("/tmp/test.txt", "r");
    fscanf(fp, "%s", buff);  // 读取，直到遇到空格
    printf("1: %s\n", buff );

    fgets(buff, 255, (FILE*)fp);  // 继续读取，直到行尾
    printf("2: %s\n", buff );

    fgets(buff, 255, (FILE*)fp);
    printf("3: %s\n", buff );  // 完整地读取第二行
    fclose(fp);

    return 0;
}


int try_macros() {
    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );  // 打印当前行号，即222
    printf("ANSI :%d\n", __STDC__ );

    return 0;
}
