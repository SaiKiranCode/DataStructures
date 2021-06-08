void bubblesort(int q[],int n)
{
 int i,j,temp;
 for(i=0;i<n;i++)
     {
         for(j=0;j<(n-i-1);j++)
            {
                if(q[j]>q[j+1])
                     {
                       temp=q[j+1];
                       q[j+1]=q[j];
                       q[j]=temp;

                        }

             }
       }
     printf("sortet array");
     for(i=0;i<n;i++)
     {
      printf("%d\t ",q[i]);
     }

