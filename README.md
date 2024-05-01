## Vitor Leandro Machado | 10409358 / Rodrigo Lucas Rosales | 10365071 / Gabriel Forster Souza | 10409702 / Rodrigo Mello de Campos Silva | 10409316

Nesta branch, será incluida o código utilizado para a realização do exercicio Lab03_A!

ENUNCIADO:
Na linguagem C, em sistemas Linux a criação de uma thread pode ser feita executando uma chamada à função clone()

clone()

Faz uma cópia compartilhada do processo (similar ao fork) mas mantém uma área de memória compartilhada.

Em sistemas Linux utilizamos o termo task para se referir a processos e threads. A principal diferença é o tipo de recurso que será compartilhado.

![clone](https://github.com/TshadowBR/Laboratorio-1-Sistemas-Operacionais/assets/32850196/f1ff67e7-e79a-4430-8470-42001fbd01f7)

O trecho abaixo apresenta uma criação de thread no Linux:


#define _GNU_SOURCE                                                                                                                              
#include <stdlib.h>                                                                                                                              
#include <malloc.h>                                                                                                                              
#include <sys/types.h>                                                                                                                           
#include <sys/wait.h>                                                                                                                            
#include <signal.h>                                                                                                                              
#include <sched.h>                                                                                                                               
#include <stdio.h>                                                                                                                               
                                                                                                                                                 
// 64kB stack                                                                                                                                    
#define FIBER_STACK 1024*64                                                                                                                      
                                                                                                                                                 
// The child thread will execute this function                                                                                                   
int threadFunction( void* argument )                                                                                                             
{                                                                                                                                                
    printf("child thread exiting\n");                                                                                                            
    return 0;                                                                                                                                    
}                                                                                                                                                
                                                                                                                                                 
int main()                                                                                                                                       
{                                                                                                                                                
    void* stack;                                                                                                                                 
    pid_t pid;                                                                                                                                   
                                                                                                                                                 
    // Allocate the stack                                                                                                                        
    stack = malloc( FIBER_STACK );                                                                                                               
    if ( stack == 0 )                                                                                                                            
    {                                                                                                                                            
        perror("malloc: could not allocate stack");                                                                                              
        exit(1);                                                                                                                                 
    }                                                                                                                                            
                                                                                                                                     
    printf( "Creating child thread\n" );                                                                                                         
                                                                                                                                                 
    // Call the clone system call to create the child thread                                                                                     
    pid = clone( &threadFunction, (char*) stack + FIBER_STACK,                                                                                   
        SIGCHLD | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, 0 );                                                                        
    if ( pid == -1 )                                                                                                                             
    {                                                                                                                                            
        perror( "clone" );                                                                                                                       
        exit(2);                                                                                                                                 
    }                                                                                                                                            
                                                                                                                                                 
    // Wait for the child thread to exit                                                                                                         
    pid = waitpid( pid, 0, 0 );                                                                                                                  
    if ( pid == -1 )                                                                                                                             
    {                                                                                                                                            
        perror( "waitpid" );                                                                                                                     
        exit(3);                                                                                                                                 
    }                                                                                                                                            
                                                                                                                                                 
    // Free the stack                                                                                                                            
    free( stack );                                                                                                                               
    printf( "Child thread returned and stack freed.\n" );                                                                                        
                                                                                                                                                 
    return 0;                                                                                                                                    
}

EXERCÍCIO: Incremente o exemplo acima para representar a troca de informações de contexto entre a thread e o processo pai.
