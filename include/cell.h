#ifndef CELL_H
#define CELL_H

#include "particle.h" 

struct cell {

	int 	number;				// number of this cell
	int 	domain;				// domain number it belongs to
	struct 	cell *prev; 		// pointer to the previous (left) cell
	struct 	cell *next;  		// pointer to the next (right) cell

	double 	x;					// position of the left cell boundary in wavelengths
	double 	charge;				// charge density in units e*n_c
	double  jx, jy, jz; 		// current density in units e*n_c*c
	double  ex, ey, ez; 		// electric fields in units m*omega*c/e
	double 	bx, by, bz; 		// magnetic fields in units m*omega/e
	double 	fp, fm, gp, gm;		// 
	double 	dens[2];			// densities for each species in units n_c -- only 2 species

	int		np[2];				// number of electrons [0] and ions [1]
	int 	npart;				// number of particles

	struct 	particle *first;	// pointer to the first particle
	struct  particle *last;		// pointer to the last particle
	struct 	particle *insert;	// pointer to particle, in front of which new particles
								// have to be inserted
};


#endif