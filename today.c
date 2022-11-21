  #include &lt;stdio.h&gt;
  #include &lt;stdlib.h&gt;
  struct node
  {
  float coeff;
  int expo;
  struct node* link;
  };
  struct node *insert(struct node *head, float co, int ex)
  {
  struct node *temp;
  struct node *newP=malloc(sizeof(struct node));
  newP-&gt;coeff=co;
  newP-&gt;expo=ex;
  newP-&gt;link=NULL;
  if(head==NULL||ex&gt;head-&gt;expo)
  {
  newP-&gt;link=head;
  head=newP;
  }
  else
  {
  temp=head;
  while(temp-&gt;link!=NULL&amp;&amp;(temp-&gt;link-&gt;expo)&gt;ex)
  {
  temp=temp-&gt;link;
  }
  newP-&gt;link=temp-&gt;link;
  temp-&gt;link=newP;
  }
  return head;
  }
  void create(struct node *head)
  {
  int n;
  printf(&quot;Enter the number of terms:\n&quot;);
  scanf(&quot;%i&quot;, &amp;n);
  for(int i=0; i&lt;n; i++)
  {
  printf(&quot;Enter the coefficent and exponent:\n&quot;);
  scanf(&quot;%f%i&quot;, &amp;head-&gt;coeff, &amp;head-&gt;expo);
  head=insert(head, head-&gt;coeff, head-&gt;expo);
  }
  }
  void display(struct node *head)
  {
  if(head==NULL)
  {
  printf(&quot;Polynomial empty\n&quot;);
  }
  else
  {
  struct node *temp=head;

  while(temp!=NULL)
  {
  printf(&quot;(%.1fx^%i)&quot;, temp-&gt;coeff, temp-&gt;expo);
  temp=temp-&gt;link;
  if(temp!=NULL)
  {
  printf(&quot;+&quot;);
  }
  else
  {
  printf(&quot;\n&quot;);
  }
  }
  }
  }
  int main()
  {
  struct node *head1=NULL;
  struct node *ptr1;
  printf(&quot;Enter the first polynomial\n&quot;);
  create(head1);
  ptr1=head1;
  struct node *head2=NULL;
  struct node *ptr2;
  printf(&quot;Enter the second polynomial\n&quot;);
  create(head2);
  ptr2=head2;
  struct node *head3=NULL;
  float res1;
  int res2;
  while(ptr1!=NULL)
  {
  while(ptr2!=NULL)
  {
  res1=ptr1-&gt;coeff*ptr2-&gt;coeff;
  res2=ptr1-&gt;expo+ptr2-&gt;expo;
  head3=insert(head3, res1, res2);
  ptr2=ptr2-&gt;link;
  }
  ptr1=ptr1-&gt;link;
  }
  display(head3);
  }
