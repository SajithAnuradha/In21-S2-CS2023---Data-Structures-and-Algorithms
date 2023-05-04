#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify

   int Max_value_index=root;
   int left=2*root +1;
   int right=2*root +2;
  // checking whether the root is smaller than the child
   if (left <n && arr[Max_value_index]< arr[left]){
      Max_value_index=left;

   }
   if (right < n && arr[Max_value_index]<arr[right] ){
       Max_value_index=right;
   }
// when root is smaller than the child , swap those
  if (Max_value_index!=root){
      swap(arr[Max_value_index],arr[root]);

      heapify(arr,n,Max_value_index);

  }

}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap by using function heapify
   for (int i=n/2-1;i>=0;i--){
      heapify(arr,n,i);

   }




   // extracting elements from heap one by one
for (int x=n-1;x>=0;x--){
      //max_number send to the end of the array
      swap(arr[0],arr[x]);
      // use recursively heapify
      heapify(arr,x,0);
   }


}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   cout<<"enter the size of array : "<<endl;
  // int heap_arr[] = {4,17,3,12,9,6};
  int n;

  cin>> n;
  int heap_arr[n];
  cout<<"enter the elemnts : " <<endl;
  for (int i=0;i<n;i++){
   cin>>heap_arr[i];

  }
   //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
