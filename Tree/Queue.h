class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(){
            this->left = 0;
            this->right = 0;
        }
        TreeNode(int data){
            this->data = data;
            this->left = 0;
            this->right = 0;
        }
};

class QueueNode {
    public:
        TreeNode *n;
        QueueNode *next;
        QueueNode(TreeNode *n){
            this->n = n;
            next = 0;
        }
};
class Queue {
    private:
        QueueNode *front, *rear;
    public:
        Queue(){
            front = rear = 0;
        }
        void enqueue(TreeNode *n){
            QueueNode *q = new QueueNode(n);
            if(front){
                rear->next = q;
                rear = rear->next;
            } else {
                front = rear = q;
            }
        }

        TreeNode * dequeue(){
            QueueNode *p;
            TreeNode *x = 0;
            if(front){
                p = front;
                front = front->next;
                x = p->n;
                delete p;
            }
            return x;
        }
        bool empty(){
            if(front) {
                return 0;
            }
            return 1;
        }
};
