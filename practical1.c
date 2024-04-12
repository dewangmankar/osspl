#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

void getdir1(){
  DIR *dir = opendir(".");
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *de;
  de = readdir(dir);
  while(de!= NULL){
   if(de -> d_name[0]!='.'){
     printf("%s \n ",de-> d_name);
    }
    de= readdir(dir);
  }
  closedir(dir);
}

void getdir2(){
  DIR *dir = opendir(".");
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *de;
  de = readdir(dir);
  while(de!=NULL){
   if(de -> d_name[0]=='.'){
     printf("%s\n",de -> d_name);
    }
    de = readdir(dir);
  }
  closedir(dir);
}
void getdir3(){
  DIR *dir = opendir(".");
  if(dir == NULL){
   printf("No files exit\n");
  }
  
  struct dirent *de;
  de = readdir(dir);
  printf("name \t type \t indexno \t offset \n");
  while(de!= NULL){
   if(de -> d_name[0]!='.'){
     printf("%s \t %d \t %ld \t %ld \n ",de-> d_name,de->d_type,de->d_ino,de->d_off);
    }
   if(de -> d_name[0]=='.'){
     printf("%s \t %d \t %ld \t %ld \n ",de-> d_name,de->d_type,de->d_ino,de->d_off);
    }
    de = readdir(dir);
  }
  closedir(dir);
}


int main(int argc, char *argv[]){
 int opt;
 while((opt =getopt(argc,argv,":lai"))!=-1){
  switch(opt){
    case 'l':
      printf("l flag is used\n");
      getdir1();
      break;
      
    case 'a':
      printf("a flag is used\n");
      getdir2();
      break;  
    case 'i':
      getdir3();
      break;
    
    default: 
      printf("Unhandled option");
  }
 }
 
 return 0;
}
