/*
implement a problem of minimum work to be done per day to co2 finish given 
tasks within D days problem 
statement : Given an array task[] of size N denoting amount of work to be 
done on each task. the problme is to find the minimum amount of work to be done on each day so that all the tasks can be completed in at most D days . 
Note : on one day work can be done for only one task.

input : 
task[]=[3,4,7,15] , D = 10
output : 4

task[]=[30,20,22,4,21] , D = 6
output : 22

*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    int D;
    cout<<"Enter Number of Days : ";
    cin>>D;
    int N;
    cout<<"Enter Number of Task : ";
    cin>>N;
    int arr[N];    //to store the work done for particular task
    int count =0;
    cout<<"Enter Work Required for each task";
    for(int i =0;i<N;i++){
        cin>>arr[i];
    }
    //Step 1 : Sort the Array in ascending order
    sort(arr, arr + N);

    //step 2 :
    float tempresult; 
    for(int i =0;i<N;i++){
        count = 0; // ✅ FIXED: reset count at start of each i loop

        for(int j =0;j<N;j++){
            tempresult = (float)arr[j] / arr[i]; // ✅ FIXED: force float division
            count += ceil(tempresult);
        }

        if(count<= D){
            cout<<"result : "<<arr[i]<<endl; // ✅ FIXED: was arr[i+1], caused out of bounds
            break;
        }
    }
    return 0;
}