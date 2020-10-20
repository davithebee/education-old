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
    string min_binary, max_binary;

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
    vector<int> indeks_min, indeks_max;
    in.seekg(0);
    for(int i=0; i<1000; i++){
        in>>s;
        if(s.size()== min_size){
                tab_min.push_back(s);
                indeks_min.push_back(i);
        }
        if(s.size()== max_size){
                tab_max.push_back(s);
                indeks_max.push_back(i);
        }
        }

    out<<"ZADANIE 1:"<<endl;
    out<<more_zero_than_one<<endl<<endl;

    out<<"ZADANIE 2:"<<endl;
    out<<divisible_by_2<<endl;
    out<<divisible_by_8<<endl<<endl;

    out<<"ZADANIE 3:"<<endl;

    min_binary=tab_min[0];
    max_binary=tab_max[0];
    for(int i=1; i<tab_min.size(); i++){
            for(int j=1; j<min_size; j++){
                if(tab_min[i][j]<min_binary[j]){
                    min_binary=tab_min[i];
                    break;
                }
            }
    }

    for(int i=0; i<indeks_min.size(); i++){
        if(min_binary==tab_min[i]) out<<indeks_min[i]+1<<endl;
    }

    for(int i=1; i<tab_max.size(); i++){
            for(int j=1; j<max_size; j++){
                if(tab_max[i][j]<max_binary[j]) break;
                if(tab_max[i][j]>max_binary[j]){
                    max_binary=tab_max[i];
                    break;
                }
            }
    }

    for(int i=0; i<indeks_max.size(); i++){
        if(max_binary==tab_max[i]) out<<indeks_max[i]+1<<endl;
    }

    return 0;
}
