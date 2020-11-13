#include "work.hpp"

class CRC{
public:
    void start(int mode);
    void drawing();
    void write_graph();
private:
    int p,n,nE,l;
    float epsilon,Pe;
    string gx,name;
    int msg,ax,e,Gx,Ner, graph;
    vector <pair<float,int>> vec;
    vector <string> graph_names;
};

void CRC::write_graph() {
    ofstream f;
    name = "graphs/graph";
    name+=(graph+'0');
    graph_names.push_back(name);
    cout<<name<<endl;
    f.open(name);
    for(int i=0;i<vec.size();i++){
        f<<vec[i].second<<"  "<<vec[i].first<<endl;
    }
    vec.clear();
    f.close();
}

void CRC::drawing() {
    FILE *gp = popen("gnuplot -persist","w");
    string cmd = "plot ";
    if(gp == NULL){
        cout<<"Error"<<endl;
        exit(1);
    }else{
        for(int i=0;i<graph_names.size();i++){
            cmd += '"'+graph_names[i]+'"'+" with lines, ";
        }
        cmd+='\n';
        char *gpcmd;
        gpcmd = strToChar(cmd);
        fprintf(gp, gpcmd);
        delete(gpcmd);
        pclose(gp);
    }
}

void CRC::start(int mode){
    if(mode == 1 || mode ==2 || mode ==3){
        srand(time(0));
        cout<<"Enter epsilon: ";
        cin>>epsilon;
        cout<<"Enter p(<=100): ";
        cin>>p;
        cout<<"Enter gx(*1101): ";
        cin>>gx;
        cout<<"Enter l(<=10): ";
        cin>>l;
        n=int(9/(4*pow(epsilon,2)))+1;
#ifdef per_debag
        cout<<"N:"<<n<<endl;
#endif
        Gx = toDec(gx);
        graph = 0;
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
            graph++;
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
#ifdef per_debag
                cout<<nE<<";"<<Pe<<";"<<p<<";"<<l<<endl;
#endif
                vec.push_back({Pe,p});
                nE = 0;
                Ner = 0;
                p+=pSTEP;
                if(mode == 3){
                    cout<<vec[0].second<<"  "<<vec[0].first<<endl;
                    break;
                }
            }
            p=pLoop;
            l++;
            if(mode ==1 || mode ==2){
                CRC::write_graph();
            }
            if(mode ==2 || mode ==3){
                break;
            }
        }
    }
}
int main(int argc, char **argv){
  int mode = testParam(argc, argv);
  CRC a;
  a.start(mode);
  if(mode == 2 || mode == 1 ){
      a.drawing();
  }
  return 0;
}
