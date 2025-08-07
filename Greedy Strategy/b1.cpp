/*
Implement a problem of activity selection problem with K persons.
Problem Statement: given two arrays S[] and E[] of size N denoting starting and closing time of the shop and an integer value K denoting the number of people, the task is to find out the maximum number of shops they can visit in total if they visit each shop optimally based on the following conditions:
1) A shop can be visited by only one person.
2) A person cannot visit another shop if its timing collide with it

-> 1.input 
S[]={1,8,3,2,6}
E[]={5,10,6,5,9}
K=2
Output = 4

-> 2.input
S[]={1,2,3}
E[]={3,4,5}
K=2
Output = 3

*/

#include<iostream>
using namespace std;

int main(){
    //declaration part
    int N; //number of shops
    cout<<"Enter Total Shops : ";
    cin>>N;
    int S[N],E[N];     //to store the start and end time of the shops
    bool isvisited[N]={false};    //to check if a shop is visited or not 
    int K;    //to store no. of peoples
cout<<"Enter Total Persons :";
cin>>K;
    int current , count =0;

    //accepting the start and end time
    for(int i =0;i<N;i++){
        cout<<i+1<<" Shop Start Time :";
        cin>>S[i];
        cout<<i+1<<" Shop End Time :";
        cin>>E[i];
    }

    //sorting the accepted input in array
for(int i =0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
        if(S[i]>S[j]){
            swap(S[i],S[j]);     
            swap(E[i],E[j]);     
        }
    }
}
//main logic 
for(int i =0;i<K;i++){
    current = S[i];
    for(int j=0;j<N;j++){
        if(!isvisited[j] && S[j]>= current){
            isvisited[j]= true;
            current = E[j];
            count++;
        }
    }
}
cout<<"Total Visited shops : "<<count<<endl;


    return 0;
}