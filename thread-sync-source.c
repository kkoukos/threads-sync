#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdbool.h> 





sem_t sem1,sem2,sem3,sem4; // η χρηση 4 semaphores εξηγειται στο documentation

void* s1(){

while(1){
   sem_wait(&sem1);   
   printf("Hello ");
   sem_post(&sem2);
 }    
   
}
 

void* s2(){

while(1){
    sem_wait(&sem2);     
    printf("there ");
    sem_post(&sem3);
    } 

}   


  

void* s3(){
  
while(1){
    sem_wait(&sem3);    
    printf("wonderful ");
    sem_post(&sem4);
} 

}


void* s4(){
   
while(1){
    sem_wait(&sem4);    
   printf("world!\n");
   sem_post(&sem1);
}

 
}  
 

        
  
 

int main()
{  
    
    pthread_t t1,t2,t3,t4;  // τα 4 thread 
    sem_init(&sem1,0,1);
    sem_init(&sem2,0,0);
    sem_init(&sem3,0,0);
    sem_init(&sem4,0,0);        

    

   

    pthread_create(&t1,NULL,&s1,NULL);
    pthread_create(&t2,NULL,&s2,NULL);
    pthread_create(&t3,NULL,&s3,NULL);
    pthread_create(&t4,NULL,&s4,NULL);
    pthread_join(t1,NULL);  //το join οδηγεί στην ολοκήρωση κάθε thread πριν το κλείσιμο του προγραμματος, αν δεν το βάλουμε δν λειτουργεί παντα το πρόγραμμα
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
 
    return 0;
}
