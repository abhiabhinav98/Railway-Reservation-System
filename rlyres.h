#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
#endif // RLYRES_H_INCLUDED


typedef struct Train
{
    char train_no [10];
    char from [10];
    char to[10];
    int fac_fare;
    int sac_fare;
}Train;


typedef struct Passenger
{
    char p_name[20];
    char gender;
    char address[40];
    int age;
    char train_no[10];
    char p_class;
    int ticketno;
    char mob_no[11];
}Passenger;

int enterchoice();

void add_trains();

void view_trains();

int book_ticket(Passenger);

int * get_ticket_no(char *);

void view_ticket(int);

void view_all_tickets(char *,int *);

void view_all_bookings();

void view_bookings(char *);

int cancel_ticket(int);

int cancel_train(char*);

int check_train_no(char *);

Passenger * get_passenger_details();

int get_booked_ticket_count(char *,char);

int last_ticket_no();

int check_mob_no(char *);

int accept_ticket_no();

char * accept_mob_no();

char * accept_train_no();




