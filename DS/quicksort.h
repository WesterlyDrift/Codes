void quicksort(int a[],int low,int high)
{
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}