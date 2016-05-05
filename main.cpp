#include <thread>
#include <cstdio>
#include <chrono>
#include <cmath>
#include <math.h>
#include <vector>
#include <sched.h>
#include <pthread.h>

using namespace std;

#define NUMTHREADS 4
#define MAX 100000000
#define PI 3.14159265

/*Função para imprimir o vetor*/
void imprimeVector(float *vector){
    cout<<vector[MAX];
}

/*Função para criar o vetor*/
void vector(float *vector){
    for(i = 0; i < MAX; i++){
        v[i] = rand() % -1 + 1; /*valores limitados de -1 a 1*/
    }
}

void somaVector(float *vector, float soma){
    for(i = 0; i < MAX; i++){
        soma+= vector[i];
    }
}

void somaSin(float *vector, double somaS){
    for(i = 0; i < MAX; i++){
        somaS+= sin(vector[i] * PI/180);
    }
}

void somaLog(float v[MAX], float somaL){
    for(i = 0; i < MAX; i++){
        somaSin+= log(vector[i]);
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
    /*initialize random seed*/
    srand(time(NULL));

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
