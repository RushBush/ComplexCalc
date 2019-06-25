#include "menu.h"

void Menu()
{
  char k,c,prefix[]="lib",postfix[]=".so",*libName;
  int libCount=0,real,img,select;
  char libs[10][12];
  struct ComplexNum (*funcArr[10])(struct ComplexNum,struct ComplexNum);
  struct ComplexNum complex1,complex2,result;
  void *ptr[10],*ptrPrint=dlopen("libPrint.so",RTLD_NOW);
  void (*Print)(struct ComplexNum);

  if (!ptrPrint)
  {
    printf("Check 'libPrint.so' file and run program again!\n");
    return;
  }

  Print=dlsym(ptrPrint,"Print");

  if (!Print)
  {
    printf("Function 'Print' not found in 'libPrint'!\n");
    return;
  }


  while(1)
  {
      printf("MENU:\n");
      printf("0.Add dynamic lib\n");

      for (int i=0;i<libCount;i++)
      {
        printf("%d.%s\n",i+1,libs[i]);
      }

      printf("Q.Exit\n");
      printf("Enter menu item in range [0-%d]:",libCount);
      scanf("%c",&k);
      getchar();

      if (k=='Q')
      {
        printf("\e[1;1H\e[2JGoodbye!\n");
        return;
      }

      if (k=='0')
      {
          if (libCount==10)
          {
              printf("Can't add more function!\n");
              continue;
          }

          printf("Enter library name without 'lib' prefix and '.so':");
          fgets(libs[libCount],12,stdin);
          strtok(libs[libCount],"\n");

          libName=malloc(sizeof(libs[libCount])+sizeof(prefix));

          strcpy(libName,prefix);
          strcat(libName,libs[libCount]);
          strcat(libName,postfix);

          ptr[libCount]=dlopen(libName,RTLD_NOW);

          if (!ptr[libCount])
          {
            printf("\e[1;1H\e[2J");
            fprintf(stderr, "dlopen failed: %s\n", dlerror()); 
            printf("Can't open 'lib%s.so'\n",libs[libCount]);
            continue;
          }

          funcArr[libCount]=dlsym(ptr[libCount],libs[libCount]);

          if (!funcArr)
          {
            printf("\e[1;1H\e[2J");
            printf("Can't find function '%s' in 'lib%s.so'\n",libs[libCount],libs[libCount]);
            continue;
          }

          printf("\e[1;1H\e[2J");

          printf("Function '%s' added\n",libs[libCount]);

          libCount++;


      }
      else if (k>'0' && k<=(libCount+'0'))
      {
          printf("Enter two complex numbers (ex.:'1 2' is 1+2i):\n");
          printf("Enter first number:");
          scanf("%d",&real);
          scanf("%d",&img);
          complex1.real=real,complex1.img=img;
          printf("Enter second number:");
          scanf("%d",&real);
          scanf("%d",&img);
          getchar();
          complex2.real=real,complex2.img=img;

          select=(int)k-48;
          result=funcArr[select-1](complex1,complex2);
          printf("\e[1;1H\e[2J");
          printf("Result of %s is ",libs[select-1]);
          Print(result);
      }
      else
      {
          printf("\e[1;1H\e[2J");
          printf("Incorrect digit,please try again!\n");
          continue;
      }
  }

  dlclose(ptrPrint);

  for (int i=0;i<libCount;i++)
    dlclose(ptr[i]);


}
