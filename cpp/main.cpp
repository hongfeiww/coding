#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <list>
#include "graph.h"

#include "details.h"
#include "dp.h"

using namespace std;

int main() {

    // test
//    graph::Graph g;
    vector<vector<int>> vec = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    // auto res = g.highestPeak(vec);
//    for (int i=0;i<res.size();i++){
//        for (int j=0;j<res[0].size();j++){
//            std::cout << res[i][j] << " , ";
//        }
//        std::cout << endl;
//    }
//    details d;
    dp::dp d;
//    vector<int> input = {10,10,1,10,10};
    auto res = d.dicesProbability(2);
//    cout<<res<<endl;
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i];
    }


//    tree::Tree tree1;
//    tree::TreeNode* root = new tree::TreeNode(1);
//    root->right = new tree::TreeNode(2);
//    root->right->left = new tree::TreeNode(3);
    //root->left->right = new tree::TreeNode(4);
//    tree::TreeNode* root2 = new tree::TreeNode(1);
//    root2->left = new tree::TreeNode(2);
//    int res = (root == root2)?1:0;
//    cout<<res;
//    root->right = new tree::TreeNode(0);
//    root->right->left = new tree::TreeNode(0);
//    root->right->right = new tree::TreeNode(1);

//    vector<int>input{-1,2,0,2,0};
//    tree1.inOrderNonRecur(root);

    // basic types
    min(0, 1);
    fmin(1.0, 2.0);
    abs(1 - 2);
    int string_to_int = stoi("12");
    double double_val = 1.0/6;

    //pair
    pair<int, double> pair_demo(1, 1.0);
    auto pair_init = make_pair(0, 1);


    // struct && typedef
    struct StructDemo {
        int int_obj;
        double double_obj;
    };
    struct StructDemo struct_demo;
    struct_demo.int_obj = 1;
    struct StructDemo *struct_demo_pointer = &struct_demo;
    struct_demo_pointer->int_obj = 1;
    typedef struct StructDemoTypeDef {
        int int_obj;
        double double_obj;
    } StructDemoTypeDef;
    typedef long int *long32;
    long32 long_pointer;

    //class
    //overload：具有相同名称的声明，但是它们的参数列表和定义（实现）不相同
    class classDemo {
    private:
        string str_obj;
        int int_obj;
    public:
        int get();

        void set(int int_obj);

        classDemo(int int_val) { int_obj = int_val; }

        classDemo() {}
    };
    classDemo class_demo;
    classDemo *class_demp_with_params = new classDemo(1); //must be a pointer


    //containers
    //https://www.jianshu.com/p/497843e403b4
    // string
    std::string str = std::to_string(1);
    str.substr(0, 1); //pos and size
    str.append(str);
    str = str + str;
    string str_init = string("abc");
    str_init[0];
    char ch = str_init.at(0);
    str.size();
    // string转char *
    const char *p = str_init.c_str();
    stoi(str);

    //vector, dynamic arrays
    vector<int> vec_demo;
    vector<vector<int>> vec_2d_demo(10, vector<int>(10));
    vec_demo.push_back(
            1); //push_back是在当前vector的内存末尾拷贝元素进入容器。注意这个地方可能产生浅拷贝，所以容器中的对象要支持拷贝操作。另外，如果vector初始化了个数，而不初始化具体的值，push_back也只会在最后面追加。
    vec_demo.pop_back();
    vec_demo.back();
    vec_demo.front();
    vec_demo.push_back(1);
    vec_demo.insert(vec_demo.begin(),1);
    vec_demo[0];
    vec_demo.at(0);
    vector<int> vec_init(10);  // 10 is size
    for (int & vec_single : vec_demo) {}
    auto vec_iter = vec_demo.begin();
    while (vec_iter != vec_demo.end()) {
        vec_iter++;
    }
    vector<int> vec_demo2(vec_demo.begin(), vec_demo.begin() + 1);

    // map
    map<int, char> map_demo;
    for (auto p: map_demo) {
        p.first;
        p.second;
    }
    map<tree::TreeNode *, int> tree_map;
    tree_map[nullptr] = 1;

    list<int> list_demo;

    //  queue
    queue<int> queue_demo;
    queue_demo.emplace(1);
    queue_demo.pop();
    queue_demo.front();
    bool queue_is_empty = queue_demo.empty();
    queue<tree::TreeNode *> pointer_queue_demo;
    pointer_queue_demo.emplace(nullptr);
    pointer_queue_demo.size();
    priority_queue<int>priorityQueue;

    // stack
    stack<int> stack_demo;
    stack_demo.empty();
    stack_demo.emplace(1);
    stack_demo.push(1);
    stack_demo.pop();
    stack_demo.top(); //empty stack will occur error


    priority_queue<int, vector<int>, greater<int>> pqueue_demo;
    deque<int> deque_demo;

    //set
    set<int> set_demo;
    unordered_set<int> u_set_demo;
    set_demo.count(1);
    set_demo.insert(1);

    //functions
    int std_max_result = std::max(1, 2);
    sort(vec_demo.begin(),vec_demo.end());





}
