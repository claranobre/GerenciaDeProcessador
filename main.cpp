#include <thread>
#include <cstdio>
#include <chrono>
#include <vector>
#include <sched.h>
#include <pthread.h>

using namespace std;

#define NUMTHREADS 4
#define MAX 100000000

void vector(float v[MAX]){
    for(i = 0; i < MAX; i++){
        v[i] = rand(); //limitar os valorede de -1 a 1
    }
}

void somaVector(float v[MAX], float soma){
    for(i = 0; i < MAX; i++){
        soma+= v[i];
    }
}

void somaSin(float v[MAX], float somaS){
    for(i = 0; i < MAX; i++){
        somaS+= sin(v[i]); //verificar o uso da função sin()
    }
}

void somaLog(float v[MAX], float somaL){
    for(i = 0; i < MAX; i++){
        somaSin+= log(v[i]); //verificar o uso da função log()
    }
}

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

    cpu_set_t cpuset;
    int ret;

    for (int i=0; i < NUMTHREADS; i++)
    {
        threads.push_back(thread(run,i));
        CPU_ZERO(&cpuset);
        CPU_SET(i, &cpuset);
        pthread_setaffinity_np(threads[i].native_handle(), sizeof(cpu_set_t), &cpuset);
    }

    for (auto& th : threads) th.join();

    return 0;
}
