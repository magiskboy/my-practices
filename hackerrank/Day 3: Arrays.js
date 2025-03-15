

/**
*   Return the second largest number in the array.
*   @param {Number[]} nums - An array of numbers.
*   @return {Number} The second largest number in the array.
**/
function getSecondLargest(nums) {
    // Complete the function
    let a = -99999, b = -99999;
    nums.forEach(el => {
        if (el > a) { b = a; a = el; }
        else if (el > b && el != a) { b = el; };
    });
    return b;
}

