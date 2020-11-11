#include "work.hpp"


int testParam(int C, char **V){
  if(C == 1){
    cout<<"hello. its CRC modeling programm"<<endl;
    exit(0);
  }
  if(C == 2){
    if(!strcmp(V[1],"-h")){
      cout<<"help"<<endl;
      exit(0);
    }
    if(!strcmp(V[1],"--bin")){
      cout<< "Enter num to test toBin func"<<endl;
      int num;
      cin>>num;
      char *bin = toBin(num);
      cout<<bin<<endl;
      num = toDec(bin);
      cout<<num<<endl;
      delete(bin);
      exit(0);
    }
    if(!strcmp(V[1],"--div")){
      int dividend,divisor;
      cout<<"Enter dividend ";
      cin>>dividend;
      cout<<"Enter divisor ";
      cin>>divisor;

    }
    if(!strcmp(V[1],"-start")){
      int epsilon,p;
    }
  }
  exit(1);
}

char *division(int dividend, int divisor){
  if(dividend < divisor){
    return NULL;
  };
  return NULL;
}

char *toBin(int num){
  int mod,div,size;
  size = deg(num);
  char *bin = new char[size];
  int j = size -1;
  for(int i = 0;i<size;i++){
    mod = num%2;
    num = num / 2;
    if(mod ==1){
      bin[j]='1';
    }else if(mod == 0){
      bin[j]='0';
    }
    j--;
  }
  return bin;
}


int deg(int num){
   int size = (int)(log2(num))+1;
   return size;
}

int toDec(char *bin){
  string s=bin;
  int size = s.length();
  int dec = 0;
  int j = size-1;
  for(int i=0;i<size;i++){
    cout<<"bin: "<<bin[i]<<"  j:"<<j<<endl;
    if(bin[i]=='1'){
      dec += pow(2,j);
    }
    j--;
  }
  return dec;
}
