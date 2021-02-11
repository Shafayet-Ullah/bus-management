#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void list_Install();
void list_Reservation();
void list_Show();
void list_Avail();

struct bus
{
    char bus_no[5];
    char bus_name[10];
    char arrival[5];
    char depart[5];
    char from[10];
    char to[10];
    char seat[8][4][10];
    float fee;

    struct bus *link;
};

struct bus *head_list=NULL;


int main()
{
    int choice;
    while(1)
    {
        printf("\n\n\n\n\n");
        printf("\t\t\t1.Install\n\t\t\t");
        printf("2.Reservation\n\t\t\t");
        printf("3.Show\n\t\t\t");
        printf("4.Bus  Available. \n\t\t\t");
        printf("5.Exit");
        printf("\n\t\t\tEnter your choice:-> ");

        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            list_Install();
            break;
        case 2:
            list_Reservation();
            break;
        case 3:
            list_Show();
            break;
        case 4:
            list_Avail();
            break;
        case 5:
            return 0;
        }
    }
    return 0;
}

void list_Install()
{
    getchar();
    struct bus *ptr;
    ptr=(struct bus*)malloc(sizeof(struct bus));

    printf("Bus no. : ");
    gets(ptr->bus_no);
    printf("Bus name : ");
    gets(ptr->bus_name);
    printf("Arrival time : ");
    gets(ptr->arrival);
    printf("Departure : ");
    gets(ptr->depart);
    printf("From : ");
    gets(ptr->from);
    printf("To : ");
    gets(ptr->to);
    printf("Fee : ");
    scanf("%f",&ptr->fee);

    //assign all seats to empty
    for(int i=0; i<8;i++)
    {
    for(int j=0;j<4;j++)
        {
          strcpy(ptr->seat[i][j], "Empty");
        }
    }

    ptr->link=0;

    if(head_list==NULL)
    {
        head_list=malloc(sizeof(struct bus));
        head_list=ptr;
    }
    else
    {
        struct bus *temp=malloc(sizeof(struct bus));
        temp=head_list;
        while(temp->link!=0)
        {
            temp=temp->link;
        }
        temp->link=ptr;
    }
}


void list_Reservation()
{
    getchar();
    struct bus *temp=malloc(sizeof(struct bus));
    temp=head_list;

    int flag=0;
    char busNo[5];
    printf("Bus no : ");
    gets(busNo);

    if(temp!=0)
    {
        while(1)
        {
            if(strcmp(temp->bus_no,busNo)==0)
            {
                flag=1;
                break;
            }
            if(temp->link==0)//check end of the list
                break;

            temp=temp->link;
        }
    }
    if(flag==1 || strcmp(temp->bus_no,busNo)==0)
    {
        int seat_no;
        printf("Seat no : ");
        scanf("%d",&seat_no);
        getchar();
        if(seat_no>32)
            printf("There are only 32 seats available in this bus.\n");
        else
        {
            if(strcmp(temp->seat[seat_no/4][(seat_no%4)-1], "Empty")==0)
            {
                printf("Passenger's name : ");
                gets(temp->seat[seat_no/4][(seat_no%4)-1]);

                printf("You have to pay : %.2f\n",temp->fee);
            }
            else
            {
                printf("The seat no. %d is already reserved.\n",seat_no);
            }
        }
    }
    else if(flag==0)
    {
        printf("Bus no. %s is not available\n",busNo);
    }
}

void list_Show()
{
    getchar();
    struct bus *temp=malloc(sizeof(struct bus));
    temp=head_list;
    char busNo[5];
    int flag=0;

    printf("Bus no. : ");
    gets(busNo);
    while(1)
    {
        if(strcmp(temp->bus_no,busNo)==0)
        {
            flag=1;
            break;
        }
        if(temp->link==0)//to check end of the list
        {
            break;
        }
        temp=temp->link;
    }
    if(flag==1)
    {
        printf("Bus no. : %s\t\t",temp->bus_no);
        printf("Bus name : %s\n",temp->bus_name);
        printf("Arrival : %s\t\t",temp->arrival);
        printf("Departure : %s\n",temp->depart);
        printf("From : %s\t\t",temp->from);
        printf("To : %s\t\t",temp->to);
        printf("Fee : %.2f\n",temp->fee);

        int seatNo=1;
        for(int i=0; i<8;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(strcmp(temp->seat[i][j],"Empty")==1)
                {
                    printf("Seat no. %d is reserved for %s\n",seatNo,temp->seat[i][j]);
                }
                seatNo++;
            }
        }
    }
    else
    {
        printf("This bus is not available.\n");
    }
}

void list_Avail()
{
    struct bus *temp=malloc(sizeof(struct bus));
    temp=head_list;

    if(temp!=0)
    {
        while(1)
        {
            printf("Bus no. : %s\t\t",temp->bus_no);
            printf("Bus name : %s\n",temp->bus_name);
            printf("Arrival : %s\t\t",temp->arrival);
            printf("Departure : %s\n",temp->depart);
            printf("From : %s\t\t",temp->from);
            printf("To : %s\t\t",temp->to);
            printf("Fee : %.2f\n",temp->fee);

            for(int i=0; i<8;i++)
            {
                for(int j=0;j<4;j++)
                {
                    printf("%s\t\t",temp->seat[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            if(temp->link==0)//to check end of the list
                break;
            temp=temp->link;
        }
    }
}
