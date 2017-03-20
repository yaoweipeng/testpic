#ifndef ERROR_H
#define ERROR_H

#include <fstream>		// to read information from files
#include <iostream>
#include <cstdio>		// Input and Output operations can also be performed in C++ 
						// using the C Standard Input and Output Library 
						// (cstdio, known as stdio.h in the C language).
#include <cstring> 		// defines several functions to manipulate strings and arrays like in C
#include <iomanip>		// providing parametric manipulators
#include <cstdlib>		// just like <cstdio>, using C std lib <stdlib.h> in C++
#include "common.h"


class error_handler {  
// an expanded concept of data structures;
// data & function are all acceptable members;  
// defined using keywords 'class' or 'structure'      
	static int error_number;
	static int message_number;
	static int Q_debug;
	static int debug_number;
	static int object_number;
	const char *my_name;
	char	   *errname
	std::ofstream	errfile;
	static int tab;
public:
// An access specifier is one of the following three keywords: private, public or protected. 
// These specifiers modify the access rights for the members that follow them.
	error_handler(const char *, char *error_file_name);
	void error(char* s1, char* s2="", char* s3="", char* s4="");
	void error(char* s1, double d2, char*, s3="", char* s4="");

	void message(char* m1, char* m2="", char* m3="", char* m4="");
    void message(char* m1, double m2,   char* m3="", char* m4="");
    void message(char* m1, double m2,   char* m3,    double m4);
    void message(char* m1, double m2,   char* m3,    double m4,
		 	char* m5,    double m6,    char* m7, double m8);
    void message(char* m1, double m2, double m3, double m4, double m5 );
    void message(char* m1, double m2, double m3, double m4 );
    void message(char* m1, double m2, char* m3,  double m4, char* m5, double m6);
    void message(char* s1, double d2, double d3);
    void message(char* s1, char* s2, double d3);

    void debug(char* m1, char* m2="", char* m3="", char* m4="");
    void debug(char* m1, double m2,   char* m3="", char* m4="");
    void debug(char* m1, double m2,   char* m3,    double m4);
    void debug(char* m1, double m2,   char* m3,    double m4, char* m5, double m6);
}

#endif


