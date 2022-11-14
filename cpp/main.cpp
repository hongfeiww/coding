#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <list>
#include <numeric>
#include "graph.h"

#include "details.h"
#include "backtracking.h"
#include "dp.h"

using namespace std;

int main() {
    int i = std::round(0.81234 * 10);
    cout << i<<endl;

    // test
    graph::Graph g;
    vector<vector<int>> vec = {{1, 1, 1},
                               {1, 1, 0},
                               {1, 0, 1}};

     auto res = g.floodFill(vec,1,1,2);
//    for (int i=0;i<res.size();i++){
//        for (int j=0;j<res[0].size();j++){
//            std::cout << res[i][j] << " , ";
//        }
//        std::cout << endl;
//    }
    details d;
    backtracking bt;
//    dp::dp d;
    vector<int> input = {1,1,1,0,0,1};
    vector<int> input2 = {1,0,0,0,1,1};
    vector<string> input_str = {"word","good","best","good"};
//       auto res = d.advantageCount(input,input2);
    //   int res = g.kSimilarity("abccaacceecdeea","bcaacceeccdeaae");
    //auto res = d.countStudents(input,input2);
    //   cout << res << endl;
//    for (int i = 0; i < res.size(); i++) {
//        std::cout << res[i] << endl;
//    }


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

    double double_val = 1.0 / 6;

    ///pair
    pair<int, double> pair_demo(1, 1.0);
    pair<int, double> pair_demo2 = {1, 1.0};
    auto pair_init = make_pair(0, 1);
    auto[x, y]=pair_demo;



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

        classDemo(int int_val) { this->int_obj = int_val; }

        classDemo() {}
    };
    classDemo class_demo;
    classDemo *class_demp_with_params = new classDemo(1); //must be a pointer


    ////containers
    //https://www.jianshu.com/p/497843e403b4
    // string
    std::string str = std::to_string(1);
    str.substr(0, 1); //pos and size
    bool a = str.find(str) == string::npos;
    str.append(str);
    str = str + str;
    string str_init = string("abc");
    str_init[0];
    char ch = str_init.at(0);
    str.size();
    // string转char *
    const char *p = str_init.c_str();
    stoi(str);

    int array_demo[] = {1, 2};
    list<int> list_demo;



    ////vector, dynamic arrays
    vector<int> vec_demo;
    vector<vector<int>> vec_2d_demo(10, vector<int>(10));
    vec_demo.push_back(
            1); //push_back是在当前vector的内存末尾拷贝元素进入容器。注意这个地方可能产生浅拷贝，所以容器中的对象要支持拷贝操作。另外，如果vector初始化了个数，而不初始化具体的值，push_back也只会在最后面追加。
    const auto *vec_ptr = &vec_demo;

    vec_demo.pop_back();
    vec_demo.back();
    vec_demo.front();
    vec_demo.push_back(1);
    vec_demo.emplace_back(2);
    vec_demo.insert(vec_demo.begin(), 1);
    vec_demo[0];
    vec_demo.at(0);

    vector<int> vec_init(10);  // 10 is size
    for (int &vec_single: vec_demo) {}
    auto vec_iter = vec_demo.begin();
    while (vec_iter != vec_demo.end()) {
        vec_iter++;
    }

    vector<int> vec_demo2(vec_demo.begin(), vec_demo.begin() + 1);
    vector<int> vec_demo3(vec_demo2); //deep copy
    // vec_demo3 = vec_demo2; //deep copy
    vec_demo3.push_back(2); //deep copy will not affect the original one
    int max_val = *max_element(vec_demo.begin(), vec_demo.end());
    int sum = std::accumulate(vec_demo.begin(), vec_demo.end(), 0);


    //// map:tree
    //unordered_map: hash
    map<int, char> map_demo = {{1, 'a'}};
    map_demo.erase(1);
    for (auto p: map_demo) {
        p.first;
        p.second;
    }
    map_demo.count(1);
    map<tree::TreeNode *, int> tree_map;
    tree_map[nullptr] = 1;


    ////  queue
    queue<int> queue_demo;
    queue_demo.emplace(1);
    queue_demo.pop();
    queue_demo.front();
    bool queue_is_empty = queue_demo.empty();
    queue<tree::TreeNode *> pointer_queue_demo;
    pointer_queue_demo.emplace(nullptr);
    pointer_queue_demo.size();
    priority_queue<int> pq;
    //priority_queue 模板有 3 个参数，其中两个有默认的参数；第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象，它定义了一个用来决定元素顺序的断言
    // greater是asc 和sort不一样
    priority_queue<int, vector<int>, greater<>> pqueue_demo;
    auto cmp = [](const int a[], const int b[]) -> bool { return a[0] + a[1] > b[0] + b[1]; };
    priority_queue<int, vector<int>, decltype(cmp)> pqueue_demo_div(cmp);
    pqueue_demo.top();
    pqueue_demo.push(1);
//    auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second]; };
//    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    deque<int> deque_demo;
    deque_demo.front();
    deque_demo.back();


    //// stack
    stack<int> stack_demo;
    stack_demo.empty();
    stack_demo.emplace(1);
    stack_demo.push(1);
    stack_demo.pop();
    stack_demo.top(); //empty stack will occur error




    ////set
    set<int> set_demo;
    unordered_set<int> u_set_demo;
    set_demo.count(1);
    set_demo.insert(1);
    set_demo.erase(1);

    ////functions
    int std_max_result = std::max(1, 2);

    sort(vec_demo.begin(), vec_demo.end()); //not stable
    sort(vec_demo.begin(), vec_demo.end(), greater<>());
    stable_sort(vec_demo.begin(), vec_demo.end());
//    sort(arr.begin(), arr.end(),
//         [x](int a, int b) -> bool { return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b; });


}
