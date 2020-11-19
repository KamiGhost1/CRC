#include "work.hpp"
#include "crc.h"

int main(int argc, char **argv){
  int mode = testParam(argc, argv);
  CRC a;
  a.start(mode, argc, argv);
  if(mode == 2 || mode == 1 ){
      a.drawing();
  }
  return 0;
}
