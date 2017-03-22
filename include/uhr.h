#ifndef UHR_H
#define UHR_H

#include <ctime>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include "error.h"
#include "common.h"
#include "parameter.h"

class input_uhr {
private:
	char 		errname[filename_size];
	readfile 	rf;
	void 		save( parameter &p);

public:

	int 		Q_restart;
	char 		restart_file[filename_size];
	int 		Q_restart_save;
	char 		restart_file_save[filename_size];

	input_uhr( parameter &p );
};


class uhr{
private:
	double 		h_cpu, m_cpu, s_cpu, sec_cpu;		// cpu time
	clock_t		start_tics, stop_tics, tics;		// processor clocks
	double 		h_sys, m_sys, s_sys, sec_sys;		// system time
	time_t 		start_time, stop_time;

	char 		errname[filename_size];
	char 		uhrname[filename_size];
	char		path[filename_size];

	int 		domain_number;
	readfile    rf;
	input_uhr	input;

public:
	uhr( parameter &p, char *name );
	void 		reset( void );
	void 		start( void );
	void stop_and_add( void );
	void 		  add( void );
	void 		  sys( void );
	void  seconds_cpu( void );
	void  seconds_sys( void );
	void 	  restart( void );
	void restart_save( void );
};


#endif