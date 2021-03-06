#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution1(vector<int> input_vec) {
  vector<int> output_vec(input_vec.size());
  stack<int> stack;
  stack.push(input_vec[0]);
  for (int i = 1; i < input_vec.size(); ++i) {
    if (input_vec[i] < stack.top()) {
      int count = 1;
      int j = i;
      while (!stack.empty() && input_vec[i] < stack.top()) {
        stack.pop();
        if (output_vec[--j] == 0) {
          output_vec[j] = count++;
        }
      }
    }
    stack.push(input_vec[i]);
  }
  for (int i = 0; i < output_vec.size(); ++i) {
    if (output_vec[i] == 0) {
      output_vec[i] = output_vec.size() - i - 1;
    }
  }
  return output_vec;
}

vector<int> solution2(vector<int> input_vec) {
  vector<int> output_vec(input_vec.size());
  stack<int> stack;
  for (int i = 0; i < input_vec.size(); i++) {
    while (!stack.empty() && input_vec[stack.top()] > input_vec[i]) {
      output_vec[stack.top()] = i - stack.top();
      stack.pop();
    }
    stack.push(i);
  }
  while (!stack.empty()) {
    output_vec[stack.top()] = input_vec.size() - stack.top() - 1;
    stack.pop();
  }
  return output_vec;
}

int main() {
  vector<int> input_vec{1, 2, 3, 2, 3, 1};
  vector<int> output_vec1 = solution1(input_vec);
  vector<int> output_vec2 = solution2(input_vec);
  for (const auto output : output_vec1) {
    cout << output << ", ";
  }
  cout << endl;
  for (const auto output : output_vec2) {
    cout << output << ", ";
  }
  return 0;
}
