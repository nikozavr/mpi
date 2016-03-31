#include <mpi.h>
#include "root.h"

void startRoot(int rank, const char *dataFile){
	File *file;
	file = fopen(dataFile, "rb");
	// TODO reading numbers from file
	fclose(file);

	// TODO making array from numbers
	//numbers[] = ...
	float numbers[];

	//TODO 
}