
#include <iostream>
using namespace std;
void swap(int &a,int &b){
    int c=a;
    a=b;
    b=c;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
                
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main()
{
    int arr[]={3,4,2,1,7};
    bubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
