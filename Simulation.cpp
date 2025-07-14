#include "Simulation.h"

Simulation::Simulation(int nrounds)
{
  numrounds = nrounds;
}

void Simulation::updateSimulation(Response strategy1response, Response strategy2response)
{
  strategy1run.push_back(strategy1response);
  strategy2run.push_back(strategy2response);
}
