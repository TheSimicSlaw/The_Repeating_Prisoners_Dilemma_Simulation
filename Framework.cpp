#include "Framework.h"
#include "Simulation.h"

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

  evaluate_simulation();
  record_simulation();
}