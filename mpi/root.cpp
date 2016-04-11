#include <mpi.h>
#include "root.h"
#include "job.h"

#include <iostream>
#include <cassert>
#include <assert.h>
#include <cmath>
#include <fstream>

#include "../lib/quicksort.h"


#define log std::cout << "Root: "

using namespace std;

namespace qh {

void startRoot(int rank, const char *dataFile) {
    log << "Reading file..." << std::endl;
    std::ifstream ifs(dataFile);

    vector<float> array;

    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        float a;
        if (!(iss >> a)) { break; } // error
        cout << a << endl;
        array.push_back(a);
        // process pair (a,b)
    }

    log << "Finished reading file." << std::endl;

    log << "Array size: " << array.size() << std::endl;

    double startTime = MPI::Wtime();

    int maxRank = MPI::COMM_WORLD.Get_size() - 1;

    if (maxRank > 0) {
        
        int nextWorker = maxRank / 2 + 1;

        vector<float> v1;
        vector<float> v2;



        if (!v2.empty()) {
            log << "max rank = " << maxRank << std::endl;
            log << "nextWorker = " << nextWorker << std::endl;
            qh::sendJob(rank, nextWorker, maxRank, v2);
        }

        log << "Computing v1" << std::endl;
        compute(res, v1, rank, maxRank / 2);

        if (!s2.empty()) {
            log << "Waiting for result from node " << nextWorker << std::endl;
            std::vector<qh::Point> workerRes;
            qh::receiveResult(rank, nextWorker, workerRes);

            log << "Merging results.." << std::endl;
            res.insert(res.end(), workerRes.begin(), workerRes.end());
        }

        log << "Result:" << std::endl;
        log << qh::ToString(res) << std::endl;
    }
    else {
        std::vector<float> res = quickSortSerial(array);
        log << "Result: " << std::endl;
        log << printArray(res) << std::endl;
    }

    double stopTime = MPI::Wtime();
    double elapsedTime = stopTime - startTime;
    log << "Time: " << elapsedTime;
}

}
