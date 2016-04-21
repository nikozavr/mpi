#include <mpi.h>

#include "worker.h"

#include <assert.h>
#include <vector>

#include "job.h"

#define log std::cout << "Worker " << rank << ": "

namespace qs {

  void startWorker(int rank) {
      qh::Point p;
      qh::Point q;
      std::vector<float> v;
      int sender = -1;
      int maxRank = -1;
      qs::receiveJob(rank, sender, maxRank, v);

      assert(sender != -1);
      assert(maxRank != -1);

      std::vector<float> res;

      compute(res, v, rank, maxRank);

      qs::sendResult(rank, sender, res);
  }

}
