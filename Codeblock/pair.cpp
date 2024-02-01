#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int main(){
pair <int,int> v = {10,20};
//v = make_pair(100,200);
cout << v.first << endl;
cout << v.second << endl;
tuple <string,string,string,string> t = make_tuple("c","java","sql","python");
cout << get<0>(t) << endl;
cout << get<1>(t) << endl;
cout << get<2>(t) << endl;
cout << get<3>(t) << endl;
return 0;
}
