#include "parse.h"
#include <map>
using namespace std;

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool parseFile(std::istream& in, std::vector<Atom>& atoms)
{
    atoms.clear();

    string objType;

    //for looking up atom indeces by name
    map<string, unsigned> atomIndex;

    string crystalName;
    in >> crystalName;
    cerr << "crystalName= " << crystalName << endl;

    float uniScale;
    in >> uniScale;
    //cerr << "uniScale= " << uniScale << endl;


    Vector3f basisA, basisB, basisC;

    in >> basisA[0];
    in >> basisA[1];
    in >> basisA[2];
    
    //cerr << "basis A= " << basisA[0] << ", " << basisA[1] << ", " << basisA[2] << endl;

    in >> basisB[0];
    in >> basisB[1];
    in >> basisB[2];

    //cerr << "basis B= " << basisB[0] << ", " << basisB[1] << ", " << basisB[2] << endl;

    in >> basisC[0];
    in >> basisC[1];
    in >> basisC[2];

    //cerr << "basis C= " << basisC[0] << ", " << basisC[1] << ", " << basisC[2] << endl;

    string objStr;
    vector <string> atomTypes;
    in >> objStr;
    while (!is_number(objStr))
    {
        cerr << objStr << "\t";
        atomTypes.push_back(objStr);
        in >> objStr;
    }
    cerr << endl;

    unsigned atomCount;
    vector<unsigned> atomCounts;
    atomCount = stoi(objStr);
    while (is_number(objStr))
    {
        cerr << objStr << "\t";
        atomCount = stoi(objStr);
        atomCounts.push_back(atomCount);
        in >> objStr;
    }
    cerr << endl;

    if (atomTypes.size() != atomCounts.size())
        return false;

    cerr << "Mode: " << objStr << endl;

    if (objStr == "direct" || objStr == "Direct") 
    {
        for (unsigned i = 0; i < atomTypes.size(); i++)
        {
            Atom element;
            for (unsigned j = 0; j < atomCounts[i]; j++)
            {                
                AtomPoint atomPos;
                float x1, x2, x3;

                in >> x1 >> x2 >> x3;
                atomPos.V = x1 * basisA + x2 * basisB + x3 * basisC;

                //cerr << "atomPos.V= " << atomPos.V[0] << "\t" << atomPos.V[1] << "\t" << atomPos.V[2] << endl;
                atomPos.elem = atomTypes[i];

                element.push_back(atomPos);
            }
            atoms.push_back(element);
        }

    }



    return true;
}
