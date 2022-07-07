#include <stdio.h>
#include <stdlib.h>
struct set{
    int nr;
    int array[10000];
};
struct set empty_set()
{
    struct set c;
    c.nr = 0;
    return c;
}
void add_element(struct set c,int element)
{
    c.array[c.nr++]=element;
    return c;
}
struct set sets_union(struct set x, struct set y)
{
    int i=0,j=0;
    struct set c = empty_set();
    while(i<x.nr && j<y.nr)
    {
        if(x.array[i]==y.array[j])
            i++;
        if(i==x.nr)
            break;
        c=add_element(c,x.array[i]<y.array[j] ? x.array[i++] : y.array[j++]);
    }
    while(i<x.nr)
        c=add_element(c,x.array[i++]);
    while(j<y.nr)
        c=add_element(c,y.array[j++]);
    return c;
}
struct set sets_intersection(struct set x, struct set y)
{
    int i=0, j=0;
    struct set c=empty_set();
    while(i<x.nr && j<y.nr)
    {
        if(x.array[i] == y.array[j])
        {
            c=add_element(c,x.array[i++]);
            j++;
        }
        if(x.array[i]<y.array[j])
            i++;
        if(x.array[i]>y.array[j])
            j++;
    }
    return c;
}
int main()
{
    char q;
    int n,m,i,a;
    scanf("%c",&q);
    while(q!='x')
    {
        struct set c=empty_set(),x=empty_set(),y=empty_set();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            x=add_element(x,a);
        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            y=add_element(y,a);
        }
        if(q=='u')
            c=sets_union(x,y);
        if(q=='i')
            c=sets_intersection(x,y);
        for(i=0;i<c.nr;i++)
            printf("%d ", c.array[i]);
        printf("\n");
        scanf("%c",&q);
    }
    return 0;
}
