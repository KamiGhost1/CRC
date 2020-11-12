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
      int div = division(dividend,divisor);
      cout<<div<<endl;
    }
    if(!strcmp(V[1],"--test")){
      cout<<((float)5/10)<<endl;
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
    }
    if(!strcmp(V[1],"--msg")){
      int d;
      cout<<"Enter deg: ";
      cin>>d;
      cout<<generateM(d)<<endl;
    }
    if(!strcmp(V[1],"--start")){
      srand(time(0));
      int p,n,nE,l;
      float epsilon,Pe;
      string gx;
      int msg,ax,bx,e,Gx,Ner;
      char *Ax;
      long int tick =0;
      cout<<"Enter epsilon: ";
      cin>>epsilon;
      cout<<"Enter p: ";
      cin>>p;
      cout<<"Enter gx(*1101): ";
      cin>>gx;
      cout<<"Enter l: ";
      cin>>l;
      n=int(9/(4*pow(epsilon,2)))+1;
      cout<<"N:"<<n<<endl;
      nE = 0;
      Ner = 0;
      Gx = toDecStr(gx);
      int err_size;
      for(int j = l-lSTEP;j<=l+(lSTEP*10);j++){
        err_size = j+deg(Gx)-1;
        for(int i = 0;i<n;i++){
          msg = generateM(j);
          msg*=pow(2,(deg(Gx)-1));
          ax = division(msg,Gx);
          msg = msg^ax;
          e = generateErr(err_size,p);
          bx = msg^e;
          bx = division(bx,Gx);
          if(bx == 0 && e > 0){
            nE++;
          }
          if (bx != 0){
            Ner++;
          }
          #ifdef main_debag
          cout<<'\n'<<"debag info " <<i<<'\n'<<endl;
          cout<<"Gx:"<<Gx<<endl;
          cout<<"ax:"<<ax<<endl;
          cout<<"e:"<<e<<endl;
          cout<<"bx:"<<bx<<endl;
          cout<<'\n'<<"end"<<'\n'<<endl;
          #endif
        }
        Pe = ((float)nE/n);
        cout<<nE<<"\t"<<Pe<<"\t"<<p<<"\t"<<j<<endl;
        nE = 0;
        Ner = 0;
        p+=pSTEP;
        if(p>100){
          break;
        }
      }
    }
  }
  exit(1);
}

int division(int dividend, int divisor){
  if(dividend < divisor){
    return dividend;
  };
  int size = deg(dividend);
  if(dividend==divisor){
    return dividend;
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
      delete(m);
      return 0;
    }
  }
  dividend = toDec(m);
  delete(m);
  return dividend;
}

int generateErr(int n,int p){
  int rand_num;
  char *e = new char[n];
  for(int i = 0;i<n;i++){
    rand_num = 1+rand()%100;
    if(rand_num<=p){
      e[i]='1';
    }else{
      e[i]='0';
    }
  }
  rand_num = toDec(e);
  delete(e);
  return rand_num;
}

int generateM(int d){
  int m;
  do{
    m = 1+rand()%MAX_MSG;
  }while(deg(m)>d);
  return m;
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
