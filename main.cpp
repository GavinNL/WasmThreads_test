#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
int shared_counter = 0;

void worker(int id) {
    for (int i = 0; i < 3; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++shared_counter;
        std::cout << "Thread ID," << std::this_thread::get_id() << ", incremented counter to " << shared_counter << std::endl;
    }
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 6; ++i) {
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final counter: " << shared_counter << std::endl;
    return 0;
}
