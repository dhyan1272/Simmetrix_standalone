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
  pGModel g = GM_load("/users/nathd2/2BOX/Box_s1.smd", nm, p);
  pMesh sm =  M_load("/users/nathd2/2BOX/Box_1-case1.sms", g, p);

  //Loop over elements 
  RIter regions = M_regionIter(sm);
  pRegion rgn;
  int count = 0;
  while ((rgn = (pRegion) RIter_next(regions))) {
    count ++;

  }
  RIter_delete(regions);
  std::cout<<"Count regions: "<<count<<std::endl;

  //Loop over vertices
  VIter vertices = M_vertexIter(sm);
  pVertex vtx;
  while ((vtx = (pVertex) VIter_next(vertices))) {
     double xyz[3];
     V_coord(vtx,xyz);
  }
  VIter_delete(vertices);


  M_release(sm);
  GM_release(g);

  SimModel_stop();
  std::cout<<"Done"<<std::endl;
  return 0;
}
