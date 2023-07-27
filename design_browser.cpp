#include <vector>
#include <string>

using namespace std;

class BrowserHistory {
private:
    vector<string> history; // first create a vector 
    int current_index; // take a veriable this name is current_index

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage); // insert homepage in vector 
        current_index = 0; // current_index variable equal 0 
    }

    
    void visit(string url) {
        history.erase(history.begin() + current_index + 1, history.end()); // clera vector using stl erase()
        history.push_back(url); // insert url in vector 
        current_index = history.size() - 1;//after insert we need current_index . if an current_index to history size() to (-) mineous 1 .
    }
    string back(int steps) {
         current_index = max(0, current_index - steps);//current_index max we need find 
        return history[current_index]; //return history
    }
    
    string forward(int steps) {
         current_index = min((int)history.size() - 1, current_index + steps); //we need find min current_index
        return history[current_index];//return history
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */