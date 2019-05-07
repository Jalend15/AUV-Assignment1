#include <iostream>
using namespace std;
  struct node
  {
    int data;
    node* next1;
    node* next2;
  };
node *createlist1(int a, int n)
{
  node *head = NULL;
  node * tail = NULL;
  int x=a;
  while(x<=n)
    {
      //A.add_node(x);
        node *tmp = new node;
        tmp->data = x;
        tmp->next1 = NULL;
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
	  tail->next1 = tmp;
          tail = tail->next1;
        }
        x+=a;
         }
  tail=NULL;
         return head;
}
node *createlist2(int a, int b,int n,node **A)
{
  node *head = NULL;
  node * tail = NULL;
  node *prev=NULL;
  node *head2=*A;
  int x=a;
  int y=b;
  int j=0;
  while(y<=n)
    {
        node *tmp = new node;
        tmp->data = y;
        tmp->next2 = NULL;
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
	    prev= tmp;
        }
        else
        {
	  if(y==b+b)
	    {
	      prev=tmp;
	    }
	  else
	    {
	      prev=tail;
	    }
	  
	  tail->next2 = tmp;
          tail = tail->next2;
        }
      if(y%x==0)
	{ 
	  int i =y/x;
          
	  while(i-j>1)
	    {
	      *A=(*A)->next1;
	      i--;
	    }
	  j=y/x;
	  (*A)->next2=tail->next2;
	  prev->next1=*A;
	}


        y+=b;
	
         }
        *A=head2;
	tail=NULL;
         return head;
}
void prnlist(node *A, int s)
{ 
  while(A!=NULL)
     {
       cout<<A->data<<" ";
       if(s==1)
	 {
       A=A->next1;
	 }
       else
	 {
	   A=A->next2;
	 }
       
      }
  cout<<"\n";
	}
void prnboth(node* A,node *B)
{
    while(A!=NULL&&B!=NULL)
      {
	if(A->data>B->data)
	  {
	    cout<<B->data<<" ";
	    B=B->next2;
	   
       	  }
	else if(A->data<B->data)
	  {
	    cout<<A->data<<" ";
	    A=A->next1;
	    
       	  }

	else if(A->data==B->data)
	  {
	   
	    cout<<A->data<<" ";
	    A=A->next1;
	    B=B->next2;
	    
	  }
	     
      }
      if(B==NULL&&A!=NULL)
	  {
	   
	    while(A!=NULL)
	      {
      		cout<<A->data<<" ";
	      	A=A->next1;
	      }
	  }
	  
        
	    while(B!=NULL)
	      {
  		cout<<B->data<<" ";
		B=B->next2;
		}
	 
      }
  
   int main()
  {
    int a,b,n;
    node* A;
    node *B;
    cin>>a;
    cin>>b;
    cin>>n;
    if(a<b)
      {
    A= createlist1(a,n);
    B=createlist2(a,b,n,&A);
      }
    else
      {
      A= createlist1(b,n);
    B=createlist2(b,a,n,&A);
      }
   prnlist(A,1);
   prnlist(B,2);
   
    prnboth(A,B);
  
	  
  }  
