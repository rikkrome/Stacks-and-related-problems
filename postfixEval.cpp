#include "stack.hpp"

using namespace std;

int main(){
//    freopen("/Users/rickyromero/school/Stacks-and-related-problems/input_postfixEval.txt", "r", stdin);
  freopen("input_postfixEval.txt", "r", stdin);
  string s;
  int solution;
  int line_counter = 0;
  while(cin>>solution){
    cin>>s;
    Stack<int> stack;
    // The input file is in the format "expected_solution postfix_expression"
      
      //print
//      for(int i=0; i<s.length(); ++i){
//          cout << s[i] << " ";
//      }
//      cout << endl;
      //
      
    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE to evaluate the postfix expression in s
      // At the end of the loop, stack.top() should contain the value of the postfix expression
      // We assume that all operands in the input are one digit (so they range from 0 to 9)
        int sum = 0;
        if(isdigit(s[i])){
            int input = s[i] - '0';
//               cout << input << " ";

            stack.push(input);
        }else{
            int A = stack.top();
            stack.pop();
            int B = stack.top();
            stack.pop();
            

            if(s[i] == '+'){
                sum = B + A;
//                cout << "sum: " << sum << endl;
                stack.push(sum);
            }else if(s[i] == '-'){
                sum = B - A;
//                cout << "sum: " << sum << endl;
                stack.push(sum);
            }else if(s[i] == '*'){
                sum = B * A;
//                cout << "sum: " << sum << endl;
                stack.push(sum);
            }
            else if(s[i] == '/'){
                sum = B / A;
//                cout << "sum: " << sum << endl;
                stack.push(sum);
            }
                
            
        }
    }
//      cout << endl;
      //
      
      
    // Checking whether the value you calculated is correct ...
    int value = stack.top();

    if(solution == value){
      cout << "line " << line_counter << ": OK [" << solution << " " << value << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << value << "]" << endl;
    }
    line_counter++;


  }
    
    //for testing on an IDE
//    return 0;

}
