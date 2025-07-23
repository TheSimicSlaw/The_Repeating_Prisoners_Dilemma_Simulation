#include "Simulation.h"

Simulation::Simulation(int nrounds)
{
  numrounds = nrounds;
}

void Simulation::updateSimulation(Response strategy1response, Response strategy2response)
{
  run.push_back(std::pair<Response, Response>(strategy1response, strategy2response));
}

std::pair<Response, Response> Simulation::getPair(int index)
{
  return run.at(index);
}

std::vector<std::pair<Response, Response>> Simulation::getRun()
{
  return run;
}
