#include <mpi.h>

#include "worker.hh"
#include "root.hh"

int main(int argc, char **argv) {
    MPI::Init(argc, argv);

    int rank = MPI::COMM_WORLD.Get_rank();

    if (rank == 0) {
        qh::startRoot(0, argv[1]);
    }
    else {
        qh::startWorker(rank);
    }

    MPI::Finalize();
}