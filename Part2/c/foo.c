#include <pthread.h>
#include <stdio.h>

int i = 0;

pthread_mutex_t indec_done;
// Note the return type: void*
void* incrementingThreadFunction(){
	
    for (int j = 0; j < 1000000; j++) {
	pthread_mutex_lock(&indec_done);
	// TODO: sync access to i
	
	i++;
	pthread_mutex_unlock(&indec_done);
    }
	
    return NULL;
}

void* decrementingThreadFunction(){
	
    for (int j = 0; j < 1000000; j++) {
	pthread_mutex_lock(&indec_done);
	// TODO: sync access to i
	
	i--;
	pthread_mutex_unlock(&indec_done);
	
    }
	
    return NULL;
}


int main(){
    pthread_t incrementingThread, decrementingThread;
    
    pthread_mutex_init(&indec_done, NULL);
    //pthread_mutex_lock(&indec_done);
    pthread_create(&incrementingThread, NULL, incrementingThreadFunction, NULL);
    pthread_create(&decrementingThread, NULL, decrementingThreadFunction, NULL);
  
    
    pthread_join(incrementingThread, NULL);
    pthread_join(decrementingThread, NULL);

     pthread_mutex_destroy(&indec_done);
    
    
    printf("The magic number is: %d\n", i);
    return 0;
}
