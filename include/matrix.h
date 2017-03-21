#ifndef MARTIX_H
#define MARTIX_H

#include <cstdio>
#include <cstddef>		// defines several types implicitly generated or used by certain language expressions.
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "common.h"

double** dmatrix( long nrl, long nrh, long ncl, long nch );
void	 delete_dmatrix( double **m, long nrl, long nrh, long ncl, long nch );

float**  matrix( long nrl, long nrh, long ncl, long nch );
void 	 delete_matrix( float **m, long nrl, long nrh, long ncl, long nch );

float**  fmatrix( long nrl, long nrh, long ncl, long nch );
void	 delete_fmatrix( float **m, long nrl, long nrh, long ncl, long nch );

int**	 imatrix( long nrl, long nrh, long ncl, long nch );
void  	 delete_imatrix( int **m, long nrl, long nrh, long ncl, long nch );

unsigned char **ucmatrix( long nrl, long nrh, long ncl, long nch );
void     delete_ucmatrix( unsigned char **m, long nrl, long nrh, long ncl, long nch);


void error(char* s1, char*  s2="", char* s3="", char* s4="");  // ???
void error(char* s1, double d2,    char* s3="", char* s4="");

#endif 