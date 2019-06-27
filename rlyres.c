#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<ctype.h>
#include<string.h>
#include<windows.h>

int enterchoice()
{
    textcolor(YELLOW);
    gotoxy(45,2);
    printf("Railway Reservation System\n");
    int i;
    for(i=1;i<=20;i++)
        printf("------");
    printf("\n\n");
    printf("Select an option\n1 - View Trains\n2 - Book Ticket\n3 - View Ticket\n4 - Search Ticket no\n5 - View all Bookings\n6 - View Train Bookings\n7 - Cancel Ticket\n8 - Cancel Train\n9 - Quit\n\nEnter choice : ");
    int choice;
    scanf("%d",&choice);
    return choice;
}






void add_trains()
{
    FILE *fp=fopen("d:\\MyProject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
                                {"123","BPL","GWA",2100,1500},
                                {"546","BPL","DEL",3500,2240},
                                {"345","HBJ","AGR",1560,1135},
                                {"896","HBJ","MUM",4500,3360}
                                  };

        fp=fopen("d:\\MyProject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        fclose(fp);
    }
    else
         fclose(fp);
}





void view_trains()
{
        int i;
        textcolor(YELLOW);
        printf("\nTRAIN NO\t\tFROM\t\tTO\t\tFIRST AC FARE\t\tSECOND AC FARE\n");
        for(i=1;i<=20;i++)
        printf("------");
        printf("\n");
        FILE *fp=fopen("d:\\MyProject\\alltrains.dat","rb");
        if(fp==NULL)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("No trains available yet");
            return;
        }
        Train var;
        while(fread(&var,sizeof(Train),1,fp)==1)
           printf("%s\t\t\t%s\t\t%s\t\t%d\t\t\t%d\n",var.train_no,var.from,var.to,var.fac_fare,var.sac_fare);
         textcolor(WHITE);
        printf("\n\n\nPress any key to go back to the main screen");
}





int check_train_no(char * train_no)
{
    FILE * fp=fopen("d:\\MyProject\\alltrains.dat","rb");
    Train temp;
    while(fread(&temp,sizeof(Train),1,fp)==1)
    {
        if(strcmp(train_no,temp.train_no)==0)
            {
                    fclose(fp);
                    return 1;
            }
    }
    fclose(fp);
    return 0;
}





Passenger * get_passenger_details()
{
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit\r");
    textcolor(YELLOW);

    printf("Enter passenger name : ");
    static Passenger psn;
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char *pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(psn.p_name[0]=='0')
                    {gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled!");
            return NULL;}

    printf("Enter gender(M/F) :");
    scanf("%c",&psn.gender);
        while(!(psn.gender=='M' || psn.gender=='F'))
        {
            fflush(stdin);
            if(psn.gender=='0')
                            {gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled!");
            return NULL;}
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Gender should be M or F(in uppercase)");
            getch();
            printf("\r                                                                             ");
            textcolor(YELLOW);
            gotoxy(20,2);
            printf("     \b\b\b\b\b");
            fflush(stdin);
            scanf("%c",&psn.gender);
        }
            gotoxy(1,3);

        int valid=0;
        printf("Enter train number :");
        do
        {
            scanf("%s",psn.train_no);
            if(psn.train_no[0]=='0')
                            {gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled!");
            return NULL;}
            valid=check_train_no(psn.train_no);
            if(valid==0)
            {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Invalid train no");
            getch();
            printf("\r                                                                          ");
            textcolor(YELLOW);
            gotoxy(21,3);
            printf("          \b\b\b\b\b\b\b\b\b\b");
            }
        }while(valid==0);
            gotoxy(1,4);


        printf("Enter travelling class(First AC-F, Second AC-S) : ");
        fflush(stdin);
        scanf("%c",&psn.p_class);
        while(!(psn.p_class=='F' || psn.p_class=='S'))
        {
            if(psn.p_class=='0')
                            {gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled!");
            return NULL;}
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Travelling class should be F or S");
            getch();
            printf("\r                                                                  ");
            textcolor(YELLOW);
            gotoxy(50,4);
            printf("     \b\b\b\b\b");
            fflush(stdin);
            scanf("%c",&psn.p_class);
        }
            gotoxy(1,5);

            printf("Enter address : ");
            fflush(stdin);
            fgets(psn.address,20,stdin);
            pos=strchr(psn.address,'\n');
            *pos='\0';
        if(psn.address[0]=='0')
                        {gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled!");
            return NULL;}

       printf("Enter age : ");
       fflush(stdin);
       scanf("%d",&psn.age);
        while(psn.age<=0)
        {
            if(psn.age==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled!");
            return NULL;
        }
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Please enter a valid age.");
            getch();
            printf("\r                                          ");
            textcolor(YELLOW);
            gotoxy(13,6);
            printf("          \b\b\b\b\b\b\b\b\b\b");
            scanf("%d",&psn.age);
        }
            gotoxy(1,7);

            printf("Enter your phone number : ");
            do
            {
                fflush(stdin);
                fgets(psn.mob_no,11,stdin);
                pos=strchr(psn.mob_no,'\n');
                if(pos!=NULL)
                    *pos='\0';
            if(strcmp(psn.mob_no,"0")==0)
            {
                gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled!");
            return NULL;
            }
            valid=check_mob_no(psn.mob_no);
            if(valid==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error! Invalid mobile no");
                getch();
                printf("\r                                      ");
                textcolor(YELLOW);
                gotoxy(26,7);
                printf("                                                    ");
                gotoxy(26,7);
            }
            }while(valid==0);

        return &psn;
}




