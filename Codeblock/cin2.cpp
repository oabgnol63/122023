#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> temp;
vector<string> detect;
string current_tag = "";
string tag = "";
map<string,string> mp;
void chuanhoa(string &a)
{
    if(a.find('"') != string::npos)
    {
        a = a.substr(a.find_first_of('"')+1,a.find_last_of('"')-1);
    }
}
void extract(string &in)
{
    string tmp;
    while(in != "" && in.find(" ") != string::npos)
    {
        tmp = in.substr(0,in.find(" "));
        in.erase(0,in.find(" ")+1);
        if (tmp != "=")
        {
            chuanhoa(tmp);
            temp.push_back(tmp);
        }
    }
    in.erase(in.find(">"));
    if(in != "")
    {
        chuanhoa(in);
        temp.push_back(in);
    }
}

int main()
{
    string in;
    int N, Q; cin >> N >> Q;
    cin.ignore();
    for(int i = 0;i<N;i++)
    {
    getline(cin,in);
    if(in[1] != '/')
    {
        if(current_tag != "") current_tag += ".";
        current_tag += in.substr(1,in.find_first_of(" ")-1);
        if(current_tag.find(">") != string::npos) current_tag.erase(current_tag.find(">"),1);
        if(in.find(" ") != string::npos)
        in.erase(0,in.find(" ")+1);
        else in.erase(0,in.find(">"));
        extract(in);
        for(int i = 0;i<temp.size();i+=2)
        {
            tag = current_tag;
            tag = tag + '~' + temp[i];
            mp[tag] = temp[i+1];
        }
        temp.erase(temp.begin(),temp.end());
    }

    else
    {
        string del = in.substr(2,in.find(">")-2);
        current_tag.erase(current_tag.find(del),del.length());
        if(current_tag != "") current_tag.erase(current_tag.find_last_of("."),1);

    }
}
    //cin.ignore();
    for(int j = 0;j<Q;j++)
    {
        getline(cin,in);
        detect.push_back(in);

    }
    for (auto x : detect)
    {
        if(mp[x] != "") cout << mp[x] << endl;
        else cout << "Not Found!\n";
    }
}
