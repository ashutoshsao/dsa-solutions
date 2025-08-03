#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Recursive function to generate valid balanced brackets
void generate(int openP, int closeP, int openB, int closeB, string curr,
              string stack, vector<string> &result) {

  // Base case: all brackets used
  if (openP == 0 && closeP == 0 && openB == 0 && closeB == 0) {
    result.push_back(curr);
    return;
  }

  // Try to open a parenthesis '('
  if (openP > 0) {
    generate(openP - 1, closeP, openB, closeB, curr + '(', stack + '(', result);
  }

  // Try to open a brace '{'
  if (openB > 0) {
    generate(openP, closeP, openB - 1, closeB, curr + '{', stack + '{', result);
  }

  // Try to close a parenthesis ')'
  if (closeP > openP && !stack.empty() && stack.back() == '(') {
    generate(openP, closeP - 1, openB, closeB, curr + ')',
             stack.substr(0, stack.size() - 1), result);
  }

  // Try to close a brace '}'
  if (closeB > openB && !stack.empty() && stack.back() == '{') {
    generate(openP, closeP, openB, closeB - 1, curr + '}',
             stack.substr(0, stack.size() - 1), result);
  }
}

// Main function to initiate generation
vector<string> generateBalancedBrackets(int n, int m) {
  vector<string> result;
  generate(n, n, m, m, "", "", result);
  return result;
}

int main() {
  int n, m;
  cout << "Enter number of pairs of parentheses (): ";
  cin >> n;
  cout << "Enter number of pairs of curly braces {}: ";
  cin >> m;

  vector<string> combinations = generateBalancedBrackets(n, m);

  cout << "\nAll valid balanced combinations:\n";
  for (const string &combo : combinations) {
    cout << combo << endl;
  }

  return 0;
}
