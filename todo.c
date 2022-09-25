#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct entity{
    char desc[100];
    int date[3]; // DD/MM/YYYY
    int priority;
    int status;
};



void sort(struct entity* queue, int size){
  for (int step = 0; step < size - 1; ++step) {
    for (int i = 0; i < size - step - 1; ++i) {

      if (queue[i].priority > queue[i + 1].priority) {
        struct entity temp = queue[i];
        queue[i] = queue[i + 1];
        queue[i + 1] = temp;
      }
    }
  }
}


void ShowMenu(){
    printf("\n========================================\nActions that can be taken:\n <1> To add a new todo entity\n <2> To show todo list\n <3> To remove ith entity\n <4> To toggle completition of ith entity\n <5> To sort the todo list\n <6> Exit\n========================================\n" );
}


void enqueue(struct entity* queue, int *n){
    struct entity e;
    printf("Enter entity todo: ");
    scanf("%s",e.desc);
    printf("Enter due date <DD/MM/YYYY>: ");
    scanf("%d/%d/%d", &e.date[0], &e.date[1], &e.date[2]);

    e.status = 0;
    e.priority = e.date[0] + e.date[1]*30 + e.date[2]*365;

    queue[*n] = e;
    *n = *n + 1;
}


void remove_(struct entity* queue, int *n, int pos){

    struct entity temp;
    for (int i=pos-1; i<*n-1; i++){
        temp = queue[i];
        queue[i] = queue[i+1];
        queue[i+1] = temp;
    }

    *n = *n - 1;
}

void completed(struct entity* queue, int pos){
    if (queue[pos-1].status == 0){
        queue[pos-1].status = 1;
    }
    else {
        queue[pos-1].status == 0;
    }
}

void show(struct entity* queue, int n){
    char completed[] = "Completed";
    char notcompleted[] = "Not Completed";

    for (int i = 0; i<n; i++){
        if (queue[i].status == 0){
            printf("%i) %s      %d/%d/%d      %s", i+1, queue[i].desc, queue[i].date[0], queue[i].date[1], queue[i].date[2], notcompleted);
        
        }
        else{
            printf("%i) %s      %d/%d/%d      %s", i+1, queue[i].desc, queue[i].date[0], queue[i].date[1], queue[i].date[2], completed);
        }

        printf("\n");
    }

}

void main(){
    int input, continue_ = 1, n = 0;
    struct entity *queue;
    int i=0;

    queue = (struct entity*)malloc(1000*sizeof(struct entity));

    while (continue_){
        ShowMenu();
        scanf("%i", &input);

        switch (input)
        {
        
        case 1:
            enqueue(queue, &n);
            break;
        
        case 2:
            show(queue, n);
            break;
        
        case 3:
            printf("Which todo enitity to remove: ");
            scanf("%d", &i);
            remove_(queue, &n, i);
            break;

        case 4:
            printf("Which entity to toggle: ");
            scanf("%d", &i);
            completed(queue, i);
            break;

        case 5:
            sort(queue, n);
            break;

        case 6:
            continue_ = 0;
            break;
        
        
        default:
            break;
        }

    }

}