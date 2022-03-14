#pragma once
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h> /*for clrscr()*/

 struct Job
{
    int *operation; // 01,02,03,04,...
    int *machine; // 1,2,3,4,5,6,7,... // ver como posso sem ter o valor fixo de 100
    int *cycletime;
    struct Job* next;
    struct Job* prev;
}*init, * final;

int MainFunction();
//struct Job* GetValuesToInsertNewJob();
struct Job* CreateJob();
