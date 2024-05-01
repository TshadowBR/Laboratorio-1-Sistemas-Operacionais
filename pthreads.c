// Gabriel Forster Souza - 10409702
// Rodrigo Mello de Campos Silva - 10409316
// Rodrigo Lucas Rosales - 10365071
// Vitor Leandro Machado - 10409358

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *Pth_mat_vect(void *rank) {
  long my_rank = (long) rank;
  int i, j;

  int m = 4;
  int n = 3;

  double *A = malloc(m * n * sizeof(double));
  if (A == NULL) {
    fprintf(stderr, "Error allocating memory for matrix A\n");
    return NULL;
  }
  double *x = malloc(n * sizeof(double));
  if (x == NULL) {
    fprintf(stderr, "Error allocating memory for vector x\n");
    free(A);
    return NULL;
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      A[i * n + j] = i + j;
    }
  }
  for (i = 0; i < n; i++) {
    x[i] = i;
  }

  int thread_count = 2;
  int local_m = m / thread_count;

  int my_first_row = my_rank * local_m;
  int my_last_row = (my_rank + 1) * local_m - 1;

  if (my_rank == thread_count - 1) {
    my_last_row = m - 1;
  }

  double *y = malloc(local_m * sizeof(double)); // Allocate memory for y outside the loop
  if (y == NULL) {
    fprintf(stderr, "Error allocating memory for vector y\n");
    free(A);
    free(x);
    return NULL;
  }

  for (i = my_first_row; i <= my_last_row; i++) {
    y[i - my_first_row] = 0.0;
    for (j = 0; j < n; j++) {
      y[i - my_first_row] += A[i * n + j] * x[j];
    }
  }

  free(A);
  free(x);

  return y; // Return the pointer to the allocated memory for y
}


int main()
{
    pthread_t threads[2];

    for (int rank = 0; rank < 2; rank++)
    {
        int ret = pthread_create(&threads[rank], NULL, Pth_mat_vect, (void *)rank);
        if (ret)
        {
            fprintf(stderr, "Error creating thread: %s\n", strerror(ret));
            return 1;
        }
    }

    double *final_y = NULL;

    for (int rank = 0; rank < 2; rank++)
    {
        double *local_y;
        pthread_join(threads[rank], (void **)&local_y);

        // Combine local results into final_y (implementation depends on your specific requirements)

        free(local_y);
    }
printf("Final result vector: ");
    for (int i = 0; i < 4; i++) {
        printf("%.2f ", final_y[i]);
    }
    printf("\n");

    free(final_y);
    return 0;
    
}
