#include<bits/stdc++.h>
#include "SimModel.h"
#include "SimUtil.h"
#include "SimDiscrete.h"

int main(){
  printf("Compiled & running C++ code with Simmetrix Libs using CMake \n");
  
  SimModel_start();
  Sim_readLicenseFile(NULL);
  
  pNativeModel nm = NULL;
  pProgress p = NULL;
  pGModel g = GM_load("/lore/nathd2/TOMMS_16.0/ITER_He/tomms_io/simModel_result.smd", nm, p);
  
  GM_release(g);
  SimModel_stop();
  
  std::cout<<"Done"<<std::endl;

  return 0;
}
