class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;

        for (const string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                stack.push(std::stoi(token));
            } else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                int result = 0;

                if (token == "+") {
                    result = a + b;
                } else if (token == "-") {
                    result = a - b;
                } else if (token == "*") {
                    result = a * b;
                } else if (token == "/") {
                    result = a / b;  // divisione intera troncata verso zero
                }

                stack.push(result);
            }
        }

        return stack.top();
    }
};