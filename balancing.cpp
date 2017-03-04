//ricky romero

#include "stack.hpp"
using namespace std;

int main(){
//    freopen("/Users/rickyromero/school/Stacks-and-related-problems/input_balanced.txt", "r", stdin);
  freopen("input_balanced.txt", "r", stdin);
  string s,r;
  int line_counter;
  while(cin >> r){
    cin>>s;
    Stack<char> stack;
    bool isBalanced = true;
    bool solution;
    if(r[0] == 'Y' || r[0] == 'y'){
      solution = true;
    }else{
      solution = false;
    }
    // The input file is in the format "expected_solution expression"
    // so variable solution tells you whether 'expression' is balanced or not

      //remove when done
      for(int i=0; i<s.length(); ++i){
          // WRITE CODE HERE so that isBalanced indicates whether 's' is balanced
//          cout << s[i] << " ";
      }
      //
      
    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE so that isBalanced indicates whether 's' is balanced
        
        //check if open {,(,[
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            
            //push to stack
            stack.push(s[i]);
//            cout << "push to stack" << " " << s[i] << endl;

        }
        //check if it is a closing
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            char top = stack.top();
            //if top ele on stack needs to match the closing
            if(s[i] == ')' && top == '('){
                stack.pop();
//                cout << "pop from stack" <<  " " << s[i] << endl;
            }else if(s[i] == '}' && top == '{'){
                stack.pop();
//                cout << "pop from stack" <<  " " << s[i] << endl;
            }else if(s[i] == ']' && top == '['){
                stack.pop();
//                cout << "pop from stack" <<  " " << s[i] << endl;
            }else{
//                cout << "ERROR!!" << endl;
//                stack.display();
                isBalanced = false;
                break;
            }
            
        }
        
        //else do nothing
    }
//      cout << endl;


    // checking if you stored in isBalanced the correct value
    if(isBalanced == solution){
      cout << "line " << line_counter << ": OK [" << solution << " " << isBalanced << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << isBalanced << "]" << endl;
    }
    line_counter++;
//    cout << endl;

  }

}
