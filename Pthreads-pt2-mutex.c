#include <iostream>
#include <pthread.h>

const long long n = 1000000000;
const int thread_count = 4;

pthread_mutex_t mutex;

void* Thread_sum(void* rank);

int main() {
    pthread_t* thread_handles;
    long thread;
    double pi_estimate = 0.0;
    double* partial_sums = new double[thread_count];

    thread_handles = (pthread_t*)malloc(thread_count * sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL);

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*)thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], (void**)&partial_sums[thread]);
        pi_estimate += partial_sums[thread];
    }

    pthread_mutex_destroy(&mutex);

    free(thread_handles);
    delete[] partial_sums;

    pi_estimate = 4.0 * pi_estimate;
    std::cout << "Valor estimado de Pi: " << pi_estimate << std::endl;
    std::cout << "Numero de threads usadas: " << thread_count << std::endl;

    return 0;
}

void* Thread_sum(void* rank) {
    long my_rank = (long)rank;
    double factor, my_sum = 0.0;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;

    if (my_first_i % 2 == 0) {
        factor = 1.0;
    } else {
        factor = -1.0;
    }

    for (i = my_first_i; i < my_last_i; ++i, factor = -factor) {
        my_sum += factor / (2 * i + 1);
    }

    pthread_mutex_lock(&mutex);

    double* my_partial_sum = new double(my_sum);

    pthread_mutex_unlock(&mutex);

    return my_partial_sum;

}
