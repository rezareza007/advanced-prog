#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100

struct list_node {
    char* word;
    int count;
    struct list_node * next;  //Pointer to the next word  
    struct list_node * prev;  //Pointer to the previous word
};

//Inserts the new_node after the existing_node
void insert_after(struct list_node * new_node, struct list_node * existing_node)
{
   if (existing_node==NULL || new_node==NULL)
     return;

   struct list_node * existing_next;
   existing_next=existing_node ->next;
   
   existing_node->next =new_node;
   new_node-> next = existing_next;

   if (existing_next!=NULL) existing_next->prev=new_node;
   new_node ->prev= existing_node;

}

//Inserts a new node for new_word in the linked list whose first node is head.
 struct list_node * insert (char* new_word, struct list_node * head)
{
    struct list_node *new_node;
    new_node=(struct list_node *) malloc(sizeof(struct list_node));
    if(new_node==NULL)
    {
        printf("%s", "Can't create a new node\n");
    }

    new_node->word=strdup(new_word);
    new_node->count=1;
    new_node->next=NULL;
    new_node->prev=NULL;


    int c;
    
    //struct list_node *head=*head_pointer;

    if(head==NULL) //The list is empty
    {
            //printf("%s", "head pointer is null\n");
            head=new_node;
            printf("%s", "Created the first node\n");
            return head;

    }

    struct list_node * current=head;
    
    while(1) //(current-> next!=NULL)
    {   
        printf("%s, %s\n",current->word, new_word );

        c=strcmp( current->word, new_word );
        if(c==0){
              //The two words are equal
                   (current->count)++;
                   break;
            }
        else if (c>0)  //current->word is greater than new_word
        {   
            if(current->prev!=NULL) 
                insert_after(new_node, current->prev);
            else //We must update the head
            {
                new_node->next=head;
                (head)-> prev=new_node;
                head=new_node;
            } 
            break;
        }
        else{   //new_word is greater
            //This is the way to go to the next node of a linked list:
            
            if (current->next!=NULL)
                current=current->next;
            else //We reached the end of the list
            {   //Insert the new node at the end of the list
                insert_after(new_node, current);
                break;
            
            } 
            
        } 
    }

    return head;

}

int main(int argc, char* argv[]) 
 { 
    if( argc<1)
    {
       printf("Please supply a file name!\n");
       return 1;
    }

    //char *filename=argv[1];
    char* filename="text.txt";
    FILE* f;
    f=fopen(filename, "r");

    if (f==NULL)
    {
        printf("%s", "Can't open the file!\n");
        return 1;
    }

    int n; 
    char word[MAXWORD]; 

    struct list_node*head=NULL;

    while ( fscanf(f, "%s", word, MAXWORD)!=EOF )
    {
        //printf("%s\n", word);
        head=insert(word, head);
        printf("%s\n",head->word);
    
    }

    fclose(f);

    struct list_node *current=head; 
    while(current!=NULL)
    {
            printf("%4d %s\n", current-> count, current->word);
            current=current->next; 
    }
        
 } 
 