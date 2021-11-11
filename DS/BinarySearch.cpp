#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;//Linear list
struct LNode{
    ElementType Data[MAXSIZE];
    Position Last; //last element in the linear list
};

List ReadInput();//store the elements
Position BinarySearch(List L,ElementType X)
{   
    Position start=1;
    Position middle;
    while(start<=L->Last) // <= or the last will never be reached
    {
        middle=(start+L->Last)/2;
    if (X==L->Data[middle])
        return middle;
    else if (X>L->Data[middle])
        {
            start=middle+1;
            
        }
    else if (X<L->Data[middle])
        {
            L->Last=middle-1;
        }
    }
    return NotFound;
};

int main()
{
    List L;
    ElementType X;
    Position P;

    L=ReadInput();//implemented by the judge
    scanf("%d",&X);
    P=BinarySearch(L,X);
    printf("%d\n",P);
}
// All tests passed.