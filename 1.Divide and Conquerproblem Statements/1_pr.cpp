#include <iostream>
#include <string>
using namespace std;

class expression {
private:
    string savedExpr[50];          //  expressions
    int storedResults[50][10]; //  results
    int resultSizes[50];       // result counts 
    int entryCount = 0;        //  entries

public:
    // Recursively evaluate  results
    void evaluate(string expr, int output[], int &count) {
        //  Check cache first
        for (int i = 0; i < entryCount; i++) {
            if (savedExpr[i] == expr) {
                count = resultSizes[i];
                for (int j = 0; j < count; j++) {
                    output[j] = storedResults[i][j];   
                }
                return;
            }
        }

        count = 0;

        //  splitting at every operator
        for (int i = 0; i < expr.length(); i++) {
            char op = expr[i];
            if (op == '+' || op == '-') {
                string left = expr.substr(0, i);
                string right = expr.substr(i + 1);

                int leftVals[10], rightVals[10];
                int leftCount = 0, rightCount = 0;

                // Recursively evaluate left and right
                evaluate(left, leftVals, leftCount);
                evaluate(right, rightVals, rightCount);

                // Combine results
                for (int x = 0; x < leftCount; x++) {
                    for (int y = 0; y < rightCount; y++) {
                        int val;
                        if (op == '+') {
                            val = leftVals[x] + rightVals[y];
                        } else {
                            val = leftVals[x] - rightVals[y];
                        }
                        output[count++] = val;
                    }
                }
            }
        }

        // base case
        if (count == 0) {
            int number = 0;
            for (int i = 0; i < expr.length(); i++) {
                number = number * 10 + (expr[i] - '0');
            }
            output[count++] = number;
        }

        // 4. Save to cache
        savedExpr[entryCount] = expr;
        resultSizes[entryCount] = count;
        for (int j = 0; j < count; j++) {
            storedResults[entryCount][j] = output[j];
        }
        entryCount++;
    }
};

int main() {
    string input;
    cout << "Enter expression (only + or -): ";
    cin >> input;

    expression solver;
    int finalResult[20];
    int total = 0;

    solver.evaluate(input, finalResult, total);

    cout << "All possible results: [";
    for (int i = 0; i < total; i++) {
        cout << finalResult[i];
        if (i < total - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}