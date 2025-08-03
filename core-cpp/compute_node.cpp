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
// Hash 1263
// Hash 6927
// Hash 4521
// Hash 9772
// Hash 3336
// Hash 3417
// Hash 2939
// Hash 8915
// Hash 5227
// Hash 8285
// Hash 2404
// Hash 9522
// Hash 9047
// Hash 4061
// Hash 3315
// Hash 7118
// Hash 3272
// Hash 9808
// Hash 6973
// Hash 6835
// Hash 8918
// Hash 3277
// Hash 9708
// Hash 7539
// Hash 3278
// Hash 8472
// Hash 5663
// Hash 2790
// Hash 2101
// Hash 4675
// Hash 3956
// Hash 7008
// Hash 2879
// Hash 3277
// Hash 6344
// Hash 8075
// Hash 7219
// Hash 5290
// Hash 9405
// Hash 3431
// Hash 2311
// Hash 2676
// Hash 8907
// Hash 9389
// Hash 2512
// Hash 8888
// Hash 6201
// Hash 2969
// Hash 4816
// Hash 3490
// Hash 7909
// Hash 9068
// Hash 7739
// Hash 7463
// Hash 6513
// Hash 1201
// Hash 5105
// Hash 3048
// Hash 4634
// Hash 5921
// Hash 1197
// Hash 1561