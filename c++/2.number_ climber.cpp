/*
For every positive integer N, there exists a unique sequence starting with 1 and ending with N and such that every number in the sequence is either the double of the preceeding number or the double plus 1.

For example, given N = 13, the sequence is [1, 3, 6, 13], because . . . :

 3 =  2*1 +1
 6 =  2*3
 13 = 2*6 +1
Write a function that returns this sequence given a number N. Try generating the elements of the resulting list in ascending order, i.e., without resorting to a list reversal or prependig the elements to a list.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

std::vector<int> climb(int n) {
    std::stack<int> s;
    s.push(n);
    while(n/2) {
        s.push(n/2);
        n = n/2;
    }
    std::vector<int> res;
    while(!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc != 2 ) {
        return -1;
    }
    std::stringstream ss(argv[1]);
    int c;
    ss >> c;
    std::vector<int> res = climb(c);
    for (size_t i=0;i<res.size(); ++i) {
        std::cout << res[i] << " "; 
    }
    std::cout << std::endl;
}