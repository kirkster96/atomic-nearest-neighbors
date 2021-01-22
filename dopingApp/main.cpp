// dopingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <vecmath.h>
#include <fstream>
#include <algorithm>

#include "atom.h"
#include "parse.h"

using namespace std;

namespace
{
    vector<Atom> gAtoms;
}

// Load in atoms from standard input into the global variables:
// gAtoms. If loading failes, this will exit the program
void loadAtoms(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "usage: " << argv[0] << " POSCARFILE " << endl;
        exit(0);
    }

    ifstream in(argv[1]);
    if (!in)
    {
        cerr << argv[1] << " not found\a" << endl;
        exit(0);
    }

    cerr << endl << "*** loading and constructing atomic positions ***" << endl;

    if (!parseFile(in, gAtoms))
    {
        cerr << "\aerror in file format\a" << endl;
        in.close();
        exit(-1);
    }
    in.close();


    cerr << "*** done ***" << endl;

}

int main(int argc, char * argv[])
{
    // Load in from standard input
    loadAtoms(argc, argv);

    string userElem;

    cout << "Select element in system: ";
    cin >> userElem;

    int userElemIndex;
    cout << "Select which atom of element '" << userElem << "': ";
    cin >> userElemIndex;

    string userTarget;
    cout << "Select element for nearest-neighbors" << endl << "(type 'all' for all elements in system): ";
    cin >> userTarget;

    nearestNeighbors(gAtoms, userElem, (userElemIndex-1), userTarget);

    return 0;
}
