#pragma once

#include <vecmath.h>
#include <vector>
#include <string>
using std::string;
// The AtomPoint object stores information about an atom in the unit cell.
// 
struct AtomPoint
{
	Vector3f V; //coordinate
	string elem;

};

struct DistanceStruct
{
    double value;
    int key;
    std::string name;

    DistanceStruct(double v, const int k, const std::string n) : value(v), key(k), name(n) {}

    bool operator < (const DistanceStruct& str) const
    {
        return (value < str.value);
    }
};

typedef std::vector<AtomPoint> Atom;

double evalDistance(AtomPoint a, AtomPoint b);
std::vector<DistanceStruct> nearestNeighbors(std::vector<Atom> atoms, std::string elem, int elemIndex, std::string mode);


