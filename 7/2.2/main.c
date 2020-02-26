#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// link list
struct node
{
    char esm[50];
    struct node *next;
};
// sakht mozoeat
typedef struct game_save
{
    int tedad_bazi;
    int max_emtiaz[1][2];
    int emtiaz_ha[10][2];
}
save;
save sv, ab , ma;
//chap struct
void chap (save s)
{
    int i ;
    printf("%d\n",s.tedad_bazi);
    printf("%d %d\n",s.max_emtiaz[0][0],s.max_emtiaz[0][1]);
    for (i=0;i<s.tedad_bazi;i++)
    {
         printf("%d %d\n",s.emtiaz_ha[i][0],s.emtiaz_ha[i][1]);
    }
}
// find max point
save find_max_point(save s)
{
    int i , mx[1][2] ;
    mx[0][0]=s.emtiaz_ha[0][0];
    mx[0][1]=s.emtiaz_ha[0][1];
    for(i=1;i<s.tedad_bazi;i++)
    {
        if (mx[0][1]<s.emtiaz_ha[i][1])
        {
            mx[0][0]=s.emtiaz_ha[i][0];
            mx[0][1]=s.emtiaz_ha[i][1];
        }
        else ;
    }
    s.max_emtiaz[0][0]=mx[0][0];
    s.max_emtiaz[0][1]=mx[0][1];
    return s ;
}
//save game
void save_game(save s,char name_shakhs[20],int b)
{
    int i ,a;
    char nam[30] , c1;
    for(i=0;i<30;i++)
    {
        c1=name_shakhs[i];
        a=isalpha(c1)+isdigit(c1);
        if (a==0)
        {
            break ;
        }
        else ;
        nam[i]=name_shakhs[i];
    }
    nam[i]='.';
    nam[i+1]='t';
    nam[i+2]='x';
    nam[i+3]='t';
    nam[i+4]='\0';
    if(b==0)
    {
        FILE *de_names=fopen("AVAILABLE_NAMES.txt","a");
        if (de_names==NULL)
        {
            printf("Can not open file ");
            exit(-1);
        }
        else ;
        fprintf(de_names,"%s\n",nam);
        fclose(de_names);
    }
    else ;
    FILE *gamer_info=fopen(nam,"w");
    if (gamer_info==NULL)
    {
        printf("Can not open file ");
        exit(-1);
    }
    else ;
    fprintf(gamer_info,"%d\n",s.tedad_bazi);
    fprintf(gamer_info,"%d %d\n",s.max_emtiaz[0][0],s.max_emtiaz[0][1]);
    for (i=0;i<s.tedad_bazi;i++)
    {
         fprintf(gamer_info,"%d %d\n",s.emtiaz_ha[i][0],s.emtiaz_ha[i][1]);
    }

    fclose(gamer_info);
}
//bazyabi akharin save
save last_save(char esm[20])
{
    save s ;
    char c1 ;
    int i ,a ;
    for(i=0;i<20;i++)
    {
        c1=esm[i];
        a=isalpha(c1)+isdigit(c1);
        if(a==0)
        {
            break ;
        }
        else ;
    }
    esm[i]='.';
    esm[i+1]='t';
    esm[i+2]='x';
    esm[i+3]='t';
    esm[i+4]='\0';
    FILE *gamer_info=fopen(esm,"r+");
    if (gamer_info==NULL)
    {
        printf("Your last game not found . \n ");
        exit(-1);
    }
    else ;
    fscanf(gamer_info,"%d",&s.tedad_bazi);
    fscanf(gamer_info,"%d %d",&s.max_emtiaz[0][0],&s.max_emtiaz[0][1]);
    for(i=0;i<s.tedad_bazi;i++)
    {
        fscanf(gamer_info,"%d %d",&s.emtiaz_ha[i][0],&s.emtiaz_ha[i][1]);
    }
    return s;

    fclose(gamer_info);
}
//tabe moghaiese save ghadim ba save jadid
save ghias_save_ha(save a ,save b)
{
    int i , j , k=0 ;
    save c ;
    for (i=0;i<a.tedad_bazi;i++)
    {
        for (j=0;j<b.tedad_bazi;j++)
        {
            if (a.emtiaz_ha[i][0]==b.emtiaz_ha[j][0])
            {
                if (a.emtiaz_ha[i][1]>b.emtiaz_ha[j][1])
                {
                    c.emtiaz_ha[k][0]=a.emtiaz_ha[i][0];
                    c.emtiaz_ha[k][1]=a.emtiaz_ha[i][1];
                }
                else
                {
                    c.emtiaz_ha[k][0]=b.emtiaz_ha[j][0];
                    c.emtiaz_ha[k][1]=b.emtiaz_ha[j][1];
                }
                k++;
                break ;
            }
            else ;
        }
        if (j==b.tedad_bazi)
        {
            c.emtiaz_ha[k][0]=a.emtiaz_ha[i][0];
            c.emtiaz_ha[k][1]=a.emtiaz_ha[i][1];
            k++;
        }
        else ;
    }
    for (i=0;i<b.tedad_bazi;i++)
    {
        for (j=0;j<a.tedad_bazi;j++)
        {
            if (a.emtiaz_ha[i][0]==b.emtiaz_ha[j][0])
            {
                break ;
            }
            else ;
        }
        if (j==a.tedad_bazi)
        {
            c.emtiaz_ha[k][0]=b.emtiaz_ha[i][0];
            c.emtiaz_ha[k][1]=b.emtiaz_ha[i][1];
            k++;
        }
        else ;
    }
    c.tedad_bazi=k;
    c=find_max_point(c);
    return c ;
}
// shekl haye ghargh shodan
void prnt(int a)
{
    if(a==5)
    {
        printf("\n                                            bye !! :(       ");
    }
    else ;
    if (a==0 || a==1 || a==2 || a==3 || a==4 )
        {
        printf("\n                                            +-----+          ");
        printf("\n                                            | . . |          ");
        printf("\n                                            |  |  |          ");
        }
    else ;
    if (a==0 || a==1 || a==2 || a==3)
    {
        printf("\n                                            | --- |          ");
        printf("\n                                            +-----+          ");
        printf("\n                                              | |            ");
    }
    else ;
    if (a==0 || a==1 || a==2)
    {
        printf("\n                                         +-----------+       ");
        printf("\n                                        /|           |\\      ");
        printf("\n                                       / /           \\ \\     ");
        printf("\n                                      / /|           |\\ \\    ");
    }
    else ;
    if (a==0 || a==1)
    {
        printf("\n                                         |           |       ");
        printf("\n                                         |           |       ");
        printf("\n                                         |           |       ");
        printf("\n                                         +-+-+---+-+-+       ");
    }
    else ;
    if (a==0)
    {
        printf("\n                                            | | | |          ");
        printf("\n                                            | | | |          ");
        printf("\n                                            | | | |          ");
        printf("\n                                            | | | |          ");
    }
    else ;
    if (a==0 || a==1 || a==2 || a==3 || a==4 || a==5)
    {
        printf("\n                                   /|/|/|/|/|/|/|/|/|/|/|/|/| ");
        printf("\n                                   //////////////////////////  ");
        printf("\n                                   /|/|/|/|/|/|/|/|/|/|/|/|/| ");
        printf("\n");
    }
    else ;
}
void pnt(int a)
{
    if(a==5)
    {
        printf("\n                                   ________________                ");
        printf("\n                                   |		   |                     ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                 |* *|	           |             ");
        printf("\n                                 | _ |		   |                 ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                   |		   |                     ");
        printf("\n                              +----+----+   	   |                 ");
        printf("\n                             /|         |\\  	   |                 ");
        printf("\n                            / |         | \\	   |                 ");
        printf("\n                           / /|	        |\\ \\	   |             ");
        printf("\n                          / / |         | \\ \\      |             ");
        printf("\n                         ( )  |	        |  ( )     |             ");
        printf("\n                              |	        |	   |                 ");
        printf("\n                              +---------+          |               ");
        printf("\n                               | |   | |	   |                     ");
        printf("\n                               | |   | |	   |                     ");
        printf("\n                               | |   | |           |               ");
        printf("\n                               ^^^   ^^^	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                                   |               ");
        printf("\n                    _______________________________|               ");
        printf("\n");
    }
    else ;
    if(a==4)
    {
        printf("\n                                   ________________                ");
        printf("\n                                   |		   |                     ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                 |* *|	           |             ");
        printf("\n                                 | _ |		   |                 ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                   |		   |                     ");
        printf("\n                              +----+----+   	   |                 ");
        printf("\n                             /|         |\\  	   |                 ");
        printf("\n                            / |         | \\	   |                 ");
        printf("\n                           / /|	        |\\ \\	   |             ");
        printf("\n                          / / |         | \\ \\      |             ");
        printf("\n                         ( )  |	        |  ( )     |             ");
        printf("\n                              |	        |	   |                 ");
        printf("\n                              +---------+          |               ");
        printf("\n                                     | |	   |                     ");
        printf("\n                                     | |	   |                     ");
        printf("\n                                     | |           |               ");
        printf("\n                                     ^^^	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                                   |               ");
        printf("\n                    _______________________________|               ");
        printf("\n");
    }
    else ;
    if(a==3)
    {
        printf("\n                                   ________________                ");
        printf("\n                                   |		   |                     ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                 |* *|	           |             ");
        printf("\n                                 | _ |		   |                 ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                   |		   |                     ");
        printf("\n                              +----+----+   	   |                 ");
        printf("\n                             /|         |\\  	   |                 ");
        printf("\n                            / |         | \\	   |                 ");
        printf("\n                           / /|	        |\\ \\	   |             ");
        printf("\n                          / / |         | \\ \\      |             ");
        printf("\n                         ( )  |	        |  ( )     |             ");
        printf("\n                              |	        |	   |                 ");
        printf("\n                              +---------+          |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                                   |               ");
        printf("\n                    _______________________________|               ");
        printf("\n");
    }
    else ;
    if(a==2)
    {
        printf("\n                                   ________________                ");
        printf("\n                                   |		   |                     ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                 |* *|	           |             ");
        printf("\n                                 | _ |		   |                 ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                   |		   |                     ");
        printf("\n                              +----+----+   	   |                 ");
        printf("\n                              |         |\\  	   |                 ");
        printf("\n                              |         | \\	   |                 ");
        printf("\n                              |	        |\\ \\	   |             ");
        printf("\n                              |         | \\ \\      |             ");
        printf("\n                              |	        |  ( )     |             ");
        printf("\n                              |	        |	   |                 ");
        printf("\n                              +---------+          |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                                   |               ");
        printf("\n                    _______________________________|               ");
        printf("\n");
    }
    else ;
    if(a==1)
    {
        printf("\n                                   ________________                ");
        printf("\n                                   |		   |                     ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                 |* *|	           |             ");
        printf("\n                                 | _ |		   |                 ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                   |		   |                     ");
        printf("\n                              +----+----+   	   |                 ");
        printf("\n                              |         |  	   |                 ");
        printf("\n                              |         | 	   |                 ");
        printf("\n                              |	        |   	   |             ");
        printf("\n                              |         |          |             ");
        printf("\n                              |	        |          |             ");
        printf("\n                              |	        |	   |                 ");
        printf("\n                              +---------+          |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                                   |               ");
        printf("\n                    _______________________________|               ");
        printf("\n");
    }
    else ;
    if(a==0)
    {
        printf("\n                                   ________________                ");
        printf("\n                                   |		   |                     ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                 |* *|	           |             ");
        printf("\n                                 | _ |		   |                 ");
        printf("\n                                 +---+		   |                 ");
        printf("\n                                    		   |                     ");
        printf("\n                                            	   |                 ");
        printf("\n                                           	   |                 ");
        printf("\n                                          	   |                 ");
        printf("\n                                            	   |             ");
        printf("\n                                                   |             ");
        printf("\n                                                   |             ");
        printf("\n                                         	   |                 ");
        printf("\n                                                   |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                        	   |                     ");
        printf("\n                                                   |               ");
        printf("\n                                                   |               ");
        printf("\n                    _______________________________|               ");
        printf("\n");
    }
}
int chk_vrdi(int gg)
{
    int javab;
    int b , c ;
    char a , arr[2];

    if(gg==0)
    {
        gets(arr);
        gets(arr);
    }
    else
    {
        gets(arr);
    }
        a=arr[0];
        b=isalpha(a);
        c=isdigit(a);
        if(c==1)
        {
            javab=atoi(arr);
            return javab ;
        }
        else
        {
            if(b==2)
            {

                return -1000;
            }
            else
            {

                return -1111;
            }
        }

}
//chap last save
void m_chap(save a , char mozoe[10][30],int i)
{
    int  j, k, t;
    char c1;
    printf("your point in the topics : \n");
    for(j=1;j<=i;j++)
        {
            for(t=0;t<a.tedad_bazi;t++)
            {
                if(j==a.emtiaz_ha[t][0])
                {
                    for(k=0;k<30;k++)
                    {
                        c1=mozoe[j][k];
                        if(c1=='\0')
                        {
                            break ;
                        }
                        else
                        {
                            printf("%c",c1);
                        }
                    }
                    printf(":%d",a.emtiaz_ha[t][1]);
                    printf("\n");
                }
                else ;
            }
        }

    printf("\nyour max point : \n");
        for(k=0;k<30;k++)
        {
            c1=mozoe[a.max_emtiaz[0][0]][k];
            if(c1=='\0')
            {
                break ;
            }
            else
            {
                printf("%c",c1);
            }
        }
        printf(":%d",a.max_emtiaz[0][1]);
        printf("\n\n\n");
        // note
        printf("now you can play the topics you played last time again \n");
        printf("if you have better high score it will be saved \n");
        printf("also you can play new topics \n\n\n");
}
//how to play
int htp(void)
{
    int a , gg;
    printf("How to play : \n");
    printf("in this game the computer will show you some topics and you should choose between them \n");
    printf("after that the computer show you some (-) that shows the first word letters \n");
    printf("and you should guess the word \n");
    printf("you can have 4 wrong guess for each word if you guess wrong for five time you will lose that word point \n");
    printf("the point of each word is equal( 3*length of the-wrong guess ) if you can not guess the word the point will be 0 \n");
    printf("the point of a topic is equal to (sum of the words points/time(by second)*100 ");
    printf("for using each hint your point will be sub 7 unit \n");
    printf("[1]Main menu \n");
    printf("[2]Quit\n");
    gg=1;
    while(1)
    {
        a=chk_vrdi(gg);
        if(a==1 || a==2)
        {
            break ;
        }
        else
        {
            gg++;
            printf("Invalid input .\n");
        }
    }
    return a;
}

