#include "Response.h"
#include "Strategy.h"

class Framework
{
private:
  void evaluate_simulation();
  void record_simulation();

public:
  void run_simulation(Strategy strategyone, Strategy strategytwo, int nrounds);
  // void run_simulation(Strategy strategyone, Strategy strategytwo);
};
