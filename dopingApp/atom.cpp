#pragma once
#include "atom.h"
#include <vector>
#include <iostream>
#include <algorithm>


double evalDistance(AtomPoint a, AtomPoint b)
{
    Vector3f distance = a.V - b.V;
    return distance.abs();
}

std::vector<DistanceStruct> nearestNeighbors(std::vector<Atom> atoms, std::string elem, int elemIndex, std::string mode)
{
    


    Atom elemA, elemB;
    AtomPoint a, b;
    std::vector<DistanceStruct> sorted_distances;

    int i = 0;
    elemA = atoms[0];
    while (elemA[0].elem != elem)
    {
        elemA = atoms[i];
        i++;
    }
    if(i > 0)
        i = i + elemIndex -1;
    a = elemA[i];

    if (mode == "all")
    {

        for (unsigned i = 0; i < atoms.size(); i++)
        {
            elemB = atoms[i];
            for (size_t j = 0; j < elemB.size(); j++)
            {
                b = elemB[j];
                double distance = evalDistance(a, b);
                sorted_distances.push_back(DistanceStruct(distance, j + 1, b.elem));
            }
        }
    }
    std::sort(sorted_distances.begin(), sorted_distances.end());
    for (unsigned i = 0; i < sorted_distances.size(); i++)
        std::cout << "\t>>> " << elem << (elemIndex+1) << " - " << sorted_distances[i].name << sorted_distances[i].key << "\t" << sorted_distances[i].value << std::endl;

    return sorted_distances;






    //elemB = atoms[i];
    //while (elemB[0].elem != "Al")
    //{
    //    elemB = atoms[i];
    //    i++;
    //}

    //

    //std::cout << ">>> Printing all distances between Al1 and O" << std::endl;
    //b = elemB[0];
    //std::vector<DistanceStruct> Al_O_distances;
    //for (unsigned i = 0; i < elemA.size(); i++)
    //{
    //    a = elemA[i];
    //    double distance = evalDistance(a, b);
    //    Al_O_distances.push_back(DistanceStruct(distance, i + 1));

    //}

    //std::sort(Al_O_distances.begin(), Al_O_distances.end());
    //for (unsigned i = 0; i < Al_O_distances.size(); i++)
    //    std::cout << "\t>>> Al1 - O" << Al_O_distances[i].key << "\t" << Al_O_distances[i].value << std::endl;



    //std::cout << std::endl;
    //std::cout << ">>> Printing all distances between Al1 and Al" << std::endl;
    //std::vector<DistanceStruct> Al_Al_distances;
    //for (unsigned i = 0; i < elemB.size(); i++)
    //{
    //    a = elemB[i];
    //    double distance = evalDistance(a, b);
    //    Al_Al_distances.push_back(DistanceStruct(distance, i + 1));
    //}

    //std::sort(Al_Al_distances.begin(), Al_Al_distances.end());
    //for (unsigned i = 0; i < Al_Al_distances.size(); i++)
    //    std::cout << "\t>>> Al1 - Al" << Al_Al_distances[i].key << "\t" << Al_Al_distances[i].value << std::endl;

    //return std::vector<double>();
}

