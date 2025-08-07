#include<iostream>
#include<string>
using namespace std;

class ExpressionSolver {
private:
    string savedExpr[50];
    int storedResults[50][10];
    int resultSizes[50];
    int entryCount = 0;

public:
    void evaluate(string expr, int output[], int &count) {
        // Check if this expression has been processed before
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

        for (int i = 0; i < expr.length(); i++) {
            char op = expr[i];
            if (op == '+' || op == '-' || op == '*') {
                string left = expr.substr(0, i);
                string right = expr.substr(i + 1);

                int leftVals[10], rightVals[10];
                int leftCount = 0, rightCount = 0;

                evaluate(left, leftVals, leftCount);
                evaluate(right, rightVals, rightCount);

                for (int x = 0; x < leftCount; x++) {
                    for (int y = 0; y < rightCount; y++) {
                        int val = 0;
                        if (op == '+') val = leftVals[x] + rightVals[y];
                        if (op == '-') val = leftVals[x] - rightVals[y];
                        if (op == '*') val = leftVals[x] * rightVals[y];
                        output[count++] = val;
                    }
                }
            }
        }

        // If it's a pure number with no operators
        if (count == 0) {
            int number = 0;
            for (int i = 0; i < expr.length(); i++) {
                number = number * 10 + (expr[i] - '0');
            }
            output[count++] = number;
        }

        // Save results for future lookup
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
    cout << "Enter expression: ";
    cin >> input;

    ExpressionSolver solver;
    int finalResult[20];
    int total = 0;

    solver.evaluate(input, finalResult, total);

    cout << "Results: [";
    for (int i = 0; i < total; i++) {
        cout << finalResult[i];
        if (i < total - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
