//
// Created by songcong on 2021/3/31.
//

#ifndef ARROW_TEST_TIMEIT_H
#define ARROW_TEST_TIMEIT_H
#include <time.h>
#include <string>

uint64_t getHTime(timespec ts) {
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

// typedef char byte;
uint64_t getNowHTime() {
    struct timespec ts{};
    clock_gettime(CLOCK_REALTIME, &ts);
    return getHTime(ts);
}

class Timeit {

public:
    uint64_t lastTime;
    std::string detail = "";

    Timeit(std::string detail = "") : detail(detail) {
        lastTime =getNowHTime();
    }

    void report(){
        uint64_t endTime =getNowHTime();
        std::cout<<detail<<":耗时"<<endTime-lastTime<<"ms"<<std::endl;
    }
};


#endif //ARROW_TEST_TIMEIT_H
