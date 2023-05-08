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


void test_vec(vector<int> vec) {
    vec.clear();
}

int main() {
    map<int,int>mm;
    mm[0]++;

    queue<int> q;
    stack<int> v;
    //int xx = v.top();
   // cout<<xx<<endl;
   // int i = std::round(0.81234 * 10);
    //cout << i<<endl;

    // test
    graph::Graph g;
    vector<vector<int>> vec = {{1, 1, 1},
                               {1, 1, 0},
                               {1, 0, 1}};
    vector<vector<string>> vec_str= {{"a","b"},{"c","d"}};
    vector<vector<string>> vec_str2= {{"a","c"},{"b","a"}};
     vector<double>vec_d = {2,3};
    vector<vector<int>> redEdges={{95,4},{95,38},{56,93},{98,81},{22,76},{14,94},{14,28},{24,46},{35,64},{77,77},{57,51},{65,85},{83,97},{33,9},{16,49},{6,42},{73,84},{53,23},{63,49},{98,70},{85,98},{29,3},{87,16},{94,11},{19,61},{21,2},{73,48},{0,7},{42,5},{80,37},{27,25},{45,39},{52,87},{70,43},{95,97},{0,81},{5,41},{31,93},{92,23},{31,75},{99,56},{30,77},{18,33},{45,17},{83,12},{89,49},{17,22},{8,28},{45,87},{34,68},{41,91},{42,13},{3,40},{30,23},{16,2},{52,58},{19,17},{58,69},{64,61},{32,89},{91,1},{41,77},{47,19},{18,84},{99,36},{9,57},{86,61},{5,74},{57,99},{93,88},{0,15},{94,1},{15,34},{9,86},{24,1},{90,72},{1,72},{95,81},{58,59},{94,2},{19,52},{11,33},{8,22},{2,28},{39,5},{67,18},{33,77},{94,5},{54,37},{29,62},{60,6},{27,35},{6,96},{15,5},{13,31},{90,0},{91,45},{85,30},{29,29},{58,22},{90,87},{58,24},{8,33},{23,82},{96,51},{43,56},{68,59}};
    vector<vector<int>> blueEdges={{81,24},{98,66},{15,66},{78,20},{14,4},{39,10},{81,68},{61,0},{99,84},{76,82},{27,69},{97,80},{7,38},{77,13},{61,42},{1,6},{96,18},{74,28},{31,39},{3,86},{44,98},{85,45},{89,42},{23,55},{1,2},{1,40},{51,84},{14,45},{31,40},{33,20},{65,79},{41,85},{31,32},{81,55},{50,10},{53,24},{87,4},{8,15},{18,28},{73,18},{83,14},{35,26},{34,42},{59,81},{6,36},{13,42},{16,26},{54,16},{23,57},{9,50},{34,46},{46,27},{2,80},{14,83},{81,21},{19,48},{56,19},{53,35},{92,48},{85,18},{33,6},{37,17},{93,61},{63,1},{51,59},{40,22},{25,87},{99,73},{70,92},{87,54},{6,39},{54,81},{60,60},{41,54},{5,0},{31,46},{10,30},{1,98},{79,79},{6,49},{31,33},{62,15},{7,42},{19,3},{53,2},{69,74},{99,18},{86,65},{55,20},{3,58},{8,49},{52,13},{99,53},{29,70},{81,85},{9,82},{30,7},{69,44},{34,90},{41,18},{95,69},{5,59},{26,64},{21,37},{45,23},{60,37},{84,9},{92,49},{69,7},{77,28},{27,38},{94,66},{68,1},{29,22},{65,45},{19,43},{55,9},{92,0},{33,33},{70,87},{10,3},{21,28},{25,35},{51,2},{74,14},{79,1},{92,39},{12,41},{84,34},{91,77},{51,9},{87,73},{50,66},{2,19}};
    //auto res = g.shortestAlternatingPaths(100, redEdges,blueEdges);
  //  for (int i=0;i<res.size();i++){
//        for (int j=0;j<res[0].size();j++){
//            std::cout << res[i][j] << " , ";
//        }
   //     std::cout << res[i]<<endl;
//    }
    details d;
    backtracking bt;
//    dp::dp d;
    vector<int> input = {1,1,1,0,0,1};

    test_vec(input);

    vector<int> input2 = {1,1,1,1,1};
    vector<string> input_str = {"word","good","best","good"};
//       auto res = d.advantageCount(input,input2);
    //   int res = g.kSimilarity("abccaacceecdeea","bcaacceeccdeaae");
    auto res = g.braceExpansionIIBFS("{a,b}{c,{d,e}}",0);
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

    //// basic types
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
    pair_demo.first;




    //// struct && typedef
    struct StructDemo {
        int int_obj;
        double double_obj;
    };
    StructDemo struct_demo;
    struct_demo.int_obj = 1;
    struct StructDemo *struct_demo_pointer = &struct_demo;
    struct_demo_pointer->int_obj = 1;
    typedef struct StructDemoTypeDef {
        int int_obj;
        double double_obj;
    } StructDemoTypeDef;
    typedef long int *long32;
    long32 long_pointer;

    ////class
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
    /// string
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
    str.compare(str);

    int array_demo[] = {1, 2};
    list<int> list_demo;



    ////vector, dynamic arrays
    vector<int> vec_demo;
    vector<int>nums={1,2,3,4,5,6,7,8,9};
    vector<vector<int>> vec_2d_demo(10, vector<int>(10));
    vec_demo.push_back(
            1); //push_back是在当前vector的内存末尾拷贝元素进入容器。注意这个地方可能产生浅拷贝，所以容器中的对象要支持拷贝操作。另外，如果vector初始化了个数，而不初始化具体的值，push_back也只会在最后面追加。
    const auto *vec_ptr = &vec_demo;

    vec_demo.pop_back();
    vec_demo.back();
    vec_demo.front();

    vec_demo.push_back(1);
    vec_demo.pop_back();
    vec_demo.emplace_back(2);
    vec_demo.insert(vec_demo.begin(), 1);
    vec_demo[0];
    vec_demo.at(0);

    vec_demo.erase(vec_demo.begin(),vec_demo.begin()+1);
    vec_demo.assign(vec_demo.begin(),vec_demo.end());

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
    vec_demo.resize(10);
    int max_val = *max_element(vec_demo.begin(), vec_demo.end());
    int sum = std::accumulate(vec_demo.begin(), vec_demo.end(), 0);


    //// map:tree is sorted
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
    map_demo.count(1);


    ////  queue
    queue<int> queue_demo;
    queue<int>nums_q({1,2,3,4,5,6,7,8,9});
    queue_demo.push(1);
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
    priority_queue<int, vector<int>,decltype(cmp)> pqueue_demo_div(cmp);
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




    ////set is sorted
    set<int> set_demo;
    unordered_set<int> u_set_demo; //not sorted
    set_demo.count(1);
    set_demo.insert(1);
    set_demo.erase(1);
    multiset<int> multi_demo; // duplicated nums

    ///union
    //The purpose of union is to save memory by using the same memory region for storing different objects at different times.
    //一个union可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值


    ////functions
    auto is_even = [](int l) -> bool { return l % 2 == 0; };
    /*[capture list] (parameter list) -> return type { function body }
    其中，capture list 是捕获外部变量的列表，parameter list 是参数列表，return type 是返回类型，function body 是函数体3。*/
    int std_max_result = std::max(1, 2);
    std::isdigit('1');
    std::isalpha('a');
    std::pow(2,8);
    *min_element(vec_demo.begin(), vec_demo.end());
    sort(vec_demo.begin(), vec_demo.end()); //not stable
    sort(vec_demo.begin(), vec_demo.end(), greater<>());
    stable_sort(vec_demo.begin(), vec_demo.end());
//    sort(arr.begin(), arr.end(),
//         [x](int a, int b) -> bool { return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b; });


}
