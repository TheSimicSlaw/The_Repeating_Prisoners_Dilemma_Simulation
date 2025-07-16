#include "Simulation.h"

Simulation::Simulation(int nrounds)
{
  numrounds = nrounds;
}

void Simulation::updateSimulation(Response strategy1response, Response strategy2response)
{
  run.push_back(std::pair<Response, Response>(strategy1response, strategy2response));
}
