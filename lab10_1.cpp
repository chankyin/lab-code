int *pointer_to_largest(int array[], int size){
    int *result = array;
    for(int i = 1; i < size; ++i){
        if(*result < array[i]){
            result = &array[i];
        }
    }
    return result;
}