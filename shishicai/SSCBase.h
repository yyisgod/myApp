#ifndef __SSCBASE__
#define __SSCBASE__

#include<vector>
using std::vector;

class SSCBase {
  protected:
	struct node{
		long int issue;
		int* ns;
	};
	vector<node> data;
	int dst[5][10] = {};
	int res[5] = {};
	//int maxNumOfData;  
  public:
  	SSCBase(){};
  	//SSC(int maxN):maxNumOfData(maxN) {};
	virtual void update();
	virtual void result();
	virtual void add(int nums[5], long int issue=0) = 0;
	virtual ~SSCBase(){}
	
};
#endif //__SSCBASE__
