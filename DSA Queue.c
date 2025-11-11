#include <stdio.h>
#include<stdlib.h>
#define MAX 50

int queue_array[MAX];

int rear =-1;
int front =-1;

display()
{
    int i;
    if (front == -1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is: \n");
        for (i=front; i <= rear; i++)
             printf("%d ", queue_array[i]);
        printf("\n");
    }
} /*End of display() */

void main()
{
    int choice;
    while(1)
    {
        printf("1.Insert \n");
        printf("2.Delete\n");
        printf("3.Display \n");
        printf("4.Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(1);
            default:
            printf("Invalid choice \n");
        } /*End of switch*/
    } /*End of while*/
} /*End of main()*/


insert()
  {
      int items;
      if(rear==MAX-1)
        printf("queue is overflow");
      else
      {
          if (front==-1)
              front =0;
              printf("insert elements");
              scanf("%d", &items);
              rear+=1;
              queue_array[rear]=items;
              printf("%d inserted elements into the code",items);
      }
  }

  delete()
  {
      int i;
      if(front==-1 || front > rear)
        printf("queue is empty\n");
      else
      {

            printf("deleted element is: %d\n queue_array[i]");
            front +=1;

      }
  }

