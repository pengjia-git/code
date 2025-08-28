#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;

int trans_file_to_set(string path, set<string> &sets)
{
	ifstream file;
	string line;

	file.open(path.c_str(), ios::in);

	if (!file.is_open()) {
		cout << "open file fail" << endl;
		return -1;
	}

	while (getline(file, line)) {
		line[line.size()-1]='c';
		// cout << line << endl;
		sets.insert(line);
	}

	file.close();
	return 0;
}

void clean_special_key(set<string> &sets,string  key)
{
	set<string>::iterator it=sets.begin();
	while(it!=sets.end()){
		string::size_type position;
		position=it->find(key);
		if (position != it->npos){
			it=sets.erase(it);
			continue;
		}
		
		it++;
	}	
}

int main()
{
	const string all_c_files = "tmp/all_c_files.txt";
	const string all_obj_files = "tmp/all_obj_files.txt";
	vector<string> special_list;
	set<string>::iterator it;
	
	special_list.push_back("scripts");
	special_list.push_back("bounds.c");
	special_list.push_back("arch/arm");
	special_list.push_back("drivers/usb/host");
	special_list.push_back("mm/");
	special_list.push_back("fs/nfs");
	special_list.push_back("lib/");
	special_list.push_back("usr/");

	
	set<string> c_set, obj_set,diff;

	trans_file_to_set(all_c_files, c_set);
	trans_file_to_set(all_obj_files, obj_set);
	
	for(int i=0;i<special_list.size();i++)
		clean_special_key(c_set,special_list[i]);
	
	// set_difference( A.begin(), A.end(),B.begin(), B.end(),inserter( C3, C3.begin() ) );
	set_difference( c_set.begin(), c_set.end(),obj_set.begin(), obj_set.end(),inserter( diff, diff.begin() ) );
	
	it=diff.begin();
	while(it!=diff.end()){
		cout<<*it<<endl;
		remove((*it).c_str());
		it++;
	}
	return 0;
}