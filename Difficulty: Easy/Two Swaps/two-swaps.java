//{ Driver Code Starts
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = Integer.parseInt(scanner.nextLine()); // Read number of test cases

        // Loop through each test case
        while (t-- > 0) {
            String input = scanner.nextLine();
            String[] inputArr = input.split(" ");
            List<Integer> arr = new ArrayList<>();

            // Convert input to list of integers
            for (String str : inputArr) {
                arr.add(Integer.parseInt(str));
            }

            Solution ob = new Solution();
            boolean ans = ob.checkSorted(arr);

            // Output result
            if (ans)
                System.out.println("true");
            else
                System.out.println("false");
        }

        scanner.close();
    }
}

// } Driver Code Ends


class Solution {
    public void swap(int[][] a, int i, int j){
        int[] t=a[i];
        a[i]=a[j];
        a[j]=t;
    }

    public boolean checkSorted(List<Integer> arr) {
        // code here
        int n=arr.size();
        int[][] a=new int[n][2];
        for(int i=0;i<n;i++)
            a[i]=new int[]{arr.get(i), i};
        Arrays.sort(a, (x,y)->x[0]-y[0]);
        int swaps=0, idx=0;
        while(idx<n){
            if(a[idx][1]==idx) idx++;
            else{
                swap(a, idx, a[idx][1]);
                swaps++;
            }
        }
        return swaps<=2;
    }
}