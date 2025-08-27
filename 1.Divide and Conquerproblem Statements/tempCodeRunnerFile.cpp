#include<iostream>
#include<string>
using namespace std;

class expression{
     string savedExp[50];
     int storedResults[10][10];
     int resultSizes[50];
     int entryCount = 0;
     public:
     void evaluate(string expr,int output[],int count[]){
        for(int i = 0; i < entryCount;i++){
            count = resultSizes[i];
            for(int j = 0;j < count;j++){
                output[j] = storedResults[i][j];

            }
            return;
        }
     }
     
    }
    count = 0 ;

//splitting every operator

for(int i = 0;i < expr.length();i++){
    char op = expr[i];
    if(op == '+' || op == '-'){
        string left = expr.substr(0,i);
        string right = expr.substr(i+1);

        int leftVals[10],rightVals[10];
        int leftCount = 0,int rightCount = 0;

        //recursively evaluate left and right 
        evaluate(left,leftVal,leftCount);
        evaluate(right,rightVal,rightCount);

        //combine results

        for(int x = 0;x < leftCount;x++){
            for(int u = 0;y<rightCount;y++){
                int val;
                if(op == '+'){
                    val = leftVals[x] + rightVals[y];

                }
                else{
                    val = leftVals[x] - rightVals[y];
                }
                output[count++] = val;
            }
        }

    }
}