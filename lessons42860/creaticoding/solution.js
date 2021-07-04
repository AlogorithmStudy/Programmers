/*
테스트 1 〉	통과 (1.75ms, 36.5MB)
테스트 2 〉	통과 (1.63ms, 36.8MB)
테스트 3 〉	통과 (1.64ms, 37MB)
테스트 4 〉	통과 (1.68ms, 36.4MB)
테스트 5 〉	통과 (1.67ms, 38.4MB)
테스트 6 〉	통과 (1.67ms, 37.2MB)
테스트 7 〉	통과 (1.63ms, 37.1MB)
테스트 8 〉	실패 (3.01ms, 36.8MB)
테스트 9 〉	통과 (1.72ms, 36.5MB)
테스트 10 〉	실패 (3.01ms, 37.2MB)
*/

const n2a = (n)=>String.fromCharCode(n);
const a2n = (a)=>a.charCodeAt(0);

function solution(name) {
    
    var size = name.length;
    var answer = 0;
    var r=0, l=0;
    var isRight = false;
    var isZero = false;
    
    if(size == 1){
        isRight = false;
        isZero = true;
    }else{
        for(var i=1;i<size;i++)
            if(name[i] == 'A')
                r++;
            else
                break;
        for(var i=1;i<size;i++)
            if(name[size-i] == 'A')     
                l++;
            else
                break;
        isRight = r>l;
        isZero = r == 0 && l == 0;
    }
    
    // 맞는 코드 (병신주석)
    for(var i=0;i<size;i++){
        if(a2n(name[i])-a2n('M') < 0 ){
            answer+=(a2n(name[i])-a2n('A'));
        }else{
            answer+=(a2n('Z')-a2n(name[i])+1);
        }
    }
    
    answer+=(size-1);
    
    if(isZero)
        return answer;
    if(isRight)
        return answer-r;
    else
        return answer-l;
}
