#include "Response.h"
#include "Strategy.h"

class Framework
{
private:
  std::pair<int, int> evaluate_simulation(Simulation sim);
  std::pair<int, int> evaluate_response_pair(std::pair<Response, Response> response_pair);
  void record_simulation(Simulation sim);

public:
  void run_simulation(Strategy strategyone, Strategy strategytwo, int nrounds);
  // void run_simulation(Strategy strategyone, Strategy strategytwo);
};
