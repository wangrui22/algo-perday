`Complete the solution so that it reverses all of the words within the string passed in.

Example:

reverseWords("The greatest victory is that which requires no battle")
// should return "battle no requires which that is victory greatest The"`

function reverseWords(str){
    let str2 = str.split(' ');
    let str3 = '';
    for (let i=str2.length-1;i>0;--i) {
        str3 += str2[i] + ' ';
    }
    return str3+str2[0];
  }

  console.log(reverseWords("foobar" ));