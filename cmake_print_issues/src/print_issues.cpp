#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

using namespace std;

std::mutex csm;
std::chrono::microseconds msec(100);

void unProtectedPrint(int n, char c){
    for(int i=0; i<n; i++) {
        std::cout << c;
        std::this_thread::sleep_for(msec);
    }
    std::cout << std::endl;
}

void protectedPrint(int n, char c) {
    csm.lock();
    for(int i=0; i<n; i++) {
        std::cout << c;
        std::this_thread::sleep_for(msec);
    }
    std::cout << std::endl;
    csm.unlock();
}

int main() {
    // First two threads force interleaving to happen
    std::cout << "Un protected printing of sequences \n";
    std::thread t1 (unProtectedPrint,20,'A');
    std::thread t2 (unProtectedPrint,20,'B');
    t1.join();
    t2.join();

    std::cout << "Protected printing of sequences \n";
    // Second two threads print sequence is protected by mutex
    std::thread th1 (protectedPrint, 20, 'A');
    std::thread th2 (protectedPrint, 20, 'B');
    th1.join();
    th2.join();
}
