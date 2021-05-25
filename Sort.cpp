#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void insertionSort(int a[], int n){ //sap xep chen
    for(int i = 1; i<n ; i++){
        int temp = a[i];
        for(int j = i-1; j >= 0; j--){
            if(j == 0) a[0] = temp;
            if(a[j] > temp) a[j+1] = a[j];
            else{
                 a[j+1] = temp;
                 break;
            }        
        }
    }
}

void selectionSort(int a[], int n){ // sap xep chon
    int min,temp;
    for( int i = 0; i< n; i++){
        min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]) min = j;
        }
        if(min != i){
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

void bubbleSort(int a[], int n){ //sap xep noi bot
    bool x = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n-i; j++){
            if(a[j] > a[j+1]){
                x = 1;
                int temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
            if(!x) break; // ko co buoc hoan doi nao xay ra thi ket thuc luon
        }
    }
}

void merge(int a[], int start, int end, int mid){
    int *b = a;
    int index = 0;
    while((start <= mid)&&(mid+1 <= end)){
        if(b[start] < b[mid+1]){
            a[index] = b[start];
            start++;
            index++;
        }
        else {
            a[index] = b[mid+1];
            mid++;
            index++;
        }
    }
    //chep not nhung phan tu con lai cua nua trai vao a[]
    while(start <= mid){  
        a[index] = b[start];
        index++;
    }
    //chep not nhung phan tu con lai cua nua phai vao a[]
    while(mid+1 <= end){
        a[index] = b[mid+1];
        index++;
    }

}
//sap xep tron cho a[start] -> a[end] : chia de tri
void mergeSort(int a[], int start, int end){ 
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,end,mid);
    }
}

void quickSort(int a[], int n){ //sap xep nhanh

}

void heapSort(int a[], int n){

}

int main(){
    int a[] = {20,12,43,566,7};
    bubbleSort(a,5);
    for(int i= 0; i<5; i++){
        cout << a[i] << " ";
    }
}