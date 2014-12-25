#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
clock_t t;
t=clock();
int pid,i,pid2,pid3,pid4,temp=9;
void runit();
void runit2();
void runit3();
void runit4();
//for(i=0;i<10;i++)
{
switch(pid=fork())
{
case 0:
 switch(pid2=fork())
 {
  case 0:
   switch(pid3=fork())
   {
    case 0:
     switch(pid4=fork())
     {
      case 0:
	t=clock();       
	runit4();
	t=clock()-t;
	break;
      default:
temp++;
	break;
      case -1:
       /* something went wrong */
       perror("fork");
       break;
   }
	temp++;
	runit3();
    break;
    default:
     //exit(1);
    break;
    case -1:
    /* something went wrong */
    perror("fork");
    break;
   }
  runit2();
  break;
  default:
  //exit(1);
  break;
  case -1:
  /* something went wrong */
  perror("fork");
  break;
 }
 runit();
break;
default:
break;
case -1:
 /* something went wrong */
perror("fork");
exit(1);
}
//continue;
}
printf("temp=%d",temp);
}

void runit(void)
{
//printf("About to run exec1\n");
execlp("openssl", "openssl", "dgst","-sha256","-sign","rsaprivatekey2048.pem","-out","msg1.sha256","msg1", (char *) 0);

//perror("execlp"); /* if we get here, execlp failed */
//exit(1);
}
void runit2(void)
{
execlp("openssl", "openssl", "dgst","-sha256","-sign","rsaprivatekey1024.pem","-out","msg2.sha256","msg1", (char *) 0);
//printf("About to run exec2\n");
//perror("execlp"); /* if we get here, execlp failed */
//exit(1);
}
void runit3(void)
{
execlp("openssl", "openssl", "dgst","-sha1","-sign","rsaprivatekey2048.pem","-out","msg3.sha1","msg1", (char *) 0);
//printf("About to run exec2\n");
//perror("execlp"); /* if we get here, execlp failed */
//exit(1);
}
void runit4(void)
{
execlp("openssl", "openssl", "dgst","-sha1","-sign","rsaprivatekey1024.pem","-out","msg4.sha1","msg1", (char *) 0);
//printf("About to run exec2\n");
//perror("execlp"); /* if we get here, execlp failed */
//exit(1);
}
