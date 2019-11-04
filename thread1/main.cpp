#include <iostream>
#include<thread>
#include <chrono>

using namespace std;

void f1(int i)
{
    cout<<"线程ID: "<<std::this_thread::get_id()<<endl;
    cout<<"参数值: "<<i<<endl;
}

void f2(int & y)
{
    for(int i=0;i<5;i++)
        cout<<i+y<<endl;
}

void f3(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "hello thread "
              << std::this_thread::get_id()
              << " paused " << n << " seconds" << std::endl;
}

int main() {

    int x=9;
    std::thread t1;
    std::thread t2(f1,1);//按值传递
    std::thread t3(f2,std::ref(x));//按引用传递
    std::thread t4(std::move(t3));
    t2.join();
    t4.join();

    std::thread threads[3];
    for(int i=0;i<3;i++)
    {
        threads[i]=std::thread(f3,i);
    }
    for (auto& t: threads) {
        t.join();
    }
    cout<<"test come here!"<<endl;
    return 0;
}