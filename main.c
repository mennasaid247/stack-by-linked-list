#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
typedef struct
{float data;
struct node *next;
}node;
typedef struct
{char data;
struct node *next;
}nodechar;

node*newnode(float  x)
{node*n=malloc(sizeof(node));
n->data=x;
n->next=NULL;
return n;

}
nodechar*newnodechar(char  x)
{nodechar*n=malloc(sizeof(nodechar));
n->data=x;
n->next=NULL;
return n;

}
typedef struct
{
    node*top;

}stack;
typedef struct
{
    nodechar*top;

}stackchar;
stack *init()
{
    stack*s=malloc(sizeof(stack));
    s->top= NULL;
    return s;
}
stackchar *initchar()
{
    stackchar*s=malloc(sizeof(stackchar));
    s->top= NULL;
    return s;
}
void push(stack*s,float x)
{node*p=newnode(x);
p->next=s->top;
s->top=p;

}
void pushchar(stackchar*s,char x)
{nodechar*p=newnodechar(x);
p->next=s->top;
s->top=p;

}

float pop(stack*s)
{node*temp=s->top;
float data=s->top->data;
s->top=s->top->next;
free(temp);




return data;
}
char popchar(stackchar*s)
{nodechar*temp=s->top;
char data=s->top->data;
s->top=s->top->next;
free(temp);




return data;
}
float peek(stack*s)
{
   return s->top->data;

}
char peekchar(stackchar*s)
{
   return s->top->data;

}
int isEmpty(stack *s)
{
    if(s->top==NULL)
        return 1;
    return 0;
}
int isEmptychar(stackchar *s)
{
    if(s->top==NULL)
        return 1;
    return 0;
}
int priority(char op)
{
    if(op=='^')
        return 3;
        if(op=='-'||op=='+')
            return 1;
          if(op=='*'||op=='/')
            return 2;
            return 0;

}
char*  infixToPostfix(char* infix)
{int n=strlen(infix);
stackchar *temp=initchar();
char*s=malloc((n)+1);
int i;
for(i=0;i<n;i++)
{
    if(isdigit(infix[i]))
        {s[i]=infix[i];

        }
    else
    {if(infix[i]=='(')
        {
            pushchar(temp,infix[i]);
            continue;
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {if(isEmptychar(temp))
        pushchar(temp,infix[i]);
          else
          {while(!isEmptychar(temp))
            {
                if(priority(peekchar(temp))>=priority(infix[i]))
                {
                    s[i]=popchar(temp);

                }
                else

                {
                     pushchar(temp,infix[i]);
                     break;
                }
            }
        }}
        else if(infix[i]==')')
        {


           while(!isEmptychar(temp)&&peekchar(temp)!='(')
            {s[i]=popchar(temp);


            }
            char z=popchar(temp);

        }
        else
            s[i]=infix[i];

    }
}
return s;
}
int main()
{
  char *infixExpr = "(4+3-(4-3/2-1)-2)";
  char* s= infixToPostfix(infixExpr);
  printf("%s",s);
 /* char s[4]="no";
  if(s[0]=='n')
    printf("menna\n");
  else
    printf("no");*/
    return 0;
}
