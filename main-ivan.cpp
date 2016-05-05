#include <thread>
#include <cstdio>
#include <chrono>
#include <vector>
#include <sched.h>
using namespace std;

#define NUMTHREADS 4

void run(int i)
{
    for (int j=0; j < 5; j++)
    {
        printf("Thread #%d está executando no núcleo %d\n",i, sched_getcpu());
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main(int argc, char *argv[])
{
    vector<thread> threads;

    unsigned int n = thread::hardware_concurrency();
    printf("Minha CPU possui %d núcleos\n",n);

    for (int i=0; i < NUMTHREADS; i++)
        threads.push_back(thread(run,i));

    for (auto& th : threads) th.join();

    return 0;
}
