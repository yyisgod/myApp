/************************************************************
 * 通过往期数据，计算时时彩中很久没有出现的号！
 * version 0.1
 * Author: yy
 * 2015/06/14
 * ***********************************************************/
#include"SSCConsole.h"
#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
	char ch;
	SSCConsole lottery;
	cout << "$:";
	while (cin >> ch) {
		if(ch == 'q')
			break;
		if(ch == 'f') {
			long int issue = 0;
			cin >> issue;
			int input[5];
			for(int i = 0; i < 5; i++) {
				cin >> input[i];
			}
			cin.clear();
			cin.sync();
			lottery.add(input,issue);
			lottery.print(cout);
		}
		if(ch == 'a') {
			int input[5];

			for(int i = 0; i < 5; i++) {
				cin >> input[i];
			}
			cin.clear();
			cin.sync();
			lottery.add(input);
			lottery.print(cout);
		}
		if(ch >= '0' && ch <='9' ) {
			int input[5];
			input[0] = ch - '0';
			for(int i = 1; i < 5; i++) {
				cin >> ch;
				input[i] = ch - '0';
			}
			cin.clear();
			cin.sync();
			lottery.add(input);
			lottery.print(cout);
		}
		cout << endl << "$:";
	}
	return 0;
}
