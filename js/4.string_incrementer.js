`Your job is to write a function which increments a string, to create a new string. If the string already ends with a number, the number should be incremented by 1. If the string does not end with a number the number 1 should be appended to the new string.

Examples:

foo -> foo1

foobar23 -> foobar24

foo0042 -> foo0043

foo9 -> foo10

foo099 -> foo100

Attention: If the number has leading zeros the amount of digits should be considered.`

function incrementString (strng) {
    if(!strng) {
        return '1';
    }
    if (isNaN(parseInt(strng.length-1))) {
        return strng + '1';
    }
    let s=-1;
    let p=0;
    for (let i=strng.length-1; i>-1; --i) {
        let n = parseInt(strng[i]);
        if( isNaN(n) || n < 9) {
            let new_str = isNaN(n) ? strng.slice(0,i+1) + '1' : strng.slice(0,i) + (n+1);
            for (let j=0;j<p;++j) {
                new_str += '0';
            }
            return new_str;
        } else {
            p++;   
        }
    }
  }

  //console.log(isNaN(parseInt('a')));
  console.log(incrementString('foobar999'));
//   let ss = 'foobar001';
//   console.log(ss.slice(0,3));