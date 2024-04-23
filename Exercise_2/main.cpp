#include "Utils.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{

  string inputFileName = "data.csv";
  size_t n = 0;
  unsigned int S = 0;
  double* w = nullptr;
  double* r = nullptr;

  if(!ImportVectors(inputFileName, n, S, w, r))
  {
      cerr<< "Something goes wrong with import"<< endl;
      return -1;
  }
  else
      cout<< "Import successful" << endl;

  double RoR = RateofReturn(n,w,r);

  double V = FinalValue(RoR,S);

  string outputFileName = "result.txt";
  if (!ExportResult(outputFileName, n, w, r, RoR, S, V))
  {
      cerr<< "Something goes wrong with export"<< endl;
      return -1;
  }
  else
      cout<< "Export successful"<< endl;

  delete [] w;
  delete [] r;

    return 0;
}

