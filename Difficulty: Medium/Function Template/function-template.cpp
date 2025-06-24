// User function Template for C++

template <class T>
T largest(T arr[], int n) {

    // code here
    T mx=arr[0];
    for(int i=0;i<n;i++)
        if(arr[i]>mx)
            mx=arr[i];
    return mx;
}