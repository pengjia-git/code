#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;

//去掉路径部分
string remove_dir(string path)
{
	size_t pos;
	pos=path.find_last_of('/');
	if(pos == string::npos)
	{
		return path;
	}
	return path.substr(pos+1,path.size()-pos-1);
}


void split_special_names(string line,vector<string> &spe)
{
	vector<string> tmp;

	if(line.size()<3)
		return;
	size_t first=0,second=0,pos=0;
	while(1)
	{
		first=line.find("\"",pos);
	
		if(first ==string::npos)
			break;
		pos=first+1;

		second=line.find("\"",pos);
		if(second ==string::npos)
			break;
		pos=second+1;
		tmp.push_back(line.substr(first+1,second-first-1));
	}

	for(int i=0;i<tmp.size();i++)
	{
		//cout << remove_dir(tmp[i])<<endl;	
		spe.push_back(remove_dir(tmp[i]));
	}

}

int get_special_files(string path,vector<string> &spe)
{
	ifstream file;
	string line;

	file.open(path.c_str(), ios::in);

	if (!file.is_open()) {
		cout << "open file fail" << endl;
		return -1;
	}

	while (getline(file, line)) {
		split_special_names(line,spe);
	}

	file.close();
	return 0;

}

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
	set<string> c_set,obj_set,diff;
	set<string>::iterator it;
	trans_file_to_set(all_c_files, c_set);
	trans_file_to_set(all_obj_files, obj_set);
	
	#if 0
	it=obj_set.begin();
	while(it!=obj_set.end()){
		cout<<*it<<endl;
		//remove((*it).c_str());
		it++;
	}
	#endif
	//for(int i=0;i<special_list.size();i++)
	//	clean_special_key(c_set,special_list[i]);
	
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
