class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        // code here
        int n = dq.size();
        k=k%n;
        
        int arr[] = new int[n];
        int size=n,i=0;
        while(size!=0){
            arr[i++] = dq.removeFirst();
            size--;
        }
        
        if(type==1){
            revArray(arr, 0, n-1 );
            revArray(arr, 0, k-1 );
            revArray(arr, k, n-1 );
        }  
        else{
             revArray(arr, 0, k-1 );
            revArray(arr, k, n-1 );
            revArray(arr, 0, n-1 );
        }
        
        for(int x : arr){
            dq.add(x);
        }
    }
    static void revArray( int arr[] , int l, int h){
        while(l<h){
            int temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
            
            l++; h--;
        }
    }
    
}