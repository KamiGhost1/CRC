//
// Created by ghost on 19.11.2020.
//

#ifndef CRC_CRC_H
#define CRC_CRC_H


#include "work.hpp"

class CRC{
public:
    void start(int mode, int C, char **V);
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

#endif //CRC_CRC_H
