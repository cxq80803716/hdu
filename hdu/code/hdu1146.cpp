#include<stdio.h>
#include<string.h>

#define N 10000 + 50


int node_l[N] ,node_r[N];
int id_l[N] ,id_r[N];
int ans[N];
int n_l ,n_r;

int maxx(int x ,int y)
{
   return x > y ? x : y;
}

int main ()
{
   int n ,y ,m ,tt ,t;
   int i ,j ,time;
   char str[10];
   scanf("%d" ,&tt);
   while(tt--)
   {
      scanf("%d %d %d" ,&n ,&t ,&m);
      n_l = n_r = 0;
      for(i = 1 ;i <= m; i ++)
      {
         scanf("%d %s" ,&time ,str);
         if(str[0] == 'l')  
         {
            node_l[++n_l] = time;
            id_l[n_l] = i;
         }
         else 
         {
            node_r[++n_r] = time;
            id_r[n_r] = i;
         }
      }
      int now_fx = 1 ,now_time = 0;
      int l = 1 ,r = 1;
      while(l <= n_l || r <=  n_r)
      { 
         if(l <= n_l && node_l[l] < node_r[r] || r > n_r)
         {
            
            if(now_fx != 1) now_time = maxx(now_time + t,node_l[l] + t);
            else now_time = maxx(now_time ,node_l[l]);
            
            
            if(now_fx != 1)
            {
                for(i = 1 ;i <= n && r <= n_r;i ++)
               {
                  if(node_r[r] <= now_time - t)
                  {
                    ans[id_r[r++]] =now_time;
                  }
                  else break;
               }
            }  
               
                       
            for(i = 1 ;i <= n && l <= n_l ;i ++)
            {
               if(node_l[l] <= now_time)
               {
                  ans[id_l[l++]] =now_time + t; 
               }
               else break;
            }
            now_fx = 2;
            now_time += t;
         }
         else
         {
            if(now_fx != 2) now_time = maxx(now_time + t,node_r[r] + t);
            else now_time = maxx(now_time ,node_r[r]);
            
            if(now_fx != 2)
            {
                for(i = 1 ;i <= n && l <= n_l;i ++)
               {
                  if(node_l[l] <= now_time - t)
                  {
                    ans[id_l[l++]] =now_time;
                  }
                  else break;
               }
            }  
            
            for(i = 1 ;i <= n && r <= n_r;i ++)
            {
               if(node_r[r] <= now_time)
               {
                 ans[id_r[r++]] =now_time + t;
               }
               else break;
            }
            now_fx = 1;
            now_time += t;
         }
      }
      for(i = 1 ;i <= m ;i ++)
      printf("%d\n" ,ans[i]);
      if(tt) printf("\n");
   }
   return 0;
}
            
         
