#include "stack.hpp"

using namespace std;

template<class T>
void Stack<T>::push(T c){
    //push to array

    topIndex++;
    arr[topIndex] = c;
    
//    cout << "top: " << arr[topIndex] << endl;
//    int size_arr = size();
//    cout << "size_arr: " << size_arr << endl;

}
template<class T>
void Stack<T>::pop(){
    // your code goes here, check stack.hpp for the description of each method
    topIndex--;
}


template<class T>
T Stack<T>::top(){
  // your code goes here, check stack.hpp for the description of each method
  return arr[topIndex];
}


template<class T>
int Stack<T>::size(){
  // your code goes here, check stack.hpp for the description of each method
  return topIndex;
}

template<class T>
void Stack<T>::display(){
  // your code goes here, check stack.hpp for the description of each method
    cout << "inside stack: [ ";
    for (int i = topIndex; i >= 0; i--)
        cout << arr[i] << ", ";
    cout << "]" <<  endl;
}

template class Stack<char>;
template class Stack<int>;
