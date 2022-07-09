#include <iostream>
#include <queue>
using namespace std;

/*
    原型：
        template<
            class T,
            class Container = std::vector<T>,
            class Compare = std::less<typename Container::value_type>
        > class priority_queue;
    默认情况下为大堆，传入greater为小堆。
*/

/* 创建优先队列的一般方式 */
void Test_PriorityQueue1() {
    vector<int> inputArray = {5,4,7,2,3,5,9,10,0,1,15,13};
    priority_queue<int, vector<int>, greater<int>> pq1(inputArray.begin(), inputArray.end());
    priority_queue<int, vector<int>, less<int>> pq2(inputArray.begin(), inputArray.end());
    
    /* 输出结果： 0 1 2 3 4 5 5 7 9 10 13 15 */
    cout<<"传入greater排序规则, 队列中的数据从小到大排列:\n";
    while (!pq1.empty()) {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<endl;

    /* 输出结果： 15 13 10 9 7 5 5 4 3 2 1 0*/
    cout<<"\n传入less排序规则, 队列中的数据从大到小排列:\n";
    while (!pq2.empty()) {
        cout<<pq2.top()<<" ";
        pq2.pop();
    }
    cout<<endl;
}

/* 创建特殊的优先队列 */
/* 
    priority_queue允许我们传入自定的优先级规则以及底层容器，容器方面需要满足
    有提供：front，push_back，pop_back的操作，需要是有序容器，且其迭代器要
    至少是随机访问迭代器。
*/
void Test_PriorityQueue2() {
    vector<pair<int, int>> inputArray({
        {3,1}, {1,2}, {2,2},
        {4,2}, {5,3}, {4,1},
        {6,1}, {2,1}, {3,3}
        });

    cout<<"初始数据顺序:\n";
    for (auto &intPair: inputArray) {
        cout<<intPair.first<<"---"<<intPair.second<<endl;
    }
    cout<<endl;

    /* 使用lambda表达式，客制化cmp操作 */
    /* 先根据first从大到小排序，若first相同则根据second从小到大排序 */
    auto cmp = [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    };

    /* 创建自定规则队列 */
    /* 要使用decltype对cmp进行推断，否则编译不过（还没纠结原因） */
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(inputArray.begin(), inputArray.end(), cmp);

    cout<<"插入优先队列后的顺序:\n";
    while (!pq.empty()) {
        cout<<pq.top().first<<"---"<<pq.top().second<<endl;
        pq.pop();
    }
    cout<<endl;
}

int main(int argc, char **argv) {
    Test_PriorityQueue1();
    cout<<endl;
    Test_PriorityQueue2();
    return 0;
}