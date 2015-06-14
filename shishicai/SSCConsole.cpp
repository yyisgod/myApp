#include"SSCConsole.h"
#include<iostream>
#include <iomanip> 
using std::ostream;
using std::cout;
using std::endl;
using std::setw;
using std::setfill;

void SSCConsole::print(ostream& os) {
	int len = data.size();
	if (!len) {
		cout << "No data! " << endl;
		return;
	}
	//output splite line;
	for(int i = 0; i < 80; i++) {
		os << '-';
	}
	os << endl;
	
	//output result
	os << "  " << "Result:" << " | ";
	for(int i = 0; i < 5; i++) {
		os << res[i] << ((4-i)?"  ":"\n");
	}

	//output splite line;
	for(int i = 0; i < 80; i++) {
		os << '-';
	}
	os << endl;
	
	//output data (max is 20)
	cout <<setfill('0') ;          // By default
	for(int i = len-1; i >= 0; i--) {
		os << setw(9) << data[i].issue << " | ";
		for(int j = 0; j < 5; j++) {
			os << data[i].ns[j] << ((4-j)?"  ":"\n");
		}
	}
	

}

void SSCConsole::add(int nums[5], long int issue) {
	if(!nums) {
		cout << "No input data !" << endl;
		return;
	}
	int len = data.size();
	if(len == maxN) {
		data.erase(data.begin());
	}
	node nt;
	if(issue)
		nt.issue = issue;
	else {
		nt.issue = data.back().issue + 1;
	}
	nt.ns = new int[5];
	for(int i = 0; i < 5; i++) {
		nt.ns[i] = nums[i];
	}
	data.push_back(nt);
	
	update();
}
//
//void SSC::update() {
//	if(dst[0][0] == 0 ) {
//		int len = data.size();
//		for(int i = 0; i < len; i++) {
//			for(int j = 0; j < 5; j++) {
//				if (dst[j][data[i].ns[j]] > (i+1) || !dst[j][data[i].ns[j]]) {
//					dst[j][data[i].ns[j]] = i + 1;
//				}
//			}
//		}
//		for(int i = 0; i < 5; i++) {
//			for(int j = 0; j < 10; j++) {
//				if(!dst[i][j]) {
//					dst[i][j] = len + 1;
//				}
//			}
//		}
//	} else {
//		for(int i = 0; i < 5; i++) {
//			for(int j = 0; j < 10; j++) {
//				if(j == data.back().ns[i])
//					dst[i][j] = 1;
//				else
//					dst[i][j]++;
//			}
//		}
//	}
//	result();
//}

//void SSC::result() {
//	for(int i = 0; i < 5; i++) {
//		int max = 0;
//		int number = 0;
//		for(int j = 0; j < 10; j++) {
//			if(dst[i][j] > max) {
//				max = dst[i][j];
//				number = j;
//			}
//		}
//		res[i] = number;
//	}
//}

