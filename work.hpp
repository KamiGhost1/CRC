#include <iostream>
#include <string.h>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <fstream>


//#define once_loop
// #define debag true;
// #define main_debag true;
//#define per_debag
//#define err_debug
#define pSTEP 2
#define lSTEP 1
#define MAX_MSG 1024
#define MAX_L 10

using namespace std;

double random(double min, double max);
int testParam(int C, char **V);
int generateErr(int n,int p);
int generateM(int d);
int division(int dividend, int divisor);
char *toBin(int num);
int deg(int num);
int toDec(char *bin);
int toDec(string bin);
char *nullStr(int size);
char *strToChar(string m);
