#include<iostream>
using namespace std;

union Test{
    int x;
    int y;
};


int main()
{
    Test t;
    t.x = 10;
    cout << t.x << ' ' << t.y << '\n';
    t.y = 20;
    cout << t.x << ' ' << t.y << '\n';
    cout << sizeof(t);
    return 0;
}



#include<iostream>
using namespace std;

union Test{
    int x;
    char y;
    double z;
};


int main()
{
    cout << sizeof(Test);
    return 0;
}



#include<iostream>
using namespace std;

union Test1
{
    int x;
    float y;
};

union Test2
{
  int x;
  char bin[4]; 
};

int main()
{
    Test1 t1;
    t1.y = 1.1;
    cout << t1.x << '\n';
    
    Test2 t2;
    t2.x = 512;
    cout << (int)t2.bin[0] << " " << (int)t2.bin[1] << " "
         << (int)t2.bin[2] << " " << (int)t2.bin[3]; 
    return 0;
}



#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    union
    {
        struct
        {
            Node *left, *right;
        };
        struct
        {
            Node *prev, *next;
        };
    };
    Node(int x)
    {
        data = x;
    }
};

void makeLL()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    auto tail = head->next;
    tail->prev = head;
    tail->next = NULL;
    
    auto i = head;
    while(i!=NULL)
    {
        cout << i->data << ' ';
        i = i->next;
    }
}


void makeBT()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    
    queue<Node*>q ;
    q.push(root);
    while(!q.empty())
    {   
        auto t = q.front(); 
        q.pop();
        cout << t->data << ' ';
        if(t->left!=NULL)
        {
            q.push(t->left);
        }
        if(t->right!=NULL)
        {
            q.push(t->right);
        }
    }
    
}

int main()
{
    makeLL();
    cout << '\n';
    makeBT();
    return 0;
}




