`You get an array of arrays.
If you sort the arrays by their length, you will see, that their length-values are consecutive.
But one array is missing!


You have to write a method, that return the length of the missing array.

Example:
[[1, 2], [4, 5, 1, 1], [1], [5, 6, 7, 8, 9]] --> 3


If the array of arrays is null/nil or empty, the method should return 0.

When an array in the array is null or empty, the method should return 0 too!
There will always be a missing element and its length will be always between the given arrays. 

Have fun coding it and please don't forget to vote and rank this kata! :-)

I have created other katas. Have a look if you like coding and challenges.`

function getLengthOfMissingArray(arrayOfArrays) {
    let bu = [0];
    if (arrayOfArrays == null) {
        return 0;
    }
    if (arrayOfArrays[0] == null) {
        return 0;
    }
    let minLength = arrayOfArrays[0].length;
    for (let i=1; i<arrayOfArrays.length; ++i) {
        bu.push(0);
        if (arrayOfArrays[i] == null) {
            return 0;
        }
        minLength = arrayOfArrays[i].length < minLength ? arrayOfArrays[i].length : minLength;
    }
    if (minLength == 0) {
        return 0;
    }
    
    for (let i=0; i<arrayOfArrays.length; ++i) {
        bu[arrayOfArrays[i].length-minLength] = 1;
    }

    for (let i=0; i<bu.length; ++i) {
        if (!bu[i]) {
            return i+minLength;
        }
    }
    return -1;
  }

  let res = getLengthOfMissingArray([[1],
    [4, 0],
    [0, 0, 0],
    [],
    [1, 1, 3, 2],
    [1, 2, 1, 2, 2, 4],
    [2, 2, 1, 0, 3, 3, 0],
    [3, 3, 4, 0, 4, 0, 2, 2]]);
  console.log(res);
  