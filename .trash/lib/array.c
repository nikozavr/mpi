#include "array.h"

int lenght(float *array){
	return (int)(sizeof(&array)/sizeof(float));
}