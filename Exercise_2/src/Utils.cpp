#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

/**This function aims to:
 * Open a file in reading mode;
 * export data relevant to the vectors' size and the quantity invested;
 * create the two arrays w and r converting their elements from strings to real values. */
bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int& S,
                   double*& w,
                   double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    string line;
    getline(file,line);
    istringstream convertS;
    convertS.str(line.substr(2));
    convertS >> S;

    getline(file,line);
    istringstream convertN;
    convertN.str(line.substr(2));
    convertN >> n;

    getline(file,line);

    w = new double[n];
    r = new double[n];
    size_t i = 0;

    while (line != "\n")
    {
        istringstream convertW;
        istringstream convertR;
        getline(file, line);
        size_t pos = line.find(';');   //The method find() helps me find the position of the delimitator.

        if (pos == string::npos)
        {
            break;
        }

        convertW.str(line.substr(0,pos)); //The method substr() extracts the substring from the start of the line up to the delimitator.
        convertW >> w[i];

        convertR.str(line.substr(pos+1)); //The method substr() extracts the substring from the delimitator up to the end of the line.
        convertR >> r[i];

        i++;
    }

    file.close();

    return true;
};

//This function computes the scalar product between vectors w and r.
double RateofReturn(const size_t& n,
                        const double* const& w,
                        const double* const& r)
{
    double RoR = 0;
    for (unsigned int i = 0; i < n; i++)
    {
        RoR += w[i] * r[i];
    }

    return RoR;

}

double FinalValue(const double& RoR, unsigned int& S)
{
     double Value = (1 + RoR) * S;
    return Value;
}

//This function prints my results in an output file, which is opened in writing mode.
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& RateofReturn,
                  unsigned int& S,
                  double& V)
{

    ofstream file;
    file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S << ", ";
    file << "n = " << n << endl;

    file << "[";
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "")<< w[i];
    file << "]" << endl;

    file << "[";
    for (unsigned int i = 0; i < n; i++)
        file << (i != 0 ? " " : "")<< r[i];
    file << "]" <<endl;


    file<< "Rate of return of the portfolio: "<< fixed << setprecision(4)<< RateofReturn << endl;

    file << "V: " << fixed << setprecision(2) << V << endl;


    file.close();

    return true;
}




