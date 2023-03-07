#include <string>
#include <vector>

#include "avian.h"

using namespace std;

vector<string> encode(int C, int K, int N, string X) {
	vector<string> encoding(K);
	encoding[0] = "iunty23v7itdhugh3c"+X;
	return encoding;
}

string decode(int C, int K, int N, vector<string> Y, vector<int> I) {
	string ret = "";
	for (auto& s : Y)
	{
		ret += s;
	}
	return ret;
}
