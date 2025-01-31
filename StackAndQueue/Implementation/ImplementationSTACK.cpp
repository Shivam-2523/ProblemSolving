//ARRAYS->
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    // Your Code
    arr[++top]=x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if(top == -1)
        return -1;
    int temp = arr[top];
    arr[top] = 0;
    top--;
    return temp;
}


//QUEUE->
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
       return q1.front();
    }
    
    bool empty() {
        return (q1.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


//LINKED LIST->
class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        if(!top)
        {
            top = new StackNode (x);
        }else
        {
            StackNode * temp = new StackNode (x);
            temp->next = top;
            top = temp;
        }
    }

    int pop() {
        // code here
        if(!top)
            return -1;
            
        int ans = top->data;
        StackNode * temp = top->next;
        delete(top);
        top = temp;
        
        return ans;
    }

    MyStack() { 
        top = NULL;
    }
};
