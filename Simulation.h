#include <vector>
#include "Response.h"

class Simulation
{
private:
  std::vector<std::pair<Response, Response>> run;

public:
  int numrounds;
  Simulation(int nrounds);
  void updateSimulation(Response strategy1response, Response strategy2response);
  std::pair<Response, Response> getPair(int index);
  std::vector<std::pair<Response, Response>> getRun();
};
