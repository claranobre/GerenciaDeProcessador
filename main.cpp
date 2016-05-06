#include <thread>
#include <cstdio>
#include <chrono>
#include <cmath>
#include <math.h>
#include <vector>
#include <sched.h>
#include <pthread.h>

using namespace std;

//#define NUMTHREADS 4
#define MAX 100000000
#define PI 3.14159265

/*
* Função para imprimir o vetor
* @param *vetor
*/
void imprimeVetor(float *vetor){
    cout<<"Vetor: \n" << vector[MAX];
}

/*
* Função para criar o vetor
* @param *vetor
*/
void vetor(float *vetor){
    for(int i = 0; i < MAX; i++){
        vetor[i] = rand() % -1 + 1; /*valores limitados de -1 a 1*/
    }
}
/* Função para somar os valores do vetor
 * @param *vetor, soma
*/
void somaVetor(float *vetor, float soma){
    for(int i = 0; i < MAX; i++){
        soma += vetor[i];
    }
}
/*
* Função para somar os valores do vetor utilizando a função sin
* @param *vetor, somaS
*/
void somaSin(float *vetor, float somaS){
    for(int i = 0; i < MAX; i++){
        somaS += sin(vetor[i] * PI/180);
    }
}
/*
* Função para somar os valores do vetor utilizando a função log
* @param *vetor, somaL
*/
void somaLog(float *vetor, float somaL){
    for(int i = 0; i < MAX; i++){
        somaL += log(vetor[i]);
    }
}
/*
* Função run, execução da thread
* @param i
*/
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

    int NUMTHREADS;

    vector<thread> threads;

    unsigned int n = thread::hardware_concurrency();
    printf("Minha CPU possui %d núcleos\n",n);

    cpu_set_t cpuset;
    int ret;

    for (int i = 0; i < (NUMTHREADS = 1); i++)
    {
        auto t1 = chrono::high_resolution_clock::now();
    	threads.push_back(thread(run,i));
    
    /*
    * initialize random seed
    * srand(time(NULL));
    */
    	vetor();
    	somaVetor();
    	somaSin();
    	somaLog();

        CPU_ZERO(&cpuset);
        CPU_SET(i, &cpuset);
        pthread_setaffinity_np(threads[i].native_handle(), sizeof(cpu_set_t), &cpuset);

        auto t2 =  chrono::high_resolution_clock::now();
        chrono::duration<double> tempo = t2 - t1;
        cout << "Tempo total gasto: " << tempo.count() << "\n";
    }       

    for (auto& th : threads) th.join();

    return 0;
}
