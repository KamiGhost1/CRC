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
      dividend*=pow(2,(deg(divisor)-1));
      char *div = division(dividend,divisor);
      cout<<div<<endl;
    }
    if(!strcmp(V[1],"-start")){
      int epsilon,p;
    }
  }
  exit(1);
}

char *division(int dividend, int divisor){
  if(dividend < divisor){
    return toBin(dividend);
  };
  int size = deg(dividend);
  if(dividend==divisor){
    return nullStr(deg(dividend));
  }
  string div = toBin(dividend);
  string dis = toBin(divisor);
  char *m = strToChar(div);
  #ifdef debag
  cout<<div<<endl;
  cout<<dis<<endl;
  #endif
  int size_j,key;
  key = 0;
  size -= deg(divisor)-1;
  for(int i =0;i<size;i++){
    size_j=i+deg(divisor);
    if(m[i]=='0'){
      continue;
    }else{
      for(int j=i;j<size_j;j++){
        if(m[j]==dis[key]){
          m[j]='0';
        }else{
          m[j]='1';
        }
        key++;
      }
      key=0;
    }
    #ifdef debag
    cout<<i<<"  m:"<<m<<endl;
    #endif
    if(toDec(m)==0){
      return nullStr(deg(dividend));
    }
  }
  return strToChar(m);
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
    if(bin[i]=='1'){
      dec += pow(2,j);
    }
    j--;
  }
  return dec;
}

int toDecStr(string bin){
  int size = bin.length();
  int dec = 0;
  int j = size-1;
  for(int i=0;i<size;i++){
    if(bin[i]=='1'){
      dec += pow(2,j);
    }
    j--;
  }
  return dec;
}
char *nullStr(int size){
  char *msg = new char[size];
  for(int i=0;i<size;i++){
    msg[i]='0';
  }
  return msg;
}
char *strToChar(string m){
  char *mes = new char[m.length()];
  for(int i=0;i<m.length();i++){
    mes[i]=m[i];
  }
  return mes;
}
