typedef struct Node{
    void* next;
    int data;
} Node;
struct Node* add(int data);
struct Node* insert(int data, int nodeData);
struct Node* removeNode(int data);
void show_list();
void process_user_input();