#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<iterator>
#include<cstring>
using namespace std;
map<string, vector<pair<string, int > > >mp1;
string str1, str2;
int n;
bool cmp(pair<string , int> x , pair<string , int> y){
	return x.second > y.second;
}

int main(int argc, char *argv[]){
	string str3 = "";
	if(argc == 4){
		for(int i = 0; i < strlen(argv[3]); i ++ ){
			str3 += argv[3][i];	
		}	
	}
	string s1 = "D:\\rg\\";
	string s2 = "D:\\rg\\";
	char c1[110], c2[110];
	for(int i = 0; i < 100; i ++ ){
		c1[i] = c2[i] = 0;	
	}
	for(int i = 0; i < strlen(argv[1]); i ++ ){
		s1 += argv[1][i];	
	}
	for(int i = 0; i < strlen(argv[2]); i ++ ){
		s2 += argv[2][i];	
	}
	for(int i = 0; i < s1.size(); i ++ ){
		c1[i] = s1[i];
	}
	for(int i = 0; i < s2.size();i ++ ){
		c2[i] = s2[i];	
	}
	freopen(c1, "r", stdin);
	freopen(c2, "w", stdout);
	while(cin >> str1 >> str2 >> n){
		mp1[str1].push_back(pair<string, int>(str2, n));
	}
	map<string, vector<pair<string, int> > > :: iterator it1;
	map<pair<int , string> , vector<pair<string, int > > , greater<pair<int , string> > >mp;
	map<pair<int , string> , vector<pair<string, int> > > :: iterator it;
	for(it1 = mp1.begin(); it1 != mp1.end(); it1++){ 
		mp[pair<int,string>(it1->second.size() , it1->first)] = (it1->second);
	}
	if(argc == 3){
		for(it = mp.begin(); it != mp.end(); it ++ ){
			//if(it -> first == argv[0]) cnt++;
			cout << it -> first.second << '\t' << it -> first.first << endl;
			sort(it->second.begin(),it->second.end() , cmp);
			for(int i = 0; i < it -> second.size(); i ++ ){
				cout << it -> second[i].first << '\t' << it -> second[i].second << endl;	
			}
			cout << endl;
		}
	}
	if(argc == 4){
		for(it = mp.begin(); it != mp.end(); it ++ ){
			if(it->first.second == str3) {
				cout << it -> first.second << '\t' << it -> first.first << endl;
				sort(it->second.begin(),it->second.end() , cmp);
				for(int i = 0; i < it -> second.size(); i ++ ){
					cout << it -> second[i].first << '\t' << it -> second[i].second << endl;	
				}
			}
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
