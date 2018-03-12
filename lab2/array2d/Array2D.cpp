#include "Array2D.h"


void PrintArray2D(int** array, int k_cols, int k_rows) {
    for(int i=0; i<k_rows; i++){
        for(int j=0; j<k_cols; j++){
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }

}

int **NewArray2D(int n_rows, int n_columns){
    if(n_rows<=0 || n_columns<=0){
        return nullptr;
    }
    else{
        int **array=new int* [n_rows];
        for(int i=0; i<n_rows; i++){
            array[i]=new int[n_columns];
        }
        return array;
    }
}

void FillArray2D(int **array, int n_rows, int n_columns) {
    int k=1;
    for(int i=0; i<n_rows; i++){
        for(int j=0; j<n_columns; j++){
            array[i][j]=k++;
        }
    }
}

int **Array2D(int n_rows, int n_columns){
    if(n_rows<=0 || n_columns<=0){
        return nullptr;
    }
    else{
        int **array=new int* [n_rows];
        for(int i=0; i<n_rows; i++){
            array[i]=new int[n_columns];
        }
        FillArray2D(array, n_rows, n_columns);
        PrintArray2D(array, n_columns,  n_rows);
        return array;
    }
}


void DeleteArray2D(int **array, int n_rows, int n_columns){
    for(int i=0; i<n_rows; i++){
        delete [] array[i];
    }
    delete [] array;
}
