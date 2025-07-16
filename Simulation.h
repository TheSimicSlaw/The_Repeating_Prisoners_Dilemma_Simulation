#include <vector>
#include "Response.h"

class Simulation
{
public:
  int numrounds;
  std::vector<std::pair<Response, Response>> run;
  Simulation(int nrounds);
  void updateSimulation(Response strategy1response, Response strategy2response);
};
