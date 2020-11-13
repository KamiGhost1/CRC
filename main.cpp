#include "work.hpp"


int main(int argc, char **argv){
  int mode = testParam(argc, argv);
  if(mode == 1 || mode ==2 || mode ==3){
      srand(time(0));
      int p,n,nE,l;
      float epsilon,Pe;
      string gx;
      int msg,ax,e,Gx,Ner;
      cout<<"Enter epsilon: ";
      cin>>epsilon;
      cout<<"Enter p(<=100): ";
      cin>>p;
      cout<<"Enter gx(*1101): ";
      cin>>gx;
      cout<<"Enter l(<=10): ";
      cin>>l;
      n=int(9/(4*pow(epsilon,2)))+1;
      cout<<"N:"<<n<<endl;
      Gx = toDec(gx);
      int err_size,count,max_count;
      count = l-lSTEP;
      if(count<=0){
          count = 1;
      }
      nE = p;
      max_count = 1;
      do{
          nE+=pSTEP;
          max_count++;
      }while(nE<100);
      nE=0;
      Ner=0;
      max_count+=count;
      int pLoop = p;
      for(int k = l;k<=MAX_L;k++){
          for(int j = count;j<max_count;j++){
              err_size = j+deg(Gx)-1;
              for(int i = 0;i<n;i++){
                  msg = generateM(l);
                  msg*=pow(2,(deg(Gx)-1));
                  ax = division(msg,Gx);
                  msg = msg^ax;
                  e = generateErr(err_size,p);
                  ax = msg^e;
                  ax = division(ax,Gx);
                  if(ax == 0 && e > 0){
                      nE++;
                  }
                  if (ax != 0){
                      Ner++;
                  }
                  #ifdef main_debag
                  cout<<'\n'<<"debag info " <<i<<'\n'<<endl;
                  cout<<"Gx:"<<Gx<<endl;
                  cout<<"ax:"<<ax<<endl;
                  cout<<"e:"<<e<<endl;
                  cout<<'\n'<<"end"<<'\n'<<endl;
                  #endif
              }
              Pe = ((float)nE/n);
              cout<<nE<<";"<<Pe<<";"<<p<<";"<<l<<endl;
              nE = 0;
              Ner = 0;
              p+=pSTEP;
              if(mode == 3){
                  break;
              }
          }
          p=pLoop;
          l++;
        if(mode ==2 || mode ==3){
            break;
        }
      }
  }
  return 0;
}