//high score
int high_score(int tedad_mozoe)
{
    save etelaeat[20] ,l;
    int i=0 , j=0 , k=0 , ii=0 , a=0 ,tos=0 , arr_pre_srt[10][20]={0} ,tmp , nem, kk , gg ,tt;
    char c , nam[30] ,esme_afrad[20][30] ,c7;

    FILE *de_name=fopen("AVAILABLE_NAMES.txt","r");
    if(de_name==NULL)
    {
        printf("Names file not found . \n");
        exit(-1);
    }
    else ;
    while(1)
    {
        while(1)
        {
            c=fgetc(de_name);
            if(feof(de_name))
            {
                break ;
            }
            else ;
            if (c=='.')
            {
                nam[j]='\0';
                fseek(de_name,5*sizeof(char),SEEK_CUR);
                break ;
            }
            else
            {
                nam[j]=c;
                j++;
            }
        }
        //j=0;
        if(feof(de_name))
        {
            break ;
        }
        else
        {
            ii++;
            //printf("[%d]",i);
            //printf("%s\n",mozoe);
            for(i=0;i<=j;i++)
            {
                esme_afrad[ii][i]=nam[i];
            }
        }
        j=0;
    }
    for(j=1;j<=ii;j++)
    {
        for(i=0;i<30;i++)
        {
            c=esme_afrad[j][i];
            a=isalpha(c)+isdigit(c);
            if(a==0)
            {
                break ;
            }
            else ;
        }
        esme_afrad[j][i]='.';
        esme_afrad[j][i+1]='t';
        esme_afrad[j][i+2]='x';
        esme_afrad[j][i+3]='t';
        esme_afrad[j][i+4]='\0';
        //printf("%s\n",esme_afrad[j]);
        FILE *gamer_nam=fopen(esme_afrad[j],"r+");
        if (gamer_nam==NULL)
        {
            printf("Your name not found . \n ");
            //exit(-1);
        }
        else ;
        l=etelaeat[j];
        fscanf(gamer_nam,"%d",&l.tedad_bazi);
        fscanf(gamer_nam,"%d %d",&l.max_emtiaz[0][0],&l.max_emtiaz[0][1]);
        for(i=0;i<l.tedad_bazi;i++)
        {
            fscanf(gamer_nam,"%d %d",&l.emtiaz_ha[i][0],&l.emtiaz_ha[i][1]);
        }
        //return s;
        etelaeat[j]=l;
        for(k=0;k<etelaeat[j].tedad_bazi;k++)
        {

        }
        //chap(etelaeat[j]);
        fclose(gamer_nam);
    }
    for(k=1;k<=tedad_mozoe;k++)
    {
        for(j=1;j<=ii;j++)
        {
            for(i=0;i<etelaeat[j].tedad_bazi;i++)
            {
                if(etelaeat[j].emtiaz_ha[i][0]==k)
                {
                    arr_pre_srt[k][j]=etelaeat[j].emtiaz_ha[i][1];
                    //printf("%d-%d\n",arr_pre_srt[k][j],etelaeat[j].emtiaz_ha[i][1]);
                    //break ;
                    //tos++;
                }

            }
        }
    }

    for(i=1;i<=tedad_mozoe;i++)
    {
        for(j=1;j<=ii;j++)
        {
            for(k=2;k<=ii;k++)
            {
                if(arr_pre_srt[i][j]>arr_pre_srt[i][k])
                {
                    tmp=arr_pre_srt[i][j];
                    arr_pre_srt[i][j]=arr_pre_srt[i][k];
                    arr_pre_srt[i][k]=tmp;
                    for(kk=0;kk<30;kk++)
                    {
                        nam[kk]=esme_afrad[j][kk];
                        esme_afrad[j][kk]=esme_afrad[k][kk];
                        esme_afrad[k][kk]=nam[kk];
                    }

                }
            }
        }
    }
    k=0;
    //printf("Enter the number of topic you want the high score off that : \n");
    while(1)
    {
        printf("Enter the number of topic you want the high score off that : \n");
        nem=chk_vrdi(1);
        if(nem>0 && nem<=tedad_mozoe)
        {
            break ;
        }
        else
        {
            printf("invalid input .\n");
        }
    }
    i=nem;
        for(j=2;j<=ii+1;j++)
        {
            while(1)
            {
                c7=esme_afrad[j-1][k];
                if(c7=='.')
                {
                    nam[k]='\0';
                    break ;
                }
                else
                {
                    nam[k]=c7;
                    k++;
                }
                //printf("%s",nam);
                //printf("%d\n",arr_pre_srt[i][j]);
            }
            printf("%s :",nam);
            printf("%d\n",arr_pre_srt[i][j]);


        k=0;
        }
        //printf("\n");
        printf("[1]Main menu \n");
        printf("[2]Quit\n");
        gg=1;
        while(1)
        {
            tt=chk_vrdi(gg);
            if(tt==1 || tt==2)
            {
                break ;
            }
            else
            {
                gg++;
                printf("Invalid input .\n");
            }
        }
        return tt;
}
//tabe sakht link list
struct node *sakht_node(char *nam)
{
    int i;
    struct node * nn;
    nn = (struct node *) malloc(sizeof(struct node));
    for(i=0;i<50;i++)
    {
        nn->esm[i]=nam[i];
    }
    nn->next = NULL;
    return nn;
}
//tabe ezafe kardan be enteha
void add_end(struct node *list, struct node * new_node)
{
    struct node *current;
    for(current = list; current-> next != NULL; current = current->next);
    current->next = new_node;
    new_node->next = NULL;
}
//adad tasadofi
int adad_t(void)
{
    int a;
    time_t t=time(NULL);
    srand(t);
    a=rand();
    return a;
}
//delete first
void delete_first(struct node **start,char *lgt)
{
	struct node *ptr;
	int temp ,i;
	ptr = *start ;
	temp = ptr->esm;
	*start = ptr->next ;
	for(i=0;i<50;i++)
    {
        lgt[i]=ptr->esm[i];
    }
	//printf("1-%s\n",ptr->esm);
	free(ptr);
}
//delete miane
void delete_mid(int pos,struct node * list,char *lgt)
{
    struct node *p , *q;
    int delNode,k=1  ,i ;
    delNode=pos;
    p=list ;
    while(k!=delNode)
    {
        q=p;
        p=p->next;
        k++;
    }
    q->next=p->next;
    for(i=0;i<50;i++)
    {
        lgt[i]=p->esm[i];
    }
    //printf("2-%s\n",p->esm);
    free(p);
}
//delete end
int delete_end(struct node *list,char *lgt)
{
    int i;
    struct node *temp =list;
    struct node *t;
    while(temp->next != NULL)
    {
        t=temp;
        temp=temp->next;
    }
    for(i=0;i<50;i++)
    {
        lgt[i]=t->next->esm[i];
    }
    //printf("3-%s\n",t->next->esm);
    free(t->next);
    t->next=NULL;
}
// tabe asli
int main (void)
{
    // gereftan etelaeat avalie
    float yor_point,exe_time;
    int i=0 , j=0 ,a , k=0 , d=0 , r=0 ,l ,t , ttt ,sss=0 , wh=0 ,ch=0 ,  qq , wh_save_model=0 , ch_val=0 ,http ,ii=0 , hint[20]={0} , hic ,ccc , hkk=0;
    int edame_ya_jadid ,kodom_mozoe[10]={0} , emtiaz , sum_emtiaz=0 , sev_qut ,qu_re , gme_mdl=0 , mmr_1=0 , hsco;
    char c1 , c2 , c3 , c4 , c5;
    clock_t t1,t2;
    char esme_shakhs[20] , mozoe[30] , loghat[50] ,lgt[50] , de_lgt[50]={0} , nesh_kal[50] , esme_mozoe[10][30];
    struct node *list =NULL;
    struct node *first;
    struct node *nnn;
    struct node **head ;
    for(qq=0;qq<10;qq++)
    {
        sv.emtiaz_ha[1][qq]=0;
    }
    for(qq=0;qq<10;qq++)
    {
        sv.emtiaz_ha[0][qq]=0;
    }
    for(qq=0;qq<10;qq++)
    {
        ab.emtiaz_ha[1][qq]=0;
    }
    for(qq=0;qq<10;qq++)
    {
        ab.emtiaz_ha[0][qq]=0;
    }
    for(qq=0;qq<10;qq++)
    {
        ma.emtiaz_ha[1][qq]=0;
    }
    for(qq=0;qq<10;qq++)
    {
        ma.emtiaz_ha[0][qq]=0;
    }
    FILE *the_topics=fopen("AVAILABLE_TOPICS.txt","r");
    if(the_topics==NULL)
    {
        printf("Topics file not found . \n");
        exit(-1);
    }
    else ;
    printf("Please enter your name : \n");
    scanf("%s",esme_shakhs);
    printf("welcome %s !! \n\n",esme_shakhs);
while(1)
{
    sum_emtiaz=0;
    sss=0;
    //ii=0;
    hkk=0;
    i=0;
    j=0;
    k=0;
    d=0;
    r=0;
    ch=0;

    //i=0;
    while(1)
    {
    //i=0;
    if(mmr_1==0)
    {
        ch_val=0;
    }
    else
    {
        ch_val=1;
    }
    fseek(the_topics,0,SEEK_SET);
    //printf("%d-%d\n",ch_val,mmr_1);
    printf("[1]New game \n");
    printf("[2]Resume last game \n");
    printf("[3]High scores \n");
    printf("[4]How to play \n");
    printf("[5]Exit game \n");
    while(1)
    {
        edame_ya_jadid=chk_vrdi(ch_val);
        if(edame_ya_jadid>=0 && edame_ya_jadid<=5)
        {
            break ;
        }
        else
        {
            ch_val++;
            printf("invalid input .\n");
        }
    }

    /////////////////
    //printf("%d\n",ii);
    while(1)
        {
            //i=0;
            while(1)
            {
                c1=fgetc(the_topics);
                if(feof(the_topics))
                {
                    break ;
                }
                else ;
                if (c1=='.')
                {
                    mozoe[j]='\0';
                    fseek(the_topics,5*sizeof(char),SEEK_CUR);
                    break ;
                }
                else
                {
                    mozoe[j]=c1;
                    j++;
                }
            }
            //j=0;
            if(feof(the_topics))
            {
                break ;
            }
            else
            {
                ii++;
                //printf("[%d]",i);
                //printf("%s\n",mozoe);
                for(i=0;i<=j;i++)
                {
                    esme_mozoe[ii][i]=mozoe[i];
                }
            }
            j=0;
        }
        //printf("%d\n",ii);
    /////////////
    mmr_1=0;
    //barresi shive edame
    if (edame_ya_jadid==2)
    {
        ab=last_save(esme_shakhs);
        m_chap(ab,esme_mozoe,ii);
        //chap(ab);
        wh_save_model=1;
        break ;
    }
    else
    {
        if (edame_ya_jadid==1)
        {
            wh_save_model=0;
            break ;
        }
        else
        {
            if (edame_ya_jadid==3)
            {
                hsco=high_score(ii);
                if(hsco==1)
                {
                    ii=0;
                    mmr_1++;
                    break ;
                }
                else  ;
                if(hsco==2)
                {
                    fclose(the_topics);
                    return 0 ;
                }
                else ;
                break ;
            }
            else
            {
                if(edame_ya_jadid==4)
                {
                    http=htp();
                    if(http==1)
                    {
                        ii=0;
                        mmr_1++;
                        break ;
                    }
                    else  ;
                    if(http==2)
                    {
                        fclose(the_topics);
                        return 0 ;
                    }
                    else ;
                    break ;
                }
                else
                {
                    if(edame_ya_jadid==5)
                    {
                        fclose(the_topics);
                        return 0 ;
                    }
                    else
                    {
                        //mmr_1++;
                        //ch_val++;
                        //printf("Invalid input .\n");
                    }
                }
            }
        }
    }
    }
    if(mmr_1==1)
    {
        continue ;
    }
    else ;
    printf("choose your model :\n");
    printf("[1]Drown\n");
    printf("[2]hanging\n");
    ch_val=1;
    while(1)
    {
        gme_mdl=chk_vrdi(ch_val);
        if (gme_mdl==1 || gme_mdl==2)
        {
            break ;
        }
        else
        {
            printf("Invalid input .\n");
            ch_val++;
        }
    }
    while(1)
{
        fseek(the_topics,0,SEEK_SET);
        sum_emtiaz=0;
        sss=0;
        //ii=0;
        i=0;
        j=0;
        k=0;
        d=0;
        r=0;
        ch=0;
        hkk=0;
        printf("Choose your topic number : \n");
        for(j=1;j<=ii;j++)
        {
            printf("[%d]",j);
            for(k=0;k<30;k++)
            {
                c1=esme_mozoe[j][k];
                if(c1=='\0')
                {
                    break ;
                }
                else
                {
                    printf("%c",c1);
                }
            }
            printf("\n");
        }
        //vorodi motabar
        fseek(the_topics,0,SEEK_SET);
        while(1)
        {
            ch_val=1;
            while(1)
            {
                ttt=chk_vrdi(ch_val);
                if(ttt>0 && ttt<=ii)
                {
                    break ;
                }
                else
                {
                    ch_val++;
                    printf("Invalid input . \n");
                }
            }

            for (k=0;k<10;k++)
            {
                if(ttt==kodom_mozoe[k])
                {
                    printf("This topic was playing later .\n");
                    sss++;
                    //wh--;
                    break ;
                }
                else ;
            }
            if (sss!=0)
            {
                break ;
            }
            else
            {
                kodom_mozoe[wh]=ttt;
                sv.emtiaz_ha[wh][0]=ttt;
            }
            for (j=1;j<=ii;j++)
            {
                if(ttt==j)
                {
                    break ;
                }
            }
            if (j==ii+1)
            {
                printf("Invalid input .\n");
            }
            else
            {
                break ;
            }
        }
        //peida kradan file i ke bayad baz shavad
        if(sss!=0)
        {
            continue;
        }
        else ;
            //ii=0;
            i=0 ;
            j=0 ;
            while(1)
            {
                c1=fgetc(the_topics);
                if(feof(the_topics))
                {
                    break ;
                }
                else
                {
                    if (c1=='.')
                    {
                        j++;
                        if(j==ttt)
                        {
                            mozoe[i]='.';
                            mozoe[i+1]='t';
                            mozoe[i+2]='x';
                            mozoe[i+3]='t';
                            mozoe[i+4]='\0';
                            break ;
                        }
                        else
                        {
                            fseek(the_topics,5*sizeof(char),SEEK_CUR);
                        }
                        i=0 ;
                    }
                    else
                    {
                        mozoe[i]=c1;
                        i++;
                    }
                }
            }
        // baz kardna va khandan file
        FILE * dis_topic=fopen(mozoe,"r");
        if(dis_topic==NULL)
        {
            printf("Can not open your topic file .");
            fclose(the_topics);
            exit(-1);
        }
        else ;
        k=0;
        while (1)
        {
            i=0 ;
            while(1)
            {
                c1=fgetc(dis_topic);
                a=isalpha(c1);
                if (a==0)
                {
                    loghat[i]='\0';
                    break ;
                }
                else ;
                if (a==2)
                {
                    loghat[i]=c1;
                    i++;
                }
                else ;
            }
            for(i=0;i<50;i++)
            {
                lgt[i]=loghat[i];
            }
            if (feof(dis_topic))
            {
                break ;
            }
            else ;
            if (list==NULL)
            {
                k++;
                list=sakht_node(lgt);
            }
            else
            {
                k++;
                nnn=(struct node *) malloc(sizeof(struct node));
                for(i=0;i<50;i++)
                {
                    nnn->esm[i]=lgt[i];
                }
                add_end(list,nnn);
            }
        }
    //adad tasadfi dar baze va hazfe node ha
    head=&list;
    while(1)
    {
        if (k==0)
        {
            t2=clock()-t1;
            break ;
        }
        a=adad_t()%k;
        a++;

        if (k==1)
        {
            delete_first(head,de_lgt);
        }
        else
        {
            if (k==2)
            {
                delete_first(head,de_lgt);
            }
            else
            {
                if(a==1)
                {
                    delete_first(head,de_lgt);
                }
                else
                {
                    if(a==k)
                    {
                        delete_end(list,de_lgt);
                    }
                    else
                    {
                        delete_mid(a,list,de_lgt);
                    }
                }
            }
        }
        i=0;
        j=0;
        //printf("%s\n",de_lgt);
        //shomordan tedad horof har kalame
        while(1)
        {
            c1=de_lgt[i];
            //printf("%c-",c1);
            a=isalpha(c1);
            if(a==0)
            {
                break ;
            }
            else
            {
                j++;
            }
            if(j==50)
            {
                break ;
            }
            else ;
            i++;
        }
        k--;
        for(i=0;i<j;i++)
        {
            nesh_kal[i]='-';
        }
        nesh_kal[i]='\0';
        if (ch==0)
        {
            t1=clock();
        }
        else ;
        printf("%s\n",nesh_kal);
        l=0;
        t=0;
        //r=0;
        while (1)
        {
            d=0;
            //printf("\n");
            printf("Enter your letter : \n");
            if(r==0)
            {
                //gets(&c3);
                gets(&c2);
            }
            else
            {
                gets(&c2);
            }
            if(c2=='Q')
            {
                printf("[1]Save and quit\n");
                printf("[2]Quit\n");
                scanf("%d",&sev_qut);
                if(sev_qut==1)
                {
                    if(wh_save_model==0)
                    {
                        sv=find_max_point(sv);
                        //chap(sv);
                        save_game(sv,esme_shakhs,wh_save_model);
                        fclose(the_topics);
                        return 0 ;
                    }
                    else ;
                    if(wh_save_model==1)
                    {
                        sv=find_max_point(sv);
                        ma=ghias_save_ha(ab,sv);
                        save_game(ma,esme_shakhs,wh_save_model);
                        fclose(the_topics);
                        return 0 ;
                    }
                }
                //return 0 ;
            mmr_1=0;
            }
            if(c2=='M')
            {
                ii=0;
                mmr_1++;
                break ;
            }
            else ;
            hic=0;
            if(c2=='H')
            {
                hkk++;
                if(hkk==5)
                {
                    printf("you use all of your hints in this topic .\n");
                    printf("Enter your letter : \n");
                    gets(&c2);
                }
                else
                {
                //printf("%s\n",de_lgt);
                for(i=0;i<j;i++)
                {
                    if(nesh_kal[i]=='-')
                    {
                        //printf("%d\n",i);
                        //break ;
                        hint[hic]=i;
                        hic++;
                    }
                    else ;
                }
                nesh_kal[hint[0]]=de_lgt[hint[0]];
                c4=de_lgt[hint[0]];
                for(i=1;i<hic;i++)
                {
                    c5=de_lgt[hint[i]];
                    ccc=isalpha(c5);
                    if(ccc==0)
                    {
                        break ;
                    }
                    else ;
                    if(c4==c5)
                    {
                        t++;
                        nesh_kal[hint[i]]=c5;
                    }
                    else ;
                }
                t++;
                sum_emtiaz=sum_emtiaz-7;
                }
            }
            else ;
            //scanf("%c",&c2);
            for(i=0;i<j;i++)
            {
                if(c2==de_lgt[i])
                {
                    if(nesh_kal[i]=='-')
                    {
                        t++;
                        d++;
                    }
                    else ;
                    nesh_kal[i]=c2;

                }
                else ;
                //printf("\n");
            }
            if (d==0)
            {
                //printf("%c\n",c2);
                printf("Wrong \n");
                l++;
                if(gme_mdl==1)
                {
                    prnt(l);
                }
                else ;
                if(gme_mdl==2)
                {
                    pnt(l);
                }
                else ;
            }
            else
            {
                printf("Correct \n");
                if(gme_mdl==1)
                {
                    prnt(l);
                }
                else ;
                if(gme_mdl==2)
                {
                    pnt(l);
                }

            }
            printf("%s\n",nesh_kal);
            //printf("%d-%d\n",t,j);
            if(t==j)
            {
                emtiaz=3*t-l;
                sum_emtiaz+=emtiaz;
                //sum_all_emtiaz+=emtiaz;
                printf("The word was %s \n",de_lgt);
                //hkk=0;
                break ;
            }
            if(l==5)
            {
                emtiaz=0;
                sum_emtiaz+=emtiaz;
                //sum_all_emtiaz+=emtiaz;
                printf("The word was %s \n",de_lgt);
                //hkk=0;
                break ;
            }
            else ;
            r++;
        }
        ch++;
        if(mmr_1==1)
        {
            break ;
        }
        else ;


    }
    if(mmr_1==1)
    {
        break ;
    }
    else ;

    exe_time=((float)t2)/CLOCKS_PER_SEC;
    //printf("%d\n",exe_time);
    yor_point=sum_emtiaz/exe_time;
    yor_point*=100;
    sv.emtiaz_ha[wh][1]=yor_point;
    printf("Your point is %.0f\n",yor_point);
    printf("[1]Quit\n");
    printf("[2]Resume\n");
    printf("[3]Main menu\n");
    ch_val=1;
    while(1)
    {
        qu_re=chk_vrdi(ch_val);
        if (qu_re==1 || qu_re==2 || qu_re==3)
        {
            break ;
        }
        else
        {
            printf("Invalid input .\n");
            ch_val++;
        }
    }

    wh++;
    sv.tedad_bazi=wh;
    //printf("%d\n",wh);
    if(qu_re==1)
    {
        printf("[1]Save and quit\n");
        printf("[2]Quit\n");
        ch_val=1;
        while(1)
        {
            sev_qut=chk_vrdi(ch_val);
            if (sev_qut==1 || sev_qut==2)
            {
                break ;
            }
            else
            {
                printf("Invalid input .\n");
                ch_val++;
            }
        }
        if(sev_qut==1)
        {
            if(wh_save_model==0)
            {
                sv=find_max_point(sv);
                //chap(sv);
                save_game(sv,esme_shakhs,wh_save_model);
                fclose(the_topics);
                return 0 ;
            }
            else ;
            if(wh_save_model==1)
            {
                sv=find_max_point(sv);
                ma=ghias_save_ha(ab,sv);
                save_game(ma,esme_shakhs,wh_save_model);
                fclose(the_topics);
                return 0 ;
            }
        }
        else
        {
            fclose(the_topics);
            return 0;
        }
    }
    if(qu_re==3)
    {
        ii=0;
        mmr_1++;
        break ;
    }
    else ;
    fclose(dis_topic);
}
}
}



