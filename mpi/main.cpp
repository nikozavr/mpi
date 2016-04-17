#include <mpi.h>

#include "worker.h"
#include "root.h"

int main(int argc, char **argv) {
    MPI::Init(argc, argv);

    int rank = MPI::COMM_WORLD.Get_rank();

    if (rank == 0) {
        qs::startRoot(0, argv[1]);
    }
    else {
        qs::startWorker(rank);
    }

    MPI::Finalize();
}
