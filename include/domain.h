#ifndef DOMAIN_H
#define DOMAIN_H


#include <fstream>
#include <cstdio>
#include <iomanip>
#include <cmath>

#include "common.h"
#include "error.h"
#include "cell.h"
#include "particle.h"
#include "parameter.h"
#include "readfile.h"

class input_domain {

private:
	char errname[filename_size];

public:
	int 	Q_restart;						// start from t>0, using restart files
	char	restart_file[filename_size];
	int 	Q_restart_save;

	int 	n_domains;						// grid
	int 	cells;
	int 	cells_per_wl;
	int 	cells_left;
	int 	cells_ramp;
	int 	cells_plasma;
	double  dx;

	double  n_ion_over_nc;					// plasma density
	double  n_ele_over_nc;					

	int 	nsp;							// particles
	int  	*ppc;							
	int 	*fix;
	double  *z, *zmax, *m;
	double  *vtherm;

	double  angle;							// angles of incidence
	double  Gamma, Beta;					// Lorentz transformation
	int 	spp;							// steps per laser period

	readfile rf;
	input_domain( parameter &p );           // ???
	void save( parameter &p );
};


class domain {
private:

	char 		 errname[filename_size];
	int 		 domain_number;
	int 		 n_domains;
	char 		 path[filename_size];

	input_domain input;

	void restart_configuration( void );
	void        set_boundaries( void );
	void 		   chain_cells( void );
	void 			init_cells( void );
	void 	   chain_particles( void );
	void 		init_particles( void );
	double 		  gauss_rand48( void );
	double 	  exponential_rand( double );  // exponential velocity distribution

public:

	int 		n_left; 		// cell number at the left boundary
	int 		n_right;		// cell number at the right boundary
	int 		n_cells;		// number of cells in this domain

	double      dx; 			// cell width

	struct cell *Lbuf;			// lhs: left buffer cell, left of left
	struct cell *lbuf;			//      right buffer      left of left  ???
	struct cell *left;			// pointer to the first occupied cell
	struct cell *right;			// pointer to the last occupied cell
	struct cell *rbuf;          // rhs: right buffer cell, right of right
	struct cell *Rbuf;			// 		right buffer   ???
	struct cell *dummy;  		// definitely the last one

	int n_ele;					// number of electrons
	int n_ion; 					// number of ions
	int n_part;					// total number particles

	                  domain( parameter &p );
	void     count_particles( void );
	void               check( void );

	void         reo_to_prev( int request_to_prev, int *cells_to_prev, int *parts_to_prev );
	void         reo_to_next( int request_to_next, int *cells_to_next, int *parts_to_next );
	void  reo_delete_to_prev( int cells_to_prev, int parts_to_prev );
	void  reo_delete_to_next( int cells_to_next, int parts_to_next );
	void reo_alloc_from_prev( int cells_to_prev, int parts_to_prev );
	void reo_alloc_from_next( int cells_to_next, int parts_to_next );
	void reo_update_n_ele_n_ion( int ele_count, int ion_count );
};

#endif