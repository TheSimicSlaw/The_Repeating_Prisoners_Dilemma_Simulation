#include "Framework.h"

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

  record_simulation(thisrun, strategyone, strategytwo);
}

pair<int, int> Framework::evaluate_simulation(Simulation sim)
{
  std::vector<pair<Response, Response>> sim_run = sim.getRun();
  pair<int, int> out = std::accumulate(sim_run.begin(), sim_run.end(), pair<int, int>(0, 0), evaluate_response_pair);
}

pair<int, int> Framework::evaluate_response_pair(pair<Response, Response> response_pair)
{
  if (response_pair.first == COOPERATE)
  {
    if (response_pair.second == COOPERATE)
    {
      return pair<int, int>(3, 3);
    }
    else
    {
      return pair<int, int>(0, 5);
    }
  }
  else
  {
    if (response_pair.second == COOPERATE)
    {
      return pair<int, int>(5, 0);
    }
    else
    {
      return pair<int, int>(1, 1);
    }
  }
}

void Framework::record_simulation(Simulation sim, Strategy strategyone, Strategy strategytwo)
{
  pair<int, int> results = evaluate_simulation(sim);

  string strat1name = strategyone.strategyName;
  string strat2name = strategytwo.strategyName;
  bool strat1_first = strat1name < strat2name;
  string filename = "simulation_1_" + ((strat1_first) ? strat1name + "_" + strat2name : strat2name + "_" + strat1name);
  std::ofstream sim_file;
  sim_file.open(filename);
  if (sim_file.is_open())
  {
    int width = ((strat1name.length() > strat2name.length()) ? strat1name : strat2name).length() + 2;
    if (width < 11)
    {
      width = 11;
    }
    sim_file << std::setw(width) << ((strat1_first) ? strat1name : strat2name) << std::setw(width) << ((!strat1_first) ? strat1name : strat2name);
    sim_file << std::setw(width) << ((strat1_first) ? results.first : results.second) << std::setw(width) << ((!strat1_first) ? results.first : results.second) << "\n";

    pair<Response, Response> *currpair;
    pair<int, int> currpoints;
    for (int i = 0; i < sim.numrounds; i++)
    {
      currpair = &sim.getPair(i);
      currpoints = evaluate_response_pair(*currpair);
      sim_file << std::setw(width) << ((strat1_first) ? (*currpair).first : (*currpair).second) << std::setw(width) << ((!strat1_first) ? (*currpair).first : (*currpair).second);
      sim_file << std::setw(width) << ((strat1_first) ? (*currpair).first : (*currpair).second) << std::setw(width) << ((!strat1_first) ? (*currpair).first : (*currpair).second) << "\n";
    }
  }
  else
  {
    std::cerr << "sim_file \"" << filename << "\" is not open." << std::endl;
  }
}
