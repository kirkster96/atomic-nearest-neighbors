#pragma once

#include "atom.h"
#include <iostream>
#include <string>

/* This function implements a parser for the "VASP" file format.

	A POSCAR.vasp file allows you to describe a unit cell of a crystal structure.
	To specify a curve, you use the following syntax:
	
	NAME
	UNIVERSAL SCALING FACTOR (lattice constant)
	LATTICE PARAMETER A
	LATTICE PARAMETER B
	LATTICE PARAMETER C
	CONSTITUING ELEMENTS (IN ORDER OF APPEARANCE OF POTCAR)
	NUMBER OF ATOMS PER ATOMIC SPECIES
	SELECTIVE DYNAMICS OR DIRECT COORDINATES
	COORDINATE FOR EACH ATOM (direct mode means these scale the basis vectors)
	*/
bool parseFile(std::istream& in, std::vector<Atom>& atoms);

