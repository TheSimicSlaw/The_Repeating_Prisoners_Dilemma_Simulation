#include "Framework.h"
#include "Simulation.h"
#include <numeric>

void Framework::run_simulation(Strategy strategyone, Strategy strategytwo, int nrounds)
{
  strategyone.StartNewSimulation(nrounds);
  strategytwo.StartNewSimulation(nrounds);

  Simulation thisrun(nrounds);

  Response strategyoneresponse = strategyone.initialResponse();
  Response strategytworesponse = strategytwo.initialResponse();
  thisrun.updateSimulation(strategyoneresponse, strategytworesponse);

  for (int roundnum = 0; roundnum < nrounds; roundnum++)
  {
    strategyoneresponse = strategyone.continuedResponse(strategytworesponse);
    strategytworesponse = strategytwo.continuedResponse(strategyoneresponse);
    thisrun.updateSimulation(strategyoneresponse, strategytworesponse);
  }

  record_simulation(thisrun);
}

std::pair<int, int> Framework::evaluate_simulation(Simulation sim)
{
  std::vector<std::pair<Response, Response>> sim_run = sim.run;
  std::pair<int, int> out = std::accumulate(sim_run.begin(), sim_run.end(), std::pair<int, int>(0, 0), evaluate_response_pair);
}

std::pair<int, int> Framework::evaluate_response_pair(std::pair<Response, Response> response_pair)
{
  if (response_pair.first == COOPERATE)
  {
    if (response_pair.second == COOPERATE)
    {
      return std::pair<int, int>(3, 3);
    }
    else
    {
      return std::pair<int, int>(0, 5);
    }
  }
  else
  {
    if (response_pair.second == COOPERATE)
    {
      return std::pair<int, int>(5, 0);
    }
    else
    {
      return std::pair<int, int>(1, 1);
    }
  }
}

void Framework::record_simulation(Simulation sim)
{
  auto results = evaluate_simulation(sim);
}