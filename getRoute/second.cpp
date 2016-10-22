#include <bits/stdc++.h>
#include "atf.cpp"

using namespace std;

//#define END_STR							"----------------"


vector<string>route;

void workRoute(){
	string outStr,str;
	input.open("all.data",ios::in);
	output.open("route.data",ios::out);
	
	bool jump = false;
	while(input>>str){
		if(str == "0"){
			int pos1 = outStr.find("allLocJson") - 4;
			int pos2 = outStr.find("useZip") + 15;
			string tmp;
			for(int i = pos1; i < pos2; ++i)
				if(outStr[i] == '\\' && outStr[i-1] == '\\') 
					continue;
				else tmp += outStr[i];
			if(tmp.size() > 100)
				route.push_back(tmp);
			outStr.clear();
		}
		if(str.size() < 7){
			jump = true;
			continue;	
		} 
		if(!jump) outStr += " "+str;
		else{
			jump = false;
			outStr += str;
		}
	}
	bool fitst = true;
	for(auto it:route)
		if(it.size() > 50) 
			if(fitst){
				bool first = false;
				output<<it<<endl<<END_STR;
			}else
				output<<endl<<it<<endl<<END_STR;
			
	output.close();
	input.close();
}

int main(){
	cerr<<"1"<<endl;
	workRoute();
	cerr<<"2"<<endl;
	work();
	cerr<<"3"<<endl;
	return 0;
}
