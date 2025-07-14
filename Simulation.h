#include <vector>
#include "Response.h"

class Simulation
{
public:
  int numrounds;
  std::vector<Response> strategy1run;
  std::vector<Response> strategy2run;
  Simulation(int nrounds);
  void updateSimulation(Response strategy1response, Response strategy2response);
};
