#include <iostream>
#include <string.h>
#include <cmath>
#include <stdlib.h>

// #define debag true;
// #define main_debag true;
#define pSTEP 5
#define lSTEP 2
#define MAX_MSG 1024

using namespace std;

int testParam(int C, char **V);
int generateErr(int n,int p);
int generateM(int d);
int division(int dividend, int devisor);
char *toBin(int num);
int deg(int num);
int toDec(char *bin);
int toDecStr(string bin);
char *nullStr(int size);
char *strToChar(string m);
