#include<stdio.h>
#include<string.h>

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

   existing_next->prev=new_node;
   new_node ->prev= existing_node;

}

//Inserts a new node for new_word in the linked list whose first node is head.
void insert (char* new_word, struct list_node * head)
{
    struct list_node new_node;
    new_node.word=new_word;
    new_node.count=1;

    if(head==NULL) //The list is empty
    {
            
            head=&new_node;

    }
    struct list_node * current=head;
    
    while(current-> next!=NULL)
    {
        switch (strcmp( current->word, new_word ))
        {
            case 0:  //The two words are equal
                   (current->count)++;
                   break;
            case 1:  //current->word is greater

            insert_after(&new_node, current->prev);
            break;

            case -1:  //new_word is greater
            //This is the way to go to the next node of a linked list:
            
            if (current->next!=NULL)
                current=current->next;
            else //We reached the end of the list
            {   //Insert the new node at the end of the list
                insert_after(&new_node, current);
            
            }      
        } 
    }

}