char * accept_mob_no()
{
    static char mob_no[20],*pos;
    int valid;
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to cancel\r");
    textcolor(YELLOW);
    printf("Enter your mobile number : ");
    do
    {
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
        *pos='\0';
        if(strcmp(mob_no,"0")==0)
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Cancelling request..., please wait");
                Sleep(2000);
                return NULL;
            }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error! Invalid mobile number");
            textcolor(YELLOW);
            getch();
            printf("\r                                              ");
            gotoxy(28,1);
            printf("                                           ");
            gotoxy(28,1);
        }
    }
        while(valid==0);
    return mob_no;

}




int check_mob_no(char *mob)
{
    if(strlen(mob)!=10)
         return 0;
    while(*mob!='\0')
    {
        if(isdigit(*mob)==0)
            return 0;
    mob++;
    }
    return 1;
}




int get_booked_ticket_count(char *train_no,char tc)
{
    FILE *fp=fopen("d:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
        return 0;
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if((strcmp(pr.train_no,train_no)==0) && (pr.p_class==tc))
            count++;
    }
    fclose(fp);
    return count;
}





int last_ticket_no()
{
    FILE *fp=fopen("d:\\MyProject\\allbookings.dat","rb");
    Passenger pr;
    fseek(fp,-1*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}





int book_ticket(Passenger psn)
{
    if(get_booked_ticket_count(psn.train_no,psn.p_class)==2)
    {
        gotoxy(1,1);
        textcolor(LIGHTRED);
        printf("Booking Failed\nAll seats are full in train no %s in %c class \n\n",psn.train_no,psn.p_class);
        textcolor(WHITE);
        printf("Press any key to go back to main screen");
        return -1;
    }
    int tno=last_ticket_no()+1;
    FILE *fp=fopen("d:\\MyProject\\allbookings.dat","ab");
    psn.ticketno=tno;
    fwrite(&psn,sizeof(Passenger),1,fp);
    fclose(fp);
    return tno;
}



int accept_ticket_no()
{
    int t_no,valid=0;
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to cancel\r");
    textcolor(YELLOW);
    printf("Enter ticket no : ");
    do
    {
        scanf("%d",&t_no);
        if(t_no==0)
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Cancelling Input... , please wait");
                Sleep(2000);
                return 0;
            }

        if(t_no<0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Ticket number should be positive");
            textcolor(YELLOW);
            getch();
            printf("\r                                                     ");
            gotoxy(19,1);
            printf("                    ");
            gotoxy(19,1);
        }
        else valid=1;
    }
        while(valid==0);
    return t_no;
}





void view_ticket(int t_no)
{
    FILE *bookings=fopen("d:\\MyProject\\allbookings.dat","rb");
    Passenger p;
    Train t;
    textcolor(YELLOW);
    int flag=0;
    while(fread(&p,sizeof(p),1,bookings)==1)
        if(p.ticketno==t_no)
        {
            FILE *trains=fopen("d:\\MyProject\\alltrains.dat","rb");
            flag=1;
            printf("\nNAME : %s\nGENDER : %c\nTRAIN NO : %s\nCLASS : %c\nADDRESS : %s\nAGE : %d\nMOBILE NO : %s\nTICKET NO : %d\n",p.p_name,p.gender,p.train_no,p.p_class,p.address,p.age,p.mob_no,p.ticketno);
            while(fread(&t,sizeof(t),1,trains)==1)
            if(strcmp(t.train_no,p.train_no)==0)
                {
                    printf("FROM : %s\nTO : %s\nFARE : %d",t.from,t.to,t.fac_fare);
                    fclose(trains);
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to main screen");
                    break;
                }
            fclose(bookings);
            break;
        }
        if(flag==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("No details of the ticket found");
        }
        getch();
}





int * get_ticket_no(char *mob_no)
{
            FILE *fp=fopen("d:\\MyProject\\allbookings.dat","rb");
            if(fp==NULL)
                return 0;
            Passenger ps;
            int count=0,i=0;
            while(fread(&ps,sizeof(ps),1,fp)==1)
                if(strcmp(ps.mob_no,mob_no)==0)
                count++;
            if(count==0)
            {
                fclose(fp);
                return NULL;
            }
            rewind(fp);
            int *p=(int *)malloc((count+1)*sizeof(int));
            while(fread(&ps,sizeof(ps),1,fp)==1)
            {
                if(strcmp(ps.mob_no,mob_no)==0)
                  {
                    *(p+i)=ps.ticketno;
                    i++;
                  }
            }
            *(p+i)=-1;
            fclose(fp);
            return p;

}




