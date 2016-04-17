#include <mpi.h>

#include "job.h"

#include <vector>
#include <iostream>
#include <assert.h>

#define log std::cout << "Node " << rank << ": "

namespace qs {

void sendJob(int rank, int dest, int maxRank, std::vector<float> const &v) {

    log << "Spawning worker " << dest << std::endl;
    int jobInfo[] = { rank, maxRank };
    MPI::COMM_WORLD.Send(jobInfo, 2, MPI::INT, dest, 0);

    log << "Parent = " << jobInfo[0] << std::endl;
    log << "Max rank = " << jobInfo[1] << std::endl;

    log << "Sending size" << std::endl;
    int size = v.size();
    MPI::COMM_WORLD.Send(&size, 1, MPI::INT, dest, 0);

    log << "Sending array" << std::endl;
    MPI::COMM_WORLD.Send(v[0], size, MPI::FLOAT , dest, 0);
}

void receiveJob(int rank, int &sender, int &maxRank, std::vector<float> &v) {

    int jobInfo[2];
    MPI::COMM_WORLD.Recv(jobInfo, 2, MPI::INT, MPI::ANY_SOURCE, MPI::ANY_TAG);

    sender = jobInfo[0];
    maxRank = jobInfo[1];

    log << "started. Parent process = " <<  sender << std::endl;
    log << "Max rank = " << maxRank << std::endl;

    log << "Receiving size.." << std::endl;
    int size = -1;
    MPI::COMM_WORLD.Recv(&size, 1, MPI::INT, sender, 0);
    log << "Size = " << size << std::endl;

    assert(size != -1);

    log << "Receiving array..." << std::endl;
    v.resize(size_t(size));
    MPI::COMM_WORLD.Recv(v[0], size, MPI::FLOAT, sender, 0);

    a = line[0];
    b = line[1];

}

void sendResult(int rank, int dest, std::vector<float> const &res) {

    log << "Sending result to " << dest << std::endl;
    int resSize = int(res.size());
    MPI::COMM_WORLD.Send(&resSize, 1, MPI::INT, dest, 0);
    MPI::COMM_WORLD.Send(res.data(), resSize, PointType, dest, 0);
}

void receiveResult(int rank, int source, std::vector<float> &res) {

    log << "Receiving result from " << source << std::endl;
    int resSize = -1;
    MPI::COMM_WORLD.Recv(&resSize, 1, MPI::INT, source, MPI_ANY_TAG);
    log << "Res size = " << resSize << std::endl;

    res.resize(size_t(resSize));
    MPI::COMM_WORLD.Recv(res.data(), resSize, PointType, source, MPI_ANY_TAG);
}

void compute(std::vector<float> &res, std::vector<float> const &v, int rank, int maxRank) {
    if (v.empty()) {
        if (rank != maxRank) {
            int nextWorker = (maxRank - rank) / 2 + rank + 1;
            qs::sendJob(rank, nextWorker, maxRank, std::vector<float>());

            std::vector<float> wr;
            qs::receiveResult(rank, nextWorker, wr);
        }
        return;
    }

    res.push_back(c);
    std::vector<Point> s1 = qh::rightOf(qh::Line(p, c), sk);
    std::vector<Point> s2 = qh::rightOf(qh::Line(c, q), sk);

    if (rank != maxRank) {
        log << "maxRank = " << maxRank << ". rank = " << rank << std::endl;

        int nextWorker = (maxRank - rank) / 2 + rank + 1;
        int nextMax = maxRank;

        log << "Sending s2 to " << nextWorker << std::endl;

        assert(nextWorker > rank);

//        if (!s2.empty()) {
            qh::sendJob(rank, nextWorker, nextMax, s2, c, q);
//        }

        compute(res, s1, p, c, rank,  (maxRank - rank) / 2 + rank);

//        if (!s2.empty()) {
            std::vector<float> workerRes;
            receiveResult(rank, nextWorker, workerRes);
            res.insert(res.end(), workerRes.begin(), workerRes.end());
//        }
    }
    else {
        log << "i am the last. Computing result on my own" << std::endl;
        qh::findHull(res, s1, p, c);
        qh::findHull(res, s2, c, q);
    }
}

}
