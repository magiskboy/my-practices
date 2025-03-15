

function getLetter(s) {
    let letter;
    // Write your code here
    letter = s.charAt(0);
    
    switch(true) {
        case 'aeiou'.includes(letter): return 'A';
        case 'bcdfg'.includes(letter): return 'B';
        case 'hjklm'.includes(letter): return 'C';
    }
    return 'D';
}