void view_all_tickets(char * mob_no,int * ticket_list)
{
    if(ticket_list==NULL)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("No tickets booked against the mobile number %s",mob_no);
        textcolor(WHITE);
        printf("\nPress any key to return");
        getch();
        return;
    }
    printf("\n\nFollowing are the tickets booked for mobile no %s\n\nTICKET NO\n----------\n",mob_no);
    while(*ticket_list!=-1)
    {
        printf("  %d\n",*ticket_list);
        ticket_list++;
    }
    textcolor(WHITE);
    printf("\n\nPress any key to go back to main screen");
    getch();
}





char * accept_train_no()
{
    int valid=0;
    static char train_no[10];
    gotoxy(100,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to cancel\r");
    textcolor(YELLOW);
    printf("Enter train no : ");
    do
    {
        scanf("%s",train_no);
        if(train_no[0]=='0')
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Cancelling request, please wait");
            Sleep(2000);
            return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error! Invalid train no");
            getch();
            printf("\r                                  ");
            textcolor(YELLOW);
            gotoxy(18,1);
            printf("                        ");
            gotoxy(18,1);
        }
    }
        while(valid==0);
        return train_no;
}





void view_bookings(char *train_no)
{
    Passenger ps;
    short i,flag=0;
    FILE *fp=fopen("d:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\n\nNo bookings done yet");
        textcolor(WHITE);
        printf("\nPress any key to go back to main screen");
        return ;
    }
    fread(&ps,sizeof(ps),1,fp);
    printf("\nTICKET NO     TRAIN NO     NAME\t\t\tGENDER\tTRAVELLING CLASS\tAGE\tMOBILE NO\tADDRESS\n");
        for(i=1;i<=20;i++)
        printf("------");
        printf("\n\n");
    do
        if(strcmp(ps.train_no,train_no)==0)
           {
             printf("%d\t\t%s        %-12.12s\t\t%c\t\t%c\t\t%d\t%s\t%s\n",ps.ticketno,ps.train_no,ps.p_name,ps.gender,ps.p_class,ps.age,ps.mob_no,ps.address);
            flag=1;
           }
    while(fread(&ps,sizeof(ps),1,fp)==1);
        fclose(fp);
        if(flag==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("No tickets booked in the train number %s ",train_no);
        }
        textcolor(WHITE);
        printf("\nPress any key to go back to main menu");
}




void view_all_bookings()
{
    Passenger ps;
    short i;
    FILE *fp=fopen("d:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL||fread(&ps,sizeof(ps),1,fp)!=1)
    {
        textcolor(LIGHTRED);
        printf("\n\nNo bookings done yet");
        textcolor(WHITE);
        printf("\nPress any key to go back to main screen");
        return;
    }
        printf("\nTICKET NO     TRAIN NO     NAME\t\t\tGENDER\tTRAVELLING CLASS\tAGE\tMOBILE NO\tADDRESS\n");
        for(i=1;i<=20;i++)
        printf("------");
        printf("\n\n");
        do
            printf("%d\t\t%s        %-12.12s\t\t%c\t\t%c\t\t%d\t%s\t%s\n",ps.ticketno,ps.train_no,ps.p_name,ps.gender,ps.p_class,ps.age,ps.mob_no,ps.address);
            while(fread(&ps,sizeof(ps),1,fp)==1);
        fclose(fp);
        textcolor(WHITE);
        printf("\n\n\nPress any key to go back to main screen");
}




int cancel_ticket(int t_no)
{
    FILE *fp=fopen("d:\\MyProject\\allbookings.dat","rb");
    int found=0;
    Passenger ps;
    if(fp==NULL)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("No bookings done yet");
        return -1;
    }
    FILE *temp=fopen("d:\\MyProject\\temp.dat","wb");
    while(fread(&ps,sizeof(ps),1,fp)==1)
    {
        if(ps.ticketno!=t_no)
            fwrite(&ps,sizeof(ps),1,temp);
        else
            found=1;
    }
        fclose(fp);
        fclose(temp);
        if(found==1)
        {
            remove("d:\\MyProject\\allbookings.dat");
            rename("d:\\MyProject\\temp.dat","d:\\MyProject\\allbookings.dat");
        }
        else
            remove("d:\\MyProject\\temp.dat");
        return found;
}





int cancel_train(char *train_no)
{
    FILE *fp=fopen("d:\\MyProject\\allbookings.dat","rb");
    if(fp==NULL)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("No Bookings done yet");
        return -1;
    }
    FILE *temp=fopen("d:\\MyProject\\temp.dat","wb");
    Passenger ps;
    int found=0;
    while(fread(&ps,sizeof(ps),1,fp)==1)
    {
        if(strcmp(ps.train_no,train_no)!=0)
            fwrite(&ps,sizeof(ps),1,temp);
        else found=1;
    }
    fclose(fp);
    fclose(temp);
    if(found==1)
    {
        remove("d:\\MyProject\\allbookings.dat");
        rename("d:\\MyProject\\temp.dat","d:\\MyProject\\allbookings.dat");
    }
    else
        remove("d:\\MyProject\\temp.dat");
    return found;
}









