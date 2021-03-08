#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> input_vec) {
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
  vector<int> input_vec{2, 3, 5, 4, 1};
  vector<int> output_vec = solution(input_vec);
  for (const auto output : output_vec) {
    cout << output << ", ";
  }
  return 0;
}
