#ifndef PARTICLE_H
#define PARTICLE_H

#include "cell.h"

struct particle {
	
	int 			number;				// number of this particle
	int 			species;			// particle species, 0=electron, 1=ions
	struct cell 	*cell;				// pointer to the cell this particle belongs to
	struct particle *prev;				// pointer to the previous particle in this cell
	struct particle *next;				// pointer to the next particle in this cell

	int 			fix;				// fixed species? 0->no, 1->yes
	double			z;					// charge of the micro particle in units of e
	double 			m;					// mass of the micro particle in units of m_e
	double  		zm;					// specific charge, z/m
	double 			x, dx;				// position and shift within one timestep
	double 			igamma;				// inverse gamma factor
	double			ux, uy, uz			// gamma * velocity
	double 			n;					// particle density in units of n_c
	double 			zn;					// contribution of the particle to the charge density
										// in units of n_c ( = z * n)

};



#endif