
#include <iostream>
using namespace std;

void linearSearch(int arr[],int n,int value){
    bool found=false;
    for(int i=0;i<n;i++){
        if(arr[i]==value){
            cout<<"element found \n";
            found=true;
            break;
        }
    }
    if(!found){
        cout<<"element not found \n";
    }
}

int main()
{
    int arr[]={3,4,2,1,7};
    linearSearch(arr,5,8);
    return 0;
}
