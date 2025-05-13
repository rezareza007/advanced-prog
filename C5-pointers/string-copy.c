/* strcpy: copy t to s; array subscript version */ 
 void strcpy(char *s, char *t) 
 { 
 int i; 
 i = 0; 
 
 while (t[i] != '\0') 
 {  s[i] = t[i];
    i++; 
 }
  t[i]='\0';

 } 

 /* strcpy: copy t to s; pointer version */ 
 void strcpy(char *s, char *t) 
 { 
  
 while ((*s = *t) != '\0') { 
 s++; 
 t++; 
 } 
 } 


 /* strcpy: copy t to s; pointer version 3 */ 
 void strcpy(char *s, char *t) 
 { 
 while (*s++ = *t++) 
 ; 
 } 