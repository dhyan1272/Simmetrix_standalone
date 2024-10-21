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
    
    double xyz[4][3];
    double cent[3];
    int x = EN_coord(rgn, xyz);
    EN_centroid	(rgn, cent);
    
    //Debugging
    if (count==0){
      for (int i=0; i<4; i++)
        printf("Vertex coords %d %.15e %.15e %.15e \n", i, xyz[i][0], xyz[i][1], xyz[i][2]);
      printf("Centroid %.15e %.15e %.15e \n", cent[0], cent[1], cent[2]);
    }
    count ++;
  }
  RIter_delete(regions);
  std::cout<<"Count regions: "<<count<<std::endl;

  //Loop over vertices
  count=0;
  VIter vertices = M_vertexIter(sm);
  pVertex vtx;
  while ((vtx = (pVertex) VIter_next(vertices))) {
     double xyz[3];
     V_coord(vtx,xyz);
     count++;
  }
  VIter_delete(vertices);
  std::cout<<"Count Vertices: "<<count<<std::endl;

  M_release(sm);
  GM_release(g);

  SimModel_stop();
  std::cout<<"Done"<<std::endl;
  return 0;
}
