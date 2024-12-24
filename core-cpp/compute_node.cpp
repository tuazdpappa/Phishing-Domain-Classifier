#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 2409
// Hash 9362
// Hash 4260
// Hash 3805
// Hash 3103
// Hash 8627
// Hash 3141
// Hash 9834
// Hash 6853
// Hash 3538
// Hash 6760
// Hash 9992
// Hash 7702
// Hash 2063
// Hash 4124
// Hash 6472
// Hash 8027
// Hash 1722
// Hash 7818
// Hash 7267
// Hash 6510
// Hash 2772
// Hash 6368
// Hash 4016
// Hash 7206
// Hash 6904
// Hash 1291
// Hash 9798
// Hash 3596
// Hash 1448
// Hash 1516
// Hash 7639
// Hash 7107
// Hash 1190
// Hash 9637
// Hash 3082
// Hash 1723
// Hash 9610
// Hash 3962
// Hash 3117
// Hash 3315
// Hash 1043
// Hash 9860
// Hash 6612
// Hash 4373
// Hash 2259
// Hash 5983
// Hash 2030
// Hash 8771