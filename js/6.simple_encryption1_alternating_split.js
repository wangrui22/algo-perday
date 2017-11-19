`For building the encrypted string:
Take every 2nd char from the string, then the other chars, that are not every 2nd char, and concat them as new String.
Do this n times!

Examples:

"This is a test!", 1 -> "hsi  etTi sats!"
"This is a test!", 2 -> "hsi  etTi sats!" -> "s eT ashi tist!"
Write two methods:

function encrypt(text, n)
function decrypt(encryptedText, n)
For both methods:
If the input-string is null or empty return exactly this value!
If n is <= 0 then return the input text.

This kata is part of the Simple Encryption Series:
Simple Encryption #1 - Alternating Split
Simple Encryption #2 - Index-Difference
Simple Encryption #3 - Turn The Bits Around
Simple Encryption #4 - Qwerty

Have fun coding it and please don't forget to vote and rank this kata! :-)`

function encrypt(text, n) {
    if (!text) {
        return text;
    }
    if (n <=0) {
        return text;
    }
    let i =0;
    let res0='';
    let res1='';
    while (i<n) {
        for (let j=0; j<text.length; ++j) {
            if(j%2) {
                res0 += text[j];
            } else {
                res1 += text[j];
            }
        }
        text = res0 + res1;
        res0 = '';
        res1 = '';
        i++;
    }

    return text;
}
    
function decrypt(text, n) {
    if (!text) {
        return text;
    }
    if (n <=0) {
        return text;
    }
    let res='';
    let s = parseInt(text.length/2);
    let t = text.length - s*2;
    let i = 0;
    while (i<n) {
        for (let j=0; j<s; ++j) {
            res += (text[s+j] + text[j]);
        }
        if(t != 0) {
            res += text[text.length-1];
        }
        text = res;
        res = '';
        i++;
    }
    return text;
}

console.log(encrypt(null, 0));