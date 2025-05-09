#include <bits/stdc++.h>
#define ll long long
using namespace std;

int hash1(string s , int size){
    ll int hash =0;
    for(int i =0;i<s.size();i++){
        hash = (hash + ((int)s[i]));
        hash = hash % size;
    }
    return hash;
}

int hash2(string s, int size){
    ll int hash =1;
    for(int i =0;i<s.size();i++){
        hash = hash + pow(19,i) * s[i];
        hash = hash % size;
    }
    return hash % size;
}


int hash3(string s , int size){
    ll int hash = 7;
    for(int i =0;i<s.size();i++){
        hash = (hash*31 + s[i]) % size;
    }
    return hash % size;
}

int hash4(string s , int size){
    ll int hash = 3;
    int p = 7;
    for(int i =0;i<s.size();i++){
        hash += hash * 7 + s[0] + pow(p,i);
        hash = hash % size;
    }
    return hash;
}

bool lookup(bool* bitarray, int size, string s){
    int a = hash1(s, size);
    int b = hash2(s, size);
    int c = hash3(s, size);
    int d = hash4(s, size);
    if (bitarray[a] && bitarray[b] && bitarray[c] && bitarray[d])
        return true;
    else
        return false;
}


bool insert(bool* bitarray, int size , string s){
    if(lookup(bitarray, size, s)){
        cout << s << " is Probably already present" << endl;
    }else{
        int a = hash1(s, size);
        int b = hash2(s, size);
        int c = hash3(s, size);
        int d = hash4(s, size);

        bitarray[a] = true;
        bitarray[b] = true;
        bitarray[c] = true;
        bitarray[d] = true;

        cout<<s<<" is inserted"<<endl;
    }
}

int main(){
    bool bitarray[100] = { false };
    int size = 100;

    string sarray[34] = {
        "abound",   "abounds",       "abundance",
        "abundant", "accessible",    "bloom",
        "blossom",  "bolster",       "bonny",
        "bonus",    "bonuses",       "coherent",
        "cohesive", "colorful",      "comely",
        "comfort",  "gems",          "generosity",
        "generous", "generously",    "genial",
        "bluff",    "cheater",       "hate",
        "war",      "humanity",      "racism",
        "hurt",     "nuke",          "gloomy",
        "facebook", "geeksforgeeks", "twitter" , "race"
    };
    for(int i =0;i<34;i++){
        insert(bitarray, size, sarray[i]);
    }
    return 0;
}