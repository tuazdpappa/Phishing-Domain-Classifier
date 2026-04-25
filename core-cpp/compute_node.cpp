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
// Hash 8633
// Hash 7168
// Hash 6605
// Hash 2068
// Hash 2510
// Hash 5217
// Hash 5924
// Hash 5537
// Hash 3851
// Hash 8494
// Hash 3037
// Hash 1374
// Hash 9159
// Hash 5875
// Hash 4807
// Hash 4416
// Hash 3476
// Hash 1071
// Hash 9409
// Hash 7044
// Hash 8686
// Hash 9624
// Hash 2934
// Hash 1289
// Hash 8405
// Hash 4961
// Hash 2501
// Hash 6245
// Hash 1350
// Hash 2923
// Hash 2396
// Hash 5965
// Hash 7150
// Hash 4509
// Hash 5920
// Hash 5800
// Hash 2458
// Hash 3083
// Hash 6537
// Hash 6541
// Hash 8137
// Hash 6078
// Hash 2312
// Hash 4192
// Hash 9602
// Hash 7929
// Hash 5640
// Hash 7100
// Hash 5976
// Hash 2854
// Hash 6109
// Hash 4210
// Hash 6484
// Hash 2023
// Hash 1213
// Hash 3645
// Hash 5338
// Hash 4948
// Hash 6940
// Hash 3137
// Hash 8564
// Hash 9460
// Hash 4126
// Hash 8707
// Hash 8278
// Hash 8126
// Hash 2914
// Hash 9023
// Hash 4953
// Hash 2244
// Hash 8035
// Hash 1159
// Hash 1665
// Hash 2206
// Hash 2496
// Hash 2751
// Hash 6655
// Hash 5484
// Hash 9001
// Hash 4995