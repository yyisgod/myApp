#include"SSCBase.h"
void SSCBase::update() {
	if(dst[0][0] == 0 ) {
		int len = data.size();
		if(!len) {
			throw "NoData";
		}
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < 5; j++) {
				if (dst[j][data[i].ns[j]] > (i+1) || !dst[j][data[i].ns[j]]) {
					dst[j][data[i].ns[j]] = i + 1;
				}
			}
		}
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 10; j++) {
				if(!dst[i][j]) {
					dst[i][j] = len + 1;
				}
			}
		}
	} else {
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 10; j++) {
				if(j == data.back().ns[i])
					dst[i][j] = 1;
				else
					dst[i][j]++;
			}
		}
	}
	result();
}

void SSCBase::result() {
	for(int i = 0; i < 5; i++) {
		int max = 0;
		int number = 0;
		for(int j = 0; j < 10; j++) {
			if(dst[i][j] > max) {
				max = dst[i][j];
				number = j;
			}
		}
		res[i] = number;
	}
}
