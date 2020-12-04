#include "work.hpp"


int testParam(int C, char **V){
  if(C == 1){
    cout<<"hello. its CRC modeling programm"<<endl;
    exit(0);
  }
  if(C == 2){
    if(!strcmp(V[1],"-h")){
      cout<<"\n\tCRC HELP\n"<<endl;
      cout<<"./e --start - basic mode"<<endl;
      cout<<"./e --start -m - basic mode with new sheme"<<endl;
      cout<<"./e --start --once - calculate 1 length"<<endl;
      cout<<"./e --start --once -m - calculate 1 length with new sheme"<<endl;
      cout<<"./e --start --only_once - calculate 1 length and 1 p"<<endl;
      cout<<"./e --words - all wolds"<<endl;
      cout<<"./e --div - coder"<<endl;
      cout<<"./e --bin - binary"<<endl;
      cout<<"./e --test - random check"<<endl;
      cout<<"./e --msg - deg of msg"<<endl;
      cout<<"./e --err - generate err"<<endl;
      cout<<""<<endl;
      exit(0);
    }
    if(!strcmp(V[1],"--bin")){
      cout<< "Enter num to test toBin func"<<endl;
      int num;
      cin>>num;
      char *bin = toBin(num,10);
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
      int div = division(dividend,divisor);
      cout<<div<<endl;
      exit(0);
    }
    if(!strcmp(V[1],"--test")){
        srand(time(0));
        for(int i =0;i<10;i++){
            cout<<random(0, MAX_MSG)/MAX_MSG<<endl;

        }
        exit(0);
    }
    if(!strcmp(V[1],"--err")){
      int n,p,i;
      cout<<"Enter n ";
      cin>>n;
      cout<<"Enter p ";
      cin>>p;
      cout<<"Enter i ";
      cin>>i;
      srand(time(0));
      for(int j = 0;j<i;j++){
        cout<<generateErr(n,p)<<endl;
      }
      exit(0);
    }
    if(!strcmp(V[1],"--msg")){
      int d;
      cout<<"Enter deg: ";
      cin>>d;
      cout<<generateM(d)<<endl;
    }
    if(!strcmp(V[1],"--start")){
        return 1;
    }
    if(!strcmp(V[1],"--words")){
        int length;
        string Gx;
        cout<<"enter length: ";
        cin>>length;
        cout<<"enter gx(*1101): ";
        cin>>Gx;
        wordsList(length,toDec(Gx));
        exit(0);
    }
  }
  if(C==3){
      if(!strcmp(V[1],"--start") && !strcmp(V[2],"-m")){
          return 1;
      }
      if(!strcmp(V[1],"--start") && !strcmp(V[2],"--once")){
          return 2;
      }
      if(!strcmp(V[1],"--start") && !strcmp(V[2],"--only_once")){
          return 3;
      }
  }
    if(C==4){
        if(!strcmp(V[1],"--start") && !strcmp(V[2],"--once") && !strcmp(V[3],"-m")){
            return 2;
        }
        if(!strcmp(V[1],"--start") && !strcmp(V[2],"--only_once") && !strcmp(V[3],"-m")){
            return 3;
        }
    }
    if(C==5){
        if(!strcmp(V[1],"-i") && !strcmp(V[3],"-c")){
            return 4;
        }
    }
  cout<<"unknown params, use -h"<<endl;
  exit(1);
}

double random(double min, double max){
    return (double)(rand())/RAND_MAX*(max - min) + min;
}

int division(int dividend, int divisor){
  if(deg(dividend) < deg(divisor)){
    return dividend;
  };
  if(dividend==divisor){
    return 0;
  }
  int size = deg(dividend);
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
      delete(m);
      return 0;
    }
  }
  dividend = toDec(m);
  delete(m);
  return dividend;
}

int generateErr(int n,int p){
  double rand_num;
  int Ve;
  char *e = new char[n];
  double PP = (double)p/100;
  for(int i = 0;i<n;i++){
    rand_num = random(0,MAX_MSG)/MAX_MSG; //TODO 0-1
    if(rand_num <= PP){
      e[i]='1';
    }else{
      e[i]='0';
    }
  }
  Ve = toDec(e);
#ifdef err_debug
  cout<<p<<"   "<<PP<<"  "<<rand_num<<"  "<<e<<endl;
#endif
  delete(e);
  return Ve;
}

void wordsList(int length, int gx){
    int msg,cx;
    char *mg;
    for(int i=0;i<pow(2,length);i++){
        msg = i*pow(2,(deg(gx)-1));
        cx = division(msg,gx);
        msg = msg^cx;
        mg = toBin(msg,length+deg(gx)-1);
        cout<<mg<<endl;
        delete(mg);
    }
}

int generateErr(int n,int p, int msg){
    double rand_num;
    int Ve;
    char *e = new char[n];
    double PP = (double)p/100;
    char *mg = toBin(msg,n);
    for(int i = 0;i<n;i++){
        rand_num = random(0,MAX_MSG)/MAX_MSG; //TODO 0-1
        if(rand_num <= PP && mg[i]=='1'){
//            cout<<"yep"<<endl;
            e[i]='1';
        }else{
            e[i]='0';
        }
    }
    Ve = toDec(e);
#ifdef err_debug
    cout<<p<<"   "<<PP<<"  "<<rand_num<<"  "<<e<<endl;
#endif
    delete(mg);
    delete(e);
    return Ve;
}

int generateM(int d){
  int m;
  do{
    m = 1+rand()%MAX_MSG;
  }while(deg(m)>d);
  return m;
}

char *toBin(int num){
  int mod,size;
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

char *toBin(int num, int length){
    int mod;
    char *bin = new char[length];
    int j = length -1;
    for(int i = 0;i<length;i++){
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

int toDec(string bin){
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
