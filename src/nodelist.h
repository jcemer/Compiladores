struct nodelist {
   Node *data;
   struct nodelist *link;
};

void listadd(struct nodelist **list, Node *data){
   struct nodelist *new, *temp;

   new = (struct nodelist *) malloc(sizeof(struct nodelist));
   new->data = data;
   new->link = NULL;

   if(*list == NULL){
      *list = new;
   }else{
      temp = *list;
      while(temp->link != NULL)
         temp = temp->link;
      temp->link = new;
   }
}
Node* listget(struct nodelist **list, int i){
   struct nodelist *temp = *list;
   for(i; i > 0 && temp != NULL; i--)
      temp = temp->link;
   return temp->data;
}
int listlenght(struct nodelist **list){
   int i = 0;
   struct nodelist *temp = *list;

   while(temp != NULL){
      temp = temp->link;
      i++;
   }
   return i;
}

