#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool parenthCheck(string input);

int main()
{
    //stack<int> myStack;
    //stack int type called myStack
    bool correct = false;
    string input = "";
    cout << "Please type the expression you want to check for correct parathensis" << endl;
    cin >> input;

    correct = parenthCheck(input);

    if(correct){
        cout << "This statement has complete set(s) of parenthesis" <<endl;
    }
    return 0;
}

/* Stacks parenthesis from input/ pushes closing statements to tracking stack/ compares pairing of top values
@param input: input to be placed in stack
@return: true if all characters are cleared within the stack which means each bracket has a pair
@retirn: false if stacks still hold values which means pairing did not happen
@pre: initialize stacks to be used and use symbol arrays for guide on what conditionals need to look for
@post: stacks must be empty to be passed true
*/
bool parenthCheck(string input)
{
    char parenthSym[6] = {'[', ']', '{', '}', '(', ')'};
    char openSym[3] = {'{', '[', '('};
    char closeSym[3] = {'}', ']', ')'};
    stack<char> fullStack;
    stack<char> trackStack;

    for (int i = 0; i < input.length(); i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (input[i] == parenthSym[j])
            {
                fullStack.push(input[i]);
                cout << fullStack.top() << " Has ben placed in fullstack!" <<endl;
                break;
            }
        }
    }

        while (!fullStack.empty())
        {
            //nothing to track
            if(trackStack.empty()){
                for(int i=0; i<3; i++){
                    if(fullStack.top() == openSym[i]){
                        cout<< "cannot have open parenthesis without a closer" <<endl;
                        return false;
                    }
                }
                trackStack.push(fullStack.top());
                cout << fullStack.top() << " Has been added to the trackStack" << endl;
                fullStack.pop();
            }
            //something to track
            
            else if(!trackStack.empty()){
                //found the opener to the closer
                for(int i=0; i<3; i++){
                    if((fullStack.top() == openSym[i]) && (trackStack.top() == closeSym[i])){
                         
                        cout << "Pairs " << trackStack.top() << " & " << fullStack.top()<< " have complete pairs" << endl;
                        fullStack.pop();
                        trackStack.pop();
                        break;
                    }
                    else if(fullStack.top() == openSym[i]){
                        cout << "your brackets are mixed up and not in proper scope" <<endl;
                        return false;
                    }
                    else if(fullStack.top() == closeSym[i]){
                        trackStack.push(fullStack.top());
                        cout << fullStack.top() << " has been added to the track stack" << endl;
                        fullStack.pop();
                        break;
                    }
                }
            }
        }\
        if(!trackStack.empty()){
            cout << "You have closing parenthesis not in use!!" << endl;
            return false;
        }
        return true;
    }