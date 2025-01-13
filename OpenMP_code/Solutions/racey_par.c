#include <assert.h>
#include <stdio.h>
#include <omp.h>

int main()
{

  printf("I think");

  // create excess threads to see if using threads
  // other than the initial thread will give me the
  // race condition we desire
  omp_set_num_threads(8);
  #pragma omp parallel
  {
    int id = omp_get_thread_num();
    int Nthr = omp_get_num_threads();
    assert(Nthr > 1);

    if (id ==  Nthr/2 || id == Nthr/2-1)
    {
       #pragma omp single
       {
          #pragma omp task
             printf(" car");

          #pragma omp task
             printf(" race");
       }
    }
  }

  printf("s are fun\n");

}
