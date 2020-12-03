#include "work.hpp"
#include "crc.h"

int main(int argc, char **argv){
  int mode = testParam(argc, argv);
  CRC a;
  if(mode <=3){
      a.start(mode, argc, argv);
      if(mode == 2 || mode == 1 ){
          a.drawing();
      }
  }
  if(mode == 4){
      a.expectedValue(argv[2],argv[4]);
  }
  return 0;
}
