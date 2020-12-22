//This helped in understanding -> https://www.youtube.com/watch?v=uCsD3ZGzMgE&t=269s
//The above approach was static as k = 1 but the idea to express it in binary was amazing.
//This helped me in Implementation -> https://www.youtube.com/watch?v=ULUNeD0N9yI&t=201s
//In the original problem n was 41 and k was 1 and my code gives the correct answer which is 19 
//Recursive implementation... by me ̥
#include <iostream>
#include<vector>
using namespace std;
int k;
vector<int>m;
int josephus(int pos,int n){
    if(n == 1) {
        return m[pos];
    }
    
    for(int i=0;i<m.size();i++) cout<<m[i]<<" ";
    cout<<endl;
    
    auto it = m.begin()+(pos+k)%m.size();
    cout<<"Killed "<<*it<<" at position "<<(it-m.begin())<<endl;
    m.erase(it);
    
    
    if(it - m.begin() <= pos){
    return josephus(pos % m.size(),n-1);
    }
    else{
    return josephus(pos+1 % m.size() , n-1);
    }
    
}

int main()
{
    int n;
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++) m.push_back(i);
    cout<<josephus(0,n);
    return 0;
}
