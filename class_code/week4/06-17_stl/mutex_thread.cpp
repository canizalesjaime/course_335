#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

map<string, string> g_pages;
mutex g_pages_mutex;
 
void save_page(const string &url)
{
    // simulate a long page fetch
    this_thread::sleep_for(chrono::seconds(2));
    string result = "fake content";
 
    lock_guard<mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}
 
int main() 
{
    thread t1(save_page, "http://foo");
    thread t2(save_page, "http://bar");
    t1.join();
    t2.join();
 
    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) 
        cout << pair.first << " => " << pair.second << '\n';
}