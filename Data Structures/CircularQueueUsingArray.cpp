#include <iostream>
using namespace std;

class cqueue
{
    private:
        int front,rear;
        int *arr;
        int n,eleCount;

    public:
        cqueue(int x)
        {
            n=x;
            eleCount=0;
            front=-1;
            rear=-1;
            arr=new int[n];
            for (int i=0;i<n;i++)
                arr[i]=0;
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
            if ((rear+1)%n==front)
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
                arr[rear]=val;
            }
            else 
            {
                rear=(rear+1)%n;
                arr[rear]=val;
            }
            eleCount++;
        }

        int dequeue()
        {
            int x;
            if (isempty())
            {
                cout<<"Queue is empty"<<endl;
                return 0;
            }
            else if (front==rear)
            {
                x=arr[front];
                arr[front]=0;
                front=-1;
                rear=-1;
                eleCount--;
                return x;
            }
            else
            {
                x=arr[front];
                arr[front]=0;
                front=(front+1)%n;
                eleCount--;
                return x;
            }
        }

        int count()
        {
            return eleCount;
        }

        void display()
        {
            if (isempty())
                cout<<"There are no elements in the Queue"<<endl;
            else
            {
                cout<<"All the elements in the Queue are as follows- "<<endl;
                if (rear>=front)
                {
                    for (int i=front;i<=rear;i++)
                    {
                        cout<<arr[i]<<endl;
                    }
                }
                else 
                {
                    for (int i=front;i<n;i++)
                    {
                        cout<<arr[i]<<endl;
                    }
                    for (int i=0;i<=rear;i++)
                    {
                        cout<<arr[i]<<endl;
                    }
                }
            }
        }
};

int main()
{
    cout<<"Please enter the size of the queue"<<endl;
    int n=0;
    cin>>n;
    cqueue q(n);
    int option=0,pos=0,val=0;
    do
    {
        cout<<endl;
        cout<<"Please choose from the following options-"<<endl;
        cout<<"1. To perform the enqueue opeation"<<endl;
        cout<<"2. to perform the dequeue operation"<<endl;
        cout<<"3. To check if the queue is empty"<<endl;
        cout<<"4. To check if the queue is full"<<endl;
        cout<<"5. To count the total number of elements in the queue"<<endl;
        cout<<"6. To display all the elements in the queue"<<endl;
        cout<<"7. To clear the screen"<<endl;
        cout<<"8. To exit"<<endl;
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
                cout<<"The total number of elements in the queue are- "<<q.count()<<endl;
                break;
            }
            case (6):
            {
                q.display();
                break;
            }
            case (7):
            {
                system("cls");
                break;
            }
            default:
            {
                if (option!=8)
                    cout<<"Please enter valid option number"<<endl;
            }
        }
    }while (option!=8);
    cout<<"Program Terminated"<<endl;
    return 0;
}
