#include <iostream>
#include <cmath>

using namespace std;

//Selection Sort
void selectionSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            swap(arr[i],arr[minIndex]);
        }
    }
}


//jump search
int jumpSearch(int arr[], int n, int x){
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step,n)-1] < x){
        prev = step;
        step += sqrt(n);
        if(prev>=n){
            return - 1; //elemen tidak ditemukan
        }
    }

    if (arr[prev]==x){
        return prev; //elemen ditemukan di indeks 'prev'
    }

    return -1; //Elemen tidak ditemukan
}


int main() {
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr) / sizeof(arr[0]);

    //selection sort
    selectionSort(arr,n);
    cout<<"Array setelah diurutkan dengan Selection Sort :"<<endl;
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int x = 22;//Elemen yang akan dicari dengan jump search
    int result = jumpSearch(arr,n,x);

    if(result != -1){
        cout<<"Elemen "<<x<<" ditemukan di indeks "<<result<<endl;
    }else{
        cout<<"Elemen "<<x<<" tidak ditemukan dalam array."<<endl;
    }

    return 0;
}
