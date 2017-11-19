`The maximum sum subarray problem consists in finding the maximum sum of a contiguous subsequence in an array or list of integers:

maxSequence([-2, 1, -3, 4, -1, 2, 1, -5, 4])
// should be 6: [4, -1, 2, 1]
Easy case is when the list is made up of only positive numbers and the maximum sum is the sum of the whole array. If the list is made up of only negative numbers, return 0 instead.

Empty list is considered to have zero greatest sum. Note that the empty list or array is also a valid sublist/subarray.`

var maxSequence = function(arr){
    if (arr.length==0) {
        return 0;
    }
    let sum = 0;
    let maxsum = 0;
    let s=0,e=0;
    let max_s=0,max_e=0;
    for (let i=0; i<arr.length;++i) {
        sum += arr[i];
        e+=1;
        if(sum > maxsum) {
            maxsum = sum;
            max_e = e-1;
            max_s = s;
        }
        if (sum < 0) {
            s = i+1;
            e = i+1;
            sum = 0;
        }
    }
    //return arr.slice(max_s,max_e+1);
    return maxsum;
}

console.log(maxSequence([-2, 1, -3, 4, -1, 2, 1, -5, 4]));