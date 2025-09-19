class Browser
{
    public:

    struct Node {
        string url;
        Node* prev;
        Node* next;
        Node(string u) : url(u), prev(NULL), next(NULL) {}
    };

    Node* curr;

    
    Browser(string &homepage)
    {
        // make a new node 
         curr = new Node(homepage);
    }

    void visit(string &url)
    {
       
       Node* newpage = new Node(url);
       curr->next = newpage;
       newpage->prev = curr;
       curr = newpage;
    }

    string back(int steps)
    {
        while(steps-- && curr->prev){
               curr = curr->prev;
        }

         return curr->url;
    }

    string forward(int steps)
    {
         while(steps-- && curr->next){
               curr = curr->next;
        }

         return curr->url;
    }
};
