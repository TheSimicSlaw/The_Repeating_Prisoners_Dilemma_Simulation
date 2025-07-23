#include "Response.h"
#include "Simulation.h"
#include "Strategy.h"
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
using std::pair;
using std::string;

class Framework
{
private:
  pair<int, int> evaluate_simulation(Simulation sim);
  pair<int, int> evaluate_response_pair(pair<Response, Response> response_pair);
  void record_simulation(Simulation sim, Strategy strategyone, Strategy strategytwo);

public:
  void run_simulation(Strategy strategyone, Strategy strategytwo, int nrounds);
  // void run_simulation(Strategy strategyone, Strategy strategytwo);
};
