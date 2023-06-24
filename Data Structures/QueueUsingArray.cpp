#include <iostream>
using namespace std;

class queue
{
    private:
        int front,rear;
        int *arr;
        int n;

    public:
        queue(int x)
        {
            n=x;
            front=-1;
            rear=-1;
            arr=new int[n];
            for (int i=0;i<n;i++) arr[i]=0;
        }

        bool isempty()
        {
            if (front==-1 && rear==-1)
                return true;
            else
                return false;
        }

        bool isfull()
        {
            if (rear==n-1)
                return true;
            else
                return false;
        }

        void enqueue (int val)
        {
            if (isfull())
            {
                cout<<"Queue is full"<<endl;
                return;
            }
            else if (isempty())
            {
                rear=0;
                front=0;
            }
            else 
                rear++;
            arr[rear]=val;
        }

        int dequeue()
        {
            int x;
            if (isempty())
            {
                cout<<"Queue is empty"<<endl;
                return 0;
            }
            else if (rear==front)
            {
                x=arr[front];
                arr[front]=0;
                front=-1;
                rear=-1;
                return x;
            }
            else
            {
                x=arr[front];
                arr[front]=0;
                front++;
                return x;
            }
        }

        int count()
        {
            if (isempty())
                return 0;
            else 
                return rear-front+1;
        }

        int peek(int pos)
        {
            if (isempty())
                cout<<"Queue Underflow"<<endl;
            else if(pos>rear || pos<front)
                cout<<"Invalid position input"<<endl;
            else
                return arr[pos];
            return -1;
        }

        void change(int pos,int val)
        {
            if (pos>rear || pos<front)
                cout<<"Invalid position input"<<endl;
            else
            {
                arr[pos]=val;
                cout<<"Value changed at location "<<pos<<endl;
            }
        }

        void display()
        {
            if (isempty())
                cout<<"There are no elements in the Queue"<<endl;
            else
            {
                cout<<"All the elements in the Queue are as follows- "<<endl;
                for (int i=front;i<=rear;i++)
                {
                    cout<<arr[i]<<endl;
                }
            }
        }
};

int main()
{
    cout<<"Please enter the size of the queue"<<endl;
    int n=0;
    cin>>n;
    queue q(n);
    int option=0,pos=0,val=0;
    do
    {
        cout<<endl;
        cout<<"Please choose from the following options-"<<endl;
        cout<<"1. To perform the enqueue opeation"<<endl;
        cout<<"2. to perform the dequeue operation"<<endl;
        cout<<"3. To check if the queue is empty"<<endl;
        cout<<"4. To check if the queue is full"<<endl;
        cout<<"5. To peek a value at a specific position"<<endl;
        cout<<"6. To count the total number of elements in the queue"<<endl;
        cout<<"7. To change an element at a specific position"<<endl;
        cout<<"8. To display all the elements in the queue"<<endl;
        cout<<"9. To clear the screen"<<endl;
        cout<<"10. To exit"<<endl;
        cout<<endl;

        cin>>option;
        switch(option)
        {
            case (1):
            {
                cout<<"Please enter the element that is to be enqueued"<<endl;
                cin>>val;
                q.enqueue(val);
                break;
            }
            case (2):
            {
                int x=q.dequeue();
                if (x!=-1)
                    cout<<"The popped item is "<<x<<endl;
                break;
            }
            case (3):
            {
                if(q.isempty())
                    cout<<"The queue is empty"<<endl;
                else
                    cout<<"The queue is not empty"<<endl;
                break;
            }
            case (4):
            {
                if(q.isfull())
                    cout<<"The queue is full"<<endl;
                else
                    cout<<"The queue is not full"<<endl;
                break;
            }
            case (5):
            {
                cout<<"Enter the queue position to be peeked"<<endl;
                cin>>pos;
                if (q.peek(pos)!=-1)
                    cout<<"The element at position "<<pos<<" is "<<q.peek(pos)<<endl;
                break;
            }
            case (6):
            {
                cout<<"The total number of elements in the queue are- "<<q.count()<<endl;
                break;
            }
            case (7):
            {
                cout<<"Please enter the position of the item to be changed"<<endl;
                cin>>pos;
                cout<<"Please enter the new value"<<endl;
                cin>>val;
                q.change(pos,val);
                break;
            }
            case (8):
            {
                q.display();
                break;
            }
            case (9):
            {
                system("cls");
                break;
            }
            default:
            {
                if (option!=10)
                    cout<<"Please enter valid option number"<<endl;
            }
        }
    }while (option!=10);
    cout<<"Program Terminated"<<endl;
    return 0;
}