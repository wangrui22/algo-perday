`Description:
Given an array (arr) as an argument complete the function countSmileys that should return the total number of smiling faces.

Rules for a smiling face:
-Each smiley face must contain a valid pair of eyes. Eyes can be marked as : or ;
-A smiley face can have a nose but it does not have to. Valid characters for a nose are - or ~
-Every smiling face must have a smiling mouth that should be marked with either ) or D.
No additional characters are allowed except for those mentioned.
Valid smiley face examples:
:) :D ;-D :~)
Invalid smiley faces:
;( :> :} :] 

Example cases:

countSmileys([':)', ';(', ';}', ':-D']);       // should return 2;
countSmileys([';D', ':-(', ':-)', ';~)']);     // should return 3;
countSmileys([';]', ':[', ';*', ':$', ';-D']); // should return 1;

Note: In case of an empty array return 0. You will not be tested with invalid input (input will always be an array). Order of the face (eyes, nose, mouth) elements will always be the same

Happy coding!`

//return the total number of smiling faces in the array
function countSmileys(arr) {
    let i=0;
    arr.forEach(ele => {
        if(ele.length ==2 || ele.length ==3) {
            if((ele[0] == ':' || ele[0] == ';') ) {
                if (ele.length == 3 && (ele[1] == '-' || ele[1] == '~') && (ele[2] == ')' || ele[2] == 'D')) {
                    i++;
                } else if ((ele[1] == ')' || ele[1] == 'D')){
                    i++;
                }
            }
        } 
    });
    return i;
}

console.log(countSmileys([';]', ':[', ';*', ':$', ';-D']))