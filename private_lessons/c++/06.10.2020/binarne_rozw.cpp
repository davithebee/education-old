#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool zero_count(string s){

    int zero_sum=0, one_sum=0;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='0') zero_sum++;
        if(s[i]=='1') one_sum++;
    }

    if(zero_sum>one_sum) return true;
    return false;
}

bool if_divide_2(string s){
    if(s[s.size()-1]=='0') return true;
    return false;
}

bool if_divide_8(string s){
    if(s[s.size()-1]=='0' && s[s.size()-2]=='0' && s[s.size()-3]=='0') return true;
    return false;
}

int main()
{
    fstream in, out;
    in.open("liczby.txt", ios::in);
    out.open("wynik.txt", ios::out);

    int more_zero_than_one=0, divisible_by_2=0, divisible_by_8=0;
    string s;
    int min_size=250, max_size=0;
    int min_binary=0, max_binary=0;

    if(in.good()){
        for(int i=0; i<1000; i++){
        in>>s;
        if(s.size()<min_size) min_size=s.size();
        if(s.size()>max_size) max_size=s.size();

        more_zero_than_one+=zero_count(s);

        divisible_by_2+=if_divide_2(s);
        divisible_by_8+=if_divide_8(s);

        }
    } else cout<<"ERROR";

    vector<string> tab_min, tab_max;
    in.seekg(0);
    for(int i=0; i<1000; i++){
        in>>s;
        if(s.size()== min_size) tab_min.push_back(s);
        if(s.size()== max_size) tab_max.push_back(s);
        }

    out<<"ZADANIE 1:"<<endl;
    out<<more_zero_than_one<<endl<<endl;

    out<<"ZADANIE 2:"<<endl;
    out<<divisible_by_2<<endl;
    out<<divisible_by_8<<endl<<endl;

    out<<min_size<<endl;
    out<<max_size<<endl;

    out<<"ZADANIE 3:"<<endl;
    in.seekg(0);
    for(int i=0; i<1000; i++){
        in>>s;
        if(s==min_binary){
            cout<<"Najmniejsza - "<<s;
            break;
        }
    }

    in.seekg(0);
    for(int i=0; i<1000; i++){
        in>>s;
        if(s==max_binary){
            cout<<"Najwieksza - "<<s;
            break;
        }
    }

    return 0;
}
