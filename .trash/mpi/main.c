#include <mpi.h>

#include "worker.h"
#include "root.h"

void main(int argc, char **argv) {
	int rank = -1;
	MPI_Init(&argc, &argv);

  	MPI_Comm_rank( MPI_COMM_WORLD, &rank );

  	if(rank==0){
  		
  	}

	MPI_Finalize();
}