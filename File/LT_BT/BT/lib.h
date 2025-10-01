#ifndef __LIB_H_
#define __LIB_H_

struct Info_t
{
    int STT;
    int id_std;
    char name[100];
    int age;
    char sex[5];
    float math;
    float phys;
    float chem;
    float avr;
};


typedef struct Info_t* (*Get_func)(struct Info_t*, int*);
typedef void(*Active_Func)(struct Info_t*, int);
struct Func
{
    Get_func get;
    Active_Func print;
    Active_Func sort_avr;
    Active_Func sort_name;
};

struct Info_t* std_get(struct Info_t* sv, int*);
void std_print(struct Info_t* sv, int num);
void std_sort_avr(struct Info_t* sv, int num);
void std_sort_name(struct Info_t* sv, int num);
#endif 