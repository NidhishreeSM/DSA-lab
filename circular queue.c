#include<stdio.h>
#define size 5
int items[size];
int front = -1;
int rear =-1;

int isfull(){
        return ((front == rear + 1) || (front == 0 && rear == size-1));
}

int isempty(){
   if (front==-1)return 1;
   return 0;
   }

void Enqueue(int element){
   if(isfull()){
    printf("\n queue is full!!\n");
   }else{
    if (front ==-1) front = 0;
    rear=(rear+1)%size;
    items[rear] = element;
    printf("\n inserted -> %d",element);
  }
}

int Dequeue(){
   int element;
   if (isempty()){
        printf("\n queue is empty !!\n");
        return(-1);
       }else{
           element = items[front];
           if (front == rear){
                front = -1;
                rear = -1;
           }else{
            front = (front +1)% size;
           }
           printf("\n deleted element->%d\n",element);
           return(element);
    }
}

void Display(){
    int i;
    if (isempty()){
     printf("\n empty queue\n");
    }else{
        printf("\n front -> %d",front);
        printf("\n items ->");
        for(i = front; i!= rear;i=(i+1)%size)
            printf("%d",items[i]);
        }
        printf("%d",items[i]);
        printf("\n rear ->%d\n", rear);
}

void main()
{
    int choice, value;
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue.\n3.Dispaly\n4.Exit");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Element:");
            scanf("%d",&value);
            Enqueue(value);
            break;
            case 2:Dequeue();
            break;
            case 3:Display();
            break;
            case 4:exit(0);
            defult:printf("\nWrong selection!!Try again!!");
        }
    }
}


