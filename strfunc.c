/*
Ruochong Wu
Systems Level Programming - Pd 5
Work1 - If you liked it then you should've put a string on it
9/30/16
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int mystrlen(char s[]){
  int res = 0;
  int count = 0;
  for (count ; *(s+count) ; count++){
    res+=1;
  }
  return res;
}


char *mystrcpy(char d[], char s[]){ //What to do when dest shorter than source? Assumes the destination is large enough for now.
  /*  if (strlen(s) > sizeof(d)){ //Return -1 if dest not large enough to contain the source
    return -1;
  }
  */
  int count = 0;
  // printf("%s\n",d);
  while (s[count]){
    //    printf("%s\n",d);
    //     printf("%d\n",d[count]);
     // printf("%d\n",s[count]);
    d[count] = s[count];
    //     printf("%d\n",d[count]);
    count+=1;
    
  }
  d[count]=0;
  return d;
}

char *mystrncpy(char d[], char s[], int n){
  int count = 0;
  while (n){
    d[count] = s[count];
    count+=1;
    n-=1;
  }
  d[count] = 0;
  return d;
}

char *mystrcat(char d[], char s[]){
  d+=mystrlen(d);
  while (*s){
    *d = *s;
    d+=1;
    s+=1;
  }
  *d = 0;
  return d;
}

char *mystrncat(char d[], char s[], int n){
  int off = mystrlen(d);
  int count = 0;
  while (n){
    d[count+off] = s[count];
    n-=1;
    count+=1;
  }
  return d;
}

int max(int a, int b){
  if (a>b){
    return a;
  }
  return b;
}


int mystrcmp(char a[], char b[]){
  int count = 0;
  while (count<max(mystrlen(a),mystrlen(b))){
    if ((a[count] - b[count])!=0){
      printf("%d %d\n",a[count],b[count]);
      return a[count] - b[count];
    }
    count+=1;
  }
  return 0;
}

char *mystrchr(char a[], char b){
  while(*a){
    if (*a == b){
      return a;
    }
    a+=1;
  }
  return 0;
}

char * mystrstr(char a[], char b[]){
  int count = 0;
  while(*a){
    while(1){
      if (count == mystrlen(b)){
	return a;
      }
      if (*(a+count) != *(b+count)){
	break;
      }
      count +=1;
      
    }
    count = 0;
    a+=1;
  }
  return 0;
}

int main(){
  printf("Testing mystrlen\n");
  char s[10] = "Hello";
  char d[] = "";
  printf("mystrlen of Hello: %d\n", mystrlen(s));
  printf("strlen of Hello: %d\n", strlen(s));
  printf("mystrlen of empty string: %d\n", mystrlen(d));
  printf("strlen of empty string: %d\n", strlen(d));
  printf("mystrlen of literal string: %d\n", mystrlen("Hello"));
  printf("strlen of literal string: %d\n", strlen("Hello"));
  
  printf("\nTesting mystrcpy\n");
  char x[100] = "Dog";
  char y[] = "Snake";
  printf("before cpy x is: %s\n", x);
  printf("after cpy x is: %s\n", mystrcpy(x, y));

  printf("\nTesting mystrncpy\n");
  char i[100] = "Dog";
  char j[] = "Snake";
  printf("before cpy x is: %s\n", i);
  printf("after cpy x is: %s\n", mystrncpy(i, j, 3));

  printf("\nTesting mystrcat\n");
  char k[100] = "Hello";
  char l[100] = " to you!";
  printf("before ncat k is: %s\n",k);
  mystrcat(k,l);
  printf("after cat k is: %s\n",k);
  
  printf("\nTesting mystrncat\n");
  char a[100] = "Hello";
  char b[100] = " to you!";
  printf("before ncat a is: %s\n",a);
  mystrncat(a, b, 6);
  a[mystrlen(a)+1]=0;
  printf("after ncat a is: %s\n",a);

  printf("\nTesting mystrcmp\n");
  char c[100] = "Hello";
  char e[101] = "Hella";
  printf("comparing Hello and Hella: %d\n", strcmp(c,e));

  printf("\nTesting mystrchr\n");
  char f[100] = "This is a tes";
  printf("Finding t in f: %c at position %li", *(mystrchr(f, 't')), mystrchr(f,'t'));

  printf("\nTesting mystrstr\n");
  char g[100] = "How are you?";
  char h[10] = "are";
  printf("Finding are in g: %li\n", mystrstr(g,h));
  return 0;
}
