#ifndef __UTILS_H
#define __UTILS_H
#include <iostream>

using namespace std;

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int& S,
                   double*& w,
                   double*& r);

double RateofReturn(const size_t& n,
                        const double* const& w,
                        const double* const& r);

double FinalValue(const double& RoR, unsigned int& S);

bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& RateofReturn,
                  unsigned int& S,
                  double& V);

#endif
