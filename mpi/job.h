#ifndef MPI3_JOB_H
#define MPI3_JOB_H

#include "../lib/Common.hh"
#include "../lib/Point.hh"

namespace qs {

void sendJob(int rank, int dest, int maxRank, std::vector<float> const &v);
void receiveJob(int rank, int &sender, int &maxRank, std::vector<float> &v);

void sendResult(int rank, int dest, std::vector<float> const &res);
void receiveResult(int rank, int source, std::vector<float> &res);

void compute(std::vector<float> &res, std::vector<float> const &v, int rank, int maxRank);

}

#endif