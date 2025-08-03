
/*
 * Problem: 144A - Arrival of the General
 * Link: https://codeforces.com/problemset/problem/144/A
 *
 * Problem Statement:
 * A general is reviewing a line of soldiers. He wants the tallest soldier to be at the first position
 * and the shortest soldier to be at the last position. The soldiers can only be swapped with their
 * adjacent neighbors. Find the minimum number of swaps required to achieve this configuration.
 *
 * Approach:
 * This solution simulates the process of moving the soldiers.
 * 1.  Find the index of the leftmost tallest soldier (`idx_max`).
 * 2.  Find the index of the rightmost shortest soldier (`idx_min`).
 * 3.  Simulate moving the shortest soldier to the end of the line by repeatedly swapping it with its
 *     right neighbor, counting each swap.
 * 4.  Simulate moving the tallest soldier to the beginning of the line by repeatedly swapping it with
 *     its left neighbor, counting each swap.
 * 5.  The total number of swaps is the sum of the swaps from steps 3 and 4.
 *
 * Time Complexity: O(n^2) in the worst case due to the simulation of swaps.
 * Space Complexity: O(n) for storing the soldier heights.
 */
#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    int maxm = INT_MIN,idx_max,cntr=0;
    int minm = INT_MAX,idx_min,cntl=0;
    int j = sizeof(arr)-1;
    for(int i = 0; i<n ;i++){
        if(arr[i]>maxm){
            maxm = arr[i];
            idx_max = i;
        }
    }
    for(int i = n-1; i>=0 ;i--){
        if(arr[i]<minm){
            minm = arr[i];
            idx_min = i;
        }
    }
    for(int i = idx_min; i<n-1 ;i++){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        cntl++;
    }
    for(int i = idx_max; i>0 ;i--){
        int temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
        cntr++;
    }
    cout << cntr + cntl << " ";
    return 0;

}
