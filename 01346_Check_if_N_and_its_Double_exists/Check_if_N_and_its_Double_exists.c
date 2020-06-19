/*  https://leetcode.com/problems/check-if-n-and-its-double-exist/  */

bool checkIfExist(int* arr, int arrSize) {
    int base = 1000;
    int hash_arr[2002];
    
    for ( int i = 0 ; i < 2002 ; ++i ) {
        hash_arr[i] = 0;
    }
    
    for ( int i = 0; i < arrSize ; ++i ) {
        hash_arr[ arr[i] + base ] += 1;
        
        int d_index = arr[i] >= -500 && arr[i] <= 500 ? 2 * arr[i] + base : -1;
        int h_index =  arr[i] % 2 == 0 ? arr[i] / 2 + base : -1;
        
        if ( arr[i] == 0 && hash_arr[base] > 1 ) {
            printf("0 occurs more than once.\n ");
            return true;
        } else if ( arr[i] != 0 && d_index >= 0 && hash_arr[d_index] > 0 ) {
            printf("Double exists for %d at index %d", arr[i], d_index);
            return true;
        } else if ( arr[i] != 0 && h_index >= 0 && hash_arr[h_index] > 0 ) {
            printf("Half exists for %d at index %d", arr[i], h_index);
            return true;
        }
    }
    
    return false;
}
