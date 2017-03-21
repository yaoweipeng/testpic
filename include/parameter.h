#ifndef PARAMETER_H
#define PARAMETER_H

#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>		// declares a set of functions to compute common mathematical operations 
						// and transformations: Functions.
#include "common.h"		
#include "matrix.h"		// def different types of matrix
#include "error.h"
#include "readfile.h"	// def readfile clss, together with all variable declarations.

class parameter {

private:
	void 		adjust_angle_write_steps( void );
	void 		save( void );
	readfile    rf;
	int 		Q_restart;

public:
	char 		*my_name; 				// cml input
	char		*input_file_name;		// cml input or default value
	int 		domain_number;			// cml input or default value
	int 		n_domains;				// namelist input
	char 		*path;					// namelist input
	char 		*errname;				// file name for output of errors and comments
	char 		*outname;				// file name for output of input

	int 		nsp;					// initial number of particle species
	int 		spl;					// number of cells per laser wave length
	int 		spp;					// number of time steps per period
	double 		angle, Beta, Gamma;		// Lorentz transformation

	parameter(int argc, char **argv);
};

#endif
