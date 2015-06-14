#ifndef __SSC__
#define __SSC__
#include"SSCBase.h"
#include<vector>
#include<iostream>
using std::vector;
using std::ostream;

class SSCConsole : public SSCBase{
	int maxN;
  public:
  	SSCConsole():maxN(20) {};
  	SSCConsole(int N):maxN(N) {};
	void print(ostream& os);
	void add(int nums[5], long int issue=0);
};

#endif //__SSC__
