#include "stack.hpp"

using namespace std;

// Auxiliary method, you probably find it useful
// Operands are all lower case and upper case characters
bool isOperand(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Auxiliary method, you probably find it useful
int precedence(char c)
{
  if(c == '+' || c == '-'){
    return 0;
  }
  if(c == '*' || c == '/'){
    return 1;
  }
  if(c == '^'){
    return 2;
  }
  return -1;
}


int main(){
//    freopen("/Users/rickyromero/school/Stacks-and-related-problems/input_infix2postfix.txt", "r", stdin);
  freopen("input_infix2postfix.txt", "r", stdin);
  string input;
  string solution;
  int line_counter = 0;
  while(cin >> solution){
    cin >> input;
    Stack<char> stack;
    string result;
    //The input file is in the format "expected_solution infix_expression", where expected_solution is the infix_expression in postfix format

      //print
//      for(int i=0; i<input.length(); ++i){
//          // WRITE CODE HERE so that isBalanced indicates whether 's' is balanced
//          cout << input[i] << " ";
//      }
//      cout << endl;
      //
      
      
      
    for(int i=0; i<input.length(); ++i){
      // WRITE CODE HERE to store in 'result' the postfix transformation of 'input'
        bool pop = true;

        //isOperand or
        bool inputType = isOperand(input[i]);

        
        //if Operand just add to result
        //
        if(inputType){
            result = result+input[i];
        }
        /*
         if its a closing
        */
        else if(input[i] == ')' || input[i] == ']' || input[i] == '}'){
            //pop until you find the opening
            while(pop){
                char top = stack.top();
                if(top == '(' || top == '[' || top == '{'){
                    stack.pop();
                    pop = false;
                }else{
                    result = result+top;
                    stack.pop();
                }
            }
//            stack.display();
//            cout << "result: " << result << endl << endl;

            
        }
        //if its an opening
        else if (input[i] == '(' || input[i] == '[' || input[i] == '{'){
            stack.push(input[i]);
//            stack.display();
//            cout << "result: " << result << endl << endl;
        
        }
        //if its not a opening or close
        else{
            int A = precedence(input[i]);
            pop = true;
            
            if(stack.size() == -1){
                stack.push(input[i]);
//                stack.display();
//                cout << "result: " << result << endl << endl;


            }else{
                while(pop){
                    char top = stack.top();
                    //if input is higher than top element push
                    if(precedence(input[i]) > precedence(top)){
                        stack.push(input[i]);
                        pop = false;
//                        stack.display();
//                        cout << "result: " << result << endl << endl;
                    }
                    //if input is lower or equal to top elemnt pop until you find elemt that is higher
                    else {
                        result = result+top;
                        stack.pop();
//                        stack.display();
//                        cout << "result: " << result << endl << endl;
                    }
                }
                
            }

            
        }
    } //end of loop
      
      //pop the leftovers in the stack
      while(stack.size() != -1){
          char top = stack.top();
          result = result+top;
          stack.pop();
      }

    // You need to do some extra stuff here to store in 'result' the postfix transformation of 'input'

    // Checking whether the result you got is correct
    if(solution == result){
      cout << "line " << line_counter << ": OK [" << solution << " : " << result << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " : " << result << "]" << endl;
    }
    line_counter++;
      
//      cout << endl;
  }
    //for testing
//    return 0;
    
}




