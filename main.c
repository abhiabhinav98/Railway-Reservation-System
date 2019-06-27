#include<stdio.h>
#include<stdlib.h>
#include"rlyres.h"
#include"conio2.h"
#include<string.h>

int main()
{
    int choice,t_no,result;
    char *train_no,*mob_no;
    Passenger *ptr;
    add_trains();
    while(1)
    {
     clrscr();
     fflush(stdin);
     choice= enterchoice();
     clrscr();
    switch(choice)
    {
        case 9: exit(0);
        case 1:
                        view_trains();
                        getch();
                        break;
        case 2:
                         ptr=get_passenger_details();
                         if(ptr!=NULL)
                             {
                                 clrscr();
                                int t_no = book_ticket(*ptr);
                                if(t_no!=-1)
                                {
                                textcolor(LIGHTGREEN);
                                printf("Ticket Successfuly Booked\n\nYour ticket no is : %d",t_no);
                                textcolor(WHITE);
                                printf("\n\nPress any key to go back to main menu");
                                }
                            }
                            getch();
                            break;
        case 3:
                     t_no=accept_ticket_no();
                     if(t_no!=0)
                     view_ticket(t_no);
                     break;
        case 4:
                     mob_no=accept_mob_no();
                     if(mob_no!=NULL)
                     {
                     int * ticket_list=get_ticket_no(mob_no);
                     view_all_tickets(mob_no,ticket_list);
                     }
                     break;
        case 5:
                     view_all_bookings();
                     getch();
                     break;
        case 6:
                     train_no=accept_train_no();
                     if(train_no!=NULL)
                        {view_bookings(train_no);
                        getch();}
                     break;
        case 7:

                     t_no=accept_ticket_no();
                     int result;
                     if(t_no!=0)
                         {
                             result=cancel_ticket(t_no);
                         if(result==1)
                     {
                         clrscr();
                         textcolor(LIGHTGREEN);
                         printf("Ticket no %d successfully cancelled",t_no);
                     }
                     else if(result==0)
                     {
                         clrscr();
                         textcolor(LIGHTRED);
                         printf("Sorry ! No ticket booked against ticket no %d",t_no);
                     }
                        }
                     textcolor(WHITE);
                     printf("\nPress any key to go back to main screen");
                     getch();
                     break;
        case 8:
                     train_no=accept_train_no();
                     if(train_no!=NULL)
                        result=cancel_train(train_no);
                     if(result==0)
                     {
                         clrscr();
                         textcolor(LIGHTRED);
                         printf("Sorry! No tickets booked in the train number %s",train_no);
                         textcolor(WHITE);
                         printf("\nPress any key to go back to main screen");
                     }
                     else if(result==1)
                     {
                         clrscr();
                         textcolor(LIGHTGREEN);
                         printf("Train no %s successfully cancelled",train_no);
                         textcolor(WHITE);
                         printf("\nPress any key to go back to main screen");
                     }
                     getch();
                     break;
        default:
                     textcolor(LIGHTRED);
                     printf("\n\nWrong choice ! Try Again");
                     getch();
                     clrscr();
    }
    }
    return 0;
}
